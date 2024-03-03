class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int len = 0;
        while(temp!=nullptr){
            len++;
            temp=temp->next;
        }
        if(n>len) return head;
        len = len - n;
        temp=head;
        ListNode* prev = nullptr;
        while(len--){
            prev = temp;
            temp=temp->next;
        }
        if(prev!=nullptr){
            prev->next=temp->next;
            delete(temp);
        }
        else return temp->next;
        return head;
    }
};
