/*
** vertex.c for rush in /home/lavand_m/Desktop/piscine/piscinecpprush1
**
** Made by Maxime
** Login   <lavand_m@epitech.net>
**
** Started on  Sat Jan 11 10:57:39 2014 Maxime
** Last update Sat Jan 11 15:43:59 2014 Maxime
*/

#include <stdlib.h>
#include <stdio.h>
#include "vertex.h"

typedef struct
{
  Class base;
  int x, y, z;
  char *str;
} VertexClass;

static void Vertex_ctor(Object* self, va_list *ap)
{
  VertexClass *a;

  a = (VertexClass *)self;
  a->x =(int) va_arg(*ap, int);
  a->y =(int) va_arg(*ap, int);
  a->z =(int) va_arg(*ap, int);
  a->str = NULL;
}

static void Vertex_dtor(Object* self)
{
  VertexClass *a;

  a = (VertexClass *) self;
  free(a->str);
}

static char const *Vertex_str(Object* self)
{
  VertexClass *a;

  a = (VertexClass *)self;
  if (a->str != NULL)
    free(a->str);
  a->str = malloc(200);
  snprintf(a->str, 199, "<Vertex (%d, %d, %d)>", a->x, a->y, a->y);
  return(a->str);
}

static VertexClass _description = {
  { sizeof(VertexClass), "Vertex", &Vertex_ctor, &Vertex_dtor, &Vertex_str },
  0, 0, 0, NULL
};

Class* Vertex = (Class*) &_description;
