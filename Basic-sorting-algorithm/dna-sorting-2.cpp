#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct DNA {
    string str;
    int time;
};

bool compareTwoDNA(DNA a, DNA b) {
    return a.time < b.time;
}

int main() {
    int m, n, range, this_num, next_num, time;
    cin >> m;
    while (m > 0) {
        cin >> n >> range;
        DNA dna[range];
        string dna_str;
        for (int i=0; i<range; i++) {
            time = 0;
            cin >> dna_str;
            dna[i].str = dna_str;
            for (int j=0; j<n-1; j++) {
                for (int k=j+1; k<n; k++) {
                    if (dna_str[j] > dna_str[k])
                        time++;
                }
            }
            dna[i].time = time;
        }
        stable_sort(dna, dna+range, compareTwoDNA);
        for (int i=0; i<range; i++)
            cout << dna[i].str << endl;
        if (m-1 > 0)
            cout << endl;
        m--;
    }
}