#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std; 

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("mergeSort.inp","r",stdin);
#define fo freopen("mergeSort.out","w",stdout);
  
long long _mergeSort(vector <long long > &arr, vector <long long > &temp,  
                 long long left, long long right); 
long long merge(vector <long long > &arr, vector <long long > &temp, long long left,  
                   long long mid, long long right); 
  
long long mergeSort(vector <long long > &arr, long long n) 
{ 
    vector <long long > temp(n);
    return _mergeSort(arr, temp, 0, n - 1); 
} 
  
long long _mergeSort(vector <long long > &arr, vector <long long > &temp,  
                 long long left, long long right) 
{ 
    long long mid, inv_count = 0; 
    if (right > left) { 
        mid = (right + left) / 2; 
  
        inv_count += _mergeSort(arr, temp,  
                                left, mid); 
        inv_count += _mergeSort(arr, temp,  
                             mid + 1, right); 
  
        inv_count += merge(arr, temp, left,  
                           mid + 1, right); 
    } 
    return inv_count; 
} 
  
long long merge(vector <long long > &arr, vector <long long > &temp, long long left, 
          long long mid, long long right) 
{ 
    long long i, j, k; 
    long long inv_count = 0; 
  
    i = left;
    j = mid; 
    k = left; 
    while ((i <= mid - 1) && (j <= right)) { 
        if (arr[i] <= arr[j]) { 
            temp[k++] = arr[i++]; 
        } 
        else { 
            temp[k++] = arr[j++]; 
            inv_count = inv_count + (mid - i); 
        } 
    } 
  
    while (i <= mid - 1) 
        temp[k++] = arr[i++]; 
  
    while (j <= right) 
        temp[k++] = arr[j++]; 
  
    for (i = left; i <= right; i++) 
        arr[i] = temp[i]; 
  
    return inv_count; 
} 
  
// Driver code 
int main() 
{ 
    boost;
    fi;fo;
    long long t; cin >> t;
    while (t --){
        long long n,x;
        cin >> n; 
        vector <long long> arr;
        for (long long i = 0 ; i < n ; i++) {
            cin >> x;
            arr.push_back(x);
        }
        long long ans = mergeSort(arr, n); 

        cout << ans << endl;
    }
    return 0; 
} 