#include <iostream>
using namespace std;

#define maxn (int) 101

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("stnnn.inp","r",stdin);
	freopen("stnnn.out","w",stdout);
		long long n , a , res = 0 ; 	cin >> n;
		long long c[maxn] = {0};
		for (long i = 1; i <= n; i++){
			cin >> a;
			++ c[a];
		}
		bool check = true;
		for (long long i = 0 ; i <= 1e9 ; i++){
			if (c[i] == 0) break;
			else if (c[i] == 1) {
				++ res;
				check = false;
			}
			else {
				++ res;
				if (check) ++res;
			}
		}
	cout << res << '\n';
	return 0;
}