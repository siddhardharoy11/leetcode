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
    ListNode* partition(ListNode* head, int x) {
        ListNode * new1 = new ListNode(0);
        ListNode * new2 = new ListNode(0);
        ListNode * new1head = new1;
        ListNode * new2head = new2;
        while(head){
            if(head->val>=x){
                new1->next = head;
                new1 = new1->next;
            }
            else{
                new2->next = head;
                new2 = new2->next;
            }
            head = head->next;
        }
        new1->next = nullptr;
        new2->next=new1head->next;
        return new2head->next;
    }
};
