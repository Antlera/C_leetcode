/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

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
class Solution {
public:
    // ListNode* removeNthFromEnd(ListNode* head, int k) {
    //     auto dummy = new ListNode(-1,head);
    //     int n = 0;
    //     for(auto p = dummy;p; p = p->next)
    //         n++;
    //     auto p = dummy;
    //     for (int i = 0; i < n - k - 1; i++)
    //         p = p->next;
    //     p->next = (p->next)->next;
    //     return dummy->next;
    // }
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        ListNode *nodes[31];
        auto dummy = new ListNode(-1,head);
        int n = 0;
        for (auto p = dummy; p; p = p->next)
            nodes[n++] = p;
        auto p = nodes[n - k - 1];
        p->next = (p->next)->next;
        return dummy->next;
    }
};
// @lc code=end

