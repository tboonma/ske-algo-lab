#include <iostream>
using namespace std;

int main() {
    int n, m, num, first_pos, last_pos, id=1, color, insert_id;
    bool firstnum = true;
    cin >> n >> m;
    int arr[n+m+1];
    for (int i=0; i<=n+m; i++) {
        arr[i] = -1;
    }
    arr[0] = 1;
    for (int i=0; i<n; i++) {
        cin >> num;
        if (firstnum) {
            first_pos = id;
            last_pos = id;
            firstnum = false;
            id++;
            continue;
        }
        arr[last_pos] = id;
        last_pos = id;
        id++;
    }
    for (int i=0; i<m; i++) {
        cin >> color >> insert_id;
        if (firstnum) {
            first_pos = id;
            last_pos = id;
            firstnum = false;
            id++;
            continue;
        }
        if (arr[insert_id] == -1) {
            arr[insert_id] = id;
            id++;
            continue;
        }
        arr[id] = arr[insert_id];
        arr[insert_id] = id;
        id++;
    }
    cout << first_pos << endl;
    while (true) {
        if (arr[first_pos] == -1)
            break;
        first_pos = arr[first_pos];
        cout << first_pos << endl;
    }
}