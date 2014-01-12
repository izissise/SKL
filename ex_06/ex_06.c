#include <stdio.h>
#include <assert.h>

#include "list.h"
#include "int.h"
#include "new.h"

typedef struct
{
    Container base;
    Class* _type;
    size_t _size;
    Object** _tab;
} ListClass;

typedef struct {
    Iterator base;
    ListClass* _array;
    size_t _idx;
} ArrayIteratorClass;

void ListIterator_setval(ArrayIteratorClass* self, ...);

int main()
{
    Object* array = new(List, 10, Int, 0);
    Object* it = begin(array);
    Object* it_end = end(array);
    int i;

    i = 0;
    printf("array size: %zu\n", len(array));
    setitem(array, 5, 12);
    setitem(array, 6, 13);
    printf ("\n5 : %s\n\n",str(getitem(array, 5)));
    while (lt(it, it_end) && !eq(it, it_end) && gt(it_end, it))
    {
      if (i == 2)
        ListIterator_setval(it, -4);
      printf("%s\n", str(getval(it)));
      incr(it);
      i++;
    }

    delete(it);
    delete(it_end);
    delete(array);
    return 0;
}