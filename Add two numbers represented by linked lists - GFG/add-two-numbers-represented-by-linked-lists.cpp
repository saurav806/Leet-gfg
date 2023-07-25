//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* rev(Node * head){
        if(head==NULL || head->next==NULL)
            return head;
            
        Node *curr=head;
        Node *pre=NULL;
        
        while(curr!=NULL){
            Node *temp=curr->next;
            curr->next=pre;
            pre=curr;
            curr=temp;
        }
        return pre;
    }
    
    
    Node* helper(Node* head1, Node* head2){
        int carry=0;
        Node* ans=new Node(0);
        Node* result= ans;
        while(head1 != NULL || head2!=NULL || carry != 0){
            int d1= (head1 != NULL)?head1->data:0;
            int d2= (head2 != NULL)?head2->data:0;
            int sum= d1 + d2 + carry;
            int rem= sum%10;
            carry = sum/10;
            Node * temp = new Node(rem);
            ans->next=temp;
            ans=ans->next;
            
            head1=(head1 != NULL) ? head1->next:NULL;
            head2=(head2 != NULL) ? head2->next:NULL;
        }

        return result->next;
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first=rev(first);
        second=rev(second);
        Node *ans=helper(first,second);
        return rev(ans);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends