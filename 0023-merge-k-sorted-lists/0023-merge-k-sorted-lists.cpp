/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL && list2==NULL)return NULL;
        if(list1==NULL)return list2;
        if(list2==NULL)return list1;
        ListNode*head=NULL;
        ListNode*tail=NULL;
        while(list1 && list2){
            if(list1->val<=list2->val){
                if(head==NULL){
                    head=list1;
                    tail=list1;
                }
                else{
                    tail->next=list1;
                    tail=tail->next;
                }
                list1=list1->next;
            }
            else{
                if(head==NULL){
                    head=list2;
                    tail=list2;
                }
                else{
                    tail->next=list2;
                    tail=tail->next;
                }
                list2=list2->next;
            } 
        }
        if(list1){
            tail->next=list1;
        }
        if(list2){
            tail->next=list2;
        }
        return head;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int sz=lists.size();
        if(sz==0)return NULL;
        if(sz==1)return lists[0];
        ListNode*head=mergeTwoLists(lists[0],lists[1]);
        for(int i=2;i<sz;i++){
            head=mergeTwoLists(head,lists[i]);
        }
        return head;
    }
};