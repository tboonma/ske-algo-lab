#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string area[35];
bool visited[35][35] = {0};
int edge_x, edge_y, amount;
bool is_good = false, is_excellent = false;

void travel(int curr_y, int curr_x) {
    if (area[curr_y][curr_x] == '#' || visited[curr_y][curr_x])
        return;
    amount++;
    visited[curr_y][curr_x] = 1;
    if (area[curr_y][curr_x] == '*' || area[curr_y][curr_x] == '$') {
        if (is_good)
            is_excellent = true;
        else
            is_good = true;
    }
    area[curr_y][curr_x] = '#';
    if (curr_x < edge_x-1) {
        travel(curr_y, curr_x+1);
    }
    if (curr_y < edge_y-1) {
        travel(curr_y+1, curr_x);
    }
    if (curr_x > 0) {
        travel(curr_y, curr_x-1);
    }
    if (curr_y > 0) {
        travel(curr_y-1, curr_x);
    }
}

int main() {
    int good_land=0, excellent_land=0;
    cin >> edge_y >> edge_x;
    for (int i=0; i<edge_y; i++) {
        cin >> area[i];
    }
    for (int i=0; i<edge_y; i++) {
        for (int j=0; j<edge_x; j++) {
            if (area[i][j] == '#')
                continue;
            is_good = false;
            is_excellent = false;
            amount = 0;
            travel(i, j);
            if (is_excellent)
                excellent_land += amount;
            else if (is_good) {
                good_land += amount;
            }
        }
    }
    cout << excellent_land << " " << good_land;
}