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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right ) return head;
        /*    Add Dummy node ( To handle the case when left =1 )
         dummy -> 1 -> 2 -> 3 -> 4 -> 5 -> 6
        After first loop , LEFT_PTR will be pointing to 1 and LEFT to */
        //inserting dummy node in front
        ListNode *dummy = new ListNode(0);
        dummy->next =head;
        //counter will start from dummy node hence set to 0 and not 1
        int count=0;
        ListNode* temp=dummy;
        ListNode* it= NULL;
        while(count<left ){
            it=temp;
            temp=temp->next;
            count++;
        }
        ListNode* curr=temp;
        ListNode* next=temp;
        ListNode* prev=it;
        int countR=left;
        while(countR<=right){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            countR++;
        }
        
        it->next=prev;
        temp->next=curr;
        return dummy->next;
    }
};