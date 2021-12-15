#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n, num;
    bool exit_loop = false;
    while (true) {
        cin >> n;
        if (n == 0)
            break;
        stack<int> train;
        while (true) {
            int last_train = 0;
            for (int i=0; i<n; i++) {
                cin >> num;
                if (num == 0) {
                    exit_loop = true;
                    break;
                }
                if (train.empty() || train.top() != num) {
                    for (int j=last_train+1; j<=num; j++) {
                        train.push(j);
                        last_train = j;
                    }
                }
                if (train.top() == num)
                    train.pop();
            }
            if (exit_loop) {
                exit_loop = false;
                cout << endl;
                break;
            }
            if (train.empty()) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
                while (!train.empty())
                    train.pop();
            }
        }
    }
}