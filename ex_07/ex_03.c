
#include <stdlib.h>
#include <stdio.h>

#include "new.h"
#include "string.h"

int main()
{
  Object * p1 = new(String, "tata");
  Object * p2 = new(String, " et toto");

  printf("%s\n", str(p1));
  printf("%s\n", getstr(p1));
  Object* lol = appstr_s(p1, p2);
  const char	*str = getstr(lol);
  if (str)
    printf("%s\n", str);

  delete(p1);
  delete(lol);
  delete(p2);

  return 0;
}
