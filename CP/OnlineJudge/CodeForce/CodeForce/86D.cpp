#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define MAX_N (long long) (2e5 + 7)
#define MAX_NUM (long long) (1e6 + 7)
#define ii pair<long long , long long>

struct seg {
	long long l , r , id;
};

vector <long long> v(MAX_N);
vector <long long> cnt(MAX_NUM);
vector <seg> query;
long long BLOCK;

bool cmp(seg &a , seg &b) {
	return ((a.l/BLOCK < b.l/BLOCK) || (a.l/BLOCK == b.l/BLOCK && a.r/BLOCK < b.r/BLOCK));
}

/*void remove(int pos) {

}*/

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	long long n , q; cin >> n >> q;
	BLOCK = sqrt(n);
	for (long long i = 1 ; i <= n; i++) 
		cin >> v[i];
	for (long long i = 1 ; i <= q ; i++) {
		long long l , r; cin >> l >> r;
		query.push_back({l , r , i});
	}
	sort(query.begin() , query.end() , cmp);
	long long currL = query[0].l , currR = query[0].r;
	unsigned long long prev = 0 , ans = 0;
	for (long long i = currL ; i <= currR ; i++) {
		prev = cnt[v[i]]*cnt[v[i]]*v[i];
		cnt[v[i]] ++;
		ans = ans - prev + (cnt[v[i]]*cnt[v[i]]*v[i]);
	}
	vector <long long> res(MAX_N);
	res[query[0].id] = ans;
	for (long long i = 1 ; i < q ; i++) {
		long long L = query[i].l , R = query[i].r;
		while (currL < L) {
			cnt[v[currL]] --;
			ans -= (2*cnt[v[currL]] + 1)*v[currL];
			currL++;
		}
		while (currL > L) {
			currL --;
			cnt[v[currL]] ++;
			ans += (2*cnt[v[currL]] - 1)*v[currL];
		}
		while (currR < R) {
			currR++;
			cnt[v[currR]] ++;
			ans += (2*cnt[v[currR]] - 1)*v[currR];
		}
		while (currR > R) {
			cnt[v[currR]] --;
			ans -= (2*cnt[v[currR]] + 1)*v[currR];
			currR--;
		}
		res[query[i].id] = ans;
	}
	for (int i = 1 ; i <= q ; i++) cout << res[i] << '\n';
	return 0; 
}