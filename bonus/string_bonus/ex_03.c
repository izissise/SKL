
#include <stdlib.h>
#include <stdio.h>

#include "new.h"
#include "string.h"

int main()
{
  Object * p1 = new(String, "bonjour les amis");
  
  printf("%s\n", str(p1));
  printf("%s\n", getstr(p1));
  
  delete(p1);
  
  return 0;
}
