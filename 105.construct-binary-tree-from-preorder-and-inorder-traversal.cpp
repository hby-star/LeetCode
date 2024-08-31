/*
 * @lc app=leetcode.cn id=105 lang=cpp
 * @lcpr version=30204
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    unordered_map<int, int> pre2in;
    unordered_map<int, int> in2pre;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {

        for (int i = 0; i < preorder.size(); i++)
        {
            for (int j = 0; j < inorder.size(); j++)
            {
                if (preorder[i] == inorder[j])
                {
                    pre2in[i] = j;
                    in2pre[j] = i;
                }
            }
        }

        TreeNode *res = dfs(preorder, inorder, pre2in[0], 0, inorder.size() - 1);
        return res;
    }

    // 参数均基于 inorder
    TreeNode *dfs(vector<int> &preorder, vector<int> &inorder, int root, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }

        TreeNode *temp = new TreeNode(inorder[root]);
        if (in2pre[root] + 1 < preorder.size())
        {
            temp->left = dfs(preorder, inorder, pre2in[in2pre[root] + 1], left, root - 1);
        }
        else
        {
            temp->left = nullptr;
        }
        if (in2pre[root] + root - left + 1 < preorder.size())
        {
            temp->right = dfs(preorder, inorder, pre2in[in2pre[root] + root - left + 1], root + 1, right);
        }
        else
        {
            temp->right = nullptr;
        }
        return temp;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,9,20,15,7]\n[9,3,15,20,7]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */
