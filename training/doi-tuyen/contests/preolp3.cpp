#include <iostream>

using namespace std;

int n , m;
long long a[100000] , b[100000];
long long X[100000];
long long ans = 0;
void init(){
	for (int i = 0 ; i <= 100000 ; i++) {
		a[i] = 0;
		b[i] = 0;
		X[i] = 0;
	}
}

void write() {
	long long weight = 0 , sum = 0;
	X[0] = -1; X[n + 1] = -1;
	//for (int i = 1 ; i <= n ; i++) cout << X[i] << " ";
	//cout << endl;
	for (int i = 1 ; i <= n ; i++) {
		if ((X[i] == 1) && (X[i] != X[i + 1] )){ 
			sum += a[i];
			weight += b[i];
			if (weight > m) return; 
		}
	}
	ans = max(ans , sum);
}

void backtr(int i) {
	for (int j = 0 ; j <= 1 ; j ++) {
		X[i] = j;
		if (i == n) write();
		else backtr(i + 1);
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("preolp3.inp","r",stdin);
	freopen("preolp3.out","w",stdout);
	int test; cin >> test;
	for (int t = 0 ; t < test ; t ++) {
		ans = 0;
		cin >> n >> m;
		for (int i = 1 ; i <= n ; i++) {
			cin >> a[i] >> b[i];
		}
		backtr(1);
		cout << ans << endl;
	}

	return 0;
}