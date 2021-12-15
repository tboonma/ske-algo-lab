#include <iostream>
using namespace std;

int main() {
    int n, p, max_tall;
    char a;
    cin >> n;
    int t[11];
    for (int i=1; i<=10; i++) {
        t[i] = 0;
    }
    for (int i=1; i<=n; i++) {
        cin >> a >> p;
        if (a == '-') {
            max_tall =  0;
            for (int j=p; j<p+4; j++)
                if (t[j] > max_tall)
                    max_tall = t[j];
            max_tall++;
            for (int j=p; j<p+4; j++)
                t[j] = max_tall;
        }
        else if (a == 'i') {
            t[p] += 4;
        }
        else if (a == 'o') {
            max_tall = 0;
            for (int j=p; j<p+2; j++)
                if (t[j] > max_tall)
                    max_tall = t[j];
            max_tall += 2;
            for (int j=p; j<p+2; j++)
                t[j] = max_tall;
        }
    }
    int maximum = 0;
    for (int i=1; i<=10; i++) {
        if (t[i] > maximum)
            maximum = t[i];
    }
    cout << maximum;
}

// testcases
/*
5
i 1
- 2
i 3
- 2
o 3
*/