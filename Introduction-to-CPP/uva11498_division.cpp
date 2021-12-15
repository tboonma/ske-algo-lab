#include <iostream>

using namespace std;

int main() {
    unsigned int queries=1;
    int dp_coor1, dp_coor2, coor1, coor2;
    while (queries)
    {
        cin >> queries;
        if (queries == 0) break;
        cin >> dp_coor1 >> dp_coor2;
        for (int i=0; i<queries; i++) {
            cin >> coor1 >> coor2;
            if (coor1 == dp_coor1 || coor2 == dp_coor2) cout << "divisa";
            else if (coor1 > dp_coor1 && coor2 > dp_coor2) cout << "NE";
            else if (coor1 > dp_coor1 && coor2 < dp_coor2) cout << "SE";
            else if (coor1 < dp_coor1 && coor2 > dp_coor2) cout << "NO";
            else if (coor1 < dp_coor1 && coor2 < dp_coor2) cout << "SO";
            cout << endl;
        }
    }
    
}