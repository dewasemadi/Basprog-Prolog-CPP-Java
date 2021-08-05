#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <numeric>
#include <cmath>
using namespace std;

class Poligon
{
private:
    vector<double> x, y;
    int n_edge;

public:
    Poligon(){};

    void Set(double *xt, double *yt, int n_edge)
    {
        for (int i = 0; i < n_edge; i++)
        {
            x.push_back(xt[i]);
            y.push_back(yt[i]);
        }
    }

    double Kll()
    {
        double sum = 0.0;
        for (int i = 0; i < n_edge; i++)
            sum += sqrt(pow(x[i] - x[i - 1], 2) + pow(y[i] - y[i - 1], 2));
        sum += sqrt(pow(x[0] - x[n_edge - 1], 2) + pow(y[0] - y[n_edge - 1], 2));
        return sum;
    }

    double GetEdge_N(int n)
    {
        double edge = 0.0;
        if (n == 0)
            edge = sqrt(pow(x[0] - x[n_edge - 1], 2) + pow(y[0] - y[n_edge - 1], 2));

        else
            edge = sqrt(pow(x[n] - x[n - 1], 2) + pow(y[n] - y[n - 1], 2));
        return edge;
    }
};

class Segitiga : public Poligon
{
public:
    double Luas()
    {
        double kll = Kll();
        double luas = (kll / 4.0) * (kll / 4.0);
        return luas;
    }
};

class Segiempat : public Poligon
{
public:
    double Luas()
    {
        double kll = Kll();
        double S = kll / 2.0;
        double a = GetEdge_N(0);
        double b = GetEdge_N(1);
        double c = GetEdge_N(2);
        double luas = sqrt(S * (S - a) * (S - b) * (S - c));
        return luas;
    };
};

int main()
{
    int n = 0, m = 0;
    double x = 0.0, y = 0.0;
    Segitiga segitiga;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        segitiga.Set(&x, &y, n);
    }
    cout << segitiga.Luas() << endl;
    return 0;
}