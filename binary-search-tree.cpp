//
// Created by admin on 2018/11/3.
//

#include "TreeNode.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return nullptr;
        if (key > root->val)
            root->right = deleteNode(root->right, key);
        else if (key < root->val)
            root->left = deleteNode(root->left, key);
        else { //root.val == key
            if (!root->left)
                return root->right;
            else if (!root->right)
                return root->left;
            else { //target has tow children
                // root->val = getMin(root->right);
                // root->right = deleteNode(root->right, root->val);
                root->val = getMax(root->left);
                root->left = deleteNode(root->left, root->val);
            }
        }
        return root;
    }
private:
    int getMax(TreeNode* node){
        for (; node->right; node = node->right)
            ;
        return node->val;
    }

    int getMin(TreeNode* node){
        for (; node->left; node = node->left)
            ;
        return node->val;
    }
};



class KthLargest {
public:
    KthLargest(int k, vector<int> nums) {
        root = build(nums);
        this->k = k;
    }

    int add(int val) {
        createNode(root, val);
        return search(root, k);
    }

private:
    struct Node{
        int val;
        int cnt;
        Node* right;
        Node(int x): val(x), cnt(1), left(nullptr), right(nullptr){}
        Node* left;
    };

    Node* root;
    int k;

    Node* build(vector<int> nums){
        Node* root = nullptr;
        for (int e : nums)
            root = createNode(root, e);
        return root;
    }

    Node* createNode(Node* node, int val){
        if (!node)
            return new Node(val);
        node->cnt++;
        if (node->val > val){
            node->left = createNode(node->left, val);
        }
        else {
            node->right = createNode(node->right, val);
        }
        return node;
    }

    void inorder(Node* root){
        if (!root)
            return;
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }

    int search(Node* root, int k){
        cout << k << " ";
        int r = root->right ? root->right->cnt : 0;
        if (k == 1 && !root->right)
            return root->val;
        if (k == r + 1)
            return root->val;
        if (k-1 < r)
            return search(root->right, k);
        if (k-1 > r)
            return search(root->left, k - r - 1);
    }

};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */