//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool valid(int sum,int k,int arr[],int N){
        int tot=0;
        int c=1;
        for(int i=0;i<N;i++){
            if(tot+arr[i]<=sum){
                tot+=arr[i];
            }
            else{
                tot=arr[i];
                c++;
            }
        }
        return c<=k;
        
    }
    int splitArray(int arr[] ,int N, int K) {
        // code here
          int maxi=0;
          int mini=INT_MIN;
          for(int i=0;i<N;i++){
              maxi+=arr[i];
              mini=max(arr[i],mini);
          }
          int low=mini;
          int high=maxi;
          int ans=INT_MAX;
          while(low<=high){
              int mid=low+(high-low)/2;
              if(valid(mid,K,arr,N)){
                  ans=min(ans,mid);
                  high=mid-1;
              }
              else{
                  low=mid+1;
              }
          }
          return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends