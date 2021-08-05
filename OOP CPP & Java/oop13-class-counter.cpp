#include <iostream>
using namespace std;

class Counter
{
private:
    int count;

public:
    // constructor
    Counter()
    {
        count = 0;
    }
    void set(int num)
    {
        count = num;
    }
    void inc()
    {
        count++;
    }
    void dec()
    {
        if (count > 0)
            count--;
    }
    void print()
    {
        cout << count << endl;
    }
};

int main()
{
    Counter count;
    int awal = 0, num = 0;
    while (1)
    {
        cin >> awal;
        if (awal == -9)
            break;
        else if (awal == 0)
        {
            cin >> num;
            if (num < 0)
                continue;
            else
                count.set(num);
        }
        else if (awal == 1)
            count.inc();
        else if (awal == -1)
            count.dec();
        else if (awal == 9)
            count.print();
        else
            continue;
    }
    return 0;
}