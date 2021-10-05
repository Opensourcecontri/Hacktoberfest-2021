#include<iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* rvList(ListNode* head, int len){
    if(head == NULL || head->next == NULL) 
        return head;
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* nxt = head->next;
    int cnt = 0;
    while(cnt < len){
        cnt++;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        if(nxt)
            nxt = nxt->next;
    }
    head->next = curr;
    return prev;
}


ListNode* solve(ListNode* head, int k) {
    ListNode* new_head = rvList(head, k);
    ListNode* prev = head;
    ListNode* tmp = head->next;
    int cnt = 1;
    while(tmp){
        if(cnt % 2 == 0){
            prev->next = rvList(tmp, k);
            prev = tmp;
            tmp = tmp->next;
        }else{
            for(int i=0; i<k; i++){
                prev = tmp;
                tmp = tmp->next;
            }
        }
        cnt++;
    }
    return new_head;
}