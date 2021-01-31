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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr){
            return l2;
        }
        if(l2==nullptr){
            return l1;
        }
        if(l1->val>l2->val){
            l2->next = mergeTwoLists(l2->next,l1); 
            return l2;}
        l1->next=mergeTwoLists(l1->next,l2);
        return l1;
    }
};

//两两比较，谁大就套谁，递归
//设定两个节点，头节点和尾节点，用循环来做，迭代