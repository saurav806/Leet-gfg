//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:
    struct node {
        int key;
        int value;
        node *prev;
        node *next;
        node(int key1, int value1){
            key=key1;
            value=value1;
        }
    };
    
    node *head = new node(0,0);
    node *tail = new node(0,0);
    
    unordered_map<int, node*>m;
    int size;

    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        // code here
        size=cap;
        head->next=tail;
        tail->prev=head;
    }
    
    //Function to return value corresponding to the key.
    int GET(int key)
    {
        // your code here
        if(m.count(key)){
            node *exist= m[key];
            int val=exist->value;
            deleteNode(exist);
            addNode(key, val);
            m.erase(key);
            m[key]= head->next;
            return val;
        }
        return -1;
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        // your code here   
        if(m.count(key)){
            node *exist = m[key];
            m.erase(key);
            deleteNode(exist);
        }
        
        if(m.size() == size){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        addNode(key, value);
        m[key]= head->next;
    }
    
    void addNode(int key, int value){
        node *create= new node(key, value);
        create->next= head->next;
        head->next->prev= create;
        head->next= create;
        create->prev= head;
    }
    
    void deleteNode(node * del){
        del->prev->next= del->next;
        del->next->prev= del->prev;
        delete del;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends