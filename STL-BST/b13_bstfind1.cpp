#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val, TreeNode* left=nullptr, TreeNode* right=nullptr)
        : val(val), left(left), right(right) {}
};

void insert(TreeNode*& r, int x) {
    if (!r)
        r = new TreeNode(x);
    if (x < r->val)
        insert(r->left, x);
    else if (x > r->val)
        insert(r->right, x);
}

TreeNode* find(TreeNode* r, int x) {
    if (!r || r->val == x)
        return r;
    if (x < r->val)
        return find(r->left, x);
    return find(r->right, x);
}

int main() {
    int M, action, x;
    cin >> M;
    TreeNode* root;
    for (int i=0; i<M; i++) {
        cin >> action >> x;
        if (action == 1) {
            insert(root, x);
        }
        else if (action == 2) {
            if (find(root, x))
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
    }
}