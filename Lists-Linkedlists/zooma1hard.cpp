#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ball;

int getIndex(vector<int> v, int index)
{
    vector<int>::iterator itr = find(v.begin(), v.end(), index);
    if (itr != v.cend()) {
        return distance(v.begin(), itr);
    }
    else {
        return v.size()-1;
    }
}

int main() {
    int n, m, ball_id=1, ball_color, after, index;
    cin >> n >> m;
    for (int i=0; i<n; i++)
    {
        cin >> ball_color;
        ball.push_back(ball_id);
        ball_id++;
    }
    for (int i=0; i<m; i++) {
        cin >> ball_color >> after;
        index = getIndex(ball, after);
        ball.insert(ball.begin()+index+1, ball_id);
        ball_id++;
    }
    for (int i=0; i<ball.size(); i++) {
        cout << ball[i] << endl;
    }
}