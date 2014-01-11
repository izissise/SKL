/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include <stdio.h>
#include <stdlib.h>
#include "object.h"
#include "new.h"
#include "float.h"

typedef struct
{
  Class base;
  float x;
  char *str;
} FloatClass;

typedef struct
{
  Class base;
  char x;
  char *str;
} CharClass;

typedef struct
{
  Class base;
  int x;
  char *str;
} IntClass;

static void Float_ctor(Object* self, va_list *ap)
{
  FloatClass *a;

  a = (FloatClass *) self;
  double tmp = (double)va_arg(*ap, double);
  a->x = tmp;
  a->str = NULL;
}

static void Float_dtor(Object* self)
{
  FloatClass *a;

  a = (FloatClass *) self;
  free(a->str);
}

static char const *Float_str(Object* self)
{
  FloatClass *a;

  a = (FloatClass *) self;
  if (a->str != NULL)
    free(a->str);
  a->str = malloc(200);
  snprintf(a->str, 199, "<%s (%f)>", a->base.__name__, a->x);
  return(a->str);
}

static Object *Float_add(const Object* self, const Object* other)
{
  FloatClass *a;
  CharClass *b;
  FloatClass *c;
  IntClass *d;
  Class *e;

  e = (Class *)other;
  a = (FloatClass *)self;
  if (strcmp(e->__name__, "Float") == 0)
    {
      c = (FloatClass *)other;
      return (new(Float, (a->x + (char)c->x)));
    }
  if (strcmp(e->__name__, "Int") == 0)
    {
      d = (IntClass *)other;
      return (new(Float, (a->x + (int)d->x)));
    }
  if (strcmp(e->__name__, "Char") == 0)
    {
      b = (CharClass *)other;
      return(new(Float, a->x + b->x));
    }
  return (NULL);
}

static Object *Float_sub(const Object* self, const Object* other)
{
  FloatClass *a;
  CharClass *b;
  FloatClass *c;
  IntClass *d;
  Class *e;

  e = (Class *)other;
  a = (FloatClass *)self;
  if (strcmp(e->__name__, "Float") == 0)
    {
      c = (FloatClass *)other;
      return (new(Float, (a->x - (char)c->x)));
    }
  if (strcmp(e->__name__, "Int") == 0)
    {
      d = (IntClass *)other;
      return (new(Float, (a->x - (int)d->x)));
    }
  if (strcmp(e->__name__, "Char") == 0)
    {
      b = (CharClass *)other;
      return(new(Float, a->x - b->x));
    }
  return (NULL);
}

static Object *Float_mul(const Object* self, const Object* other)
{
  FloatClass *a;
  CharClass *b;
  FloatClass *c;
  IntClass *d;
  Class *e;

  e = (Class *)other;
  a = (FloatClass *)self;
  if (strcmp(e->__name__, "Float") == 0)
    {
      c = (FloatClass *)other;
      return (new(Float, (a->x * (char)c->x)));
    }
  if (strcmp(e->__name__, "Int") == 0)
    {
      d = (IntClass *)other;
      return (new(Float, (a->x * (int)d->x)));
    }
  if (strcmp(e->__name__, "Char") == 0)
    {
      b = (CharClass *)other;
      return(new(Float, a->x * b->x));
    }
  return (NULL);
}

static Object *Float_div(const Object* self, const Object* other)
{
  FloatClass *a;
  CharClass *b;
  FloatClass *c;
  IntClass *d;
  Class *e;

  e = (Class *)other;
  a = (FloatClass *)self;
  if (strcmp(e->__name__, "Float") == 0)
    {
      c = (FloatClass *)other;
      return (new(Float, (c->x == 0 ? 0 : (a->x / (char)c->x))));
    }
  if (strcmp(e->__name__, "Int") == 0)
    {
      d = (IntClass *)other;
      return (new(Float, (d->x == 0 ? 0 : (a->x / (int)d->x))));
    }
  if (strcmp(e->__name__, "Char") == 0)
    {
      b = (CharClass *)other;
      return(new(Float, (b->x == 0 ? 0 : (a->x / b->x))));
    }
  return (NULL);
}

static bool Float_eq(const Object* self, const Object* other)
{
  //==
  FloatClass *a;
  CharClass *b;
  FloatClass *c;
  IntClass *d;
  Class *e;

  e = (Class *)other;
  a = (FloatClass*)self;
  if (strcmp(e->__name__, "Float") == 0)
    {
      c = (FloatClass *)other;
      return (a->x == c->x);
    }
  if (strcmp(e->__name__, "Int") == 0)
    {
      d = (IntClass *)other;
      return (a->x == (int)d->x);
    }
  if (strcmp(e->__name__, "Char") == 0)
    {
      b = (CharClass *)other;
      return(a->x == b->x);
    }
  return (false);
}

static bool Float_gt(const Object* self, const Object* other)
{
  //>
  FloatClass *a;
  CharClass *b;
  FloatClass *c;
  IntClass *d;
  Class *e;

  e = (Class *)other;
  a = (FloatClass *)self;
  if (strcmp(e->__name__, "Float") == 0)
    {
      c = (FloatClass *)other;
      return (a->x > c->x);
    }
  if (strcmp(e->__name__, "Int") == 0)
    {
      d = (IntClass *)other;
      return (a->x > (int)d->x);
    }
  if (strcmp(e->__name__, "Char") == 0)
    {
      b = (CharClass *)other;
      return(a->x > b->x);
    }
  return (false);
}

static bool Float_lt(const Object* self, const Object* other)
{
  //<
  FloatClass *a;
  CharClass *b;
  FloatClass *c;
  IntClass *d;
  Class *e;

  e = (Class *)other;
  a = (FloatClass *)self;
  if (strcmp(e->__name__, "Float") == 0)
    {
      c = (FloatClass *)other;
      return (a->x < (char)c->x);
    }
  if (strcmp(e->__name__, "Int") == 0)
    {
      d = (IntClass *)other;
      return (a->x < (char)d->x);
    }
  if (strcmp(e->__name__, "Char") == 0)
    {
      b = (CharClass *)other;
      return(a->x < b->x);
    }
  return (false);
}

static FloatClass _description = {
  { sizeof(FloatClass), "Float", &Float_ctor, &Float_dtor, &Float_str, &Float_add, &Float_sub, &Float_mul, &Float_div, &Float_eq, &Float_gt, &Float_lt},
  0.0, NULL
};

Class* Float = (Class*) &_description;
