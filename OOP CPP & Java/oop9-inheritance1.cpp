#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <numeric>
#include <cmath>
using namespace std;

class Poligon
{
public:
    long int nEdge;
    vector<double> x, y, total, result;

public:
    Poligon(){};
    void set(double xt, double yt)
    {
        x.push_back(xt);
        y.push_back(yt);
    }

    void kll()
    {
        for (long int i = 0; i < x.size() - 1; i++)
        {
            // mencari jarak dari x[0], y[0] sampai x[n-1], y[n-1]
            double d = sqrt(pow(x[i] - x[i + 1], 2) + pow(y[i] - y[i + 1], 2));
            total.push_back(d);
        }
        // mencari jarak sisanya
        double d = sqrt(pow(x[0] - x[x.size() - 1], 2) + pow(y[0] - y[x.size() - 1], 2));
        total.push_back(d);
    }

    double getTotal()
    {
        return accumulate(total.begin(), total.end(), 0.0);
    }

    void clear()
    {
        x.clear();
        y.clear();
    }

    double avg(long int n)
    {
        double sum = accumulate(result.begin(), result.end(), 0.0);
        return sum / n;
    }

    long int lebihBesar(long int n)
    {
        long int N = 0;
        double avg = this->avg(n);
        vector<double>::iterator it;
        for (it = result.begin(); it != result.end(); it++)
            if (*it >= avg)
                N++;
        return N;
    }
};

class Segitiga : public Poligon
{
public:
    void getLuas()
    {
        // sarrus
        double a = ((x[1] * y[2]) + (x[2] * y[0]) + (x[0] * y[1]));
        double b = ((y[0] * x[1]) + (y[1] * x[2]) + (y[2] * x[0]));
        double luas = (double)(a - b) / 2;
        result.push_back(luas);
        this->clear();
    }
};

class Segiempat : public Poligon
{
public:
    void getLuas()
    {
        // primitip :)
        double a = sqrt(pow(x[1] - x[0], 2) + pow(y[1] - y[0], 2));
        double b = sqrt(pow(x[2] - x[1], 2) + pow(y[2] - y[1], 2));
        double c = sqrt(pow(x[3] - x[2], 2) + pow(y[3] - y[2], 2));
        double d = sqrt(pow(x[3] - x[0], 2) + pow(y[3] - y[0], 2));
        double p = (double)(a + b + c + d) / 4;

        p *= p;
        result.push_back(p);
        total.clear();
        this->clear();
    }
};

int main()
{
    int n = 0, m = 0;
    double x[100000], y[100000];
    Segitiga segitiga;
    Segiempat segiempat;
    cin >> n;
    // segitiga
    for (long int i = 0; i < n; i++)
    {
        cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];
        for (int j = 0; j < 3; j++)
            segitiga.set(x[j], y[j]);
        segitiga.getLuas();
    }

    // segiempat
    cin >> m;
    for (long int i = 0; i < m; i++)
    {
        cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2] >> x[3] >> y[3];
        for (int j = 0; j < 4; j++)
            segiempat.set(x[j], y[j]);
        segiempat.getLuas();
    }
    cout << fixed << setprecision(2) << segitiga.avg(n) << " " << fixed << setprecision(2) << segiempat.avg(m) << endl;
    cout << segitiga.lebihBesar(n) << " " << segiempat.lebihBesar(m) << endl;

    return 0;
}