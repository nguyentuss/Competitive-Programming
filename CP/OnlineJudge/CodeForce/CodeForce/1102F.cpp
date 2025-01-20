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
*/

#include <bits/stdc++.h>

using namespace std;

#define inf (int) (1e9 + 7)
#define MAX_N (int) (1e4 + 7)

int n , m;
int f[17][17][(1<<16) + 7];
int fmin1[17][17];
int fmin2[17][17];
int a[17][MAX_N];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	cout.tie(NULL);
	freopen("test.inp","r",stdin);
	freopen("test.out","w",stdout);
	cin >> n >> m;
	for (int i = 0 ; i < n; i++) {
		for (int j = 0 ; j < m ;j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0 ; i < n ;i++) {
		for (int j = 0 ; j < n ; j ++) {
			fmin1[i][j] = inf;
			fmin2[i][j] = inf;
		}
	}
	for (int i = 0; i < n ;i++) {
		for (int j = 0 ; j < n ; j ++) {
			for (int k = 0 ; k < m ; k++) {
				fmin1[i][j] = min(fmin1[i][j] , abs(a[i][k] - a[j][k]));
				if (k < (m - 1)) 
					fmin2[i][j] = min(fmin2[i][j] , abs(a[i][k] - a[j][k + 1]));
			}
		}
	}
 	for (int mask = 0 ; mask < (1<<n) ; mask++) {
		for (int i = 0 ; i < n ;i++) {	
			for (int j = 0 ; j < n ; j++) {
					f[i][j][mask] = 0;
			}
		}
	}
	for (int i = 0 ; i < n ; i++) {
		f[i][i][1<<i] = inf;
	}
	for (int mask = 0 ; mask < (1 << n) ; mask++) {
		for (int i = 0 ; i < n ; i++) {
			for (int start = 0 ; start < n ; start++) {
			if (f[i][start][mask]) {
				for (int j = 0 ; j < n ; j++) {
					if (!(mask & (1 << j))) {
						f[j][start][mask | (1 << j)] = max(f[j][start][mask | (1 << j)] , 
							min(f[i][start][mask] , fmin1[i][j]));
						}
					}
				}
			}
		}
	}
	int res = 0;
	for (int start = 0 ; start < n ; start++) {
		for (int i = 0 ; i < n ; i++) {
			res = max(res , min(f[i][start][(1 << n) - 1] , fmin2[i][start]));
		}
	}
	cout << res;
	return 0;
}