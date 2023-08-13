//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool Search(int N, vector<int>& arr, int key) {
        // Code here
        int start = 0;
        int end = N-1;
        while(start <= end){
            int mid = start+ (end-start)/2;
            if(arr[mid] == key) return true;
            if(arr[mid] == arr[start] && arr[mid] == arr[end]){
                start++;
                end--;
            }
            else if(arr[start] <= arr[mid]){
                if(arr[start] <= key && key <= arr[mid])
                    end = mid - 1;
                else
                    start = mid + 1;
            }
            else{
                if(arr[mid] <= key && key <= arr[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends