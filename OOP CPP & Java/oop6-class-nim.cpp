#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <new>
using namespace std;

class NIM
{
	string value;
	public:
		NIM() { value=""; }
		void setNIM(string p) { value=p; }
		char getFakultas();                  // Mendapatkan kode Fakultas
		string getNIM();                     // Mendapatkan nilai NIM
		string getProdi();                   // Mendapatkan kode Program Studi
		int getTahunMasuk();                 // Mendapatkan Tahun Masuk
};

// IMPLEMENTASI FUNGSI ANGGOTA
char NIM::getFakultas(){
    return value[0];
}

string NIM::getNIM(){
    return value;
}

string NIM::getProdi(){
    return value.substr(0, 3);
}

int NIM::getTahunMasuk(){
    char thn[2];
    thn[0] = value[3];
    thn[1] = value[4];
    int angkatan = atoi(thn);
    if(angkatan >62)
      return angkatan += 1900;
    else
      return angkatan += 2000;
}

int main()
{
	NIM *mhs = new NIM;
	char st[10];
	while (scanf("%s", st)!=EOF)
	{
		mhs->setNIM(st);
		cout << mhs->getNIM() << " " << mhs->getFakultas() << " " << mhs->getProdi() << " " << mhs->getTahunMasuk()-1963 << endl;
	}
	return 0;
}