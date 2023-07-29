//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  
    void parentFind(Node* root, Node* &tar, map<Node*, Node*>&parent, int target){
        if(root==NULL) return ;
        if(root->data==target)
            tar=root;
        if(root->left){
            parent[root->left]=root;
            parentFind(root->left,tar,parent,target);
        }
        if(root->right){
            parent[root->right]=root;
            parentFind(root->right,tar,parent,target);
        }
    }
    
    int burn(Node* root, map<Node*, Node*>&parent){
        queue<Node*>q;
        q.push(root);
        map<Node*, bool>visited;
        visited[root]=1;
        int ans=0;
        while(!q.empty()){
            // Node* node = q.front();
            // q.pop();
            int n=q.size();
            bool flag=0;
            while( n-- >0){
                Node* node= q.front();
                q.pop();
                if(node->left && !visited[node->left]){
                    visited[node->left] = 1;
                    q.push(node->left);
                    flag=1;
                }
                if(node->right && !visited[node->right]){
                    visited[node->right] = 1;
                    q.push(node->right);
                    flag=1;
                }
                if(parent[node] && !visited[parent[node]]){
                    visited[parent[node]] =1;
                    q.push(parent[node]);
                    flag=1;
                }
            }
            if(flag==1) ans++;
        }
        return ans;
    }
    
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        Node* tar ;
        map<Node*, Node*>parent;
        parent[root]=NULL;
        parentFind(root,tar,parent, target);
        int ans= burn(tar,parent);
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends