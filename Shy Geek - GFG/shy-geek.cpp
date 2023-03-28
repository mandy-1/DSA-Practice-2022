//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

class Shop
{
    vector<int> chocolates;
    int countOfCalls;
    public:
    Shop()
    {
        countOfCalls = 0;
    }
    void addChocolate(int x)
    {
        chocolates.push_back(x);
    }
    long long get(int i)
    {
        countOfCalls++;
        if(i<0 || i>=(int)chocolates.size() || countOfCalls>50)return -1;
        return chocolates[i];
    }
};


// } Driver Code Ends
//User function Template for Java

/*
Instructions - 

    1. 'shop' is object of class Shop.
    2. User 'shop.get(int i)' to enquire about the price
            of the i^th chocolate.
    3. Every chocolate in shop is arranged in increasing order
            i.e. shop.get(i) <= shop.get(i + 1) for all 0 <= i < n - 1
*/
class Solution{
    public:
Shop shop;
    Solution(Shop s)
    {
        this->shop = s;
    }
    
    long long find(int n, long k)
    {
        long long l, r = n-1, ans = 0;
        
        if(k > shop.get(n-1)){
            long long tmp = shop.get(n-1);
            ans += k/tmp;
            k %= tmp;
        }
    
        while (r>=0 && k >= 1)
        {
            long long ind = 0, tmp;
            l = 0;
            
            while (l <= r)
            {
                long long mid = l + (r - l) / 2;
                long long temp = shop.get(mid);
                if (temp <= k)
                {
                    ind = mid;
                    l = mid + 1;
                }
                else
                    r = mid - 1;
            }
            tmp = shop.get(ind);
    
            ans += k / tmp;
            k = k % tmp;
    
            r = ind - 1;
        }
    
        return ans;
    }

};

//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        long long k;
        cin >> k;
        
        Shop shop;
        for(int i = 0; i<n; i++)
        {
            int x;
            cin >> x;
            shop.addChocolate(x);
        }
        
        Solution obj(shop);
        long long res = obj.find(n, k);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends