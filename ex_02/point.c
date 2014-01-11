/*
** point.c for rush in /home/lavand_m/Desktop/piscine/piscinecpprush1
**
** Made by Maxime
** Login   <lavand_m@epitech.net>
**
** Started on  Sat Jan 11 10:57:16 2014 Maxime
** Last update Sat Jan 11 11:31:40 2014 Maxime
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "point.h"

typedef struct
{
  Class base;
  int x, y;
  char *str;
} PointClass;

static void Point_ctor(Object* self, va_list *ap)
{

  self->x = va_arg(*ap, int);
  self->y = va_arg(*ap, int);
  self->str = NULL;
}

static void Point_dtor(Object* self)
{
  free(self->str);
}

static char const *Point_str(Object* self)
{
  if (self->str != NULL)
    free(str);
  self->str = malloc(33);
  snprintf(self->str, 33, "<Point (%d, %d)>", self->x, self->y);
  return(self->str);
}

static PointClass _description = {
  { sizeof(PointClass), "Point", &Point_ctor, &Point_dtor, &Point_str },
  0, 0, NULL
};

Class* Point = (Class*) &_description;
