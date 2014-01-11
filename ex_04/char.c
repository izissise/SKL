/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Sat Jan 11 14:56:29 2014 Maxime
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "new.h"
#include "int.h"
#include "char.h"
#include "float.h"

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
} CharClass;

static void Char_ctor(Object* self, va_list *ap)
{
  CharClass *a;

  a = (CharClass *) self;
  char tmp = (char)((int)va_arg(*ap, int));
  a->x = tmp;
  a->str = NULL;
}

static void Char_dtor(Object* self)
{
  CharClass *a;

  a = (CharClass *) self;
  if (a != NULL)
    free(a->str);
}

static char const *Char_str(Object* self)
{
  CharClass *a;

  a = (CharClass *) self;
  if (a != NULL)
    {
      if (a->str != NULL)
        free(a->str);
      a->str = malloc(200);
      snprintf(a->str, 199, "<%s (%d)>", a->base.__name__, (int)a->x);
      return(a->str);
    }
  return NULL;
}

static Object *Char_add(const Object* self, const Object* other)
{
  CharClass *this = (CharClass *)self;
  Class *second = (Class *)other;
  Object *toCall;
  Class *tmp;

  if (this != NULL && other != NULL && !strcmp(this->base.__name__, "Char"))
    {
      if (strcmp(second->__name__, "Char") == 0)
        {
          CharClass *c = (CharClass *)other;
          return (new(Char, (this->x + c->x)));
        }
      if (strcmp(second->__name__, "Float") == 0)
        {
          toCall = new(Float, (int)this->x);
          tmp = (Class*)toCall;
          return tmp->__add__(toCall, other);
        }
      if (strcmp(second->__name__, "Int") == 0)
        {
          toCall = new(Int, (char)this->x);
          tmp = (Class*)toCall;
          return tmp->__add__(toCall, other);
        }
    }
  return (NULL);
}

static Object *Char_sub(const Object* self, const Object* other)
{
  CharClass *this = (CharClass *)self;
  Class *second = (Class *)other;
  Object *toCall;
  Class *tmp;

  if (this != NULL && other != NULL && !strcmp(this->base.__name__, "Char"))
    {
      if (strcmp(second->__name__, "Char") == 0)
        {
          CharClass *c = (CharClass *)other;
          return (new(Char, (this->x - c->x)));
        }
      if (strcmp(second->__name__, "Float") == 0)
        {
          toCall = new(Float, (int)this->x);
          tmp = (Class*)toCall;
          return tmp->__sub__(toCall, other);
        }
      if (strcmp(second->__name__, "Int") == 0)
        {
          toCall = new(Int, (char)this->x);
          tmp = (Class*)toCall;
          return tmp->__sub__(toCall, other);
        }
    }
  return (NULL);
}

static Object *Char_mul(const Object* self, const Object* other)
{
  CharClass *this = (CharClass *)self;
  Class *second = (Class *)other;
  Object *toCall;
  Class *tmp;

  if (this != NULL && other != NULL && !strcmp(this->base.__name__, "Char"))
    {
      if (strcmp(second->__name__, "Char") == 0)
        {
          CharClass *c = (CharClass *)other;
          return (new(Char, (this->x * c->x)));
        }
      if (strcmp(second->__name__, "Float") == 0)
        {
          toCall = new(Float, (int)this->x);
          tmp = (Class*)toCall;
          return tmp->__mul__(toCall, other);
        }
      if (strcmp(second->__name__, "Int") == 0)
        {
          toCall = new(Int, (char)this->x);
          tmp = (Class*)toCall;
          return tmp->__mul__(toCall, other);
        }
    }
  return (NULL);
}

static Object *Char_div(const Object* self, const Object* other)
{
  CharClass *this = (CharClass *)self;
  Class *second = (Class *)other;
  Object *toCall;
  Class *tmp;

  if (this != NULL && other != NULL && !strcmp(this->base.__name__, "Char"))
    {
      if (strcmp(second->__name__, "Char") == 0)
        {
          CharClass *c = (CharClass *)other;
          if (c->x == 0)
            return (new(Char, 0));
          return (new(Char, (this->x / c->x)));
        }
      if (strcmp(second->__name__, "Float") == 0)
        {
          toCall = new(Float, (int)this->x);
          tmp = (Class*)toCall;
          return tmp->__div__(toCall, other);
        }
      if (strcmp(second->__name__, "Int") == 0)
        {
          toCall = new(Int, (char)this->x);
          tmp = (Class*)toCall;
          return tmp->__div__(toCall, other);
        }
    }
  return (NULL);
}

static bool Char_eq(const Object* self, const Object* other)
{
  CharClass *this = (CharClass *)self;
  Class *second = (Class *)other;
  Object *toCall;
  Class *tmp;

  if (this != NULL && other != NULL && !strcmp(this->base.__name__, "Char"))
    {
      if (strcmp(second->__name__, "Char") == 0)
        {
          CharClass *c = (CharClass *)other;
          return (this->x == c->x);
        }
      if (strcmp(second->__name__, "Float") == 0)
        {
          toCall = new(Float, (int)this->x);
          tmp = (Class*)toCall;
          return tmp->__eq__(toCall, other);
        }
      if (strcmp(second->__name__, "Int") == 0)
        {
          toCall = new(Int, (char)this->x);
          tmp = (Class*)toCall;
          return tmp->__eq__(toCall, other);
        }
    }
  return (false);
}

static bool Char_gt(const Object* self, const Object* other)
{
  CharClass *this = (CharClass *)self;
  Class *second = (Class *)other;
  Object *toCall;
  Class *tmp;

  if (this != NULL && other != NULL && !strcmp(this->base.__name__, "Char"))
    {
      if (strcmp(second->__name__, "Char") == 0)
        {
          CharClass *c = (CharClass *)other;
          return (this->x > c->x);
        }
      if (strcmp(second->__name__, "Float") == 0)
        {
          toCall = new(Float, (int)this->x);
          tmp = (Class*)toCall;
          return tmp->__gt__(toCall, other);
        }
      if (strcmp(second->__name__, "Int") == 0)
        {
          toCall = new(Int, (char)this->x);
          tmp = (Class*)toCall;
          return tmp->__gt__(toCall, other);
        }
    }
  return (false);
}

static bool Char_lt(const Object* self, const Object* other)
{
  CharClass *this = (CharClass *)self;
  Class *second = (Class *)other;
  Object *toCall;
  Class *tmp;

  if (this != NULL && other != NULL && !strcmp(this->base.__name__, "Char"))
    {
      if (strcmp(second->__name__, "Char") == 0)
        {
          CharClass *c = (CharClass *)other;
          return (this->x < c->x);
        }
      if (strcmp(second->__name__, "Float") == 0)
        {
          toCall = new(Float, (int)this->x);
          tmp = (Class*)toCall;
          return tmp->__lt__(toCall, other);
        }
      if (strcmp(second->__name__, "Int") == 0)
        {
          toCall = new(Int, (char)this->x);
          tmp = (Class*)toCall;
          return tmp->__lt__(toCall, other);
        }
    }
  return (false);
}

static CharClass _description = {
  { sizeof(CharClass), "Char", &Char_ctor, &Char_dtor, &Char_str, &Char_add, &Char_sub, &Char_mul, &Char_div, &Char_eq, &Char_gt, &Char_lt},
  0.0, NULL
};

Class* Char = (Class*) &_description;
