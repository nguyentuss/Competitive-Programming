#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll a , b;
ll f[20][150][3];

void init() {
	for (int i = 0; i <= 15 ; i++) {
		for (int sum = 0 ; sum <= 135 ; sum++) {
			for (int status = 0 ; status <= 2 ; status++) 
				f[i][sum][status] = 0;
		}
	}
}


string change(long long x) {
    string res = ""; 
    long long val = x; 
 
    while (val) {
        res += (char) (val % 10 + '0'); 
        val /= 10; 
    }
    reverse(res.begin() , res.end()); 
    return res; 
}


ll dynamicprogramming(long long a) {
	init();
	string N = change(a);
	int len = N.size();
	for (int num = 1 ; num <= 9 ; num++) {
		int status;
		if (num < N[0] - '0') status = 0;
		else if (num == N[0] - '0') status = 1;
		else status = 2;
		f[1][num][status] ++;
	}
	for (int i = 1 ; i < len ;i++) {
		for (int sum = 0 ; sum <= 135 ; sum++) {
			for (int status = 0 ; status <= 2 ; status ++) {
				if (f[i][sum][status] == 0) continue;
				ll val = f[i][sum][status];
				for (int num = 0 ; num <= 9 ; num++) {
					if (sum + num > 135) continue;
					ll newsum = sum + num;
					ll newstatus = status;
					if (newstatus == 1) {
						if (num < N[i] - '0') newstatus = 0;
						else if (num > N[i] - '0') newstatus = 2;
					}
					f[i + 1][newsum][newstatus] += val;
				}
			}
		}
	}
	ll ans = 0;
	for (int i = 1 ; i <= len ; i++) {
		for (int sum = 0 ; sum <= 135 ; sum++) {
			for (int status = 0 ; status <= (i < len ? 2 : 1) ; status++) {
				ans += f[i][sum][status]*sum;
			}
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> a >> b;
	cout << dynamicprogramming(b) - dynamicprogramming(a -1);
	return 0;
}