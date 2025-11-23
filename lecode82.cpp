struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(-101,head);
        ListNode* cur = &dummy;
        while(cur->next and cur->next->next){
            if(cur->next->val == cur->next->next->val){
                int val = cur->next->val;
                while(cur->next and cur->next->val == val){
                    ListNode* temp = cur->next;
                    cur->next = cur->next->next;
                    delete temp;
                }
            }else cur = cur->next;
        }
        return dummy.next;
        
    }
};