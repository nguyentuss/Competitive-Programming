#include <bits/stdc++.h>

using namespace std;

struct seg {
	int val , i , j;
};

bool cmp(seg &a , seg &b) {
	return a.val < b.val;
}

vector<seg> pairsum;
vector<int> v;
int n;
 
bool isfind(int x , int posx) {
	int l = 0 , r = pairsum.size() - 1;
	int pos = -1;
	while (l <= r) {
		int mid = (l + r)/2;
		if (pairsum[mid].val >= x) {
			r = mid - 1;
			if (pairsum[mid].val == x) pos = mid;
		}
		else l = mid + 1;
	}

	if (pos != -1) {
		for (int i = pos ; i < pairsum.size() ; i++) {
			if (pairsum[i].val > x) break;
			if (pairsum[i].j != posx && pairsum[i].i != posx) return true;
		}
	}
	return false; 
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("AVERAGE.INP","r",stdin);
	freopen("AVERAGE.OUT","w",stdout);
	cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		int x; cin >> x;
		v.push_back(x);
	}
	for (int i = 0 ; i < (n - 1); i++) {
		for (int j = i + 1 ; j < n ; j++) {
			pairsum.push_back({v[i] + v[j] , i , j});
		}
	}
	// a[i] + a[j]

	sort(pairsum.begin() , pairsum.end() , cmp);
	int ans = 0;
	for (int i = 0 ; i < n ; i++) {
		for (int j = 0 ; j < n ; j++) {
			if (i != j){
				int x = 3*v[i] - v[j];
				if (isfind(x , j)) {
					ans++;
					break;
				}
			} 
		}
	}
	cout << ans;
	return 0;
}