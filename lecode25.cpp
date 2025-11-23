#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* reverseKGroup(ListNode* head, int k) {
            if(!head || k == 1) return head;
            ListNode dummy(0,head);
            ListNode* cur = head;
            ListNode* pre = &dummy,*last = nullptr;//本组前一个，本组最后一个
            while(true)
            {
                int count = k;
                while(cur && count) {cur = cur->next;count--;}
                if(count) break;
                ListNode* prev = pre;
                ListNode* tail = head;
                //头插法
                for(int i = 0;i < k;i++)
                {
                    ListNode* nxt = head->next;
                    head->next = prev->next;
                    prev->next = head;
                    head = nxt;
                }
                tail->next = head;
                pre = tail;
            }
            return dummy.next;
        }
    };