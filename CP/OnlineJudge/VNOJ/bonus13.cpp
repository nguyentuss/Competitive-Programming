#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")
#define N (int) (1e2)

struct pos {
	int x , y;
};

int k , count_1 = 0 , count_2 = 0;
int counted = 0;
vector <pos> freeb(100);
vector <pos> bonus(100);
vector <vector<long long>> table(10 , vector<long long> (10 , 0));
vector <vector<long long>> cnt_t(10 , vector<long long> (10 , 0));
vector <pos> X(100);
vector <long long> cnt_x(100) , cnt_y(100) , cnt_ch1(100) , cnt_ch2(100);
vector <bool> C(100 , false);
long long ans = -1;
const int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
const int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};

void update() {
	long long total = 0;
	for (int i = 1 ; i <= count_2; i++) {
		int x = bonus[i].x , y = bonus[i].y;
		if (cnt_t[x][y] || cnt_x[x] || cnt_y[y] || cnt_ch1[x + y] || cnt_ch2[x - y + 8]){
			total += table[x][y];
		}
	}
	ans = max(ans , total);
}
void put(int type, int x, int y, int v) {
    if (type == 1 || type == 2)
        cnt_x[x] += v, cnt_y[y] += v;
    if (type == 1 || type == 3)
        cnt_ch1[x + y] += v, cnt_ch2[x - y + 8] += v;
    if (type == 4){
	    for (int i = 0 ; i < 8 ; i++) {
	       	int a = x + dx[i] ,b = y + dy[i];
	        if (0 < a && 0 < b && a < 9 && b < 9)
	            cnt_t[a][b] += v;
	    }
	}
}

void backtr(int i) {
	for (int j = 1 ; j <= count_1 ; j++) {
		if (!C[j]){
			put(i , freeb[j].x , freeb[j].y , 1);
			C[j] = true;
			if (i == 4) update();
			else backtr(i + 1);
			C[j] = false;
			put(i , freeb[j].x , freeb[j].y , -1);
		}
	}
}
int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.out","w",stdout);
	cin >> k;
	int u , v , w;
	for (int i = 1 ; i <= k ; i++) {	
		cin >> u >> v >> w;
		table[u][v] = w;
	}
	for (int i = 1 ; i <= 8 ; i++) {
		for (int j = 1; j <= 8 ; j++) {
			if (!table[i][j]) 
				freeb[++count_1] = (pos) {i , j};
			else bonus[++count_2] = (pos) {i , j};
		}
	}
	backtr(1);
	cout << ans;
	return 0;
}