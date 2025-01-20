#include <iostream>
#include <string>

using namespace std;


int main(){
	int t; cin >> t;
	while (t--){
		int n ; cin >> n;
		string st;	cin >> st;
		if (n == 1) {
			int so = st[0] - '0';
			if (so % 2 == 0)
				cout << 2 << endl;
			else cout << 1 << endl;
		}
		else {
		if (n % 2 == 0) 
		{
			bool kt = true;
			for (int i = 1 ; i < n ; i += 2){
				int so = st[i] - '0';
				if (so % 2 == 0){
					cout << 2 << endl;
					kt = false;
					break;
				}

			}
			if (kt) cout << 1 << endl;
		}
		else {
			bool kt = true;
			for (int i = 0 ; i < n ; i += 2){
				int so = st[i] - '0';
				if (so % 2 != 0){
					cout << 1 << endl;
					kt = false;
					break;
				}
			}
			if (kt) cout << 2 << endl;
		}
	}
	}
	return 0;
}