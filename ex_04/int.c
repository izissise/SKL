/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Sat Jan 11 14:59:56 2014 Maxime
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
  int x;
  char *str;
} IntClass;

static void Int_ctor(Object* self, va_list *ap)
{
  IntClass *a;

  a = (IntClass *) self;
  int tmp = (int)va_arg(*ap, int);
  a->x = tmp;
  a->str = NULL;
}

static void Int_dtor(Object* self)
{
  IntClass *a;

  a = (IntClass *) self;
  if (a != NULL)
    free(a->str);
}

static char const *Int_str(Object* self)
{
  IntClass *a;

  a = (IntClass *) self;
  if (a != NULL)
    {
      if (a->str != NULL)
        free(a->str);
      a->str = malloc(200);
      snprintf(a->str, 199, "<%s (%d)>", a->base.__name__, a->x);
      return(a->str);
    }
  return NULL;
}

static Object *Int_add(const Object* self, const Object* other)
{
  IntClass *this = (IntClass *)self;
  Class *second = (Class *)other;
  Object *toCall;
  Class *tmp;

  if (this != NULL && other != NULL && !strcmp(this->base.__name__, "Int"))
    {
      if (strcmp(second->__name__, "Int") == 0)
        {
          IntClass *c = (IntClass *)other;
          return (new(Int, (this->x + c->x)));
        }
      if (strcmp(second->__name__, "Float") == 0)
        {
          toCall = new(Float, (int)this->x);
          tmp = (Class*)toCall;
          return tmp->__add__(toCall, other);
        }
      if (strcmp(second->__name__, "Char") == 0)
        {
          toCall = new(Char, (char)this->x);
          tmp = (Class*)toCall;
          return tmp->__add__(toCall, other);
        }
    }
  return (NULL);
}

static Object *Int_sub(const Object* self, const Object* other)
{
  IntClass *this = (IntClass *)self;
  Class *second = (Class *)other;
  Object *toCall;
  Class *tmp;

  if (this != NULL && other != NULL && !strcmp(this->base.__name__, "Int"))
    {
      if (strcmp(second->__name__, "Int") == 0)
        {
          IntClass *c = (IntClass *)other;
          return (new(Int, (this->x - c->x)));
        }
      if (strcmp(second->__name__, "Float") == 0)
        {
          toCall = new(Float, (int)this->x);
          tmp = (Class*)toCall;
          return tmp->__sub__(toCall, other);
        }
      if (strcmp(second->__name__, "Char") == 0)
        {
          toCall = new(Char, (char)this->x);
          tmp = (Class*)toCall;
          return tmp->__sub__(toCall, other);
        }
    }
  return (NULL);
}

static Object *Int_mul(const Object* self, const Object* other)
{
  IntClass *this = (IntClass *)self;
  Class *second = (Class *)other;
  Object *toCall;
  Class *tmp;

  if (this != NULL && other != NULL && !strcmp(this->base.__name__, "Int"))
    {
      if (strcmp(second->__name__, "Int") == 0)
        {
          IntClass *c = (IntClass *)other;
          return (new(Int, (this->x * c->x)));
        }
      if (strcmp(second->__name__, "Float") == 0)
        {
          toCall = new(Float, (int)this->x);
          tmp = (Class*)toCall;
          return tmp->__mul__(toCall, other);
        }
      if (strcmp(second->__name__, "Char") == 0)
        {
          toCall = new(Char, (char)this->x);
          tmp = (Class*)toCall;
          return tmp->__mul__(toCall, other);
        }
    }
  return (NULL);
}

static Object *Int_div(const Object* self, const Object* other)
{
  IntClass *this = (IntClass *)self;
  Class *second = (Class *)other;
  Object *toCall;
  Class *tmp;

  if (this != NULL && other != NULL && !strcmp(this->base.__name__, "Int"))
    {
      if (strcmp(second->__name__, "Int") == 0)
        {
          IntClass *c = (IntClass *)other;
          if (c->x == 0)
            return (new(Int, 0));
          return (new(Int, (this->x / c->x)));
        }
      if (strcmp(second->__name__, "Float") == 0)
        {
          toCall = new(Float, (int)this->x);
          tmp = (Class*)toCall;
          return tmp->__div__(toCall, other);
        }
      if (strcmp(second->__name__, "Char") == 0)
        {
          toCall = new(Char, (char)this->x);
          tmp = (Class*)toCall;
          return tmp->__div__(toCall, other);
        }
    }
  return (NULL);
}

static bool Int_eq(const Object* self, const Object* other)
{
  IntClass *this = (IntClass *)self;
  Class *second = (Class *)other;
  Object *toCall;
  Class *tmp;

  if (this != NULL && other != NULL && !strcmp(this->base.__name__, "Int"))
    {
      if (strcmp(second->__name__, "Int") == 0)
        {
          IntClass *c = (IntClass *)other;
          return (this->x == c->x);
        }
      if (strcmp(second->__name__, "Float") == 0)
        {
          toCall = new(Float, (int)this->x);
          tmp = (Class*)toCall;
          return tmp->__eq__(toCall, other);
        }
      if (strcmp(second->__name__, "Char") == 0)
        {
          toCall = new(Char, (char)this->x);
          tmp = (Class*)toCall;
          return tmp->__eq__(toCall, other);
        }
    }
  return (false);
}

static bool Int_gt(const Object* self, const Object* other)
{
  IntClass *this = (IntClass *)self;
  Class *second = (Class *)other;
  Object *toCall;
  Class *tmp;

  if (this != NULL && other != NULL && !strcmp(this->base.__name__, "Int"))
    {
      if (strcmp(second->__name__, "Int") == 0)
        {
          IntClass *c = (IntClass *)other;
          return (this->x > c->x);
        }
      if (strcmp(second->__name__, "Float") == 0)
        {
          toCall = new(Float, (int)this->x);
          tmp = (Class*)toCall;
          return tmp->__gt__(toCall, other);
        }
      if (strcmp(second->__name__, "Char") == 0)
        {
          toCall = new(Char, (char)this->x);
          tmp = (Class*)toCall;
          return tmp->__gt__(toCall, other);
        }
    }
  return (false);
}

static bool Int_lt(const Object* self, const Object* other)
{
  IntClass *this = (IntClass *)self;
  Class *second = (Class *)other;
  Object *toCall;
  Class *tmp;

  if (this != NULL && other != NULL && !strcmp(this->base.__name__, "Int"))
    {
      if (strcmp(second->__name__, "Int") == 0)
        {
          IntClass *c = (IntClass *)other;
          return (this->x < c->x);
        }
      if (strcmp(second->__name__, "Float") == 0)
        {
          toCall = new(Float, (int)this->x);
          tmp = (Class*)toCall;
          return tmp->__lt__(toCall, other);
        }
      if (strcmp(second->__name__, "Char") == 0)
        {
          toCall = new(Char, (char)this->x);
          tmp = (Class*)toCall;
          return tmp->__lt__(toCall, other);
        }
    }
  return (false);
}

static IntClass _description = {
  { sizeof(IntClass), "Int", &Int_ctor, &Int_dtor, &Int_str, &Int_add, &Int_sub, &Int_mul, &Int_div, &Int_eq, &Int_gt, &Int_lt},
  0.0, NULL
};

Class* Int = (Class*) &_description;
