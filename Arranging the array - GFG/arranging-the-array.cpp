//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
class Solution
{
    public:
        void reverse(int arr[],int i,int j){
            while(i<=j){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                i++;j--;
            }
        }
    
        void merge(int arr[],int start,int mid,int end){
            int i=start,j=mid+1;
            while(i<=mid && arr[i]<0)i++;
            while(j<=end && arr[j]<0)j++;
            reverse(arr,i,mid);
            reverse(arr,mid+1,j-1);
            reverse(arr,i,j-1);
        }
    
        void mergesort(int arr[],int start,int end){
            if(start<end){
                int mid=(start+end)/2;
                mergesort(arr,start,mid);
                mergesort(arr,mid+1,end);
                merge(arr,start,mid,end);
            }
        }
    
        void Rearrange(int arr[], int n)
        {
            // Your code goes here
            mergesort(arr,0,n-1);
        }
};

//{ Driver Code Starts.
void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
        Solution ob;
        ob.Rearrange(arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends