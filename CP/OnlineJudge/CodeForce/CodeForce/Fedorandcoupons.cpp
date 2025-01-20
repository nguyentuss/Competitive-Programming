#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define boost ios::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
typedef pair<int , int> ii;

int pos[300005] , n ;

struct segment{
	int l , r , ID;
	bool operator <(const segment &b) {
		if (l < b.l || (l == b.l && r < b.r))
			return true;
		else return false;
	}
}v[300005];

bool compare(segment &a , segment &b) {
	if (a.r > b.r) return true;
	else return false;
}


int main() {
	boost;
	//freopen("input.inp","r",stdin);
	//freopen("output.out","w",stdout);

	int  p , k , ml , mr , maximum = 0; cin >> n >> k;

	priority_queue <int , vector<int> , greater<int>> pq;


	for (int i = 1 ; i <= n  ; i ++) {
		cin >> v[i].l >> v[i].r;
		v[i].ID = i;
	}

	sort(v + 1 , v + 1 + n);

	for (int i = 1 ; i <= k ; i ++) 
		pq.push(v[i].r);
	ml = v[k].l; mr = pq.top();
	if (maximum < (mr - ml + 1)) {
		maximum = mr - ml + 1;
		pos[1] = v[k].ID;
		p = k;
	}

	for (long long i = k + 1; i <= n ; i ++) {
		pq.pop();
		pq.push(v[i].r);
		ml = v[i].l; mr = pq.top();

		if (maximum < (mr - ml + 1)){
			p = i;
			maximum = mr - ml + 1;
			pos[1] = v[i].ID;
		}
	}

	if (maximum == 0) {
		cout << maximum << endl;
		for (int i = 1 ; i <= k ; i++) 
			cout << i << " " ;
	}
	else {
		cout << maximum << endl;
		sort(v + 1 , v + p , compare);
		for (int i = 1 ; i <= k - 1 ; i ++) {
			cout << v[i].ID << " ";
		} 
		cout << pos[1];
		
	}

	return 0;
}