/*
** new.c for new in /home/debas_e/Project/piscine_cpp/Rush/piscinecpprush1/ex_01
**
** Made by Etienne
** Login   <debas_e@epitech.net>
**
** Started on  Sat Jan 11 09:28:41 2014 Etienne
** Last update Sat Jan 11 09:50:25 2014 Etienne
*/

#include "object.h"
#include <stdlib.h>

Object		*new(Class *object) {
  Object	*ret = NULL;

  ret = malloc(object->__size__);
  memcpy(ret, object, object->__size__);
  ret->base->__init__(ret);
  return (ret);
}


void		delete(Object* ptr)
{
  if (ptr != NULL)
    {
      Class *base = &(ptr->base);
      if (base->__del__ != NULL)
      base->__del__(ptr);
    }
}
