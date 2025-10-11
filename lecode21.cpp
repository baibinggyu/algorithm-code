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
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            if(list1 == nullptr && list2 == nullptr) return nullptr;
            if(list1 == nullptr) return list2;
            if(list2 == nullptr) return list1;
            queue<ListNode*> node01;
            queue<ListNode*> node02;
            ListNode* res = new ListNode(list1->val,nullptr);
            if(res->val > list2->val) {res = new ListNode(list2->val,nullptr);list2 = list2->next;}
            else list1 = list1->next;
            ListNode* ret = res;
            while(list1 && list2){
                if(list1->val < list2->val) {
                    res->next  = list1;
                    list1 = list1->next;
                    res = res->next;
                }
                else {
                    res->next = list2;
                    list2 = list2->next;
                    res = res->next;
                }
            }
            while(list1){
                res->next = list1;
                list1 = list1->next;
                res = res->next;
            }
            while(list2){
                res->next = list2;
                list2 = list2->next;
                res = res->next;
            }
            return ret;
        }   
    };