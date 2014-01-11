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
#include "float.h"
#include "int.h"
#include "char.h"

typedef struct
{
  Class base;
  float x;
  char *str;
} Float;

static void	Float_ctor(Object* self, va_list *ap)
{
  Float *this = (Float*)self;
  this->x = (float)(va_arg(*ap, float));
}

static void	Float_dtor(Object* self)
{
  Float *a;

  a = (Float *)self;
  free(a->str);
}

static char const *Float_str(Object* self)
{
  Float *a;

  a = (Float *)self;
  if (a->str != NULL)
    free(a->str);
  a->str = malloc(200);
  snprintf(a->str, 200, "<%s (%f)>", a->base->__name__, a->x);
  return(a->str);
}

static Object* Float_add(const Object* self, const Object* other)
{
  Class	*this;
  Float	*res;

  this = (Float*)self;
  if (other != NULL)
    {
      Class* type = (Class*)other;
      if (!strcmp(type->__name__, "Float"))
        {
          Float	*second = (Float*)other;
          res = new(Float, this->x + second->x);
        }
      if (!strcmp(type->__name__, "Int"))
        {
          Int	*second = (Int*)other;
          res = new(Float, this->x + (float)(second->x));
        }
      if (!strcmp(type->__name__, "Char"))
        {
          Char	*second = (Char*)other;
          res = new(Float, this->x + (float)(second->x));
        }
    }
  return NULL;
}

static Object* Float_sub(const Object* self, const Object* other)
{
  Class	*this;
  Float	*res;

  this = (Float*)self;
  if (other != NULL)
    {
      Class* type = (Class*)other;
      if (!strcmp(type->__name__, "Float"))
        {
          Float	*second = (Float*)other;
          res = new(Float, this->x - second->x);
        }
      if (!strcmp(type->__name__, "Int"))
        {
          Int	*second = (Int*)other;
          res = new(Float, this->x - (float)(second->x));
        }
      if (!strcmp(type->__name__, "Char"))
        {
          Char	*second = (Char*)other;
          res = new(Float, this->x - (float)(second->x));
        }
    }
  return NULL;
}

static Object* Float_mul(const Object* self, const Object* other)
{
  Class	*this;
  Float	*res;

  this = (Float*)self;
  if (other != NULL)
    {
      Class* type = (Class*)other;
      if (!strcmp(type->__name__, "Float"))
        {
          Float	*second = (Float*)other;
          res = new(Float, this->x * second->x);
        }
      if (!strcmp(type->__name__, "Int"))
        {
          Int	*second = (Int*)other;
          res = new(Float, this->x * (float)(second->x));
        }
      if (!strcmp(type->__name__, "Char"))
        {
          Char	*second = (Char*)other;
          res = new(Float, this->x * (float)(second->x));
        }
    }
  return NULL;
}

static Object* Float_div(const Object* self, const Object* other)
{
  Class	*this;
  Float	*res;

  this = (Float*)self;
  if (other != NULL)
    {
      Class* type = (Class*)other;
      if (!strcmp(type->__name__, "Float"))
        {
          Float	*second = (Float*)other;
          if (second->x == 0)
            res = new(Float, 0.0);
          else
            res = new(Float, this->x / (float)second->x);
        }
      if (!strcmp(type->__name__, "Int"))
        {
          Int	*second = (Int*)other;
          if (second->x == 0)
            res = new(Float, 0.0);
          else
            res = new(Float, this->x / (float)second->x);
        }
      if (!strcmp(type->__name__, "Char"))
        {
          Char	*second = (Char*)other;
          if (second->x == 0)
            res = new(Float, 0.0);
          else
            res = new(Float, this->x / (float)second->x);
        }
    }
  return NULL;
}

static bool Float_eq(const Object* self, const Object* other)
{
  Class	*this;
  Float	*res;

  this = (Float*)self;
  if (other != NULL)
    {
      Class* type = (Class*)other;
      if (!strcmp(type->__name__, "Float"))
        {
          Float	*second = (Float*)other;
          return (other->x == this->x);
        }
      if (!strcmp(type->__name__, "Int"))
        {
          Int	*second = (Int*)other;
          return (other->x == this->x);
        }
      if (!strcmp(type->__name__, "Char"))
        {
          Char	*second = (Char*)other;
          return (other->x == this->x);
        }
    }
  return false;
}

static bool Float_gt(const Object* self, const Object* other)
{
  Class	*this;
  Float	*res;

  this = (Float*)self;
  if (other != NULL)
    {
      Class* type = (Class*)other;
      if (!strcmp(type->__name__, "Float"))
        {
          Float	*second = (Float*)other;
          return (this->x > other->x);
        }
      if (!strcmp(type->__name__, "Int"))
        {
          Int	*second = (Int*)other;
          return (this->x > other->x);
        }
      if (!strcmp(type->__name__, "Char"))
        {
          Char	*second = (Char*)other;
          return (this->x > other->x);
        }
    }
  return false;
}

static bool Float_lt(const Object* self, const Object* other)
{
  Class	*this;
  Float	*res;

  this = (Float*)self;
  if (other != NULL)
    {
      Class* type = (Class*)other;
      if (!strcmp(type->__name__, "Float"))
        {
          Float	*second = (Float*)other;
          return (this->x < other->x);
        }
      if (!strcmp(type->__name__, "Int"))
        {
          Int	*second = (Int*)other;
          return (this->x < other->x);
        }
      if (!strcmp(type->__name__, "Char"))
        {
          Char	*second = (Char*)other;
          return (this->x < other->x);
        }
    }
  return false;
}

static Float _description = {
  { sizeof(Float), "Float", &Float_ctor, &Float_dtor, &Float_str,
    &Float_add, &Float_sub, &Float_mul, &Float_div, &Float_eq
  },
  0.0
};

Class* Float = (Class*) &_description;
