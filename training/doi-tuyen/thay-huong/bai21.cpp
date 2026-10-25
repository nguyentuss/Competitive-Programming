#include <iostream>
#include <string>
#include <algorithm>
using namespace std; 

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("bai21.inp","r",stdin);
	freopen("bai21.out","w",stdout);

	string s;
	cin >> s; 
	int k ; cin >> k;
	//long long minn = 1e18;

	while (k --)
	for (long long i = 0 ; i < s.size(); i ++){
		if (s[i] > s[i+1]) {
			s.erase(i,1);  
			//cout << s << endl;  
			break;
		} 
	}
	/*if (s[0] == '0'){
		reverse(s.begin(),s.end());
			cout << s;
		return 0;
	}
	*/
	cout << s;
	return 0;
}