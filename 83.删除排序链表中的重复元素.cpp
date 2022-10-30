/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
        dummy->next =head;//虚拟头结点，排除判断
        auto p = dummy;
        while (p->next)
        { 
            auto q = p->next->next;//p-next为当前指针，q为下个指针
            while (q && q->val == p->next->val) q = q->next;//若下个指针与当前相同则跳过，直到找到一个不相同的
            p->next->next = q;//连接至下一个不同的结点
            p = p->next;//继续遍历
        }
        return dummy->next; 
    }
};
// @lc code=end

