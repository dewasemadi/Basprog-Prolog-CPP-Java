#include <iostream>
#include <cstring>
#include <map>
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
    void deposit(double val);
    void withdraw(double val);
    void print();
};

Account::Account(char n[100], char p[100], double s)
{
    strcpy(nama, n);
    strcpy(akun, p);
    saldo = s;
}
char *Account::getNama()
{
    return nama;
}
char *Account::getAkun()
{
    return akun;
}
double Account::getSaldo()
{
    return saldo;
}
void Account::deposit(double nilai)
{
    saldo = getSaldo() + nilai;
    ;
}
void Account::withdraw(double nilai)
{
    saldo = getSaldo() - nilai;
}
void Account::print()
{
    cout.precision(2);
    cout << nama << " : " << akun << " : " << fixed << saldo << endl;
}

int main()
{
    char nama[100], acc[15];
    int input = 0;
    double val = 0.0;
    cin.getline(nama, 100);
    cin.getline(acc, 15);
    nama[strcspn(nama, "\n") - 1] = 0;
    acc[strcspn(acc, "\n") - 1] = 0;
    Account act(nama, acc);
    cin >> input;
    while (input != 0)
    {
        if (input == 1)
        {
            cin >> val;
            act.deposit(val);
        }
        else if (input == 2)
        {
            cin >> val;
            act.withdraw(val);
        }
        else if (input == 3)
        {
            act.print();
        }
        cin >> input;
    }
    return 0;
}