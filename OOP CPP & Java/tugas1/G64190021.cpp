#include <iostream>
#include <string>
#include <sstream>
#define SIZE 100
using namespace std;

class Mahasiswa
{
public:
    // property / atribut
    string NIM;
    int usia, jk;
    float ipk;
};

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    string line, temp;
    int n;
    cin >> n;
    getline(cin, line);  //pura2 baca '\0'
    Mahasiswa mhs[SIZE]; //array of object :)

    for (int i = 0; i < n; i++)
    {
        getline(cin, line);
        stringstream s(line);

        getline(s, temp, ' ');
        mhs[i].NIM = temp; //ambil nim

        getline(s, temp, ' ');
        mhs[i].usia = stoi(temp); //ambil usia

        getline(s, temp, ' ');
        mhs[i].jk = stoi(temp); //ambil jenkel

        getline(s, temp, '\0');
        mhs[i].ipk = stof(temp); //ambil ipk
    }

    int m, a, b;
    cin >> m;
    while (m--)
    {
        cin >> a >> b;
        swap(mhs[a - 1], mhs[b - 1]);
    }

    // cetak hasil
    for (int i = 0; i < n; i++)
        cout << mhs[i].NIM << " " << mhs[i].usia << " " << mhs[i].jk << " " << mhs[i].ipk << endl;

    return 0;
}