#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <limits.h>
#include <deque>
#include <queue>
#include <algorithm>

using namespace std;

#define fi freopen("vfibo.inp","r",stdin);
#define fo freopen("vfibo.out","w",stdout);
#define boost ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define maximum (long long) 1e9 + 7

int main(){
	boost;
	fi;fo;
	long long n ; cin >> n;
	vector <long long> f(100);

	f[1] = 1; f[2] = 1;

	for (long long i = 3 ; i <= 50; i++) {
		f[i] = f[i - 1] + f[i - 2];
		if (f[i] == n) {
			cout << i;
			return 0;
		}
	}
	cout << -1;


	return 0;
}