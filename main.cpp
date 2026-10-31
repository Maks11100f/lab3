// Компілятор: gcc (MinGW)
#include <chrono>
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    cout << "Обчислення розпочато." << endl;
    auto start = chrono::steady_clock::now();

    auto finish = chrono::steady_clock::now();
    chrono::duration<double> duration = finish - start;
    cout << "Обчислення завершено. Тривалість обчислення " << duration.count() << " секунд." << endl;

    return 0;
}
