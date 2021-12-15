#include <iostream>
#include <math.h>

using namespace std;

int next_prime(int number);

int main() {
    int number;
    cin >> number;
    cout << next_prime(number);
}

int next_prime(int number) {
    int next_number = number + 1;
    bool is_prime = true;
    for (int i=2; i<next_number; i++) {
        if (next_number%i == 0) {
            is_prime = false;
            break;
        }
    }
    if (is_prime) {
        return next_number;
    }
    else {
        return next_prime(next_number);
    }
}