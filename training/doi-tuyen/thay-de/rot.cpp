/*
#################################################################
#                             _`                                #
#                          _ooOoo_                              #
#                         o8888888o                             #
#                         88" . "88                             #
#                         (| -_- |)                             #
#                         O\  =  /O                             #
#                      ____/`---'\____                          #
#                    .'  \\|     |//  `.                        #
#                   /  \\|||  :  |||//  \                       #
#                  /  _||||| -:- |||||_  \                      #
#                  |   | \\\  -  /'| |   |                      #
#                  | \_|  `\`---'//  |_/ |                      #
#                  \  .-\__ `-. -'__/-.  /                      #
#                ___`. .'  /--.--\  `. .'____                   #
#             ."" '<  `.___\_<|>_/___.' _> \"".                 #
#            | | :  `- \`. ;`. _/; .'/ /  .' ; |                #
#            \  \ `-.   \_\_`. _.'_/_/  -' _.' /                #
#=============`-.`___`-.__\ \___  /__.-'_.'_.-'=================#
                           `=--=-'                    



          _.-/`)
         // / / )
      .=// / / / )
     //`/ / / / /
    // /     ` /
   ||         /
    \\       /
     ))    .'
    //    /
         /
    Mong Phat do code khong bi bug :<
    Mong Phat do code khong bi tle :<
    Mong Phat do code khong bi RTE :<
    Mong Phat do code khong bi WA :<
*/

#include <bits/stdc++.h>

using namespace std;

char a[20][20];
char v[20][20];

void init(int n , int m) {
	vector<char> v1[11];
	vector<char> v2[11];
	int len1 = 0;
	for (int i = 1 ; i <= n ; i++) {
		len1 ++;
		int x = i , y = 1;
		while (x && y <= m) {
			v1[len1].push_back(v[x][y]);
			x--; y++;
		}	
	}
	int len2 = 0;
	for (int i = 2 ; i <= m ; i++) {
		len2 ++;
		int x = n , y = i;
		while (x && y <= m) {
			v2[len2].push_back(v[x][y]);
			x--; y++;
		}
	}
	int tmp = n;
	for (int i = 1 ; i <= len1 ; i++) {
		tmp--;
		for (int j = 1 ; j <= tmp ; j++) 
			cout << " ";
		for (int j = 0 ; j < v1[i].size() ; j++){
			char x = v1[i][j];
			if (j == (v1[i].size() - 1)) cout << x;
		 	else cout << x << " ";
		}
		cout << '\n';
	}
	for (int i = 1 ; i <= len2 ; i++) {
		int space = i;
		for (int j = 1 ; j <= space ; j++) cout << " ";
		for (int j = 0 ; j < v2[i].size() ; j++){
			char x = v2[i][j];
			if (j == (v2[i].size() - 1)) cout << x;
		 	else cout << x << " ";
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("rot.inp","r",stdin);
	freopen("rot.out","w",stdout);
	int n , m; cin >> n >> m;
	for (int i = 1 ; i <= n ;i++) {
		for (int j = 1 ; j <= m ; j++) {
			cin >> a[i][j];
		}
	}
	int k; cin >> k;
	if (k == 90) {
		for (int i = 1 ; i <= m ; i++) {
			for (int j = n ; j >= 1 ; j--) {
				cout << a[j][i];
			}
			cout << '\n';
		}
	}
	if (k == 180) {
		for (int i = n ; i >= 1 ; i--) {
			for (int j = m ; j >= 1 ; j--) {
				cout << a[i][j];
			}
			cout << '\n';
		}
	}
	if (k == 270) {
		for (int i = m ; i >= 1 ; i --) {
			for (int j = 1 ; j <= n ; j++)  {
				cout << a[j][i];
			}
			cout << '\n';
		}
	}
	if (k == 360 || k == 0) {
		for (int i = 1 ; i <= n ;i++) {
			for (int j = 1 ; j <= m ; j++) {
				cout << a[i][j];
			}
			cout << '\n';
		}
	}
	if (k == 45) {
		for (int i = 1 ; i <= n ;i++) {
			for (int j = 1 ; j <= m ; j++) {
				v[i][j] = a[i][j];
			}
		}
		init(n , m);
	}
	if (k == 135) {
		int sz1 = 0 , sz2 = 0;
		for (int i = 1 ; i <= m ; i++) {
			sz1++;
			int s2 = 0;
			for (int j = n ; j >= 1 ; j--) {
				s2++;
				v[sz1][s2] = a[j][i];
			}
			sz2 = s2;
		}
		init(sz1 , sz2);
	}
	if (k == 225) {
		int sz1 = 0 , sz2 = 0;
		for (int i = n ; i >= 1 ; i--) {
			sz1++;
			int s2 = 0;
			for (int j = m ; j >= 1 ; j--) {
				s2++;
				v[sz1][s2] = a[i][j];
			}
			sz2 = s2;
		}
		init(sz1 , sz2);
	}
	if (k == 315) {
		int sz1 = 0 , sz2 = 0;
		for (int i = m ; i >= 1 ; i--) {
			sz1++;
			int s2 = 0;
			for (int j = 1 ; j <= n ; j++) {
				s2++;
				v[sz1][s2] = a[j][i];
			}
			sz2 = s2;
		}
		init(sz1 , sz2);

	}
	return 0;
}
/*

3 5
damir
marko
darko
45
*/
/*dmd
aaa
rrm
kki
oor*/
