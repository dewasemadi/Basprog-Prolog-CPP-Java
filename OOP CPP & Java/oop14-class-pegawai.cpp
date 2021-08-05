#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Pegawai
{
protected:
    string id;
    int usia, tipe, income;

public:
    void set(string pid, int u, int t)
    {
        id = pid;
        usia = u;
        tipe = t;
    }
    string getID()
    {
        return id;
    }
    void print()
    {
        cout << id << " " << tipe << " " << income << endl;
    }
};

class Tetap : public Pegawai
{
public:
    // constructor
    Tetap()
    {
        income = 0;
    }
    void setIncomeTetap(int lembur)
    {
        income += lembur;
    }
};

class Harian : public Pegawai
{
public:
    // constructor
    Harian()
    {
        income = 0;
    }
    void setIncomeHarian(int gaji)
    {
        income += gaji;
    }
};

int main()
{
    vector<Tetap> pt;
    vector<Harian> ph;

    string id = "";
    int n = 0, age = 0, type = 0, pokok = 0;
    cin >> n;
    while (n--)
    {
        Tetap tetap;
        Harian harian;
        cin >> id >> age >> type;
        if (type == 1)
        {
            cin >> pokok;
            tetap.set(id, age, type);
            tetap.setIncomeTetap(pokok);
            pt.push_back(tetap);
        }
        else if (type == 2)
        {
            harian.set(id, age, type);
            ph.push_back(harian);
        }
    }

    // baca upah (pegawai harian) & uang lembur (pegawai tetao)
    while (1)
    {
        int cek = 0, lembur = 0, upah = 0;
        string temp_id = "", abaikan = "";
        cin >> id;
        if (id == "END")
            break;

        // cek pegawai tetap
        for (int T = 0; T < pt.size(); T++)
        {
            temp_id = pt[T].getID();
            if (temp_id == id)
            {
                cin >> lembur;
                pt[T].setIncomeTetap(lembur);
                cek = 1;
            }
        }

        // cek pegawai harian
        if (cek == 0)
        {
            for (int H = 0; H < ph.size(); H++)
            {
                temp_id = ph[H].getID();
                if (temp_id == id)
                {
                    cin >> upah;
                    ph[H].setIncomeHarian(upah);
                    cek = 1;
                }
            }
        }

        //id ga ketemu
        if (cek == 0)
            cin >> abaikan;
    }

    for (int T = 0; T < pt.size(); T++)
        pt[T].print();

    for (int H = 0; H < ph.size(); H++)
        ph[H].print();

    return 0;
}