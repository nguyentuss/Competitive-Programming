#include <iostream>

using namespace std;

int main(){
	//ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	//freopen("cnum.inp","r",stdin);
	//freopen("cnum.out","w",stdout);
	int n ; cin >> n;
	int a[n+1] , cnt1 = 0 , cnt2 = 0 , pos;
	for (int i = 1 ; i <= n ; i++)
		{
			cin >> a[i];
			if (a[i] == 1){
				cnt1 ++;
				pos = i;
			}
		}
	cnt2 = pos - cnt1;bool check = false;int dem = 0;
	if (cnt1 == 0) cout << 0;
	else {
		for (int i = 1 ; i <= pos ; i++){
			if (a[i] == 1){
				cnt1 --;
			}
			else
			{
				if (cnt1 <= cnt2)
					for (int j = i ; j <= pos ; j ++)
						if (a[j] == 1)
							{
								a[j] = 2;
								dem ++;
								check = true;
							}
					if (check) break;
				else {
					for (int j = i ; j <= pos ; j++)
						if (a[j] == 2){
							a[j] = 1;
							dem ++;
							check = true;
						}
					if (check) break;
				}
			}
		}

		cout << dem;
	} 
	return 0;
}