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
        ListNode* swapPairs(ListNode* head) {
            if(!head) return nullptr;
            if(!head->next) return head;
            ListNode* res = head->next;
            ListNode* temp = nullptr;
            while(head){
                if(head->next == nullptr) break;
                ListNode* first = head,*second = head->next,*node = second->next;
                if(temp) temp->next = second;
                second->next = first;
                first->next = node;
                temp = first;
                head = node;
            }
            return res;

        }
    };