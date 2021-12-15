#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

struct Direction {
    int start;
    int stop;
    int min_level;

    Direction(int start, int stop, int min_level)
        : start(start), stop(stop), min_level(min_level) {}
};

bool seen[100010];
map< int, vector<Direction> > station;

bool check_possible(int start, int stop, int level) {
    bool able = false;
    seen[start] = true;
    // cout << "Visited: ";
    // for (auto i=visited.begin(); i!=visited.end(); i++) {
    //     cout << *i << " ";
    // }
    // cout << "\n";
    if (start == stop) {
        return true;
    } else if (station[start].empty()) {
        // cout << "case1\n";
        return false;
    }
    for (auto i=station[start].begin(); i!=station[start].end(); i++) {
        if (level < i->min_level) {
            continue;
        } else if (seen[i->stop]) {
            continue;
        }
        able = check_possible(i->stop, stop, level);
        if (able)
            return true;
    }
    // cout << "case2\n";
    return false;
}

int main() {
    int n, m, q, start, stop, level_required, passenger_level;
    bool able;
    cin >> n >> m >> q;
    for (int i=0; i<m; i++) {
        cin >> start >> stop >> level_required;
        station[start].push_back(Direction(start, stop, level_required));
        station[stop].push_back(Direction(stop, start, level_required));
    }
    for (int i=0; i<q; i++) {
        for (int j=1; j<=m; j++)
            seen[j] = false;
        cin >> passenger_level >> start >> stop;
        able = check_possible(start, stop, passenger_level);
        if (able) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
}

/*
5 7 4
1 2 20 
1 4 1
2 4 7
2 3 3
3 4 9
5 3 2
5 4 10
*/