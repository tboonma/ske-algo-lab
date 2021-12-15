//
// Created by Tawan Boonma on 25/11/2021 AD.
//

//
// Created by NoBoomTa on 12/26/2020.
//

#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
int main(){
    int n;
    cin >> n;
    vector< pair <int,int> > vect;
    for(int op = 0; op<n; op++){
        int D, use;
        cin >> D >> use;
        vect.emplace_back(D, use );
    }
    sort(vect.begin(), vect.end());

    int pay =0;
    int time_now=0;

    for(auto & i : vect){

        time_now += i.second;
        if(time_now - i.first > 10){
            if(pay < (time_now - i.first - 10) * 1000){
                pay = (time_now - i.first - 10) * 1000;
            }
        }
    }
    cout << pay;
}