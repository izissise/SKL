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
#include <string.h>
#include "object.h"
#include "new.h"
#include "float.h"
#include "char.h"
#include "int.h"

typedef struct
{
  Class base;
  float x;
  char *str;
} FloatClass;

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
  if (a != NULL)
    free(a->str);
}

static char const *Float_str(Object* self)
{
  FloatClass *a;

  a = (FloatClass *) self;
  if (a != NULL)
    {
      if (a->str != NULL)
        free(a->str);
      a->str = malloc(200);
      snprintf(a->str, 199, "<%s (%f)>", (a->base).__name__, a->x);
      return(a->str);
    }
  return NULL;
}

static Object *Float_add(const Object* self, const Object* other)
{
  FloatClass *this = (FloatClass *)self;
  Class *second = (Class *)other;
  Object *toCall;
  Class *tmp;

  if (this != NULL && other != NULL && !strcmp(this->base.__name__, "Float"))
    {
      if (strcmp(second->__name__, "Float") == 0)
        {
          FloatClass *c = (FloatClass *)other;
          return (new(Float, (this->x + c->x)));
        }
      if (strcmp(second->__name__, "Int") == 0)
        {
          toCall = new(Int, (int)this->x);
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

static Object *Float_sub(const Object* self, const Object* other)
{
  FloatClass *this = (FloatClass *)self;
  Class *second = (Class *)other;
  Object *toCall;
  Class *tmp;

  if (this != NULL && other != NULL && !strcmp(this->base.__name__, "Float"))
    {
      if (strcmp(second->__name__, "Float") == 0)
        {
          FloatClass *c = (FloatClass *)other;
          return (new(Float, (this->x - c->x)));
        }
      if (strcmp(second->__name__, "Int") == 0)
        {
          toCall = new(Int, (int)this->x);
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

static Object *Float_mul(const Object* self, const Object* other)
{
  FloatClass *this = (FloatClass *)self;
  Class *second = (Class *)other;
  Object *toCall;
  Class *tmp;

  if (this != NULL && other != NULL && !strcmp(this->base.__name__, "Float"))
    {
      if (strcmp(second->__name__, "Float") == 0)
        {
          FloatClass *c = (FloatClass *)other;
          return (new(Float, (this->x * c->x)));
        }
      if (strcmp(second->__name__, "Int") == 0)
        {
          toCall = new(Int, (int)this->x);
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

static Object *Float_div(const Object* self, const Object* other)
{
  FloatClass *this = (FloatClass *)self;
  Class *second = (Class *)other;
  Object *toCall;
  Class *tmp;

  if (this != NULL && other != NULL && !strcmp(this->base.__name__, "Float"))
    {
      if (strcmp(second->__name__, "Float") == 0)
        {
          FloatClass *c = (FloatClass *)other;
          if (c->x == 0)
            return (new(Float, 0.0));
          return (new(Float, (this->x / c->x)));
        }
      if (strcmp(second->__name__, "Int") == 0)
        {
          toCall = new(Int, (int)this->x);
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

static bool Float_eq(const Object* self, const Object* other)
{
  FloatClass *this = (FloatClass *)self;
  Class *second = (Class *)other;
  Object *toCall;
  Class *tmp;

  if (this != NULL && other != NULL && !strcmp(this->base.__name__, "Float"))
    {
      if (strcmp(second->__name__, "Float") == 0)
        {
          FloatClass *c = (FloatClass *)other;
          return (this->x == c->x);
        }
      if (strcmp(second->__name__, "Int") == 0)
        {
          toCall = new(Int, (int)this->x);
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

static bool Float_gt(const Object* self, const Object* other)
{
  FloatClass *this = (FloatClass *)self;
  Class *second = (Class *)other;
  Object *toCall;
  Class *tmp;

  if (this != NULL && other != NULL && !strcmp(this->base.__name__, "Float"))
    {
      if (strcmp(second->__name__, "Float") == 0)
        {
          FloatClass *c = (FloatClass *)other;
          return (this->x > c->x);
        }
      if (strcmp(second->__name__, "Int") == 0)
        {
          toCall = new(Int, (int)this->x);
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

static bool Float_lt(const Object* self, const Object* other)
{
  FloatClass *this = (FloatClass *)self;
  Class *second = (Class *)other;
  Object *toCall;
  Class *tmp;

  if (this != NULL && other != NULL && !strcmp(this->base.__name__, "Float"))
    {
      if (strcmp(second->__name__, "Float") == 0)
        {
          FloatClass *c = (FloatClass *)other;
          return (this->x < c->x);
        }
      if (strcmp(second->__name__, "Int") == 0)
        {
          toCall = new(Int, (int)this->x);
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

static FloatClass _description = {
  { sizeof(FloatClass), "Float", &Float_ctor, &Float_dtor, &Float_str, &Float_add, &Float_sub, &Float_mul, &Float_div, &Float_eq, &Float_gt, &Float_lt},
  0.0, NULL
};

Class* Float = (Class*) &_description;
