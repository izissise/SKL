
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
  printf("%s\n", apstrc(p1, p2));
  
  delete(p1);
  
  return 0;
}
