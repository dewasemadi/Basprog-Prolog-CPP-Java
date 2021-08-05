#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

typedef pair<double, double> P; //P.first = x, P.second = y

class Poligon : public vector<P>
{
public:
    P get(int i) { return at(i); }
    void input(int n)
    {
        double t1, t2;
        while (n--)
        {
            cin >> t1 >> t2;
            push_back(make_pair(t1, t2));
        }
    }

    double euclid(P t1, P t2)
    {
        double t = (t1.first - t2.first) * (t1.first - t2.first);
        t += (t1.second - t2.second) * (t1.second - t2.second);
        return sqrt(t);
    }

    double keliling()
    {
        int i = 0;
        double sum = 0.0;
        for (i = 1; i < size(); i++)
            sum += euclid(get(i - 1), get(i));
        sum += euclid(get(i - 1), get(0));
        return sum;
    }
};

int main()
{
    Poligon p;
    int n;
    cin >> n;
    p.input(n);

    double x0 = p.get(0).first, y0 = p.get(0).second;
    double xn = p.get(n - 1).first, yn = p.get(n - 1).second;

    cout << fixed << setprecision(2) << "[" << x0 << "," << y0 << "]-[" << xn << "," << yn << "]" << endl;
    cout << fixed << setprecision(2) << p.keliling() << endl;

    return 0;
}