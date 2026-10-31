#include <latch>

#include "action.h"

using namespace std;

namespace scheme
{
    struct Set
    {
        char name;
        latch done;
    };

    Set a{'a', latch(4)};
    Set b{'b', latch(6)};
    Set c{'c', latch(4)};
    Set d{'d', latch(5)};
    Set e{'e', latch(8)};
    Set g{'g', latch(5)};
    Set h{'h', latch(7)};
    Set i{'i', latch(4)};
    Set j{'j', latch(5)};
    Set k{'k', latch(8)};

    void run(Set &x, int from, int to)
    {
        for (int n = from; n <= to; ++n)
            f(x.name, n);
        x.done.count_down(to - from + 1);
    }
}
