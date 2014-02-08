// Max Sum
// 最大子序列

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace::std;

#define DEBUG 1

int st, ed;
// int len;

int maxsub(int a[], int len)
{
    st = ed = 1;
    int sum, j, b, bs, be;
    sum = b = a[0];
    for (j = 0; j < len; j++) {
        if ( b >= 0 && j != 0) {
            b = b + a[j];
            be = j+1;
        } else {
            b = a[j];
            bs = j+1;
            be = j+1;
        }
        if (b > sum) {
            sum = b;
            st = bs;
            ed = be;
        }
    }
    return sum;
}

int a[100005];

int main(void)
{
#if DEBUG
    ifstream ifile("1003.in");
    // ofstream ofile();
    cin.rdbuf(ifile.rdbuf());
#endif

    int T;
    cin >> T;
    int k(1), len;
    while (T--) {
        cin >> len;
        for (int i = 0; i < len; ++i)
            cin >> a[i];
        int sum;
        sum = maxsub(a, len);
        
        if(T==0)    printf("Case %d:\n%d %d %d\n",k++,sum,st,ed);
        else printf("Case %d:\n%d %d %d\n\n",k++,sum,st,ed);
    }

    return 0;
}