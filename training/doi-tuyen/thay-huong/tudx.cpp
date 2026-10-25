#include <iostream>
#include <string>

using namespace std;

int main(){
	freopen("tudx.inp","r",stdin);
	freopen("tudx.out","w",stdout);

	string st;
	cin >> st;
	int d = st.size(); 
	bool check = true; 
	for (long long i = 0 ; i < st.size() / 2 ; i++)
	{
		d --;
		if (st[i] != st[d]) {
			cout << "NO";
			return 0;
		}
	}
	if (check) 
		cout << "YES";
	return 0;
}