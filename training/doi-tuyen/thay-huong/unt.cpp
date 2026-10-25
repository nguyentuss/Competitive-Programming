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

#define fi freopen("unt.inp","r",stdin);
#define fo freopen("unt.out","w",stdout);
#define boost ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

bool check(int a) {
	for (int i = 2 ; i <= (int) sqrt(a) ; i ++) 
		if (a % i == 0) return false;
	if (a > 1) return true;
	else return false;
}

int main(){
	boost;
	fi;fo;
	bool checkunt = false;

	int n; cin >> n ;

	for (int i = 2 ; i <= (int) n / 2; i ++) {
		if (n % i == 0 && check(i)) {
			checkunt = true;
			cout << i << " ";
		}
	}
	if (!checkunt) cout << -1;

	return 0;
}