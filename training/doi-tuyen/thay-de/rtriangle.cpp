#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (2e3 + 7)
#define ii pair<int ,int>
#define iii pair<int , ii>

struct orc{
	int cnt = 0 , x , y;
};

struct pos{
	int x , y;
};

struct heso {
	int a , b , c;
};

map<iii , int> check;
int n;
pos a[MAX_N];
vector<orc> adj;
pos npos[MAX_N]; 
int f[4];
pos root;
int ans = 0;


void pt(pos A , pos B) {
	int a = A.y - B.y , b = B.x - A.x;
	int c = -(a*A.x + b*A.y);	
	check[iii(a , ii(b , c))] ++;
}

heso write(pos a , pos b) {
	int a = A.y - B.y , b = B.x - A.x;
	int c = -(a*A.x + b*A.y);	
	return heso(a , b , c);
}

void quay(int status , pos A) {
	if (status == 1) {
		pos B;
		B.x = -A.y;
		B.y = A.x;
		heso tmp = write(root , B);
		f[1] = check[ii(tmp.a , ii(tmp.b , tmp.c))];
	}
	if (status == 2) {
		pos B;
		B.x = -A.x;
		B.y = -A.y;
		heso tmp = write(root , B);
		f[2] = check[ii(tmp.a , ii(tmp.b , tmp.c))];
	}
	if (status == 3) {
		pos B;
		B.x = A.y;
		B.y = -A.x;
		heso tmp = write(root , B);
		f[3] = check[ii(tmp.a , ii(tmp.b , tmp.c))];
	}
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("test.inp","r",stdin);
	cin >> n;
	for (int i = 1; i <= n ; i++) {
		cin >> a[i].x >> a[i].y;
	}
	for (int i = 1 ; i <= n ; i++) {
		check.clear();
		root = a[i];
		for (int j = 1 ; j <= n ; j++) {
			npos[j].x = a[j].x - a[i].x;
			npos[j].y = a[j].y - a[i].y;
			pt(root , npos[j]);
		}
		for (int j = 1 ; j <= n ; j++) {
			heso tmp = write(root , npos[j]);
			f[0] = check[iii(tmp.a , ii(tmp.b , tmp.c))];
			quay(1 , npos[j]); quay(2 , npos[j]); quay(3 , npos[j]);
			ans += f[0]*f[1] + f[1]*f[2] + f[2]*f[3];
		}
	}
	cout << ans;
	return 0;
}