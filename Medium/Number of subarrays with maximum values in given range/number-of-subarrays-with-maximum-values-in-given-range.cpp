//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    long countSubarrays(int a[], int n, int l, int r)
    {
      long start=0;
      long end=0;
      long empire=0;
      long ans=0;
      
      for(end=0;end<n;end++)
      {
          if(a[end]>=l&&a[end]<=r)
          {
              empire=end-start+1;
          }
            if(a[end]>r)
            {
                start=end+1;
                empire=0;
            }
          
          ans+=empire;
      }
      return ans;
        
    }
};

//{ Driver Code Starts.
// driver program
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        
        int n ,l,r;
        cin >> n>>l>>r;
        int a[n];
        for(int i=0;i<n;i++)
        cin >> a[i];
        Solution ob;
    	cout << ob.countSubarrays(a, n, l, r)<<endl;
    }
	return 0;
}

// } Driver Code Ends