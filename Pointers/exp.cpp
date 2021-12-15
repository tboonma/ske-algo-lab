#include <iostream>
using namespace std;

int main()
{
    int n, e;
    cin >> n;
    int exp = 0;
    for (int i=1; i<=n; i++) {
        cin >> e;
        if (i%4 == 0)
            exp += e;
        exp += e;
    }
    cout << exp;
}