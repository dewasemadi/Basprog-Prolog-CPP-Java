#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
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

    // mutator -> assign value
    void setPerson(string nama, int usia, int tinggi, float berat)
    {
        Person::nama = nama;
        Person::usia = usia;
        Person::tinggi = tinggi;
        Person::berat = berat;
    }

    // accesor -> get value
    int getTinggi()
    {
        return tinggi;
    }

    float getBerat()
    {
        return berat;
    }

    float getIMT(float berat, int tinggi)
    {
        float t = tinggi / 100.0;
        return berat / (t * t);
    }

    string statusGizi(float IMT)
    {
        if (IMT < 17.0)
            return "sangat kurus";
        else if (IMT < 18.5)
            return "kurus";
        else if (IMT < 25.0)
            return "normal";
        else if (IMT < 28.0)
            return "gemuk";
        else
            return "sangat gemuk";
    }

    void print()
    {
        cout << nama << " " << usia << " " << tinggi << " " << fixed << setprecision(2) << berat << " ";
    }
};

int main()
{
    string nama;
    int n, usia, tinggi;
    float berat;
    cin >> n;
    Person person[n]; //array of object

    for (int i = 0; i < n; i++)
    {
        cin >> nama >> usia >> tinggi >> berat;
        person[i].setPerson(nama, usia, tinggi, berat);
    }

    int p = 0, q = 0, r = 0, s = 0, t = 0;
    for (int i = 0; i < n; i++)
    {
        person[i].print();
        float imt = person[i].getIMT(person[i].getBerat(), person[i].getTinggi());
        string resultIMT = person[i].statusGizi(imt);

        if (resultIMT == "sangat kurus")
            p++;
        else if (resultIMT == "kurus")
            q++;
        else if (resultIMT == "normal")
            r++;
        else if (resultIMT == "gemuk")
            s++;
        else if (resultIMT == "sangat gemuk")
            t++;

        cout << imt << " " << resultIMT << endl;
    }

    // mencari rata2
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += person[i].getTinggi();

    float average = (float)sum / n;
    printf("%.2f\n", average);

    // cari berapa orang yang punya tinggi diatas rata2
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (person[i].getTinggi() > average)
            cnt++;
    }
    cout << cnt << endl;
    printf("%d %d %d %d %d\n", p, q, r, s, t);

    return 0;
}