#include <bits/stdc++.h>

using namespace std;

#define base (int) (311)

string A , B;
int k , lenA , lenB;
vector <long long> POW(1e5 + 7) , hashA(1e5 + 7) ;
map<long long , bool> cnthashB;

long long gethash(int i , int j) {
	return (hashA[j] - hashA[i - 1]*POW[j - i + 1]);
}

bool check(int val) {
	int cnt = 0;
	for (int i = 1 ; i <= lenA - val + 1 ; i++) {
		int j = i + val - 1;
		long long tmp = gethash(i , j);
		if (!cnthashB[tmp]) continue;
		else {
			//cout << i << " " << j << " " << val <<  '\n';
			cnt ++;
			if (cnt >= k) return true;
		}
	}
	return false;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	getline(cin , A);
	getline(cin , B);
	lenA = A.size() , lenB = B.size();
	A = ' ' + A;
	B = ' ' + B;
	cin >> k;
	POW[0] = 1;
	for (int i = 1 ; i <= lenA ; i++) {
		POW[i] = POW[i - 1]*base;
	}
	long long hashB = 0;
	for (int i = 1 ; i <= lenB ; i++) {
		hashB = hashB*base + B[i]; 
		cnthashB[hashB] = true;
	}
	for (int i = 1 ; i <= lenA ; i++) 
		hashA[i] = hashA[i - 1]*base + A[i];

	int l = 1 , r = lenB;
	int ans = 0;
	while (l <= r) {
		int mid = (l + r)/2;
		if (check(mid)) {	
			ans = mid;
			l = mid + 1; 
		}
		else {
			r = mid - 1;
		}
	}
	if (!ans) cout << "IMPOSSIBLE" << '\n';
	else {
		for (int i = 1 ; i <= ans ;i++) 
			cout << B[i];
	}

	return 0;
}