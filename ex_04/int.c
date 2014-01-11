/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Sat Jan 11 14:32:24 2014 Maxime
*/

#include "int.h"
#include "char.h"
#include "float.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "new.h"

typedef struct
{
  Class base;
  int x;
  char *str;
} IntClass;

static void Int_ctor(Object* self, va_list *ap)
{
  IntClass *a;

  a = (IntClass *) self;
  a->x = (int)va_arg(*ap, int);
  a->str = NULL;
}

static void Int_dtor(Object* self)
{
  IntClass *a;

  a = (IntClass *) self;
  free(a->str);
}

static char const *Int_str(Object* self)
{
  IntClass *a;

  a = (IntClass *) self;
  if (a->str != NULL)
    free(a->str);
  a->str = malloc(200);
  snprintf(a->str, 199, "<%s (%d)>",a->base->name, a->x);
  return(a->str);
}

static Object *Int_add(const Object* self, const Object* other)
{
  IntClass *a;
  IntClass *b;
  FloatClass *c;
  CharClass *d;
  Class *e;

  e = (Class *)other;
  if (strcmp(e->name, "Float") == 0)
    {
      a = (IntClass *)self;
      c = (FloatClass *)other;
      return (new(Int, (a->x + (int)c->x)));
    }
  if (strcmp(e->name, "Char") == 0)
    {
      a = (IntClass *)self;
      d = (CharClass *)other;
      return (new(Int, (a->x + (int)d->x)));
    }
  if (strcmp(e->name, "Int") == 0)
    {
      a = (IntClass *)self;
      b = (IntClass *)other;
      return(new(Int, a->x + b->x));
    }
  return (NULL);
}

static Object *Int_sub(const Object* self, const Object* other)
{
  IntClass *a;
  IntClass *b;
  FloatClass *c;
  CharClass *d;
  Class *e;

  e = (Class *)other;
  if (strcmp(e->name, "Float") == 0)
    {
      a = (IntClass *)self;
      c = (FloatClass *)other;
      return (new(Int, (a->x - (int)c->x)));
    }
  if (strcmp(e->name, "Char") == 0)
    {
      a = (IntClass *)self;
      d = (CharClass *)other;
      return (new(Int, (a->x - (int)d->x)));
    }
  if (strcmp(e->name, "Int") == 0)
    {
      a = (IntClass *)self;
      b = (IntClass *)other;
      return(new(Int, a->x - b->x));
    }
  return (NULL);
}

static Object *Int_mul(const Object* self, const Object* other)
{
  IntClass *a;
  IntClass *b;
  FloatClass *c;
  CharClass *d;
  Class *e;

  e = (Class *)other;
  if (strcmp(e->name, "Float") == 0)
    {
      a = (IntClass *)self;
      c = (FloatClass *)other;
      return (new(Int, (a->x * (int)c->x)));
    }
  if (strcmp(e->name, "Char") == 0)
    {
      a = (IntClass *)self;
      d = (CharClass *)other;
      return (new(Int, (a->x * (int)d->x)));
    }
  if (strcmp(e->name, "Int") == 0)
    {
      a = (IntClass *)self;
      b = (IntClass *)other;
      return(new(Int, a->x * b->x));
    }
  return (NULL);
}

static Object *Int_div(const Object* self, const Object* other)
{
  IntClass *a;
  IntClass *b;
  FloatClass *c;
  CharClass *d;
  Class *e;

  e = (Class *)other;
  if (strcmp(e->name, "Float") == 0)
    {
      a = (IntClass *)self;
      c = (FloatClass *)other;
      return (new(Int, (c->x == 0 ? 0 :(a->x / (int)c->x))));
    }
  if (strcmp(e->name, "Char") == 0)
    {
      a = (IntClass *)self;
      d = (CharClass *)other;
      return (new(Int, (d->x == 0 ? 0 :(a->x / (int)d->x))));
    }
  if (strcmp(e->name, "Int") == 0)
    {
      a = (IntClass *)self;
      b = (IntClass *)other;
      return(new(Int, (b->x == 0 ? 0 :(a->x / b->x))));
    }
  return (NULL);
}

static bool Int_eq(const Object* self, const Object* other)
{
  //==
  IntClass *a;
  IntClass *b;
  FloatClass *c;
  CharClass *d;
  Class *e;

  e = (Class *)other;
  if (strcmp(e->name, "Float") == 0)
    {
      a = (IntClass *)self;
      c = (FloatClass *)other;
      return (a->x == (int)c->x ? true, false);
    }
  if (strcmp(e->name, "Char") == 0)
    {
      a = (IntClass *)self;
      d = (CharClass *)other;
      return (a->x == (int)d->x ? true, false);
    }
  if (strcmp(e->name, "Int") == 0)
    {
      a = (IntClass *)self;
      b = (IntClass *)other;
      return(a->x == b->x ? true, false);
    }
  return (false);
}

static bool Int_gt(const Object* self, const Object* other)
{
  //>
  IntClass *a;
  IntClass *b;
  FloatClass *c;
  CharClass *d;
  Class *e;

  e = (Class *)other;
  if (strcmp(e->name, "Float") == 0)
    {
      a = (IntClass *)self;
      c = (FloatClass *)other;
      return (a->x > c->x ? true, false);
    }
  if (strcmp(e->name, "Char") == 0)
    {
      a = (IntClass *)self;
      d = (CharClass *)other;
      return (a->x > d->x ? true, false);
    }
  if (strcmp(e->name, "Int") == 0)
    {
      a = (IntClass *)self;
      b = (IntClass *)other;
      return(a->x > b->x ? true, false);
    }
  return (false);
}

static bool Int_lt(const Object* self, const Object* other)
{
  //<
  IntClass *a;
  IntClass *b;
  FloatClass *c;
  CharClass *d;
  Class *e;

  e = (Class *)other;
  if (strcmp(e->name, "Float") == 0)
    {
      a = (IntClass *)self;
      c = (FloatClass *)other;
      return (a->x < c->x ? true, false);
    }
  if (strcmp(e->name, "Char") == 0)
    {
      a = (IntClass *)self;
      d = (CharClass *)other;
      return (a->x < d->x ? true, false);
    }
  if (strcmp(e->name, "Int") == 0)
    {
      a = (IntClass *)self;
      b = (IntClass *)other;
      return(a->x < b->x ? true, false);
    }
  return (false);
}

static IntClass _description = {
  { sizeof(IntClass), "Int", &Int_ctor, &Int_dtor, &Int_str, &Int_add, &Int_sub, &Int_mul, &Int_div, &Int_eq, &Int_gt, &Int_lt},
  0, NULL
};

Class* Int = (Class*) &_description;
