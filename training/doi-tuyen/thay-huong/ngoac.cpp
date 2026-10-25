#include <iostream>
#include <string>
#include <stack>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define fi freopen("ngoac.inp","r",stdin);
#define fo freopen("ngoac.out","w",stdout);

string st;
stack <long> s;

int main(){
	boost;
	fi;fo;
	cin >> st;
	long n = st.size();
	for (long i = 0 ; i < n ; i++){
		if (st[i] == '(') s.push(i);
		else {
			cout << s.top() + 1 << " " << i + 1 << '\n';
			s.pop();
		}
	}
	return 0;
}