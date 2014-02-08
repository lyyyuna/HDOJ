#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace::std;

#define DEBUG 1

struct BigInt
{
    int n[1500];
    int len;

    BigInt(string numstr)
    {
        memset(n, 0, sizeof(n));
        int index(0);
        for (string::reverse_iterator iter = numstr.rbegin(); iter != numstr.rend(); ++iter) {
            n[index++] = *iter - '0';
        }
        len = index;
    }

    void set(int t)
    {
        memset(n, 0, sizeof(n));
        n[0] = t;
        len = 1;
    }

    void operator += (const BigInt rhs)
    {
        if (rhs.len > len)
            len = rhs.len;
        for (int i = 0; i < len; ++i) {
            n[i] += rhs.n[i];
            if (n[i] > 9) {
                n[i+1] ++;
                n[i] -= 10;
            }
        }
        if (n[len])
            len ++;
    }

    void print() {
        for (int i = len-1; i >= 0; --i)
            cout << n[i];
        //cout << endl;
    }
};

int main(void)
{
#if DEBUG
    ifstream ifile("1002.in");
    cin.rdbuf(ifile.rdbuf());
#endif

    int T;
    cin >> T;
    int i(0);
    while (T--) {
        string A, B;
        cin >> A >> B;
        BigInt BigA(A), BigB(B), BigC(A);
        BigC += BigB;

        i++;
        cout << "Case " << i << ":" << endl;
        BigA.print();
        cout << " + ";
        BigB.print();
        cout << " = ";
        BigC.print();
        cout << endl;

        if (T != 0)
            cout << endl;
    }

    return 0;
}
