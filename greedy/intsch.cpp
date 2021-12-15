#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int max_n = 1000010;

int n;
int s[max_n];
int t[max_n];

void read_input()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i] >> t[i];
    }
}

int main() {
    vector< pair<int,int> > tidx;

    read_input();
    tidx.reserve(n);
    for (int i = 0; i < n; ++i) {
        tidx.emplace_back(t[i], i);
    }

    sort(tidx.begin(), tidx.end());

    int last_finish = -1;
    int c = 0;

    for (int i = 0; i < n; ++i) {
        int j = tidx[i].second;

        if (s[j] >= last_finish) {
            c++;
            last_finish = t[j];
        }
    }

    cout << c << endl;
}