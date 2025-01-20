#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

int n ;
long long m;
int v[100] , x[100];
vector <string> s;

int backtr(int i) {

	for (int j = 0 ; j <= 1 ; j ++) {
		x[i] = j;
		if (i == n - 1) {
			long long total = v[1];
			for (int k = 2 ; k <= n ; k ++) {
				if (x[k - 1] == 0) total -= v[k];
				else total += v[k]; 
			}
			if (total == m) {
				string str ="";
				for (int k = 1 ; k <= n - 1 ; k++) {
					if (x[k] == 0) {
						if (v[k + 1] >= 0) 
							str += "1";
						else str += "0";
					}
					else {
						if (v[k + 1] >= 0) str += "0";
						else str += "1";
					}
				}
				s.push_back(str);
			}
			
			/*if (total == m) {
				for (int k = 1; k <= n - 1; k ++) cout << x[k] << " " ;
				cout << endl;
			}*/
		}
		else backtr(i + 1);
	}

	return 0;
}

int main() {
	boost;

	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) {
		cin >> v[i];
	}

	backtr(1);

	sort(s.begin() , s.end());
	for (int i = 0 ; i < (int) s.size() ; i++) {
		cout << v[1];
		string a = s[i];
		for (int j = 0 ; j < (int) a.size() ; j ++) {
			if (a[j] == '0') cout << "+";
			else cout << "-";
			cout << abs(v[j + 2]);
		}
		cout << endl;
	}

	return 0;
}