#include <iostream>

using namespace std;



int main(){
	//ios::sync_with_stdio(0); cin.tie(NULL);
	/*freopen("text.txt","r",stdin);
	freopen("out.txt.","w",stdout);*/
	int a , c;
	while (scanf("%d %d",&a,&c) == 2 && (c != 0) && (a != 0)) {
		int x[c + 1] = {0} , res = 0;
		int arr[a+2][c+2] = {0}; 
		for (int i = 1 ; i <= c ; i++)
			cin >> x[i];
		//cout << c - x[1] +1;
		for (int i = 1 ; i <= a ; i++){
			for (int j = 1 ; j <= c ; j++){
				if (i < (a - x[j] + 1)) 
					arr[i][j] = 1;   
			}
		}
		
		for (int i = 1 ; i <= a ; i++){
			for (int j = 1 ; j <= c; j++)
				if (arr[i][j] == 1 && arr[i][j+1] == 0) res++;
		}
		cout << res << endl; 	
	}

	return 0;
}