#include <iostream>
using namespace std;

struct Ball {
    int id;
    int color;
    Ball* next;

    Ball(int int_id, int int_color, Ball* n=0)
      : id(int_id), color(int_color), next(n) {}
};

Ball* ball = nullptr;

void insert(int id, int insert_after, int color)
{
    if (ball == nullptr) {
        Ball* temp = new Ball(1, color);
        ball = temp;
        return;
    }
    Ball* temp = ball;
    while (true) {
        if (temp->next == nullptr) {
            Ball* temp2 = new Ball(id, color);
            temp->next = temp2;
            return;
        }
        if (temp->id == insert_after) {
            Ball* temp2 = new Ball(id, color, temp->next);
            temp->next = temp2;
            return;
        }
        temp = temp->next;
    }
}

int main() {
    int n, m, ball_id=1, ball_color, after;
    cin >> n >> m;
    for (int i=0; i<n; i++)
    {
        cin >> ball_color;
        insert(ball_id, ball_id-1, ball_color);
        ball_id++;
    }
    for (int i=0; i<m; i++) {
        cin >> ball_color >> after;
        insert(ball_id, after, ball_color);
        ball_id++;
    }
    while (ball != nullptr) {
        cout << ball->id << endl;
        ball = ball->next;
    }
}