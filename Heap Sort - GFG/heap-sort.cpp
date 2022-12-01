//{ Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    void heapify(int arr[], int N, int i)
    {
        int largest = i;
     
        int l = 2 * i + 1;
     
        int r = 2 * i + 2;
     
        if (l < N && arr[l] > arr[largest])
            largest = l;
    
        if (r < N && arr[r] > arr[largest])
            largest = r;
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, N, largest);
        }
    }
    void heapSort(int arr[], int N)
    {
     
        for (int i = N / 2 - 1; i >= 0; i--)
            heapify(arr, N, i);
     
        for (int i = N - 1; i > 0; i--) {
     
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
};




//{ Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends