#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

bool visited[100010];
vector<int> component[100010];

void traversal(int number) {
    if (visited[number])
        return;
    visited[number] = true;
    for (auto i=component[number].begin(); i!=component[number].end(); i++) {
        traversal(*i);
    }
}

int main() {
    int n, m, a, b;
    cin >> n >> m;
    int amount = 0;
    
    memset(visited, false, n+1);
    for (int i=0; i<m; i++) {
        cin >> a >> b;
        component[a].push_back(b);
        component[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        int pos = i;
        if (visited[pos])
            continue;
        amount++;
        traversal(i);
    }
    cout << amount;
}