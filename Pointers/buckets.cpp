#include <iostream>
using namespace std;

int min_bucket(int* b) {
    int min = *b;
    int number = 0;
    for (int i=0; i<5; i++) {
        if (*(b+i) < min) {
            min = *(b+i);
            number = i;
        }
    }
    return number;
}

int main() {
    int n, b;
    cin >> n;
    int jar;
    int bucket[5] = {0, 0, 0, 0, 0};
    int tank = 0;
    for (int i=0; i<n; i++) {
        cin >> jar;
        b = min_bucket(bucket);
        bucket[b] += jar;
        if (bucket[b] >= 1000) {
            tank += 1000;
            bucket[b] = 0;
        }
    }
    cout << tank;
}