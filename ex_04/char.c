/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Sat Jan 11 14:39:00 2014 Maxime
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "new.h"
#include "int.h"
#include "char.h"
#include "float.h"

typedef struct
{
  Class base;
  char x;
  char *str;
} CharClass;

static void Char_ctor(Object* self, va_list *ap)
{
  CharClass *a;

  a = (CharClass *) self;
  a->x = (char)va_arg(*ap, char);
  a->str = NULL;
}

static void Char_dtor(Object* self)
{
  CharClass *a;

  a = (CharClass *) self;
  free(a->str);
}

static char const *Char_str(Object* self)
{
  CharClass *a;

  a = (CharClass *) self;
  if (a->str != NULL)
    free(a->str);
  a->str = malloc(200);
  snprintf(a->str, 199, "<%s (%d)>",a->base.__name__, (int)a->x);
  return(a->str);
}

static Object *Char_add(const Object* self, const Object* other)
{
  CharClass *a;
  CharClass *b;
  FloatClass *c;
  IntClass *d;
  Class *e;

  e = (Class *)other;
  if (strcmp(e->__name__, "Float") == 0)
    {
      a = (CharClass *)self;
      c = (FloatClass *)other;
      return (new(Char, (a->x + (char)c->x)));
    }
  if (strcmp(e->__name__, "Int") == 0)
    {
      a = (CharClass *)self;
      d = (IntClass *)other;
      return (new(Char, (a->x + (int)d->x)));
    }
  if (strcmp(e->__name__, "Char") == 0)
    {
      a = (CharClass *)self;
      b = (CharClass *)other;
      return(new(Char, a->x + b->x));
    }
  return (NULL);
}

static Object *Char_sub(const Object* self, const Object* other)
{
  CharClass *a;
  CharClass *b;
  FloatClass *c;
  IntClass *d;
  Class *e;

  e = (Class *)other;
  if (strcmp(e->__name__, "Float") == 0)
    {
      a = (CharClass *)self;
      c = (FloatClass *)other;
      return (new(Char, (a->x - (char)c->x)));
    }
  if (strcmp(e->__name__, "Int") == 0)
    {
      a = (CharClass *)self;
      d = (IntClass *)other;
      return (new(Char, (a->x - (int)d->x)));
    }
  if (strcmp(e->__name__, "Char") == 0)
    {
      a = (CharClass *)self;
      b = (CharClass *)other;
      return(new(Char, a->x - b->x));
    }
  return (NULL);
}

static Object *Char_mul(const Object* self, const Object* other)
{
  CharClass *a;
  CharClass *b;
  FloatClass *c;
  IntClass *d;
  Class *e;

  e = (Class *)other;
  if (strcmp(e->__name__, "Float") == 0)
    {
      a = (CharClass *)self;
      c = (FloatClass *)other;
      return (new(Char, (a->x * (char)c->x)));
    }
  if (strcmp(e->__name__, "Int") == 0)
    {
      a = (CharClass *)self;
      d = (IntClass *)other;
      return (new(Char, (a->x * (int)d->x)));
    }
  if (strcmp(e->__name__, "Char") == 0)
    {
      a = (CharClass *)self;
      b = (CharClass *)other;
      return(new(Char, a->x * b->x));
    }
  return (NULL);
}

static Object *Char_div(const Object* self, const Object* other)
{
  CharClass *a;
  CharClass *b;
  FloatClass *c;
  IntClass *d;
  Class *e;

  e = (Class *)other;
  if (strcmp(e->__name__, "Float") == 0)
    {
      a = (CharClass *)self;
      c = (FloatClass *)other;
      return (new(Char, (c->x == 0 ? 0 :(a->x / (char)c->x))));
    }
  if (strcmp(e->__name__, "Int") == 0)
    {
      a = (CharClass *)self;
      d = (IntClass *)other;
      return (new(Char, (d->x == 0 ? 0 :(a->x / (int)d->x))));
    }
  if (strcmp(e->__name__, "Char") == 0)
    {
      a = (CharClass *)self;
      b = (CharClass *)other;
      return(new(Char, (b->x == 0 ? 0 :(a->x / b->x))));
    }
  return (NULL);
}

static bool Char_eq(const Object* self, const Object* other)
{
  //==
  CharClass *a;
  CharClass *b;
  FloatClass *c;
  IntClass *d;
  Class *e;

  e = (Class *)other;
  if (strcmp(e->__name__, "Float") == 0)
    {
      a = (CharClass *)self;
      c = (FloatClass *)other;
      return (a->x == c->x ? true, false);
    }
  if (strcmp(e->__name__, "Int") == 0)
    {
      a = (CharClass *)self;
      d = (IntClass *)other;
      return (a->x == (int)d->x ? true, false);
    }
  if (strcmp(e->__name__, "Char") == 0)
    {
      a = (CharClass *)self;
      b = (CharClass *)other;
      return(a->x == b->x ? true, false);
    }
  return (false);
}

static bool Char_gt(const Object* self, const Object* other)
{
  //>
  CharClass *a;
  CharClass *b;
  FloatClass *c;
  IntClass *d;
  Class *e;

  e = (Class *)other;
  if (strcmp(e->__name__, "Float") == 0)
    {
      a = (CharClass *)self;
      c = (FloatClass *)other;
      return (a->x > c->x ? true, false);
    }
  if (strcmp(e->__name__, "Int") == 0)
    {
      a = (CharClass *)self;
      d = (IntClass *)other;
      return (a->x > (int)d->x ? true, false);
    }
  if (strcmp(e->__name__, "Char") == 0)
    {
      a = (CharClass *)self;
      b = (CharClass *)other;
      return(a->x > b->x ? true, false);
    }
  return (false);
}

static bool Char_lt(const Object* self, const Object* other)
{
  //<
  CharClass *a;
  CharClass *b;
  FloatClass *c;
  IntClass *d;
  Class *e;

  e = (Class *)other;
  if (strcmp(e->__name__, "Float") == 0)
    {
      a = (CharClass *)self;
      c = (FloatClass *)other;
      return (a->x < (char)c->x ? true, false);
    }
  if (strcmp(e->__name__, "Int") == 0)
    {
      a = (CharClass *)self;
      d = (IntClass *)other;
      return (a->x < (char)d->x ? true, false);
    }
  if (strcmp(e->__name__, "Char") == 0)
    {
      a = (CharClass *)self;
      b = (CharClass *)other;
      return(a->x < b->x ? true, false);
    }
  return (false);
}

static CharClass _description = {
  { sizeof(CharClass), "Char", &Char_ctor, &Char_dtor, &Char_str, &Char_add, &Char_sub, &Char_mul, &Char_div, &Char_eq, &Char_gt, &Char_lt},
  0, NULL
};

Class* Char = (Class*) &_description;
