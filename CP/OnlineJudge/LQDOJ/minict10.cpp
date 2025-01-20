#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

#define boost ios::sync_with_stdio(0);cin.tie(NULL);

int main(){
	boost;	
	string st;
	cin >> st;

	sort(st.begin() , st.end());

	int count = 0;
	for (int i = 0 ; i < (int) st.size() ; i++) 
		if (st[i] == '+') count ++;

	for (int i = count ; i < (int) st.size() ; i++) {
		cout << st[i];
		if (i != (int) st.size() - 1) cout << "+";
	}

	return 0;
}