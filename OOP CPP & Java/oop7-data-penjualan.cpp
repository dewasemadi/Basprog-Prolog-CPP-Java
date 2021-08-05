#include <iostream>
#include <iomanip>
#include <cstring>
#include <map>

using namespace std;

struct record
{
    int jumlah; // jumlah item barang
    int total;  // nilai rupiah
};

typedef struct record ITEM;
typedef pair<string, int> P;

class Produk
{
    map<string, int> list; // Daftar kode barang dan harga satuan per unit
public:
    // Fungsi membaca daftar kode barang dan harga satuan
    void initProduk()
    {
        string item;
        int n, harga;
        cin >> n;
        while (n--)
        {
            cin >> item >> harga;
            list.insert(P(item, harga));
        }
    }

    // Fungsi mendapatkan harga satuan dari suatu item barang
    // Nilai 0 untuk item barang yang tidak ditemukan
    int getHarga(string item)
    {
        if (list[item])
            return list[item];
        else
            return 0;
    }
};

class Penjualan
{
    Produk dt;                   // Daftar harga satuan barang
    map<string, ITEM> penjualan; // Daftar penjualan
public:
    Penjualan() { dt.initProduk(); }

    // Fungsi membaca data penjualan dan memasukkan ke dalam Daftar penjualan -> map
    void addPenjualan()
    {
        int n, jml;
        string item;

        cin >> n;
        while (n--)
        {
            cin >> item >> jml;
            penjualan[item].jumlah += jml;
            penjualan[item].total += dt.getHarga(item) * jml;
        }
    }

    // Fungsi mencetak data penjualan dan total nilai penjualan
    void print()
    {
        double convertHarga = 0.0, totalHarga = 0.0, sum = 0.0;
        map<string, ITEM>::iterator it;
        for (it = penjualan.begin(); it != penjualan.end(); it++)
        {
            convertHarga = (double)it->second.total / 1000000;
            sum += it->second.total;

            // kalo 0 berarti ga ada di list barang
            if (it->second.total)
                cout << it->first << " " << it->second.jumlah << " " << fixed << setprecision(2) << convertHarga << endl;
        }
        totalHarga = (double)sum / 1000000;
        cout << "Total Nilai : " << fixed << setprecision(2) << totalHarga << " juta rupiah" << endl;
    }
};

int main()
{
    Penjualan p;
    p.addPenjualan();
    p.print();
    return 0;
}