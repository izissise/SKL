
#include <stdlib.h>
#include <stdarg.h>

#include "raise.h"
#include "array.h"
#include "new.h"


typedef struct
{
    Container base;
    Class* _type;
    size_t _size;
    Object** _tab;
} ListClass;

typedef struct {
    Iterator base;
    ListClass* _array;
    size_t _idx;
} ListIteratorClass;

Object* List_getitem(ListClass* self, ...);
size_t List_len(ListClass* self);
void List_setitem(ListClass* self, ...);

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
    delete(self->_array->_tab[self->_idx]);
    self->_array->_tab[self->_idx] = va_new(self->_array->_type, &ap);
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
    self->_size = (size_t) va_arg(*args, int);
    self->_type = (Class*) va_arg(*args, void *);
    self->_tab = malloc((self->_size + 1) * sizeof(Object**));
    i = 0;
    while (i < (int)self->_size)
    {
      va_copy(ap, *args);
      self->_tab[i] = va_new(self->_type, &ap);
      i++;
    }
    self->_tab[i] = NULL;
}

void List_dtor(ListClass* self)
{
    int i;

    i = 0;
    if (self == NULL)
      return ;
    while (i < (int)self->_size)
    {
        delete(self->_tab[i]);
        i++;
    }
    free(self->_tab);
    self->_tab = NULL;
}

size_t List_len(ListClass* self)
{
  if (self == NULL)
    return ((size_t)0);
  return ((size_t)self->_size);
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
    if (id > (int)self->_size)
        return (NULL);
    return (self->_tab[id]);
}


void List_setitem(ListClass* self, ...)
{
    int id;
    va_list	ap;

    if (self == NULL)
      return ;
    va_start(ap, self);
    id = va_arg(ap, int);
    delete(self->_tab[id]);
    self->_tab[id] = va_new(self->_type, &ap);
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
    NULL, 0, NULL
};

Class* List = (Class*) &_descr;
