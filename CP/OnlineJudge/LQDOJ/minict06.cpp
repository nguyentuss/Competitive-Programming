#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits.h>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("minict06.inp","r",stdin);
#define fo freopen("minict06.out","w",stdout);
#define maxn (int) 1e5 + 7

/*:3*/
vector <int> v(maxn) , posone(maxn) , poszero(maxn) , lenone(maxn) , lenzero(maxn);
int n , x;
int ans = INT_MIN;

int main() {
	boost;

	int n; cin >> n;
	lenzero[0] = 0; lenone[0] = 0; posone[0] = 0 ; poszero[0] = 0;
	int countone = 0 , countzero = 0;
	for (int i = 1 ; i <= n ; i++) {
		cin >> v[i];
		if (v[i] == 0) {
			lenzero[i] = lenzero[i-1] + 1;
			lenone[i] = lenone[i-1];
			countzero ++ ;
			poszero[countzero] = i;
		}
		else {
			lenone[i] = lenone[i-1] + 1;
			lenzero[i] = lenzero[i-1];
			countone++;
			posone[countone] = i;
		}
	}
	int l = 1;
	if (v[n] == 1) {
		for (int i = 1 ; i <= countone ; i++)  {
			if ((lenzero[posone[i]] - lenzero[l-1])  == (lenone[posone[i]] - lenone[l-1]) && posone[i] != 1) {
				ans = max(ans, posone[i] - l + 1);

			}
			else if (lenzero[posone[i]] - lenzero[l-1] > lenone[posone[i]] - lenone[l-1] && posone[i] != 1){
				while ((lenzero[posone[i]] - lenzero[l-1]) != (lenone[posone[i]] - lenone[l-1]) && posone[i] != 1 && l < i){
					if (l + 1 < i) l ++ ;
					else break;
				}
				ans = max(ans, posone[i] - l + 1);
			}
			else if (lenzero[posone[i]] - lenzero[l-1] < lenone[posone[i]] - lenone[l-1] && posone[i] != 1){
				while ((lenzero[posone[i]] - lenzero[l-1]) != (lenone[posone[i]] - lenone[l-1]) && posone[i] != 1 && l >= 1){
					if (l - 1 > 1) l -- ;
					else break;
				}
				ans = max(ans, posone[i] - l + 1);
			}
		}
	}
	else {
		for (int i = 1 ; i <= countzero ; i++)  {
			if ((lenzero[poszero[i]] - lenzero[l-1])  == (lenone[poszero[i]] - lenone[l-1]) && poszero[i] != 1) {
				ans = max(ans, poszero[i] - l + 1);

			}
			else if (lenone[poszero[i]] - lenone[l-1] > lenzero[poszero[i]] - lenzero[l-1] && poszero[i] != 1){
				while ((lenone[poszero[i]] - lenone[l-1]) != (lenzero[poszero[i]] - lenzero[l-1]) && poszero[i] != 1 && l < i){
					if (l + 1 < i) l ++ ;
					else break;
				}
				ans = max(ans, poszero[i] - l + 1);
			}
			else if (lenone[poszero[i]] - lenone[l-1] < lenzero[poszero[i]] - lenzero[l-1] && poszero[i] != 1){
				while ((lenone[poszero[i]] - lenone[l-1]) != (lenzero[poszero[i]] - lenzero[l-1]) && poszero[i] != 1 && l >= 1){
					if (l - 1 > 1) l -- ;
					else break;
				}
				ans = max(ans, poszero[i] - l + 1);
			}
		}
	}
	cout << ans;
	return 0;
}