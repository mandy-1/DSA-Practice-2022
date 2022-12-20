//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
// 1 2 3 4 7
// 137+24
class Solution{   
public:
    string solve(int arr[], int n) {
        sort(arr,arr+n);
        string num1="",num2="";
        int j=0;
        while(arr[j]==0)j++;
        for(;j<n;j+=2){
            num1 = num1+to_string(arr[j]);
            
            if(j+1<n){
                num2 = num2+to_string(arr[j+1]);   
            }
        }
        // cout<<num1<<" "<<num2<<endl;
        string ans="";
        int car=0;
        for(int i=num1.length()-1;i>=0;i--){
            int no1=(num1[i]- '0');
            int no2=(num2[i]- '0');
            if(num1.length()>num2.length()){
                if(i==0){
                    no2=0;
                }
                else no2=(num2[i-1]- '0');
            }
            
            int temp=no1+no2+car;
            int cur=temp%10;
            car=temp/10;
            if(temp==0 && i==0 )continue;
            // cout<<no1<<" "<<no2<<" "<<temp<<" "<<car<<" "<<cur<<endl;
            ans=to_string(cur)+ans;
        }
        if(car!=0)ans=to_string(car)+ans;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends