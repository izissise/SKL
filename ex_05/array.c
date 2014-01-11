
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
} ArrayClass;

typedef struct {
    Iterator base;
    ArrayClass* _array;
    size_t _idx;
} ArrayIteratorClass;

Object* Array_getitem(ArrayClass* self, ...);
size_t Array_len(ArrayClass* self);
void Array_setitem(ArrayClass* self, ...);

void ArrayIterator_ctor(ArrayIteratorClass* self, va_list* args)
{
    int tmp;

    if (self == NULL || args == NULL)
      return ;
    self->_array = (ArrayClass*)va_arg(*args, void*);
    tmp = va_arg(*args, int);
    if (tmp == 1)
        self->_idx = Array_len(self->_array);
    else
        self->_idx = 0;
}

bool ArrayIterator_eq(ArrayIteratorClass* self, ArrayIteratorClass* other)
{
  if (self == NULL || other == NULL)
    return 0;
    return(self->_idx == other->_idx);
}

bool ArrayIterator_gt(ArrayIteratorClass* self, ArrayIteratorClass* other)
{
  if (self == NULL || other == NULL)
    return 0;
    return(self->_idx > other->_idx);
}

bool ArrayIterator_lt(ArrayIteratorClass* self, ArrayIteratorClass* other)
{
  if (self == NULL || other == NULL)
    return 0;
    return(self->_idx < other->_idx);
}

void ArrayIterator_incr(ArrayIteratorClass* self)
{
  if (self == NULL)
    return ;
    self->_idx++;
}

Object* ArrayIterator_getval(ArrayIteratorClass* self)
{
  if (self == NULL)
    return NULL;
    return (Array_getitem(self->_array, self->_idx));
}

void ArrayIterator_setval(ArrayIteratorClass* self, ...)
{
    va_list	ap;

    if (self == NULL)
      return ;
    va_start(ap, self);
    delete(self->_array->_tab[self->_idx]);
    self->_array->_tab[self->_idx] = va_new(self->_array->_type, &ap);
    va_end(ap);
}

static ArrayIteratorClass ArrayIteratorDescr = {
    {
        {
            sizeof(ArrayIteratorClass), "ArrayIterator",
            (ctor_t) &ArrayIterator_ctor,
            NULL, /* dtor */
            NULL, /* str */
            NULL, NULL, NULL, NULL, /* add, sub, mul, div */
            (binary_comparator_t) &ArrayIterator_eq,
            (binary_comparator_t) &ArrayIterator_gt,
            (binary_comparator_t) &ArrayIterator_lt,
        },
        (incr_t) &ArrayIterator_incr,
        (getval_t) &ArrayIterator_getval,
        (setval_t) &ArrayIterator_setval,
    },
    NULL,
    0
};

static Class* ArrayIterator = (Class*) &ArrayIteratorDescr;

void Array_ctor(ArrayClass* self, va_list* args)
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

void Array_dtor(ArrayClass* self)
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

size_t Array_len(ArrayClass* self)
{
  if (self == NULL)
    return ((size_t)0);
  return ((size_t)self->_size);
}

Iterator* Array_begin(ArrayClass* self)
{
  if (self == NULL)
    return NULL;
  return (new(ArrayIterator, self, 0));
}

Iterator* Array_end(ArrayClass* self)
{
  if (self == NULL)
    return NULL;
  return (new(ArrayIterator, self, 1));
}

Object* Array_getitem(ArrayClass* self, ...)
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


void Array_setitem(ArrayClass* self, ...)
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

static ArrayClass _descr = {
    { /* Container */
        { /* Class */
            sizeof(ArrayClass), "Array",
            (ctor_t) &Array_ctor, (dtor_t) &Array_dtor,
            NULL, /*str */
            NULL, NULL, NULL, NULL, /* add, sub, mul, div */
            NULL, NULL, NULL, /* eq, gt, lt */
        },
        (len_t) &Array_len,
        (iter_t) &Array_begin,
        (iter_t) &Array_end,
        (getitem_t) &Array_getitem,
        (setitem_t) &Array_setitem,
    },
    NULL, 0, NULL
};

Class* Array = (Class*) &_descr;
