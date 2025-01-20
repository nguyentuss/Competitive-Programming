#include <iostream>

using namespace std;

int main(){
	//ios::sync_with_stdio(0); cin.tie(NULL);
	/*freopen("tmp.txt","r",stdin);
	freopen("tmp.out","w",stdout);
	*/
	int n , b , h , w , p ;
	long long pi[201] = {0};
	while (scanf("%d %d %d %d",&n,&b,&h,&w) == 4){
		long long cnt = 0 , cnt1 = 0, pmin = 1e8;
		bool kt = true;
			long long s[201] = {0};
		for (int i = 0 ; i < h ; i ++){
			cin >> p;
			long long a[14] = {0};
			int dem = 0 ;
			cnt ++;
			for (int j = 0 ; j < w ; j ++){
				cin >> a[j];
				if ((a[j] < n) || (n > a[j])) dem ++;
			}	
			//cout << dem << " " << w << endl;
			//cout << cnt << " " << endl;
			if ((dem != w) && (n * p <= b)) {
				s[cnt] = 1;
				cnt1 ++;
				pi[cnt1] = p;
				pmin = min(pi[cnt1],pmin);
			}
		} 
		/*for (int i = 1 ; i <= h ; i ++)
			cout << s[i] << " ";*/
		for (int i = 1 ; i <= h ; i++){
			if (s[i] == 1) {
				cout << n * pmin << '\n';
				kt = false;
				break;
			}
		}
		if (kt) cout << "stay home\n";
		
	}		
	return 0;
}