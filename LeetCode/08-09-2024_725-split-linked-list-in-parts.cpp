class Solution {
private:
    int siz(ListNode* head){
        int cnt =0 ;
        while(head!=nullptr){
            cnt++;
            head=head->next;
        }
        return cnt;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = nullptr;
        vector<ListNode*>v(k);
        if(head==nullptr) return v;
        int len = siz(head);
        int c = len%k;
        len=len/k;
        int i=0;
        while(temp!=nullptr){
            int t = len;
            ListNode* p = temp;
            while(t-- and temp!=nullptr){
                prev = temp;
                temp = temp->next;
            }
            if(c>0 and temp!=nullptr){
                prev = temp;
                temp=temp->next;
                c--;
            }
            prev->next = nullptr;
            v[i]=p;
            i++;
        }
        return v;
    }
};
