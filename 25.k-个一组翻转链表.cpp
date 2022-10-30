/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto dummy = new ListNode(-1);
        dummy->next = head;
        for(auto p = dummy;;){
            auto q = p;
            for(int i = 0; i < k && q;i++) q = q->next;
            if (!q) break;//测试一下之后是否足够k个
            auto a = p->next, b = a->next;//从p的下一个，找两个
            //两个结点指针不断向后移动
            for(int i = 0;i < k - 1;i++){
                auto c = b->next;//保存b的下一个
                b ->next = a;//反向指针
                a = b,b =c;//移动两个结点指针
            }
            auto c = p->next;//保存p的下一个，即转换后的尾部
            p->next = a, c->next = b;//p接头，尾接下一个头
            p = c;
        }
        return dummy->next;
    }
};
// @lc code=end

