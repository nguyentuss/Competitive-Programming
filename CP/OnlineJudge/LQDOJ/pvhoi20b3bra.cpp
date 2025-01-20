#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")

struct seg {
	int freeO , freeC;
};

using namespace std;

int n , m , q;
string s;
vector <seg> IT(400007);

seg calc(int index , int l , int r , int L , int R) {
	if (l > R || L > r) 
		return seg{0 , 0};
	if (l <= L && r >= R) 
		return IT[index];
	int mid = (L + R)/2;
	seg temp;
	seg vLeft = calc(2*index , l , r , L , mid);
	seg vRight = calc(2*index + 1 , l , r , mid + 1 , R); 
	temp.freeO = vLeft.freeO  - min(vLeft.freeO , vRight.freeC) + vRight.freeO;
	temp.freeC = vRight.freeC - min(vRight.freeC , vLeft.freeO) + vLeft.freeC;
	return temp;
}

void update(int index , int l , int r , int i , char change) {
	if (l > i || r < i) return;
	if (l == r) {
		if (change == '(') {
			IT[index].freeO = 1;
			IT[index].freeC = 0;
		}
		else {
			IT[index].freeC = 1;
			IT[index].freeO = 0;
		}
		return;
	}
	int mid = (l + r)/2;
	update(2*index , l , mid , i , change);
	update(2*index + 1 , mid + 1 , r , i , change);
	IT[index].freeO = IT[2*index].freeO - min(IT[2*index].freeO , IT[2*index + 1].freeC) + IT[2*index + 1].freeO;
	IT[index].freeC = IT[2*index+1].freeC - min(IT[2*index+1].freeC , IT[2*index].freeO) + IT[2*index].freeC;
	return; 
}

void segmenttree(int index , int l , int r) {
	if (l == r) {
		if (s[l] == '(') {
			IT[index].freeO = 1;
			IT[index].freeC = 0;
		}
		else {
			IT[index].freeC = 1;
			IT[index].freeO = 0;
		}
		return;
	}
	int mid = (l + r)/2;
	segmenttree(2*index , l , mid);
	segmenttree(2*index + 1 , mid + 1 , r);
	IT[index].freeO = IT[2*index].freeO - min(IT[2*index + 1].freeC , IT[2*index].freeO) + IT[2*index + 1].freeO;
	IT[index].freeC = IT[2*index + 1].freeC - min(IT[2*index + 1].freeC , IT[2*index].freeO) + IT[2*index].freeC;
	return;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	cin >> n >> q;
	cin >> s;
	s = '0' + s;
	segmenttree(1 , 1 , n);
	int ask , l , r , pos;
	char change;
	for (int ask = 1 ; ask <= q ; ask++) {
		cin >> pos;
		if (s[pos] == '(') {
			s[pos] = ')';
			update(1 , 1 , n , pos , ')');
		}
		else {
			s[pos] = '(';
			update(1 , 1 , n , pos , '(');
		}
		for (int i = 1 ; i <= n ; i++) {
			char change;
			if (s[i] == '(') change = ')';
			else change = '(';
			update(1 , 1 , n , i , change);
			seg x = calc(1 , 1 , n , 1 , n);
			if ((x.freeO + x.freeC) == 0) {
				s[i] = change;
				cout << i << " ";
				break;
			}
			else {
				update(1 , 1 , n , i , s[i]);
			}
		}
	}


	return 0;

}