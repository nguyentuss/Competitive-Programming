#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>
#define f first
#define s second
#define inf (int) (1e9 + 7)

vector<int> tmpa , tmpb;
vector<ii> a , b;

int calc(vector<ii> &u , vector<ii> &v) {
	int ans = 0;
	for (int i = 0 ; i < u.size() ; i++) {
		int l = 0 , r = v.size() - 1 , x = u[i].f , pos = -1;
		while (l <= r) {
			int mid = (l + r)/2;
			if (v[mid].f >= x) {
				r = mid - 1;
				if (v[mid].f == x) pos = mid;  
			}
			else l = mid + 1;
		}
		if (pos != -1)
			ans = max(ans , v[pos].s);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	freopen("DEMSOLAN.inp","r",stdin);
	freopen("DEMSOLAN.out","w",stdout);
	int n; cin >> n;
	for (int i = 0 ; i < n ; i++) {
		int x ; cin >> x;
		tmpa.push_back(x);
	}
	for (int i = 0 ; i < n ; i++) {
		int x ; cin >> x;
		tmpb.push_back(x);
	}
	sort(tmpa.begin() , tmpa.end());
	sort(tmpb.begin() , tmpb.end());
	int cnt = 0;
	tmpa.push_back(inf) , tmpb.push_back(inf);
	for (int i = 0 ; i < (tmpa.size() - 1) ; i++) {
		if (tmpa[i] != tmpa[i + 1]) 
			a.push_back(ii(tmpa[i] , cnt + 1)) , cnt = 0;
		else cnt++;
	}
	cnt = 0;
	for (int i = 0 ; i < (tmpb.size() - 1) ; i++) {
		if (tmpb[i] != tmpb[i + 1])
			b.push_back(ii(tmpb[i] , cnt + 1)) , cnt = 0;
		else cnt++;
	}
	int ans1 = calc(a , b);
	/*for (auto e : a) cout << e.s << " ";
	cout << '\n';
	for (auto e : b) cout << e.s << " ";
	cout << '\n';*/
	int ans2 = calc(b , a);
	if (ans1 > ans2) cout << "PHONG";
	else if (ans1 < ans2) cout << "KHANG";
	else if (ans1 == ans2) cout << "HOA";
	return 0;
}