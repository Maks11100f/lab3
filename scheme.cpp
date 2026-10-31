#include <chrono>
#include <iostream>
#include <latch>
#include <syncstream>
#include <thread>

#include "scheme.h"

using namespace std;

namespace scheme
{
    void f(char x, int i)
    {
        this_thread::sleep_for(1s);
        osyncstream(cout) << "З набору " << x << " виконано дію " << i << "." << endl;
    }

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

    void thread1()
    {
        run(a, 1, 4);
        run(c, 1, 4);
        run(j, 1, 5);

        d.done.wait();
        e.done.wait();
        run(h, 5, 7);

        h.done.wait();
        i.done.wait();
        j.done.wait();
        run(k, 1, 3);
    }

    void thread2()
    {
        run(b, 1, 3);

        b.done.wait();
        run(e, 1, 4);

        a.done.wait();
        run(d, 1, 5);

        e.done.wait();
        run(h, 1, 4);

        h.done.wait();
        i.done.wait();
        j.done.wait();
        run(k, 4, 6);
    }

    void thread3()
    {
        run(b, 4, 6);

        b.done.wait();
        run(e, 5, 8);
        run(g, 1, 5);
        run(i, 1, 4);

        h.done.wait();
        i.done.wait();
        j.done.wait();
        run(k, 7, 8);
    }
}
