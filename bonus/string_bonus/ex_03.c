
#include <stdlib.h>
#include <stdio.h>

#include "new.h"
#include "string.h"

int main()
{
  Object * p1 = new(String, "bonjour les amis");
  Object * p2 = new(String, " ! on s'encule ??");

  printf("%s\n", str(p1));
  printf("%s\n", getstr(p1));
  Object* lol = appstr_s(p1, p2);
  printf("%s\n", getstr(lol));

  delete(p1);
  delete(lol);
  delete(p2);

  return 0;
}
