#include <iostream>
#include <string>
using namespace std;

bool is_palindrome(string);

int main() {
    string number;
    cin >> number;
    bool ans = is_palindrome(number);
    if (ans) cout << "yes";
    else cout << "no";
}

bool is_palindrome(string number) {
    int front = 0, back = number.length()-1;
    while (front < back) {
        if (number[front] != number[back]) {
            return 0;
        }
        front++; back--;
    }
    return 1;
}