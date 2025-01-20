#include<bits/stdc++.h>
#define int long long int
#define mod 1000000007
#define int_max 1e18
#define inf 10000001
#define hae printf("YES\n")
#define na printf("NO\n")

using namespace std;
int i,j,K,L,ts=1;
// start journey

void solve(){
    int n;
    cin >> n;
    vector<int>ans(n+10,1);
    string ch;
    cin >> ch;
    for(int i=n-2; i>=0; i--){
        if(ch[i]=='L'){
            if(ans[i]<=ans[i+1]){
                ans[i]+=ans[i+1];
            }
        }
        else if(ch[i]=='R'){
            if(ans[i+1]<=ans[i]){
                ans[i+1]+=ans[i];
            }
        }
        else{
            ans[i]=ans[i+1];
        }
    }
    for(int i=0; i<n-1; i++){
        if(ch[i]=='L'){
            if(ans[i]<=ans[i+1]){
                ans[i]+=ans[i+1];
            }
        }
        else if(ch[i]=='R'){
            if(ans[i+1]<=ans[i]){
                ans[i+1]=ans[i]+1;
            }
        }
        else{
            ans[i+1]=ans[i];
        }
    }
    for(int i=0; i<n; i++){
        cout << ans[i] << ' ';
    }
    cout << endl;
    
}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin >> t;
    while(t--){
        solve();
    }
}