#include <iostream>
#include <map>
using namespace std;

class Account
{
private:
    string id;
    map<string, int> freq;

public:
    Account()
    {
        id = "";
    }

    void set(string id)
    {
        freq[id]++;
    }

    void clear()
    {
        freq.clear();
    }

    void print()
    {
        map<string, int>::iterator p;
        for (p = freq.begin(); p != freq.end(); p++)
            cout << p->first << " " << p->second << endl;
    }
};

int main()
{
    Account account;
    string id = "";
    int t = 0, n = 0;
    cin >> t;
    while (t--)
    {
        cin >> n;
        getline(cin, id); //pura2 baca '\0'
        while (n--)
        {
            getline(cin, id);
            account.set(id);
        }
        account.print();
        account.clear();
    }

    return 0;
}