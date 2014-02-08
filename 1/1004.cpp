#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <map>

using namespace::std;

#define DEBUG 1

int main(void)
{
#if DEBUG
    ifstream ifile("1004.in");
    // ofstream ofile();
    cin.rdbuf(ifile.rdbuf());
#endif

    int N;
    cin >> N;
    while (N) {
        map <string, int> dic;
        string str;
        for (int i = 0; i < N; ++i) {
            cin >> str;
            dic[str] ++;
        }

        int max = 0;
        string maxstr;
        for (map<string, int>::iterator iter = dic.begin(); iter != dic.end(); ++iter) {
            if (iter->second > max) {
                max = iter->second;
                maxstr = iter->first;
            }
        }

        cout << maxstr << endl;
        
        cin >> N;
    }

    return 0;
}