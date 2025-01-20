#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

#define MOD (int) (1e9 + 7)
int F[19][163][5131][2][3];
string n;

int wibusum[10] = {0 , 1 , 5 , 14 , 30 , 55 , 91 , 140 , 204 , 285};

void init() {
	for (int i = 0 ; i <= (int) n.size() ; i++) 
		for (int j = 0 ; j <= 162; j++) 
			for (int k = 0 ; k <= 5130 ; k++)
				for (int h = 0 ; h <= 1 ; h++)
					for (int status = 0 ; status <= 2 ;status++)
						F[i][j][k][h][status] = 0;
}

void calc(string &N) {
	init();
	int len = N.size();
	for (int num = 1 ; num <= 9 ; num++) {
		int status;
		if (num < N[0] - '0') status = 0;
		else if (num == N[0] - '0') status = 1;
		else if (num > N[0] - '0') status = 2;
		F[1][num][wibusum[num]][(__gcd(num , wibusum[num]) == 1)?1:0][status] ++;
	}
	for (int i = 1 ; i < len ; i++) {
		for (int sum = 0 ; sum <= 162 ; sum ++) {
			for (int multisum = 0 ; multisum <= 5130 ; multisum ++) 
				for (int checkgcd = 0 ; checkgcd <= 1 ; checkgcd ++) {
					for (int status = 0 ; status <= 2 ; status ++) {
						if (F[i][sum][multisum][checkgcd][status] == 0) continue;
						int val = F[i][sum][multisum][checkgcd][status];
						for (int num = 0 ; num <= 9 ; num ++) {
							int newstatus = status; 
							int newsum = sum + num;
							int newmultisum = multisum + wibusum[num];
							if (newstatus == 1) {
								if (num < N[i] - '0') newstatus = 0;
								else if (num > N[i] - '0') newstatus = 2;
							}
							int newcheckgcd;
							if (__gcd(newsum , newmultisum) == 1) newcheckgcd = 1;
							else newcheckgcd = 0;
							F[i + 1][newsum][newmultisum][newcheckgcd][newstatus] = (F[i + 1][newstatus][newmultisum][newcheckgcd][newstatus] + val)%MOD;
						}
					}
				}
		}
	}
	long long ans = 0;
	for (int i = 1 ; i <= len ; i++)
		for (int sum = 0 ; sum <= 162 ; sum ++) 
			for (int multisum = 0 ; multisum <= 5130 ; multisum ++) 
				for (int status = 0 ; status <= (i < len ? 2 : 1) ; status++) 
					ans += F[i][sum][multisum][1][status];

	cout << ans;	

}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cin >> n;
	calc(n);

	return 0;
}