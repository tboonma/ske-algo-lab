#include <iostream>
#include <set>
using namespace std;

int main() {
    int N, M, temp;
    while (true) {
        cin >> N >> M;
        if (N==0 && M==0)
            break;
        set<int> jack;
        int sell = 0;
        for (int i = 0; i < N; i++) {
            cin >> temp;
            jack.insert(temp);
        }
        for (int i = 0; i < M; i++) {
            cin >> temp;
            if ( jack.find(temp) != jack.end() ) {
                sell++;
            }
        }
        cout << sell << endl;
    }
}