/*
** vertex.c for rush in /home/lavand_m/Desktop/piscine/piscinecpprush1
**
** Made by Maxime
** Login   <lavand_m@epitech.net>
**
** Started on  Sat Jan 11 10:57:39 2014 Maxime
** Last update Sat Jan 11 15:45:03 2014 Maxime
*/

#include <stdlib.h>
#include <stdio.h>
#include "vertex.h"
#include "new.h"

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
  snprintf(a->str, 199, "<%s (%d, %d, %d)>", a->str, a->x, a->y, a->y);
  return(a->str);
}

static Object *Vertex_add(const Object* self, const Object* other)
{
  VertexClass *a;
  VertexClass *b;

  a = (VertexClass *)self;
  b = (VertexClass *)other;
  return(new(Vertex, a->x + b->x, a->y + b->y, a->z - b->z));
}

static Object *Vertex_sub(const Object* self, const Object* other)
{
  VertexClass *a;
  VertexClass *b;

  a = (VertexClass *)self;
  b = (VertexClass *)other;
  return(new(Vertex, a->x - b->x, a->y - b->y, a->z - b->z));
}

static VertexClass _description = {
    { sizeof(VertexClass), "Vertex", &Vertex_ctor, &Vertex_dtor, &Vertex_str, &Vertex_add, &Vertex_sub },
    0, 0, 0, NULL
};

Class* Vertex = (Class*) &_description;
