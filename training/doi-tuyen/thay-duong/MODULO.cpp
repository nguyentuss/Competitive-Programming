#include <iostream>
#include <vector>
#include <set>
#include <fstream>


using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("MODULO.inp","r",stdin);
#define fo freopen("MODULO.out","w",stdout);

int main(){
	boost;
	fi;fo;
	int x;
	set <int> s;

	for (int i = 1 ; i <= 10 ; i++) {
		cin >> x;
		s.insert(x%42);
	}

	cout << s.size();

	return 0;
}