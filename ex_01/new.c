/*
** new.c for new in /home/debas_e/Project/piscine_cpp/Rush/piscinecpprush1/ex_01
** 
** Made by Etienne
** Login   <debas_e@epitech.net>
** 
** Started on  Sat Jan 11 09:28:41 2014 Etienne
** Last update Sat Jan 11 09:56:51 2014 Etienne
*/

#include "object.h"
#include <stdlib.h>

Object		*new(Class *object)
{
  Object	*ret;

  ret = NULL;
  if ((ret = malloc(object->__size__)) == NULL)
    raise ("Out of memory");
  memcpy(ret, object, object->__size__);
  if (ret->base->__init__ != NULL)
    ret->base->__init__(ret);
  return (ret);
}
