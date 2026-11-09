// Компілятор: gcc (MinGW)
#include <chrono>
#include <iostream>
#include <syncstream>
#include <thread>

#include <windows.h>

#include "scheme.h"

using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    osyncstream(cout) << "Обчислення розпочато." << endl;
    auto start = chrono::steady_clock::now();

    {
        jthread t1(scheme::thread1);
        jthread t2(scheme::thread2);
        jthread t3(scheme::thread3);
    }

    auto finish = chrono::steady_clock::now();
    chrono::duration<double> duration = finish - start;
    osyncstream(cout) << "Обчислення завершено. Тривалість обчислення " << duration.count() << " секунд." << endl;

    return 0;
}
