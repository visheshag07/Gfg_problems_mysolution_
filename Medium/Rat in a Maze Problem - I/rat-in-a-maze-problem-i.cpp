//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void helper(vector<vector<int>> &arr, int &n, int i, int j, string str, vector<string> &sol) {
        if ((i==n-1 && j==n-1) && (arr[i][j]==1)) sol.push_back(str);
        if (i<0 || j<0 || i>=n || j>=n) return;
        if (arr[i][j]==1) {
            arr[i][j] = 0;
            helper(arr, n, i+1, j, str+"D", sol);
            helper(arr, n, i-1, j, str+"U", sol);
            helper(arr, n, i, j+1, str+"R", sol);
            helper(arr, n, i, j-1, str+"L", sol);
            arr[i][j] = 1;
        }
        return;
    }
    vector<string> findPath(vector<vector<int>> &arr, int n) {
        vector<string> sol;
        helper(arr, n, 0, 0, "", sol);
        return sol;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends