#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
	string st;
	int n , k,r; cin >> st >> n >> k;
	int u[1001] , v[1001],i=0;bool check = true;int x , y;
	while (st != "END"){
		cin >> st;
		if (st == "ADD") {
			i++;
			cin >> u[i] >> v[i];

		}
		else 
			if (st == "ANY"){
				r = 1 + rand() % (i + 1 - 1);
			}
		else
			if (st == "EDG"){
				cin >> x >> y;
				

			};
	}
	cout << u[r] << " " << v[r] << "\n";
	for (int j = 1 ; j <= i ; j++)
					if ((x == u[j]) && (y == v[j]))
						check = false;
				if (check) {cout << "NO";}
					else {cout << "YES";}
	return 0;
}