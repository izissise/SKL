/*
** vertex.c for rush in /home/lavand_m/Desktop/piscine/piscinecpprush1
**
** Made by Maxime
** Login   <lavand_m@epitech.net>
**
** Started on  Sat Jan 11 10:57:39 2014 Maxime
** Last update Sat Jan 11 10:57:48 2014 Maxime
*/

#include <stdlib.h>
#include <stdio.h>
#include "point.h"

typedef struct
{
    Class base;
    int x, y, z;
    char *str;
} VertexClass;

static void Vertex_ctor(Object* self)
{
    self->str = NULL;
}

static void Vertex_dtor(Object* self)
{
    free(self->str);
}

char const *Vertex_str(Object* self)
{
    if (self->str != NULL)
        free(str);
    self->str = malloc(46);
    snprintf(self->str, 46, "<Vertex (%d, %d, %d)>", self->x, self->y, self->y);
    return(self->str);
}

static VertexClass _description = {
    { sizeof(VertexClass), "Vertex", &Vertex_ctor, &Vertex_dtor, &Vertex_str },
    0, 0, 0
};

Class* Vertex = (Class*) &_description;
