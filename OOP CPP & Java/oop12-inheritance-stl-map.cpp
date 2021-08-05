#include <iostream>
#include <iomanip>
#include <string>
#include <map>
using namespace std;

typedef struct nilai
{
    int uts, uas;
    double akhir;
    string status;
} Nilai;

typedef map<string, Nilai> myType;

class Ujian : public myType
{
    myType x;

public:
    void input(int n)
    {
        string nim;
        int _uts = 0, _uas = 0;
        while (n--)
        {
            cin >> nim >> _uts >> _uas;
            x[nim].uts = _uts;
            x[nim].uas = _uas;
        }
    }

    double avg(int n)
    {
        double sum = 0.0;
        map<string, Nilai>::iterator it;
        for (it = x.begin(); it != x.end(); it++)
            sum += (double)(it->second.uts + it->second.uas) / 2;
        return sum / n;
    }

    void print(int n)
    {
        map<string, Nilai>::iterator it;
        for (it = x.begin(); it != x.end(); it++)
        {
            double avg = (double)(it->second.uts + it->second.uas) / 2;
            cout << it->first << " " << it->second.uts << " " << it->second.uas << " " << fixed << setprecision(2) << avg << " ";
            if (avg > this->avg(n))
                cout << "LULUS" << endl;
            else
                cout << "GAGAL" << endl;
        }
    }
};

int main()
{
    Ujian ujian;
    int n = 0;
    cin >> n;
    ujian.input(n);
    ujian.print(n);
    return 0;
}
