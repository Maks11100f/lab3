#include <chrono>
#include <iostream>
#include <syncstream>
#include <thread>

#include "action.h"

using namespace std;

void f(char x, int i)
{
    this_thread::sleep_for(1s);
    osyncstream(cout) << "З набору " << x << " виконано дію " << i << "." << endl;
}
