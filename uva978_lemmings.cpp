#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n > 0) {
        int b, sg, sb, temp;
        cin >> b >> sg >> sb;
        multiset<int> green, blue;
        for (int i=0; i<sg; i++) {
            cin >> temp;
            green.insert(temp);
        }
        for (int i=0; i<sb; i++) {
            cin >> temp;
            blue.insert(temp);
        }
        while (!green.empty() && !blue.empty()) {
            int fight = min(b, (int)min(green.size(), blue.size()));
            vector<int> blue_fought;
            vector<int> green_fought;
            for (int i=0; i<fight; i++) {
                auto blue_hp = blue.end();
                auto green_hp = green.end();
                blue_hp--; green_hp--;
                if (*(blue_hp) > *(green_hp)) {
                    blue_fought.push_back(*(blue_hp) - *(green_hp));
                } else if (*(green_hp) > *(blue_hp)) {
                    green_fought.push_back(*(green_hp) - *(blue_hp));
                }
                blue.erase(blue_hp);
                green.erase(green_hp);
            }
            for (auto i : blue_fought) blue.insert(i);
            for (auto i : green_fought) green.insert(i);
            blue_fought.clear();
            green_fought.clear();
        }
        if (blue.empty() && green.empty()) {
            cout << "green and blue died\n";
        } else if (blue.empty()) {
            cout << "green wins\n";
            for (auto i=green.rbegin(); i!=green.rend(); i++) {
                cout << *i << endl;
            }
        } else {
            cout << "blue wins\n";
            for (auto i=blue.rbegin(); i!=blue.rend(); i++) {
                cout << *i << endl;
            }
        }
        blue.clear();
        green.clear();
        n--;
        if (n>0)
            cout << endl;
    }
}