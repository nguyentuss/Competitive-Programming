#include <bits/stdc++.h>

using namespace std;

int n , k , a , b , ans = 0;
bool check = false;

void recursion(int N){
	if (N == 0) return;
	if ((N + k)%2 != 0) return;
	int a = (N + k) / 2;
	int b = N - a;
	if (abs(a - b) == k && a > 0 && b > 0) {
		if (check) ans ++;
		else {
			ans += 2;
			check = true;
		}
	}
	else return;
	recursion(a);
	recursion(b);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("phantichso.inp","r",stdin);
	freopen("phantichso.out","w",stdout);
	cin >> n >> k;

	if ((n + k) % 2 != 0) cout << n;
	else {
		recursion(n);
		cout << ans;
	}

	return 0;
}