#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e6 + 3;
int n,A[maxn],B[maxn],kq;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    cout.tie(NULL);
    freopen("acm.inp","r",stdin);
    freopen("acm.out","w",stdout);
    cin >> n;
    for(int i=1;i<=2*n;i++){
        cin >> A[i] >> B[i];
        kq+=A[i];
        B[i]=A[i]-B[i];
    }
    sort(B+1,B+1+2*n);
    for(int i=2*n;i>n;i--) kq-=B[i]; 
    cout << kq;
return 0;
}