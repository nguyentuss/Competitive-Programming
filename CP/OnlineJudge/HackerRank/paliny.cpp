#include <bits/stdc++.h>

using namespace std; 

#define base (int) (311)
#define MAX_N (int) (5*1e4 + 7)

int len;
string s , revs;
int x , y;
bool ch1 , ch2;
vector <long long> hashS(MAX_N) , revhash(MAX_N) , POW(MAX_N);

long long getHash(int i , int j) {
	return (hashS[j] - hashS[i - 1]*POW[j - i + 1]);
}
long long getrevHash(int i , int j) {
	return (revhash[j] - revhash[i - 1]*POW[j - i + 1]);
}

bool check(int val) {
	for (int i = 1 ; i <= len - 2*val + 2 ; i++) {
		int j = i + val - 1;
		if (getHash(i , j) == getrevHash(len - (j + val) + 1  , len - (i + val) + 1) && i != len - 2*val + 2) {
			x = i , y = j;
			ch1 = true;
			return true;
		}
		if (getHash(i , j) == getrevHash(len - (j + val) + 2 , len - (i + val) + 2)) {
			x = i , y = j;
			ch2 = true;
			return true;
		}
	}
	return false;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> len;
	cin >> s;
	revs = s , reverse(revs.begin() , revs.end());
	s = ' ' + s , revs = ' ' + revs , POW[0] = 1;
	for (int i = 1 ; i <= len ; i++) {
		POW[i] = POW[i - 1]*base;
		hashS[i] = hashS[i - 1]*base + s[i];
		revhash[i] = revhash[i - 1]*base + revs[i];
	} 
	int l = 1 , r = len , ans = -1;
	while (l <= r) {
		int mid = (l + r)/2;
		ch1 = ch2 = false;
		if (check(mid)) {
			if (ch1) ans = mid*2;
			else ans = mid*2 - 1;
			l = mid + 1;
			//cout << x << " " << y << " " << ans << '\n';
		}	
		else 
			r = mid - 1;
	}
	cout << ans << '\n';
	return 0;
}