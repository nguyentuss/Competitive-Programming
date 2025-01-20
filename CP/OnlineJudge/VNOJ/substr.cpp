#include <bits/stdc++.h>
using namespace std;

const int base = 31;

vector <long long> POW(1000007) , hashA(1000007);
long long getHash(int i , int j) {
	return (hashA[j] - hashA[i - 1]*POW[j - i + 1]);
}

string A , B;
int main(){
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B;
	int lenA = A.size() , lenB = B.size();
	POW[0] = 1;
	A = " " + A;
	B = " " + B;
	for (int i = 1 ; i <= lenA ; i++) {
		POW[i] = POW[i - 1]*base;
	}
	//cout << POW[1000];
	long long hashB = 0;
	for (int i = 1 ; i <= lenB ; i++) {
		hashB = hashB*base + B[i] - 'a' + 1; 
	} 
	for (int i = 1 ; i <= lenA ; i++) 
		hashA[i] = hashA[i - 1]*base + A[i] - 'a' + 1; 
	for (int i = 1 ; i <= lenA - lenB + 1; i++) {
		//if (A[i] == B[1]) {
			if (hashB == getHash(i , i + lenB - 1)) {
				cout << i << " ";
			}
		//}
	}

	return 0;
}