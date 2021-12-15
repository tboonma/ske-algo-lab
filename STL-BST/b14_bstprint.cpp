#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    bool printed;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val, bool printed=false, TreeNode* left=0, TreeNode* right=0)
        : val(val), printed(printed), left(left), right(right) {}
};

void insert(TreeNode*& r, int x) {
    if (!r)
        r = new TreeNode(x);
    else if (x < r->val)
        insert(r->left, x);
    else
        insert(r->right, x);
}

void printTree(TreeNode* r, int level=0) {
    if (!r)
        return;
    printTree(r->right, level+1);
    if (!(r->printed)) {
        for (int i = 0; i < level; i++)
            cout << "...";
        cout << "* " << r->val << endl;
        r->printed = true;
    }
    if (r->left) {
        printTree(r->left, level + 1);
        if (!(r->printed)) {
            for (int i = 0; i < level; i++)
                cout << "...";
            cout << "* " << r->val << endl;
            r->printed = true;
        }
    }
}

int main() {
    int N, temp;
    TreeNode* root=0;
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> temp;
        insert(root, temp);
    }
    printTree(root);
}