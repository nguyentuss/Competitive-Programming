#include <bits/stdc++.h>
using namespace std;
const long lm = 60;
struct candy{
    long type, val;
};
candy A[lm];
bool ck[lm];
long n, k, p1, p2, test;
bool cmp(candy x, candy y){
    return x.val>y.val;
}
int main(){
    cin >> test;
    while (test--){
        cin >> n >> k;
        for (long i=1; i<=n; i++){
            cin >> A[i].type >> A[i].val; 
        }
        sort(A+1, A+n+1, cmp);
        for (int i = 1 ; i <= 50 ; i++) 
            ck[i] = true;
        long ans = 0;
        p1 = 1;
        p2 = 2;
        long d = 0;
        while (p2 <= n && p1 <=n && d < k*2){
            while (A[p2].type == A[p1].type && p2 <=n) p2 += 1;
            if (p2 > n) break;
            ck[p1] = false;
            ck[p2] = false;
            ans += A[p1].val+A[p2].val;
            d += 2;
            p2 += 1;
            while (!ck[p1] && p1 <= n) p1 += 1;
        }
        if (d < 2*k) cout << "-1\n";
        else cout << ans << "\n";
    }
    return 0;
}