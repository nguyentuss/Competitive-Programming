#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define lim (ll) (1e9 + 7)

vector<int> v;
int a[100007];
int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	v.push_back(INT_MIN);
	for (int i=1;i<=n;i++) {
		int x;cin>>x;
		if (x%2==0)
			v.push_back(x); 
	}
    a[0] = -lim;
	for (int i=1;i<=n;i++) 
		a[i]=lim;
    int ans=0;
    for (int i=1;i<v.size();i++) {
    	int x=v[i];
        int k=lower_bound(a+1,a+1+n,x)-a;
        a[k]=x;
        ans=max(ans , k);
    }
	cout<<ans;
	return 0;
}