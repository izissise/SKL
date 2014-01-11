/*
** new.c for new in /home/debas_e/Project/piscine_cpp/Rush/piscinecpprush1/ex_01
** 
** Made by Etienne
** Login   <debas_e@epitech.net>
** 
** Started on  Sat Jan 11 09:28:41 2014 Etienne
** Last update Sat Jan 11 09:39:41 2014 Etienne
*/

#include "object.h"
#include <stdlib.h>

Object		*new(Class *object) {
  Object	*ret = NULL;

  ret = malloc(object->__size__);
  
}
