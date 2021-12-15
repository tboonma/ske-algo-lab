#include <iostream>
using namespace std;

int main() {
    // int score;
    // cin >> score;
    // if (score >= 80) cout << "Excellent job.";
    // else if (score >= 50) cout << "Okay.";
    // else cout << "Please try harder.";
    int a[6] = {1,2,3,4,5};
    int i = max_element(a, a+6);
    cout << i;
}