#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, speed_limit, q, road1, road2, speed, start, stop;
    cin >> n >> m >> speed_limit >> q;
    vector<int> city[n+1];
    for (int i=0; i<m; i++) {
        cin >> road1 >> road2 >> speed;
        if (speed > speed_limit)
            continue;
        cout << "1: ";
        for (auto j=city[road2].begin(); j!=city[road2].end(); j++) {
            cout << *j << " ";
            city[road1].push_back(*j);
            city[*j].push_back(road1);
        }
        cout << endl << "2: ";
        for (auto j=city[road1].begin(); j!=city[road1].end(); j++) {
            cout << *j << " ";
            city[road2].push_back(*j);
            city[*j].push_back(road2);
        }
        cout << endl;
        city[road1].push_back(road2);
        city[road2].push_back(road1);
    }
    for (int i=0; i<q; i++) {
        cin >> start >> stop;
        if (find(city[start].begin(), city[start].end(), stop) != city[start].end()) {
            cout << "yes" << endl;
        } else {
            for (auto i=city[start].begin(); i!=city[start].end(); i++) {
                cout << *i << " ";
            }
            cout << endl;
            cout << "no" << endl;
        }
    }
}

/*
5 6 80 3
1 3 0
1 2 10
3 2 150
3 4 100
4 5 10
5 3 40
*/