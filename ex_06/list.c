#include <stdlib.h>
#include <stdarg.h>

#include "raise.h"
#include "list.h"
#include "new.h"



typedef struct s_list
{
  Object* _obj;
  struct s_list   *next;
}             t_list;

typedef struct
{
  Container base;
  Class* _type;
  t_list* phead;
} ListClass;

typedef struct {
  Iterator base;
  ListClass* _array;
  size_t _idx;
} ListIteratorClass;

Object* List_getitem(ListClass* self, ...);
size_t List_len(ListClass* self);
void List_setitem(ListClass* self, ...);


unsigned int list_get_size(t_list* list)
{
  unsigned int res = 0;

  t_list* tmp = list;
  while (tmp != NULL)
    {
      tmp = tmp->next;
      res++;
    }
  return res;
}

void list_add_elem_at_position(t_list **front_ptr, void* elem, unsigned int position)
{
  if (front_ptr == NULL)
    return ;

  t_list* newnode;
  if ((newnode = malloc(1 * sizeof(t_list))) == NULL)
    return ;
  newnode->next = NULL;
  newnode->_obj = elem;

  unsigned int i = 0;
  t_list* tmp = *front_ptr;
  if (position == 0)
    {
      if (tmp != NULL)
        newnode->next = tmp;
      (*front_ptr) = newnode;
      return;
    }

  while (i < position - 1)
    {
      if (tmp == NULL)
        return ;
      tmp = tmp->next;
      i++;
    }
  newnode->next = tmp->next;
  tmp->next = newnode;
  return;
}

void list_add_elem_at_front(t_list **front_ptr, void* elem)
{
  list_add_elem_at_position(front_ptr, elem, 0);
}

void list_add_elem_at_back(t_list **front_ptr, void* elem)
{
  list_add_elem_at_position(front_ptr, elem, list_get_size(*front_ptr));
}

void list_del_elem_at_position(t_list **front_ptr, unsigned int position)
{
  if (front_ptr == NULL || (*front_ptr == NULL))
    return ;

  unsigned int i = 0;
  t_list* tmp = *front_ptr;
  t_list* tmpo;
  if (position == 0)
    {
      *front_ptr = tmp->next;
      free(tmp);
      return;
    }

  while (i < position - 1)
    {
      if (tmp == NULL)
        return ;
      tmp = tmp->next;
      i++;
    }
  if (tmp->next == NULL)
    return ;
  tmpo = tmp->next;
  tmp->next = tmp->next->next;
  free(tmpo);
  return;
}

void list_del_elem_at_front(t_list **front_ptr)
{
  list_del_elem_at_position(front_ptr, 0);
}

void list_del_elem_at_back(t_list **front_ptr)
{
  list_del_elem_at_position(front_ptr, list_get_size(*front_ptr) - 1);
}

void* list_get_elem_at_position(t_list* list, unsigned int position)
{
  t_list* tmp = list;
  if (tmp == NULL)
    return 0;
  unsigned int i = 0;
  while (i < position && tmp != NULL)
    {
      tmp = tmp->next;
      i++;
    }
  if (tmp == NULL)
    return 0;
  return tmp->_obj;
}

void* list_get_elem_at_front(t_list* list)
{
  return list_get_elem_at_position(list, 0);
}

void* list_get_elem_at_back(t_list* list)
{
  return list_get_elem_at_position(list, list_get_size(list) - 1);
}


void ListIterator_ctor(ListIteratorClass* self, va_list* args)
{
  int tmp;

  if (self == NULL || args == NULL)
    return ;
  self->_array = (ListClass*)va_arg(*args, void*);
  tmp = va_arg(*args, int);
  if (tmp == 1)
    self->_idx = List_len(self->_array);
  else
    self->_idx = 0;
}

bool ListIterator_eq(ListIteratorClass* self, ListIteratorClass* other)
{
  if (self == NULL || other == NULL)
    return 0;
  return(self->_idx == other->_idx);
}

bool ListIterator_gt(ListIteratorClass* self, ListIteratorClass* other)
{
  if (self == NULL || other == NULL)
    return 0;
  return(self->_idx > other->_idx);
}

bool ListIterator_lt(ListIteratorClass* self, ListIteratorClass* other)
{
  if (self == NULL || other == NULL)
    return 0;
  return(self->_idx < other->_idx);
}

void ListIterator_incr(ListIteratorClass* self)
{
  if (self == NULL)
    return ;
  self->_idx++;
}

Object* ListIterator_getval(ListIteratorClass* self)
{
  if (self == NULL)
    return NULL;
  return (List_getitem(self->_array, self->_idx));
}

void ListIterator_setval(ListIteratorClass* self, ...)
{
  va_list	ap;

  if (self == NULL)
    return ;
  va_start(ap, self);

  t_list *ptr;
  if ((ptr = list_get_elem_at_position(self->_array->phead, self->_idx)) != NULL)
    {
      delete(ptr->_obj);
      ptr->_obj = va_new(self->_array->_type, &ap);
    }
  va_end(ap);
}

static ListIteratorClass ListIteratorDescr = {
  {
    {
      sizeof(ListIteratorClass), "ListIterator",
      (ctor_t) &ListIterator_ctor,
      NULL, /* dtor */
      NULL, /* str */
      NULL, NULL, NULL, NULL, /* add, sub, mul, div */
      (binary_comparator_t) &ListIterator_eq,
      (binary_comparator_t) &ListIterator_gt,
      (binary_comparator_t) &ListIterator_lt,
    },
    (incr_t) &ListIterator_incr,
    (getval_t) &ListIterator_getval,
    (setval_t) &ListIterator_setval,
  },
  NULL,
  0
};

static Class* ListIterator = (Class*) &ListIteratorDescr;

void List_ctor(ListClass* self, va_list* args)
{
  int i;
  va_list ap;

  if (self == NULL || args == NULL)
    return ;
  int lsize = (size_t) va_arg(*args, int);
  self->_type = (Class*) va_arg(*args, void *);
  self->phead = NULL;
  i = 0;
  while (i < lsize)
    {
      va_copy(ap, *args);
      list_add_elem_at_front(&(self->phead), va_new(self->_type, &ap));
      i++;
    }
}

void List_dtor(ListClass* self)
{
  int i;

  i = 0;
  if (self == NULL)
    return ;
  int lsize = list_get_size(self->phead);
  while (i < lsize)
    {
      t_list* ptr = list_get_elem_at_front(self->phead);
      delete(ptr->_obj);
      list_del_elem_at_front(&(self->phead));
      i++;
    }
}

size_t List_len(ListClass* self)
{
  if (self == NULL)
    return ((size_t)0);
  return (list_get_size(self->phead));
}

Iterator* List_begin(ListClass* self)
{
  if (self == NULL)
    return NULL;
  return (new(ListIterator, self, 0));
}

Iterator* List_end(ListClass* self)
{
  if (self == NULL)
    return NULL;
  return (new(ListIterator, self, 1));
}

Object* List_getitem(ListClass* self, ...)
{
  int id;
  va_list	ap;

  if (self == NULL)
    return NULL;
  va_start(ap, self);
  id = va_arg(ap, int);
  va_end(ap);
  int lsize = list_get_size(self->phead);
  if (id > lsize)
    return (NULL);
  return (list_get_elem_at_position(self->phead, id));
}


void List_setitem(ListClass* self, ...)
{
  int id;
  va_list	ap;

  if (self == NULL)
    return ;
  va_start(ap, self);
  id = va_arg(ap, int);
  t_list* ptr = list_get_elem_at_position(self->phead, id);
  delete(ptr->_obj);
  ptr->_obj = va_new(self->_type, &ap);
  va_end(ap);
}

static ListClass _descr = {
  { /* Container */
    { /* Class */
      sizeof(ListClass), "List",
      (ctor_t) &List_ctor, (dtor_t) &List_dtor,
      NULL, /*str */
      NULL, NULL, NULL, NULL, /* add, sub, mul, div */
      NULL, NULL, NULL, /* eq, gt, lt */
    },
    (len_t) &List_len,
    (iter_t) &List_begin,
    (iter_t) &List_end,
    (getitem_t) &List_getitem,
    (setitem_t) &List_setitem,
  },
  NULL, NULL
};

Class* List = (Class*) &_descr;


