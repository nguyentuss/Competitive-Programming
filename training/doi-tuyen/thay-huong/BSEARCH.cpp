#include <iostream>
#include <vector>


using namespace std;

#define boost ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fi freopen("BSEARCH.inp","r",stdin);
#define fo freopen("BSEARCH.out","w",stdout);
int a , n , x;
int v[(int) 100000006];

int FindPos(int x) {
	int l = 1 , r = n;
	while (l <= r) {
		int mid = (l + r)/2;
		if (v[mid] == x) {
			return mid;
		}
		else if (v[mid] < x){
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	return -1;
}

int main() {
	boost;
	fi;fo;
	cin >> n >> x; 
	for (int i = 1 ; i <= n ; i++) {
		cin >> v[i];
	}
	cout << FindPos(x);
	return 0;
}