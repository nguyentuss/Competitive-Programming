#include <bits/stdc++.h>

using namespace std;

int f[130][130][1007];
int len = 128;
int b , k;

void DynamicProgramming() {
	memset(f , -1 , sizeof(f));
	for (int i = k ; i <= b ; i++) f[0][i][0] = i;
	for (int i = 0 ; i <= b; i++) {
		for (int num1 = 0 ; num1 <= b ; num1 ++) {
			for (int d = 0 ; d <= k ; d++) {
				if (f[i][num1][d] == -1) continue;
				int val = f[i][num1][d];
				for (int bit = 0 ; bit <= 1 ; bit++) {
					f[i + 1][num1 + bit][(2*d + bit)%k] += val;
				}
			}
		}
	}
	cout << f[b][0][0];
	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> b >> k;
	DynamicProgramming();
	return 0;
}