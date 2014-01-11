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

typedef struct
{
    Class base;
    float val;
} Float;

static void	Float_ctor(Object* self, va_list *ap)
{
  Float *this = (Float*)self;
  this->val = (float)(va_arg(*ap, float));
}

static void	Float_dtor(Object* self)
{
	(void) self;
}

static Float _description = {
    { sizeof(Float), "Float", &Float_ctor, &Float_dtor },
    0.0
};

Class* Float = (Class*) &_description;



