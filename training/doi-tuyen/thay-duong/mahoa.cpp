#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int k;
string str;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("MAHOA.inp","r",stdin);
	freopen("MAHOA.out","w",stdout);
	cin >> k;
	while (cin >> str) {
		for (int i = 0 ; i < (int) str.size() ; i++){
			if (((str[i] >= 'A') && (str[i] <= 'Z'))){
				if ((str[i] + k) > 'Z') 
					str[i] = (str[i] + k)%'Z' + 'A' - 1;
				else str[i] += k;
			}
			else if ((str[i] >= 'a') && (str[i] <= 'z')) {
				if ((str[i] + k) > 'z') 
					str[i] = (str[i] + k)%'z' + 'a' - 1;
				else str[i] += k;
			}
			cout << str[i];
		}
		cout << " ";
	}

	return 0;
}