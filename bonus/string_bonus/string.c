/*
** string.c for string in /home/debas_e/Project/piscine_cpp/Rush/piscine_cpp_rush1/bonus/string_bonus
** 
** Made by Etienne
** Login   <debas_e@epitech.net>
** 
** Started on  Sat Jan 11 19:08:38 2014 Etienne
** Last update Sat Jan 11 22:17:12 2014 jonathan.collinet
*/


#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "string.h"
#include "new.h"

typedef struct
{
  Class		base;
  const char	*s;
  char		*str;
}		StringClass;

static void String_ctor(Object* self, va_list *ap)
{
  StringClass *a;

  a = (StringClass *) self;
  a->s = va_arg(*ap, char *);
  a->str = NULL;
}

static void String_dtor(Object* self)
{
  StringClass *a;

  a = (StringClass *) self;
  if (a != NULL)
    free(a->str);
}

static char const *String_str(Object* self)
{
  StringClass *a;

  a = (StringClass *) self;
  if (a != NULL && !strcmp(a->base.__name__, "String"))
    {
      if (a->str != NULL)
        free(a->str);
      a->str = malloc(strlen(a->s) + 12);
      snprintf(a->str, 199, "<%s (%s)>", (a->base).__name__, a->s);
      return(a->str);
    }
  return NULL;
}

static const char *String_c_str(Object *self)
{
  return (((StringClass*)self)->s);
}

static Object *String_append_s(const Object* self, const Object *other)
{
  StringClass *a;
  StringClass *b;
  char const	*tmp;

  a = (StringClass *)self;
  b = (StringClass *)other;
  tmp = a->s;
  if ((a != NULL && !strcmp(a->base.__name__, "String")) && (b != NULL && !strcmp(b->base.__name__, "String")))
    {
      if (b->s)
	{
	  len = strlen(b->s);
	  if (a->s)
	    len += strlen(a->s);
	  a->s = realloc(a->s, (sizeof(char) * len));
	  memset(a->s + strlen(a->s), 0, len * sizeof(char));
	  if (a->s != tmp)
	    delete(String, a);
	  strcat(a->s, b->s);
	  return(new(String, a->s));
	}
    }
  return (self);
}

static Object *String_append_c(const Object* self, const char* other)
{
  StringClass *a;
  a = new(String, other);
  return (String_append_s(self, a));
}

static StringClass _description = {
  { sizeof(StringClass), "String", &String_ctor, &String_dtor, &String_str, &String_c_str, &String_append_s, &String_append_c },
  NULL, NULL
};

Class* String = (Class*) &_description;
