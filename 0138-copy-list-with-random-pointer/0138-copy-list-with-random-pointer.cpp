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
        if(!head) return NULL;
        unordered_map<Node*, Node*>New;
        Node *curr= head;
        while(curr){
            New[curr] = new Node(curr->val);
            curr=curr->next;
        }
        curr=head;
        while(curr){
            New[curr]->next = New[curr->next];
            New[curr]->random = New[curr->random];
            curr = curr->next;
        }
        return New[head];
    }
};