#include <bits/stdc++.h>

using namespace std;

struct seg{
	int cal , a;
};

bool cmp(seg &a , seg&b) {
	return a.cal > b.cal;
}

int n , x , y;
vector <int> a,b;
vector <seg> ngarcute;

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);

	cin >> n;
	for (int i = 0 ; i < 2*n ; i++) {
		cin >> x >> y;
		a.push_back(x);
		b.push_back(y);
		ngarcute.push_back({x - y , x});
	}
	sort(ngarcute.begin() , ngarcute.end() , cmp);
	for (int i = 0 ; i < 2*n ; i++) cout << ngarcute[i].cal << " " << ngarcute[i].a << '\n';
	int ans = 0;
	for (int i = 0 ; i < n ; i++) 
		ans += -ngarcute[i].cal + ngarcute[i].a;
	for (int i = n ; i < 2*n ; i++) 
		ans += ngarcute[i].a;
	cout << ans;

	return 0;
}