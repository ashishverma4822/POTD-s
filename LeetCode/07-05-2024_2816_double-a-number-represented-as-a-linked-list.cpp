class Solution {
private:
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr ,*frw = nullptr;
        while(curr!=nullptr){
            frw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = frw;
        }
        return prev;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        head = reverse(head);
        ListNode* temp = head,*prev=nullptr;
        int carry = 0; 
        while(temp!=nullptr){
            int t = temp->val*2 + carry;
            temp->val = t%10;
            carry = t/10;
            prev=temp;
            temp=temp->next;
        }
        if(carry){
            prev->next=new ListNode(carry);
        }
        return reverse(head);
    }
};
