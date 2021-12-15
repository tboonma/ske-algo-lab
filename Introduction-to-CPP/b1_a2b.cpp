#include <iostream>

using namespace std;

int main() {
    unsigned int first_number, last_number, sum=0;
    cin >> first_number >> last_number;
    for (int i=first_number; i<=last_number; i++) sum = sum + i;
    cout << sum;
}