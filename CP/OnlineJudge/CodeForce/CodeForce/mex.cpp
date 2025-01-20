#include <iostream>
using namespace std;

#define maxn (int) 101

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--){
		int n , a , res = 0 ; 	cin >> n;
		int c[maxn] = {0};
		for (int i = 1; i <= n; i++){
			cin >> a;
			++ c[a];
		}
		bool check = true;
		for (int i = 0 ; i <= 100 ; i++){
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
	}
	return 0;
}