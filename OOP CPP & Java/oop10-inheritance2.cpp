#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

class Person
{
protected:
    string name;
    char jk;
    int usia;
    string kota;

public:
    void set(string n, char j, int u, string k)
    {
        this->name = n;
        this->jk = j;
        this->usia = u;
        this->kota = k;
    }

    string getNama()
    {
        return name;
    }

    char getSex()
    {
        return jk;
    }

    int getUsia()
    {
        return usia;
    }

    string getKota()
    {
        return kota;
    }
};

class Male : public Person
{
};

class Female : public Person
{
};

// template <class T>
// double rataan(vector<T> p);

int main()
{
    string line;

    vector<Male> L;
    vector<Female> P;
    int cewek = 0, cowok = 0;
    while (getline(cin, line))
    {
        string nama = line.substr(0, 24);
        char jenkel = line[25];
        char usia[2];
        usia[0] = line[26];
        usia[1] = line[27];
        int age = atoi(usia);
        string city = line.substr(28, 52);

        Male male;
        Female female;

        if (jenkel == 'L')
        {
            cowok++;
            male.set(nama, jenkel, age, city);
            L.push_back(male);
        }
        else if (jenkel == 'P')
        {
            cewek++;
            female.set(nama, jenkel, age, city);
            P.push_back(female);
        }
    }

    double sumA = 0.0, sumB = 0.0, avgCowok = 0.0, avgCewek = 0.0;

    // average
    for (int i = 0; i < cowok; i++)
        sumA += L[i].getUsia();
    avgCowok = (double)sumA / cowok;

    for (int i = 0; i < cewek; i++)
        sumB += P[i].getUsia();
    avgCewek = (double)sumB / cewek;

    // berapa yang lolos
    long int lolosA = 0, lolosB = 0;
    for (int i = 0; i < cowok; i++)
        if (L[i].getUsia() < avgCowok)
            lolosA++;

    for (int i = 0; i < cewek; i++)
        if (L[i].getUsia() < avgCewek)
            lolosB++;

    cout << "L " << cowok << " " << fixed << setprecision(2) << avgCowok << " " << lolosA << endl;
    cout << "P " << cewek << " " << fixed << setprecision(2) << avgCewek << " " << lolosB << endl;
    return 0;
}