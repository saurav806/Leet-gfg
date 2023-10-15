//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

Node *constructTree (int [], int );

void printInorder (Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
	

}

int main ()
{   
    int t,n;
   scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int post[n];
        for(int i=0;i<n;i++)
        scanf("%d",&post[i]);

    Node* root = constructTree(post, n);

	printInorder(root);
    printf("\n");
}
	return 0;
}

// } Driver Code Ends


/*struct Node
{
	int data;
	Node *left, *right;
};*/

Node *tree(int i, int n, vector<int>&post){
    if(i>n) return NULL;
    int mid = (i+n)/2;
    Node * root = new Node(post[mid]);
    root->left = tree(i,mid-1,post);
    root->right = tree(mid+1, n, post);
    return root;
}

Node *constructTree (int post[], int size)
{
//code here
    vector<int>pp;
    for(int i=0;i<size;i++){
        pp.push_back(post[i]);
    }
    sort(pp.begin(), pp.end());
    return tree(0,pp.size()-1,pp);
}