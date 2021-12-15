#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, action, bonus, angel=0;
    cin >> n >> m;
    vector<int> player;
    for (int i=0; i<n; i++) {
        player.push_back(0);
    }
    for (int i=0; i<m; i++) {
        cin >> action;
        if (action == 0) {
            angel = 0;
        }
        else if (action == 1) {
            angel++;
            if (angel >= player.size())
                angel = 0;
        }
        else if (action == 2) {
            player.insert(player.begin()+angel+1, 0);
        }
        else if (action == 3) {
            cin >> bonus;
            player[angel] += bonus;
        }
    }
    for (int i=0; i<player.size(); i++) {
        cout << player[i] << " ";
    }
}