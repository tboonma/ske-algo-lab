#include <iostream>
using namespace std;

int MAX_AMOUNT = 1000;

int main() {
    int amount, truck=0;
    cin >> amount;
    int box[amount];
    for (int i=0; i<amount; i++) {
        cin >> box[i];
    }
    int weight;
    for (int i=0; i<amount; i++) {
        if (box[i] == -1) continue;
        weight=box[i];
        box[i] = -1;
        for (int j=i+1; j<amount; j++) {
            if (box[j] == -1) continue;
            if (weight+box[j] <= MAX_AMOUNT) {
                weight += box[j];
                box[j] = -1;
            }
            if (weight == MAX_AMOUNT) break;
        }
        truck++;
    }
    cout << truck;
}