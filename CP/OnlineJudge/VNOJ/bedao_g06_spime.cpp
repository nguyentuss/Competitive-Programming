#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e7 +7)


vector<int> sieve(MAX_N , false); 
vector<int> v;
int l ,r , d ,u;
int n , pos;

void eratosthenes() {
	for (int i = 2 ; i * i < MAX_N ; i++) {
		if (!sieve[i]){ 
			for (int j = i *i ; j < MAX_N ; j+= i) {
				sieve[j] = true;
			}
		}
	}
	for (int i = 2 ; i < MAX_N ; i++) 
		if (!sieve[i]) {
			v.push_back(i);
			if (i == n) pos = v.size();
		}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	cin >> n;
	eratosthenes();
	r = 1;
	int cnt = 1 , x = 0 , y = 0;
	int changego = 0 , dist = 1;
	while (cnt <= pos) {
		changego++;
		cnt += dist;
	//	cout << cnt << '\n';
		if (r) {
			x += dist;
			u = 1 , r = 0;
		}
		else if (u) {
			y += dist;
			l = 1, u = 0;
		}
		else if (l) {
			x -= dist;
			d = 1 , l = 0;
		}
		else if (d) {
			y -= dist;
			r = 1, d = 0;
		}
		if (changego % 2 == 0) dist++;
	}
	//cout << x << " " << y <<'\n';
	int last = cnt - pos;
	if (r) y += last;
	if (u) x -= last;
	if (l) y -= last;
	if (d) x += last;
	cout << x << " " << y;
	return 0; 
}