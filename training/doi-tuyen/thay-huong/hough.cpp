#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("hough.inp","r",stdin);
#define fo freopen("hough.out","w",stdout);

const long long maxn = 1e5;
long long a[maxn] , b[maxn];
int n , m ;
int binarysearch(int x){
    int r = n , l = 1 , res = 0;
    bool k = false;
    while (l <= r){
        int mid = l + (r - l) /2 ;
        if (a[mid] >= x)
            r = mid - 1;
        if (a[mid] < x){
            res = mid;
            k = true;
            l = mid + 1;
        }
    }
    if (k) return res;
    else return 0;
}

int main() {
    boost;
   // fi;fo;
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++)
        cin >> a[i];
    sort(a+1,a+1+n);
    for (int i = 1 ; i <= m ; i++)
        cin >> b[i];
    for (int i = 1 ; i <= m ; i++){
        
        cout << binarysearch(b[i]) << "\n";

    }
    return 0;
}
