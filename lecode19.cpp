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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            if(head->next == nullptr and n == 1) return nullptr; 
            int cnt = 0;int p = n;
            stack<ListNode*> node;
            ListNode* res = head;
            while(head){
                node.push(head);
                head = head->next;
                cnt++;
            }
            while(--n) node.pop();
            if(p == cnt) {
                res = res->next;
                delete head;
            }            
            else{
                ListNode* temp = node.top();
                node.pop();
                node.top()->next = temp->next;
                delete temp;
            }
            return res;
        }
    };