#include <iostream>

using namespace std;

int a[200];
bool kt = false;

int main(){
	int n;	cin >> n;
	for (int i=1;i<=n;i++)	{
		cin >> a[i];
	}
	for (int i=1;i<=(n/2);i++){
		if (a[i] != a[n-(i-1)]) {
				cout << "NO";
				break;
			}
		else kt = true;
		}

	if (kt==true) cout<< "YES";
	return 0;
}
