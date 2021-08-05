#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class Kubus
{
    double sisi;

public:
    Kubus() { sisi = 0; }
    void set(double s) { sisi = s; }
    double luas() { return 6 * sisi * sisi; }      // menghitung luas permukaan kubus
    double volume() { return sisi * sisi * sisi; } // menghitung volume kubus
};
class ListKubus
{
    vector<Kubus> K;

public:
    ListKubus()
    {
        int n = 0;
        double num = 0.0;
        cin >> n;
        while (n--)
        {
            cin >> num;
            Kubus n;
            n.set(num);
            K.push_back(n);
        }
    } // membaca data n kubus
    double rataLuas()
    {
        int n = K.size();
        double sum = 0.0;
        for (int i = 0; i < n; i++)
            sum += K[i].luas();

        return sum / n;
    } // menghitung rata-rata luas permukaan n kubus
    double rataVolume()
    {
        int n = K.size();
        double sum = 0.0;
        for (int i = 0; i < n; i++)
            sum += K[i].volume();
        return sum / n;
    } // menghitung rata-rata volume n kubus
};
int main()
{
    ListKubus L;
    cout << fixed << setprecision(2)
         << L.rataLuas() << " " << L.rataVolume() << endl;
    return 0;
}