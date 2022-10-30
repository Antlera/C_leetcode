/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        //画图！！！，注意顺序！！！
        auto dummy = new ListNode(-1);
        dummy->next = head;
        for(auto p = dummy;p->next&&p->next->next;){//只有后两个指针存在时才需要调换
            auto a = p->next, b = a->next;//先保存两个指针的位置
            p->next = b;
            a->next = b->next;
            b->next = a;
            p = a;
        }

        return dummy -> next;
    }
};
// @lc code=end

