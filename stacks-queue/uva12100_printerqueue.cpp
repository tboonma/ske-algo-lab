#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int test, n, m;
    cin >> test;
    while (test-- > 0) {
        cin >> n >> m;
        int time = 0, p[n];
        queue<int> print_queue;
        for (int i=0; i<n; i++) {
            cin >> p[i];
            print_queue.push(p[i]);
        }
        sort(p, p+n);
        while(true) {
            if (p[n-1] > print_queue.front()) {
                print_queue.push(print_queue.front());
                print_queue.pop();
                if (m == 0)
                    m = n-1;
                else
                    m--;
            }
            else {
                print_queue.pop();
                time++;
                n--;
                if (m == 0)
                    break;
                else
                    m--;
            }
        }
        cout << time << endl;
    }
}
