/*
** new.c for new in /home/debas_e/Project/piscine_cpp/Rush/piscinecpprush1/ex_01
**
** Made by Etienne
** Login   <debas_e@epitech.net>
**
** Started on  Sat Jan 11 09:28:41 2014 Etienne
** Last update Sat Jan 11 11:41:45 2014 Maxime
*/

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "object.h"
#include "raise.h"
#include "point.h"

Object		*va_new(Class *object, va_list *ap)
{
  Object	*ret;

  if ((ret = malloc(object->__size__)) == NULL)
    raise("Out of memory");
  memcpy(ret, object, object->__size__);
  if (((Class*)ret)->__init__ != NULL)
    ((Class*)ret)->__init__(ret, ap);
  return (ret);
}

Object		*new(Class *object, ...)
{
  va_list	ap;
  Object	*ret;

  ret = NULL;
  if (object != NULL)
    {
      va_start(ap, object);
      ret = va_new(object, &ap);
      va_end(ap);
      return (ret);
    }
  return (NULL);
}

void		delete(Object* ptr)
{
  if (ptr != NULL)
    {
      Class *base = (Class*)ptr;
      if (base->__del__ != NULL)
        base->__del__(ptr);
      free(ptr);
    }
}
