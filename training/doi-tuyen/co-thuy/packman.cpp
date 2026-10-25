#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

char s[100007];
vector <int> pos , posgrass;
int lt = -1 , rt , temp;
bool checklt;
int n;
int ans = 1000000000;

int findgrass(int positive) {
	int l = 0 , r = posgrass.size() - 1;
	int themost = 1000000;
	while (l <= r) {
		int mid = (l + r)/2 ;
		if (posgrass[mid] + 1 < positive){
			l = mid + 1;
			themost = min(themost , posgrass[mid] + 1);
		} 
		else {
			r = mid - 1;
		}
	}
	cout << themost;
	return themost;
}

int check(int t) {
	int lt = 0 , rt = 0;
	for (int i = 1 ; i <= n ; i++) {
		if (s[i] == '*' && (lt == 0) && (i > rt)) lt = i;
		else {
			if (s[i] == 'P') {
				int tam = abs(i - lt);
				if (tam < 0) tam = 0;
				rt = max(t - 2 * tam + i , (t - tam)/2 + i);
				lt = 0;
			}
		}
	}
	if (lt) return 0; 
	else return 1;
}


int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("packman.inp","r",stdin);
	freopen("packman.out","w",stdout);
	cin >> n;
	for (int i = 1 ; i<= n ; i++) 
		cin >> s[i];
	int l = 1 , r = 2 *n;
	while(l <= r) {
		int mid = (l + r)/2;
		if(check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans;
	return 0;
}