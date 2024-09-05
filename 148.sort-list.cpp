/*
 * @lc app=leetcode.cn id=148 lang=cpp
 * @lcpr version=30204
 *
 * [148] 排序链表
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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }

        ListNode *temp = head;
        vector<int> array;

        while (temp)
        {
            array.push_back(temp->val);
            temp = temp->next;
        }

        sort(array.begin(), array.end());

        temp = head;
        int count = 0;
        while (temp)
        {
            temp->val = array[count];

            temp = temp->next;
            count++;
        }

        return head;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [-1,5,3,4,0]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */
