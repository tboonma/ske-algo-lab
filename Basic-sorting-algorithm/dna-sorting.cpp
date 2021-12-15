#include <iostream>
#include <cstring>
// #include <fstream>
using namespace std;

int main() {
    int m, n, range, this_num, next_num, time;
    cin >> m;
    // ofstream myfile;
    // myfile.open ("dna-sorting-output.txt");
    while (m--) {
        cin >> n >> range;
        string arr[range];
        int sorted_time[range];
        for (int i=0; i<range; i++) {
            cin >> arr[i];
        }
        char c[n];
        for (int i=0; i<range; i++) {
            strcpy(c, arr[i].c_str());
            bool changed;
            time = 0;
            while (true) {
                changed = false;
                for (int j=0; j<n-1; j++) {
                    this_num = c[j];
                    next_num = c[j+1];
                    if (this_num > next_num) {
                        c[j] = next_num;
                        c[j+1] = this_num;
                        time++;
                        changed = true;
                    }
                }
                if (!changed)
                    break;
            }
            sorted_time[i] = time;
            cout << c << " - " << time << endl;
        }
        while (true) {
            int print_idx = 0;
            int idx_value = sorted_time[0];
            for (int i=0; i<range; i++) {
                if (sorted_time[i] == -1)
                    continue;
                if (idx_value == -1) {
                    idx_value = sorted_time[i];
                    print_idx = i;
                }
                if (sorted_time[i] < idx_value) {
                    print_idx = i;
                    idx_value = sorted_time[i];
                }
            }
            if (idx_value == -1)
                break;
            cout << arr[print_idx] << endl;
            sorted_time[print_idx] = -1;
        }
        if (m > 0)
            cout << endl;
    }
}
