/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates(ListNode* head) {
        auto dummy = new ListNode(-1);
        dummy->next = head;//虚拟头结点
        auto p = dummy;
        while (p->next)
        {
            auto q = p->next->next;//下一个指针
            while(q && q -> val == p->next->val) q= q->next;//找到下一个不相同的
            if(p->next->next == q) p = p->next;//若是相邻结点说明没有重复元素
            else p->next = q;//若有则直接跳过,则覆盖当前指针变为找到的新元素,或者说将p直接连接至q
        }
        return dummy ->next;
        
    }
};
// @lc code=end

