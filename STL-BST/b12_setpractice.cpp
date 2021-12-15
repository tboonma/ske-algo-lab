#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m, temp, diff_upper, diff_lower;
    set<int> integers;
    set<int>::iterator lower, upper, it;
    cin >> n >> m;
    int ans[m];
    for (int i=0; i<n; i++) {
        cin >> temp;
        integers.insert(temp);
    }
    for (int i=0; i<m; i++) {
        cin >> temp;
        lower = integers.lower_bound(temp);
        upper = integers.upper_bound(temp);
        if (upper == integers.end()) {
            ans[i] = *(--upper);
            continue;
        }
        if (*(lower) == temp) {
            ans[i] = temp;
            continue;
        }
        if (lower != integers.begin())
            lower--;
        diff_upper = *(upper) - temp;
        diff_lower = temp - *(lower);
        if (diff_lower <= diff_upper)
            ans[i] = *lower;
        else
            ans[i] = *upper;
    }
    for (int i=0; i<m; i++) {
        cout << ans[i] << endl;
    }
}