#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Road {
    int start;
    int stop;
    int speed;

    Road(int start, int stop, int speed)
        : start(start), stop(stop), speed(speed) {}
};

map< int, vector<Road> > city;
int speed_limit;
bool visited[2000010];

bool check_path(int start, int stop) {
    visited[start] = true;
    bool able;
    if (start == stop)
        return true;
    if (city[start].empty()) {
        return false;
    }
    for (auto i=city[start].begin(); i!=city[start].end(); i++) {
        if (visited[i->stop]) {
            continue;
        }
        able = check_path(i->stop, stop);
        if (able)
            return true;
    }
    return false;
}

int main() {
    int n, m, q, road1, road2, speed, start, stop;
    cin >> n >> m >> speed_limit >> q;
    for (int i=0; i<m; i++) {
        cin >> road1 >> road2 >> speed;
        if (speed > speed_limit)
            continue;
        Road road = Road(road1, road2, speed);
        Road another_road = Road(road2, road1, speed);
        city[road1].push_back(road);
        city[road2].push_back(another_road);
    }
    for (int i=0; i<q; i++) {
        for (int j=0; j<m; j++) {
            visited[j] = false;
        }
        cin >> start >> stop;
        if (check_path(start, stop)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
}

/*
5 5 80 100
1 3 0
1 2 10
3 2 150
3 4 100
4 5 10
*/