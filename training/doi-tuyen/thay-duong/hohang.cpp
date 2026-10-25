#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

string s1 , s2;

vector <int> counted1(27,0);
vector <int> counted2(27,0);

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("hohang.inp","r",stdin);
	freopen("hohang.out","w",stdout);
	cin >> s1 >> s2;
	for (int i = 0 ; i < (int) s1.size() ; i++) 
		counted1[s1[i] - 'a']++;

	for (int i = 0 ; i < (int) s2.size() ; i++) 
		counted2[s2[i] - 'a']++;

	long long ans = 0;

	for (int i = 0 ; i <= 25 ; i++) {
		if (counted1[i] > 0 && counted2[i] == 0) {
			ans += counted1[i];
		}
		else if (counted1[i] == 0 && counted2[i] > 0) 
			ans += counted2[i];
	}
	cout << ans;

	return 0;
}