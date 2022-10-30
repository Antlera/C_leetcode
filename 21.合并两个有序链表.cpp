/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        auto dummy = new ListNode(-1);//有头结点特判，增加虚结点

        auto p = dummy, l1 = list1, l2 = list2;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
                p = p->next = l1, l1 = l1->next;
            else
                p = p->next = l2, l2 = l2->next;
        }
        if (l1)
            p->next = l1;
        if (l2)
            p->next = l2;
        
        return dummy->next;
    }
};
// @lc code=end
