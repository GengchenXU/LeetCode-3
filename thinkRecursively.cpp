//
// Created by admin on 2018/10/13.
//
#include <iostream>
#include "TreeNode.h"

using namespace std;

class Solution{
public:
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;

        return std::max(maxDepth(root->right), maxDepth(root->left)) + 1;
    }

    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        else
            return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode* left, TreeNode* right);
};

bool Solution::isMirror(TreeNode* left, TreeNode* right){
    if (left == nullptr && right == nullptr)
        return true;
    if (!left || !right)
        return false;

    if (left->val == right->val){
        bool inPair = isMirror(left->right, right->left);
        bool outPair = isMirror(right->right, left->left);
        return inPair && outPair;
    } else {
        return false;
    }
}

int main() {
    TreeNode c(1), d(3), e(1);
//    TreeNode b(2, &c, &d);
    TreeNode a(4, &c, &e);
    Solution s;
//    cout << s.maxDepth(&a) << endl;
    cout << s.isSymmetric(&a) << endl;
    return 0;
}