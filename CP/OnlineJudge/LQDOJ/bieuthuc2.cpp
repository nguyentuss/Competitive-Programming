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

	x[0] = 1;
	bool checkcount = false;
	long long mul = 0;
	bool kt = false;
	for (int j = 0 ; j <= 2 ; j ++) {
		x[i] = j;
		if (i == n - 1) {
			long long total;
			if (x[1] == 2 && x[2] == 1 && x[3] == 2 && x[4] == 0) kt = true;
			if (x[1] != 2) total = v[1];
			else total = 0;
			bool check = false;
			for (int k = 2 ; k <= n ; k ++) {
				if (x[k - 1] == 0 && x[k] != 2) {
					total -= v[k];
					if (checkcount)
						if (check == false) {
								total += mul;
								mul = 0;
								checkcount = false;
						}
						else {
							total -= mul;
							mul = 0; 
							checkcount = false;
						}
				}
				else if (x[k - 1] == 1 && x[k] != 2) {
					total += v[k];
					if (checkcount)
						if (check == false) {
								total += mul;
								mul = 0;
								checkcount = false;
						}
						else {
							total -= mul;
							mul = 0; 
							checkcount = false;
						}

				}
				else if ((x[k - 1] == 1 || x[k - 1] == 0) && x[k] == 2) {
					if (checkcount)
						if (check == false) {
								total += mul;
								mul = 0;
								checkcount = false;
						}
						else {
							total -= mul;
							mul = 0; 
							checkcount = false;
						}
					if (x[k - 1] == 0)
						check = true;
					else 
						check = false;
					
				}
				else if (x[k - 1] == 2) {
					if (!checkcount) {
						checkcount = true;
						mul = v[k - 1];
					}
					mul *= v[k];
				}
		
			}	
			if (checkcount)
						if (check == false) {
								total += mul;
								mul = 0;
								checkcount = false;
						}
						else {
							total -= mul;
							mul = 0; 
							checkcount = false;
						}
			//if (kt == true) cout << total << endl;
			kt = false;
			if (total == m) {
				string str ="";
				//for (int k = 1 ; k <= n - 1 ; k ++) cout << x[k] << " ";
				//cout << endl;
				for (int k = 1 ; k <= n - 1 ; k++) {
					if (x[k] == 0) {
						str += "-";
					}
					else if (x[k] == 1) 
						str += "+";
					else str += "*";
				}
				//cout << str << endl;
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
			if (a[j] == '+') cout << "+";
			else if (a[j] == '-') cout << "-";
			else if (a[j] == '*') cout << "*";
			cout << v[j + 2];
		}
		cout << endl;
	}

	return 0;
}