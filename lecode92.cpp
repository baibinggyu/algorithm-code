struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#include <deque>
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head->next) return head;
        ListNode* dummy = new ListNode(-1,head);
        int len = right - left + 1;
        ListNode* cur = dummy;
        ListNode* preNode = nullptr;
        while(left--){  
            if (left == 0) preNode = cur;
            cur = cur->next;    
        }
        std::deque<ListNode*> deque;
        while(len--){
            deque.push_back(cur);
            cur = cur->next;
        }
        while(!deque.empty()){
            preNode->next = deque.back();
            deque.pop_back();
            preNode = preNode->next;
        }
        preNode->next = cur;
        
        return dummy->next;
    }
};

