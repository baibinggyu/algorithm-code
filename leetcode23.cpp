// Nlogk
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
    ListNode* combination(ListNode* node01,ListNode* node02)
    {
        if(!node01 || !node02) return node01?node01:node02?node02:nullptr;
        ListNode* head = node01;
        if(head->val > node02->val) {head = node02;node02 = node02->next;}
        else node01 =node01->next;
        ListNode* node = head;
        while(node01 && node02)
        {
           if(node01->val < node02->val){
            node->next = node01;
            node01 = node01->next;
            node = node->next;
           }
           else{
            node->next = node02;
            node02 = node02->next;
            node = node->next;
           }
        }
        if(node01) node->next = node01;
        else node->next = node02;
        return head;
    }
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            if(lists.size() == 0) return nullptr;
            while(lists.size() > 1)
            {
                vector<ListNode*> tempList;
                for(int i = 0 ;i < lists.size();i+=2)
                {
                    ListNode* node01 = lists[i];
                    ListNode* node02 = nullptr;
                    if(i + 1 < lists.size())
                        node02 = lists[i+1];
                    tempList.push_back(combination(node01,node02));
                }
                lists = tempList;
            }
            return lists[0];
        }
    };