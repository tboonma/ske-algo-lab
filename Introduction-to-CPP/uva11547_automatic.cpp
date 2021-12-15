#include <iostream>

using namespace std;

int main() {
    unsigned int t;
    int n;
    long result;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n;
        result = n * 567;
        result /= 9;
        result += 7492;
        result *= 235;
        result /= 47;
        result -= 498;
        
        // get digit in the ten column
        result /= 10;
        result %= 10;
        result = abs(result);
        cout << result << endl;
    }
}