
#include <stdio.h>
#include <assert.h>

#include "char.h"
#include "int.h"
#include "float.h"
#include "new.h"

void test(Object* a, Object* b, Object* c)
{
    printf("a = %s, b = %s, c = %s\n", str(a), str(b), str(c));
    assert(eq(a, b));
    assert(!gt(a, b));
    assert(!lt(a, b));
    assert(!eq(a, c));
    assert(eq(a, b));
    assert(gt(c, a));

    delete(a);
    delete(b);
    delete(c);
}


int main()
{
    test(new(Int, 12), new(Int, 12), new(Int, 13));
    test(new(Char, 'a'), new(Char, 'a'), new(Char, 'd'));
    test(new(Float, 3.14159f), new(Float, 3.14159f), new(Float, 3.15f));

    Object * p1 = new(Float, 12.0),
           * p2 = new(Float, 2.0),
           * p3 = NULL,
           * p4 = NULL,
           * v1 = new(Char, 65),
           * v2 = new(Int, 4),
           * v3 = NULL,
           * v4 = NULL;

    p3 = add(p1, p2);
    printf("%s + %s = %s\n", str(p1), str(p2), str(p3));
    p4 = sub(p1, p2);
    printf("%s - %s = %s\n", str(p1), str(p2), str(p4));

    v3 = add(v1, v2);
    printf("%s + %s = %s\n", str(v1), str(v2), str(v3));
    v4 = sub(v1, v2);
    printf("%s - %s = %s\n", str(v1), str(v2), str(v4));

    delete(p1);
    delete(p2);
    delete(p3);
    delete(p4);
    delete(v1);
    delete(v2);
    delete(v3);
    delete(v4);

    return 0;
    return 0;

    return 0;
}

