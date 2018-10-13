//
// Created by admin on 2018/10/13.
//

#ifndef LEETCODE_TREENODE_H
#define LEETCODE_TREENODE_H


class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r){}
};


#endif //LEETCODE_TREENODE_H
