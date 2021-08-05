#include <iostream>
#include <cstring>
#include <cstdio>
#include <iomanip>
using namespace std;

class Account
{
    char nama[100], akun[15];
    double saldo;

public:
    Account();
    Account(char n[100], char p[100], double s = 0.0);
    char *getNama();
    char *getAkun();
    double getSaldo();
    void deposit(double nilai);
    void withdraw(double nilai);
    void print();
};

Account::Account()
{
    strcpy(nama, "");
    strcpy(akun, "");
    saldo = 0.0;
}

Account::Account(char n[100], char p[100], double s)
{
    strcpy(nama, n);
    strcpy(akun, p);
    saldo = s;
};

char *Account::getNama()
{
    return this->nama;
}

char *Account::getAkun()
{
    return this->akun;
}

double Account::getSaldo()
{
    return this->saldo;
}

void Account::deposit(double nilai)
{
    this->saldo = this->getSaldo() + nilai;
}

void Account::withdraw(double nilai)
{
    this->saldo = this->getSaldo() - nilai;
}

void Account::print()
{
    cout.precision(2);
    cout << this->getNama() << " : " << this->getAkun() << " : " << fixed << this->getSaldo() << endl;
}

int main()
{
    char name[100], acc[15];
    int code = 0;
    double value = 0.0;
    cin.getline(name, 100);
    cin.getline(acc, 15);
    name[strcspn(name, "\n") - 1] = 0;
    acc[strcspn(acc, "\n") - 1] = 0;
    Account account(name, acc, value);
    while (1)
    {
        cin >> code;
        if (code == 0)
            break;
        if (code == 1)
        {
            cin >> value;
            account.deposit(value);
        }
        else if (code == 2)
        {
            cin >> value;
            account.withdraw(value);
        }
        else if (code == 3)
            account.print();
    }

    return 0;
}