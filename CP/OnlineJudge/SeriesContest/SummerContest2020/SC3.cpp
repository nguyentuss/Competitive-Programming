#include <iostream>
#include <cmath>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

struct seg{
	int left , right;
};

int n , m , l , r; 
vector <seg> v;
int IT[400001];
void init(){
	for (int i = 1 ; i <= 400000 ; i++) IT[i] = 0;
}

void update(int index , int L , int R , int l , int r) {
	if (l > R || L > r) 
		return;
	if (l <= L && R <= r) {
		IT[index] = 1;
		return;
	}
	int mid = (L + R)/2;
	update(2 * index , L , mid , l , r);
	update(2 * index + 1 , mid + 1 , R , l , r);
	if (IT[2 * index] == 1 && IT[2 *index + 1] == 1)
		IT[index] = 1;
}


int ispaint(int index , int L , int R , int l , int r) {
	if (L > r || l > R) {
		return 1;
	}
	if (IT[index] == 1) return 1;
	if (l <= L && R <= r) return 0;
	int mid = (L + R)/2;
	int v1 = ispaint(2*index , L , mid , l , r);
	int v2 = ispaint(2*index + 1 , mid + 1 , R , l , r);
	if (v1 + v2 == 2) return 1;
	else return 0;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	int t; cin >> t;
	for (int test = 0 ; test < t ; test ++)  {
		cin >> n >> m;
		init();
		for (int i = 1; i <= n; i++) {
			cin >> l >> r;
			v.push_back((seg) {l , r});
		}	
		reverse(v.begin() , v.end());
		int ans = 0;
		for (int i = 0 ; i < n; i++) {
			if (ispaint(1 , 1 , m , v[i].left , v[i].right) == 0) ans ++;
			update(1 , 1 , m , v[i].left , v[i].right);
		}
		cout << ans << endl;
	}
	return 0;
}