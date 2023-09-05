/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node*curr=head;
        while(curr){
            Node*forw=curr->next;
            Node*newNode= new Node(curr->val);
            newNode->next=forw;
            curr->next=newNode;
            curr=forw;
        }
        curr=head;
        while(curr){
            Node*rand=curr->random;
            if(rand){
                curr->next->random=rand->next;
            }
            curr=curr->next->next;
        }
        Node*temp=new Node(-1);
        Node*dummy=temp;
        curr=head;
        while(curr){
            dummy->next=curr->next;
            dummy=dummy->next;
            curr->next=dummy->next;
            curr=curr->next;
        }
        return temp->next;
        
    }
};