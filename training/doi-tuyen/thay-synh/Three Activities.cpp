//source:: 
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e18 + 7;

void solve() {
    int n; cin >> n;
	vector<int> a(n),b(n),c(n);
    vector<pair<int,int>> va(n),vb(n),vc(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i]; 
        va[i] = {a[i] , i};
    }
    for (int i = 0 ; i < n ; i++) {
        cin >> b[i]; 
        vb[i] = {b[i] , i};
    }
    
    for(int i = 0 ;i < n; i++){
        cin >> c[i];
        vc[i]={c[i],i};
    }
    sort(va.rbegin(),va.rend());
    sort(vb.rbegin(),vb.rend());
    sort(vc.rbegin(),vc.rend());
    int ans = 0;
    for(int i = 0; i < 3 ;i++){
        for(int j = 0 ;j < 3 ;j++){
            for(int k = 0; k < 3;k++){
                if(va[i].second!=vb[j].second && va[i].second!=vc[k].second && vb[j].second!=vc[k].second){
                    ans=max(ans,va[i].first+vb[j].first+vc[k].first);
                    //cout<<"ans->"<<ans<<endl;
                }
            }
        }
    }
    cout << ans << '\n';
}

main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); 
	cout.tie(NULL);
	int test = 1;
	cin >> test;
	while(test--) {
		solve();
	}
	return 0;
}