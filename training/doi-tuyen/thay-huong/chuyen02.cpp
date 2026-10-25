#include <bits/stdc++.h>

using namespace std;

vector <int> h , a;
int n , x;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	freopen("chuyen02.inp","r",stdin);
	freopen("chuyen02.out","w",stdout);
	cin >> n;
	for (int i = 1 ; i <= n; i++) 
		for (int j = 1 ; j <= n ; j++) {
			cin >> x;
			if (x) a.push_back(j);
			if (j == n) h.push_back((int) a.size()); 
		}

	cout << 0 << " ";
	for(int i = 0 ; i < (int) h.size() ; i++) cout << h[i] << " ";
	cout << '\n';
	for (int i = 0 ; i < (int) a.size() ; i++) cout << a[i] << " ";
	return 0;
}