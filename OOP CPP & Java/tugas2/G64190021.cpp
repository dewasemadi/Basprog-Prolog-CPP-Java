#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

class Bilangan
{
private:
    int n;
    vector<int> num, del;

public:
    void readInput()
    {
        while (cin >> n && n!=-9)
        {
            num.push_back(n);
        }
        while (cin >> n && n!=-9)
        {
            del.push_back(n);
        }
    }

    int getTotalNumBefDel()
    {
        return num.size();
    }

    int getTotalNumAfDel()
    {
        return num.size() - del.size();
    }

    void sortArr()
    {
        sort(num.begin(), num.end());
    }

    void deleteNum()
    {
        for (int i = 0; i < del.size(); i++)
            num.erase(num.begin() + (del[i] - i - 1));
    }

    float avg()
    {
        int sum = 0;
        for (auto i = num.begin(); i != num.end(); i++)
            sum += *i;
        return (float)sum / num.size();
    }

    float countAvgBefDel()
    {
        return this->avg();
    }

    float countAvgAfDel()
    {
        this->sortArr();
        this->deleteNum();
        return this->avg();
    }

    void printResult()
    {
        if (num.empty())
            cout << -9.99 << endl;
        else
        {
            cout << this->getTotalNumBefDel() << " " << this->getTotalNumAfDel() << endl;
            cout << fixed << setprecision(2) << this->countAvgBefDel() << " " << fixed << setprecision(2) << this->countAvgAfDel() << endl;
        }
    }
};

int main()
{
    Bilangan bil;
    bil.readInput();
    bil.printResult();
    return 0;
}