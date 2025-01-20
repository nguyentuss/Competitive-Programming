#include <bits/stdc++.h>

using namespace std;

string A , B;

void addzero() {
	while ((int) A.size() < (int) B.size()) A = '0' + A;
	while ((int) A.size() > (int) B.size()) B = '0' + B;
	reverse(A.begin() , A.end());
	reverse(B.begin() , B.end());
}

string cong() {
	string temp = "";
	int count = 0;
	for (int i = 0 ; i < (int) A.size() ; i++) {
		int numa = A[i] - '0' , numb = B[i] - '0';
		if (numa + numb + count > 9) {
			temp += (numa + numb + count)%10 + '0';
			count = (numa + numb + count)/10;
		} 
		else {
			temp += numa + numb + count + '0';
			count = 0;
		}
	}
	if (count) temp += '1';
	reverse(temp.begin() , temp.end());
	return temp;
}

string tru() {
	string temp = "";
	int count = 0;
	for (int i = 0 ; i < (int) A.size() ; i++) {
		int numa = A[i] - '0' , numb = B[i] - '0';
		if (numa - numb + count > 9) {
			temp += (numa + numb + count)%10 + '0';
			count = (numa + numb + count)/10;
		} 
		else {
			temp += numa + numb + count + '0';
			count = 0;
		}
	}
	if (count) temp += '1';
	reverse(temp.begin() , temp.end());
	return temp;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("bignum.inp","r",stdin);
	freopen("bignum.out","w",stdout);
	cin >> A >> B;
	addzero();
	cout << cong() << '\n';
	cout << tru() << '\n';
	return 0;
}