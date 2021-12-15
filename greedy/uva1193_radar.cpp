#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n, cases=0;
    long double d;
    cin >> n >> d;
    while (true) {
        if (n==0 && d==0)
            break;
        cases++;
        vector<pair<long double, long double>> point;
        vector<pair<long double, long double>> x_range;
        bool out_of_area = false;
        for (int i=0; i<n; i++) {
            long double x, y;
            cin >> x >> y;
            point.emplace_back(x, y);
            if (y > d) {
                out_of_area = true;
            }
        }
        if (out_of_area) {
            cout << "Case " << cases << ": " << -1 << endl;
            cin >> n >> d;
            continue;
        }
        for (int i=0; i<n; i++) {
            long double cart = sqrt(d*d - (point[i].second*point[i].second));
            x_range.emplace_back(make_pair(point[i].first - cart, point[i].first + cart));
        }
        sort(x_range.begin(), x_range.end(), [](const pair<long double, long double> &left, const pair<long double, long double> &right) {
            if (left.second == right.second)
                return left.first < right.first;
            return left.second < right.second;
        });
        long double x_end = x_range[0].second;
        int radar = 1;
        for (int i=1; i<n; i++) {
            if (x_range[i].first > x_end) {
                radar++;
                x_end = x_range[i].second;
            }
        }
        cout << "Case " << cases << ": " << radar << endl;
        cin >> n >> d;
    }
}