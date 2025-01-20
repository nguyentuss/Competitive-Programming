#include <iostream>

using namespace std;


int main(){
	ios::sync_with_stdio(0); cin.tie(NULL); 

	int n , k ;	cin >> n >> k;
	int a[100005] , s[100005] = {0}, l = 0 , r = 0 , dem = 0;

	for (int i = 1 ; i <= n ; i++) 
		cin >> a[i];

	for (int i = 1 ; i <= n; i++){
		s[a[i]] ++;
		if (s[a[i]] == 1 ) dem++;
		if (dem == k) {
			r = i;
			break;
		}
	}
	//cout << r;
	cout << s[a[1]];
	for (int i = 1 ; i <= n ; i++){
		s[a[i]] --;
		//cout << s[a[i]] << " " ;
		if (s[a[i]] == 0) {
			l = i;
			break;
		}
	}
	if (dem < k) {
		cout << l << " " << n;
		return 0;
	}
	cout << l << " " << r;
	return 0;
}