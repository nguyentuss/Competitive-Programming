#include <iostream>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <limits.h>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

string s;

int main() {
	boost;

	cin >> s;

	string a = "";
	long long ans = INT_MIN; 
	for (int i = 0 ; i < (int) s.size() - 2 ; i++) {
		string b = "";
		a += s[i];
		for (int j = i + 1 ; j < (int) s.size() - 1 ; j ++) {
			string c = "";
			b += s[j];
			for (int k = j + 1 ; k < (int) s.size() ; k ++){
				c += s[k];
				long long edge1 , edge2 , edge3;
				edge1 = atoi(a.c_str());
				edge2 = atoi(b.c_str());
				edge3 = atoi(c.c_str());
				//cout << edge1 << " " << edge2 << " " << edge3 << endl;
				if ((edge1*edge1 + edge2*edge2 == edge3*edge3) || (edge1*edge1 + edge3*edge3 == edge2*edge2) || (edge3*edge3 + edge2*edge2 == edge1*edge1)) {
					ans = max(edge1 , max(edge2,edge3));

				}
			}
		}
	}
	cout << ans;

	return 0; 
}