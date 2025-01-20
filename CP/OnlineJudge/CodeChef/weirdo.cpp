#include <iostream>
#include <string>
#include <cmath>
#include <math.h>
#include <iomanip>

using namespace std;

string s[100005];

int main () {
	ios::sync_with_stdio(0); cin.tie(NULL);
	//freopen("text.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n ; cin >> n;
	while (n --){
		string a[10005] , b[10005];
		int countval[10005] = {0} , posa = 0 , posb = 0;
		bool check = false;
		int t; cin >> t;
		for (int i = 1 ; i <= t ; i ++)
			cin >> s[i];	
		for (int i = 1 ; i <= t ; i ++) {
			for (long long j = 0 ; j < s[i].size() ; j ++){
				countval[j] = countval[j - 1];
				if ((s[i][j] == 'a') || (s[i][j] == 'i') || (s[i][j] == 'u')	
					|| (s[i][j] == 'o') || (s[i][j] == 'e')) 
					countval[j] ++;
			}
			int maxi = 0; bool check = true;
			for (long long j = 1; j < s[i].size() ; j ++) {
				int right = 2*countval[j] - (j + 1);
				int left = 2*countval[j - 1] - j;
				if (right < maxi) {
					posb ++;
					b[posb] = s[i];
					check = false;
					break;
				}
				maxi = max(maxi , left);
			}
			if (check) {
				posa ++;
				a[posa] = s[i];
			}
		}
		int appeara[26] = {0} , counta[26] = {0} ; 
		for (int i = 1 ; i <= posa ; i++){
			int worda[26] {0};
			for (char &c : a[i]) {
				worda[c - 'a'] ++;
				counta[c - 'a'] ++;
				if (worda[c - 'a'] == 1) appeara[c - 'a'] ++;
			}	
		}
		int appearb[26] = {0} , countb[26] = {0};
		for (int i = 1 ; i <= posb ; i++){
			int wordb[26] {0};
			for (char &c : b[i]) {
				wordb[c - 'a'] ++;
				countb[c - 'a'] ++;
				if (wordb[c - 'a'] == 1) appearb[c - 'a'] ++;
			}
		}
		//cout << counta[0] << " " << appeara[0];
		double sca = 1 , scb = 1 , sum = 1;
		for (int i = 0 ; i < 26 ; i ++){
			if (appeara[i] != 0 && counta[i] != 0)
				sca = (appeara[i] / pow(counta[i] , posa)); 
			//cout << sca << endl;
			if (appearb[i] != 0 && countb[i] != 0){
				scb = (appearb[i] / pow(countb[i] , posb));
			}
			if (appearb[i] != 0 && appeara[i] != 0 && counta[i] != 0 && countb[i] != 0)
				sum *= sca / scb;
			if (sum > 10000000) {
				cout << "Infinity" ;
				check = true;
				break;
			}
		}
		if (!check)
		cout << fixed << setprecision(7) << sum << endl;
		
		}
	return 0;
}