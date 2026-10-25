#include <bits/stdc++.h>

using namespace std;

#define MAX_NUM (int) (-1e9 + 7)
#define MIN_NUM (int) (1e9 + 7)
vector <int> v;
int n , x;

void init(){
	v.clear();
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("mangtot.inp","r",stdin);
	freopen("mangtot.out","w",stdout);

	int t; cin >> t;
	while (t--) {
		init();
		cin >> n;
		int counted = 0;
		for (int i = 0 ; i < n ; i++) {
			cin >> x;
			v.push_back(x);
		}

		reverse(v.begin() , v.end());
		int before = MAX_NUM;
		int pos = 0;
		for (int i = 0 ; i < n; i++) {
			if (v[i] >= before) {
				counted ++ ;
				before = v[i];
			}
			else {
				pos = i - 1;
				break;
			}
		}
		before = v[pos];
		//cout << pos;
		for (int i = pos + 1 ; i < n ; i++) {
			if (v[i] <= before){
				counted ++;
				before = v[i];
			}
			else break;
		}

		cout << n - counted << '\n';
	}

	return 0;
}