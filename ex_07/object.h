
#ifndef CLASS_H
# define CLASS_H

# include <sys/types.h>
# include <stdarg.h>

typedef void Object;
typedef void (*ctor_t)(Object * self, va_list * args);
typedef void (*dtor_t)(Object * self);
typedef char const* (*to_string_t)(Object* self);
typedef char const* (*get_string)(Object* self);
typedef Object* (*append_string_s)(const Object* self, const Object* other);
typedef Object* (*append_string_c)(const Object* self, char const * other);

//typedef Object* (*binary_operator_t)(const Object* self, const Object* other);

typedef struct {
  const size_t		__size__;
  const char*		__name__;
  ctor_t		__init__;
  dtor_t		__del__;
  to_string_t		__str__;
  get_string		__getstr__;
  append_string_c	__apstrc__;
  append_string_s	__apstrs__;
  //    binary_operator_t   __add__;
} Class;

# define str(o) (((Class*) o)->__str__ != NULL ? ((Class*) o)->__str__(o) : "")
# define getstr(o) (((Class*) o)->__getstr__ != NULL ? ((Class*) o)->__getstr__(o) : "")
# define appstr_c(o, p) (((Class*) o)->__apstrc__ != NULL ? ((Class*) o)->__apstrc__(o, p) : "")
# define appstr_s(o, p) (((Class*) o)->__apstrs__ != NULL ? ((Class*) o)->__apstrs__(o, p) : "")
//# define add(a, b) (((Class*) a)->__add__(a, b))
#endif
