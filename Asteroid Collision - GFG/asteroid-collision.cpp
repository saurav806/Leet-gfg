//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        // code here
        stack<int>q;
        for(auto it: asteroids){
            if(it>0)
                q.push(it);
            else{
                bool flag=false;
                while(!q.empty() && abs(it)>=q.top() && q.top()>0){
                    
                    if(q.top()==abs(it)){
                        flag=true;
                        q.pop();
                        break;
                    }
                    q.pop();
                }
                if(flag) continue;
                if(q.empty() || q.top()<0)
                    q.push(it);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.top());
            q.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends