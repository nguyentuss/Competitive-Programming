#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (3e3 + 7)
#pragma GCC optimize("Ofast")

int r , c , h , w;
vector<int> v;
multiset<int> s;
int ans = 0;

int findmedian() {
	if (s.empty()) return 0;
	int n = s.size();
	auto data = s.cbegin();
	advance(data , (n + 1)/2 - 1);
	return *data;
}

void init(int x) {
	s.clear();
	for (int i = 0 ; i < h ; i ++) {
		int left = x + i*c;
		for (int j = left ; j <= left + w - 1; j++) {
			s.insert(v[j]);
		}
	}
	ans = max(ans , findmedian());
}

void xoa(int left) {
	for (int i = 0 ; i < h ; i++) {
		int tmp = left + i*c;
		s.erase(s.find(v[tmp]));
	}
}
void them(int right) {
	for (int i = 0 ; i < h ; i++) {
		int tmp = right + i*c;
		s.insert(v[tmp]);
	}
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("test.inp","r",stdin);
	cin >> r >> c >> h >> w;
	const int BLOCK = c;
	v.push_back(0);
	for (int i = 1 ; i <= r ; i++) {
		for (int j = 1 ; j <= c ; j++) {
			int x; cin >> x;
			v.push_back(x);
		}
	}
	int left = 1 , right = w;
	int level = 0;
	while (level <= (r - h)) {
		left = 1 + level*c;
		right = left + w - 1;
		init(left);
		int newl = left , newr = right;
		while (newr < level*BLOCK) {
			for (int i = 0 ; i < h ; i++) {
				int tmp1 = newl + i*c;
				int tmp2 = tmp1 + w;
				xoa(tmp1); them(tmp2);
			} 
			findmedian();
			newl++ , newr++;
		}
		level++;
	} 
	cout << ans;
	return 0;
}