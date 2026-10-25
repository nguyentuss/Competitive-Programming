#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (3e4 + 7)

set<int> s1 , s2 , s3;
// s1 là vị trí của những phần tử chia hết cho 2
// s2 là vị trí của những phần tử chia hết cho 3
// s3 là vị trí của những phần tử chia hết cho 5
int n , m , a[MAX_N];
// add là thêm những vị trí mà thỏa mãn của từng cái set
void add(int x , int i) {
	if (x % 2 == 0) s1.insert(i);
	if (x % 3 == 0) s2.insert(i);
	if (x % 5 == 0) s3.insert(i);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("queries.inp","r",stdin);
	//freopen("queries.out","w",stdout);
	freopen("test.inp","r",stdin);
	freopen("test.out","w",stdout);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i ++) {
		cin >> a[i];
		add(a[i] , i);
	}
	for (int i = 1 ; i <= m ; i++) {
		int ask; cin >> ask;
		if (ask == 1) {
			int l , r , p ; cin >> l >> r >> p;
			int pos = l;
			// upper_bound(x) là tìm thằng nhỏ nhất mà lớn hơn
			if (p == 2) {
				while (pos <= r) {
					auto it = s1.lower_bound(pos);
					// nếu kh tìm ra là nó sẽ trỏ tới .end()
					// nhớ cái dấu * nha , kh có nó kh chạy đx âu 
					if (it == s1.end() || *it > r) break;
					else {
						a[*it] /= 2;
						if (a[*it] % 2 != 0) s1.erase(it);
						pos = *it + 1;
					}
				}
			}
			if (p == 3) {
				while (pos <= r) {
					auto it = s2.lower_bound(pos);
					if (it == s2.end() || *it > r) break;
					else {
						a[*it] /= 3;
						if (a[*it] % 3 != 0) s2.erase(it);
						pos = *it + 1;
					}
				}
			}
			if (p == 5) {
				while (pos <= r) {
					auto it = s3.lower_bound(pos);
					if (it == s3.end() || *it > r) break;
					else {
						a[*it] /= 5;
						if (a[*it] % 5 != 0) s3.erase(it);
						pos = *it + 1;
					}
				}
			}
		}
		else {
			int l , d; cin >> l >> d;
			a[l] = d; add(a[l] , l);
		}
	}
	for (int i = 1 ; i <= n ; i++) {
		cout << a[i] << " ";
	}

	return 0;
}