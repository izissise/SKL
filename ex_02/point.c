#include <stdio.h>
#include "point.h"

typedef struct
{
    Class base;
    int x, y, z;
} PointClass;

static void Point_ctor(Object* self)
{
    (void) self;
    printf("Point()\n");
}

static void Point_dtor(Object* self)
{
    (void) self;
    printf("~Point()\n");
}

char const *Point_str(Object* self)
{
    return("<Point (0, 1, 2)>");
}

static PointClass _description = {
    { sizeof(PointClass), "Point", &Point_ctor, &Point_dtor, &Point_str },
    0, 0, 0
};

Class* Point = (Class*) &_description;
