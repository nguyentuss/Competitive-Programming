#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0);cout.tie(0)

int main() {
    //freopen("wc2.inp","r",stdin);
    //freopen("wc2.out","w",stdout);
    int t ; cin >> t;
    while (t--){
        int n; cin >> n;    
        int a[10000] = {0};bool kt = true;
        a[0] = 0;
        for (int i = 1 ; i <= n ; i++)
            cin >> a[i];
        for (int i = 0 ; i <= n - 1 ; i++){
            if (a[i+1] - a[i]  > 15)
            {
                cout << a[i] + 15 << endl;
                kt = false;
                break;
            }
        }
        if (kt)
            cout << min(a[n] + 15 , 90) << endl;
    }
    return 0;
}
