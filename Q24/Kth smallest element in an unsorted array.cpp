#include <bits/stdc++.h> 
using namespace std; 
  
int findkthSmallest(int arr[], int n, int k) 
{ 
    sort(arr, arr + n); 
    return arr[k - 1]; 
} 
  
int main() 
{ 
    int arr[] = { 11,5,85,65,0,5 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
	int k = 4; 
    cout << k<<" th smallest element is:  " << findkthSmallest(arr, n, k); 
    return 0; 
} 
