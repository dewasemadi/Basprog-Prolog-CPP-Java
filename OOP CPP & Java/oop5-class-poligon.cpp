#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <numeric>
#include <cmath>
using namespace std;

class Poligon
{
private:
    int nEdge;
    vector<double> x, y, total;

public:
    void set(double xt, double yt)
    {
        x.push_back(xt);
        y.push_back(yt);
    }

    void kll()
    {
        for (int i = 0; i < x.size() - 1; i++)
        {
            // mencari jarak dari x[0], y[0] sampai x[n-1], y[n-1]
            double ex = (x[i] - x[i + 1]) * (x[i] - x[i + 1]);
            double ye = (y[i] - y[i + 1]) * (y[i] - y[i + 1]);
            double d = sqrt(ex + ye);
            total.push_back(d);
        }
        // mencari jarak sisanya
        double ex = (x[0] - x[x.size() - 1]) * (x[0] - x[x.size() - 1]);
        double ye = (y[0] - y[x.size() - 1]) * (y[0] - y[x.size() - 1]);
        double d = sqrt(ex + ye);
        total.push_back(d);
    }

    double getTotal()
    {
        return accumulate(total.begin(), total.end(), 0.0);
    }

    void print()
    {
        cout << fixed << setprecision(2) << "[" << x.front() << "," << y.front() << "]-[" << x.back() << "," << y.back() << "]" << endl;
    }
};

int main()
{
    int n;
    double a, b;
    Poligon polygon;
    cin >> n;
    while (n--)
    {
        cin >> a >> b;
        polygon.set(a, b);
    }
    polygon.kll();
    polygon.print();
    cout << fixed << setprecision(2) << polygon.getTotal() << endl;
    return 0;
}