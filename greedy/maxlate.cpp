#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<long, long>> task;
    for (int i=0; i<N; i++) {
        int deadline, duration;
        cin >> deadline >> duration;
        task.emplace_back(deadline, duration);
    }
    sort(task.begin(), task.end());
    int pay = 0;
    int time_used = 0;
    int time_now;
    for(int i=0;i<N; i++){
        time_used += task[i].second;
        time_now = task[i].first;
        if(time_used - time_now > 10){
            if(pay < time_used - time_now - 10){
                pay = time_used - time_now - 10;
            }
        }
    }
    cout << pay * 1000;
}