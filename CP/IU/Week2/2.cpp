#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   	for (int a = 0 ; a <= 30 ; a++) {
   		for (int b = 0 ; b <= 15 ; b++) {
   			for (int c = 0 ; c <= 6 ; c++) {
   				for (int d = 0 ; d <= 3 ; d++) {
   					if ((a + b*2 + c*5 + d*10) == 30) {
   						if (a) cout << a << " notes of 1,000 ";
   						if (b) cout << b << " notes of 2,000 ";
   						if (c) cout << c << " notes of 5,000 ";
						if (d) cout << d << " notes of 10,000 ";
						cout << '\n';
   					}
   				}
   			}
   		}
   	}
    return 0;
}
