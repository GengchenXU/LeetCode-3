//
// Created by admin on 2018/10/13.
//
#include <iostream>
#include <vector>
#include <algorithm>
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

    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr){
            return false;
        }
        if (root->val == sum && !root->right && !root->left)
            return true;
        bool left = hasPathSum(root->left, sum - root->val);
        bool right = hasPathSum(root->right, sum - root->val);
        return left || right;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, 0, inorder.size(), postorder, 0, postorder.size());

    }

private:
    TreeNode* helper(vector<int> &inorder, int infront, int intail, vector<int> &postorder, int posfront, int postail);
    bool isMirror(TreeNode* left, TreeNode* right);
};

TreeNode* Solution::helper(vector<int> &inorder, int infront, int intail, vector<int> &postorder, int posfront, int postail){
    if (infront == intail || posfront == postail)
        return nullptr;
    int mid = postorder[postail - 1];

    auto f = find(inorder.begin() + infront, inorder.begin() + intail, mid);

    auto dis = f - inorder.begin() - infront;

    auto* root = new TreeNode(mid);
    root -> left = helper(inorder, infront, static_cast<int>(infront + dis), postorder, posfront,
                          static_cast<int>(posfront + dis));
    root -> right = helper(inorder, static_cast<int>(infront + dis + 1), intail, postorder,
                           static_cast<int>(posfront + dis), postail - 1);
    return root;
}

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
    TreeNode c(2), d(3), e(1);
//    TreeNode b(2, &c, &d);
    TreeNode a(4, &c, &e);
    Solution s;
//    cout << s.maxDepth(&a) << endl;
//    cout << s.isSymmetric(&a) << endl;
    cout << s.hasPathSum(&a, 6) << endl;
    return 0;
}