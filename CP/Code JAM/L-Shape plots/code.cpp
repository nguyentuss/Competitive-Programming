#include <bits/stdc++.h>

using namespace std;

struct matrix
{
	int i , j;
	char command1 , command2;
};

int n , m;
vector <vector <int>> adj(2001 , vector <int> (2001));
vector <matrix> v;

void check(int i , int j , int ni1 , int nj1 , int ni2 , int nj2 ,char go1 , char go2 ) {
	if (adj[i][j] && adj[ni1][nj1] && adj[ni2][nj2] && ni1 <= n && nj1 <= m && ni2 <= n && nj2 <= m) 
		v.push_back({i , j , go1 , go2});
}

/* cach nhanh hon xet tu tren xuong duoi up[i][j] = up[i - 1][j] + 1 tuong tu nhu down right left*/

int calc(int x , int y) {
	int sum = 0;
	sum += min(x / 2 , y) - 1;
	sum += min(y / 2 , x) - 1;
	return sum;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(NULL);

	int t;
	cin >> t;
	for (int test = 1 ; test <= t ; test ++) {
		v.clear();
		cin >> n >> m;
		for (int i = 1 ; i <= n ; i++) {
			for (int j = 1 ; j <= m ; j++) {
				cin >> adj[i][j];
			}
		}
		for (int i = 1 ; i <= n ; i++) {
			for (int j = 1 ; j <= m ; j++) {
				check(i , j , i , j - 1 , i - 1 , j , 'l' ,'u');
				check(i , j , i - 1 , j  , i , j + 1 ,'u' , 'r');
				check(i , j , i , j + 1 , i + 1 , j , 'r' , 'd');
				check(i , j , i + 1 , j , i , j - 1 , 'd' , 'l');
			}
		}
		int ans = 0;
		for (int i = 0 ; i < (int) v.size() ; i++) {
			int x = v[i].i , y = v[i].j;
			char c1 = v[i].command1 , c2 = v[i].command2;
			int count1 = 0 , count2 = 0;
			if (c1 == 'l' && c2 == 'u') {
				for (int i = x ; i >= 1 ; i --) {				
					if (adj[i][y] == 1) count2 ++;
					else break;
				}
				for (int i = y ; i >= 1 ; i --) {
					if (adj[x][i] == 1) count1 ++;
					else break;
				}
				ans += calc(count1 ,count2);
			}
			else if (c1 == 'u' && c2 == 'r') {
				for (int i = x ; i >= 1 ; i --) {
					if (adj[i][y] == 1) count1 ++;
					else break;
				}
				for (int i = y ; i <= m ; i ++) {
					if (adj[x][i] == 1) count2 ++;
					else break;
				}
				ans += calc(count1 ,count2);
			}
			else if (c1 == 'r' && c2 == 'd') {
				for (int i = y ; i <= m ; i++) {
					if (adj[x][i] == 1) count1 ++;
					else break;
				}
				for (int i = x ; i <= n ; i++) {
					if (adj[i][y] == 1) count2 ++;
					else break;
				}
				ans += calc(count1 ,count2);
			}
			else if (c1 == 'd' && c2 == 'l') {
				for (int i = x ; i <= n ; i++) {
					if (adj[i][y] == 1) count1 ++;
					else break;		
				}
				for (int i = y ; i >= 1 ; i--) {
					if (adj[x][i] == 1) count2 ++;
					else break;
				}
				ans += calc(count1 ,count2);
			}
		}
		cout << "Case #" << test << ": " <<  ans << endl;

	}
	return 0;
}