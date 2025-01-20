#include <bits/stdc++.h>

using namespace std;

#define ii pair<int ,int>	
#define MAX_N (int) (2e5 + 7)
#define f first
#define s second

int n ,k;
int v[MAX_N];
bool vis_num[MAX_N];

bool check(int x , int status) {
	int cnt =0;
	for (int i = 1 ; i <= n ; i++) {
		if (status == 0){
			if (v[i] <= x) {
				cnt++;
				status ^= 1;
			}
		}
		else {
			cnt++;
			status^=1;
		}
	}
	return (cnt >= k);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	for (int i = 1 ; i <= n ; i++){ 
		cin >> v[i];
	}
	int l = 1 , r = 1e9 , ans = -1;
	while (l <= r) {
		int mid = (l + r)/2;
		if (check(mid , 0) || check(mid , 1)) {
			r = mid - 1;
			ans = mid;
		}
		else l = mid + 1;
	}
	cout << ans;
	return 0;
}