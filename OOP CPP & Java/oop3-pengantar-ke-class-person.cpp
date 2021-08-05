#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Person
{
    // atribut / property
private:
    string nama;
    int usia, tinggi;
    float berat;

public: // method / behavior
    // constructor -> method yang pertama kali dipanggil saat mendefinisikan objek
    Person()
    {
        nama = "";
        usia = tinggi = 0, berat = 0.0;
    }

    void setPerson(string nama, int usia, int tinggi, float berat)
    {
        Person::nama = nama;
        Person::usia = usia;
        Person::tinggi = tinggi;
        Person::berat = berat;
    }

    int getTinggi()
    {
        return tinggi;
    }

    void print()
    {
        cout << nama << " " << usia << endl;
    }
};

int main()
{
    string nama;
    int n, usia, tinggi;
    float berat;
    cin >> n;
    Person person[n];

    for (int i = 0; i < n; i++)
    {
        cin >> nama >> usia >> tinggi >> berat;
        person[i].setPerson(nama, usia, tinggi, berat);
    }

    for (int i = 0; i < n; i++)
        person[i].print();

    // mencari rata2
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += person[i].getTinggi();

    float average = (float)sum / n;
    cout << fixed << setprecision(2) << average << endl;

    // cari berapa orang yang punya tinggi diatas rata2
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (person[i].getTinggi() > average)
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}