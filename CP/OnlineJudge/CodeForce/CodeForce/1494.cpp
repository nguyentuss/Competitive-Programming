#include <bits/stdc++.h>

using namespace std;

int n , m;
vector<int> positive , negative;
vector<int> a , b;
int x;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		positive.clear() , negative.clear() , b.clear();
		cin >> n >> m;
		for (int i = 1 ; i < n ; i++) {
			cin >> x;
			if (x < 0) negative.push_back(x);
			else positive.push_back(x);
		}
		
	}

	return 0;
}