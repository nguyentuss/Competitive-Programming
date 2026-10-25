#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("stones.inp","r",stdin);
	freopen("stones.out","w",stdout);
	int n;
	cin >> n;
	vector <long long> sumquery1(n + 7) , sumquery2(n + 7) , a;
	sumquery1[0] = sumquery2[0] = 0;
	for (int i = 1 ; i <= n ; i++) {
		int x; cin >> x;
		a.push_back(x);
		sumquery1[i] = sumquery1[i - 1] + x;
	}

	sort(a.begin(),a.end());
	for (int i = 1 ; i <= n ; i++) 
		sumquery2[i] = sumquery2[i - 1] + a[i - 1];
	//for (int i = 1 ; i <= n ; i++) cout << sumquery2[i] << " ";
	int m;
	cin >> m;
	while (m--)
	{
		int x,l,r;
		cin >> x >> l >> r;
		if (x == 1) cout << (long long) (sumquery1[r] - sumquery1[l-1]);
		else cout << (long long) (sumquery2[r] - sumquery2[l-1]);
		cout << "\n";
	}
	return 0;
}