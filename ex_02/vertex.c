#include <stdio.h>
#include "point.h"

typedef struct
{
    Class base;
    int x, y, z;
} VertexClass;

static void Vertex_ctor(Object* self)
{
    (void) self;
    printf("Vertex()\n");
}

static void Vertex_dtor(Object* self)
{
    (void) self;
    printf("~Vertex()\n");
}

char const *Vertex_str(Object* self)
{
    return("<Vertex (0, 1, 2)>");
}

static VertexClass _description = {
    { sizeof(VertexClass), "Vertex", &Vertex_ctor, &Vertex_dtor, &Vertex_str },
    0, 0, 0
};

Class* Vertex = (Class*) &_description;
