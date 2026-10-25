#include <bits/stdc++.h>

using namespace std;

#define mininf (int) (INT_MIN)
#define inf (int) (INT_MAX)

vector <int> v;
int maximum , n , m;
int last;

bool check(int maxi) {
	v[0] = maximum - maxi;
	last = n - m - 1;
	//for (int i = 0 ; i < m ; i++) cout << v[i] << " ";
	//cout << '\n';
	for (int i = 0 ; i < m ; i++) {
		if (v[i] > maxi) {
			int tmp = max(0 , v[i] - maxi);
			if (tmp % maxi) last --;
			last -= tmp / maxi;
			//cout << last << " " << tmp <<  " " << i  << '\n';
		}
	}
	if (last >= 0) return true;
	return false;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("marble.inp","r",stdin);
	freopen("marble.out","w",stdout);
	cin >> n >> m;
	int l = 1 , r = mininf;

	for (int i = 0 ; i < m ; i++) {
		int x; cin >> x;
		v.push_back(x);
		r = max(r , x);
	}
	int ans = -1;
	sort(v.begin() , v.end() , greater<int>());
	if (n == m) cout << v[0];
	else  
	{
		maximum = v[0];
		while (l <= r) {
			int mid = (l + r)/2;
			//cout << mid << " ";
			if (check(mid)) {
			//	cout << 1;
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		cout << ans;
	}
	return 0;
}