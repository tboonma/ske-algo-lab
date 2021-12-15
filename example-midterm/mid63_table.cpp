#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n][n], sum_row[n];
    for (int i=0; i<n; i++) {
        int summ = 0;
        for (int j=0; j<n; j++) {
            cin >> arr[i][j];
            summ += arr[i][j];
        }
        sum_row[i] = summ;
    }
    int sum_of_alls = 0;
    for (int i=0; i<n; i++) {
        int countn = count(sum_row, sum_row+n, sum_row[i]);
        if (countn > 1)
            sum_of_alls = sum_row[i];
    }
    int problem_row, problem_col;
    for (int i=0; i<n; i++) {
        if (sum_row[i] != sum_of_alls)
            problem_row = i;
    }
    for (int j=0; j<n; j++) {
        int sum_this_col = 0;
        for (int i=0; i<n; i++) {
            sum_this_col += arr[i][j];
        }
        if (sum_this_col != sum_of_alls) {
            problem_col = j;
        }
    }
    cout << arr[problem_row][problem_col];
}