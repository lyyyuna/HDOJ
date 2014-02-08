#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace::std;

#define DEBUG 0

int main(void)
{
#if DEBUG
    ifstream ifile("1003.in");
    // ofstream ofile();
    cin.rdbuf(ifile.rdbuf());
#endif

    int A, B, n;
    int a[100];
    a[1] = 1;
    a[2] = 1;
    while ((cin >> A >> B >> n) && (A||B||n)) {
        for (int i = 3; i < 100; ++i) {
            a[i] = (A*a[i-1] + B* a[i-2]) % 7;
        }
        // a[i-1], a[i]     7 * 7 = 49    49-1=48
        cout << a[n%48] << endl;
    }

    return 0;
}