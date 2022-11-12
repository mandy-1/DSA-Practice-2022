//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       int i=0,ans=0,req=0,ext=0;
       while(i<n){
           int dif = p[i].petrol - p[i].distance;
           if(ext+dif<0){
               req += ext+dif;
               ext=0;
               ans=i+1;
           }
           else{
               ext+=dif;
           }
           i++;
       }
       if(ext+req >= 0)return ans;
       return -1;
    }
    
    // 55 33 77 40
    // 52 100 61 69
    // 96 46 68 65 51 9 79 85
    // 25 83 15 35 44 88 77 89
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends