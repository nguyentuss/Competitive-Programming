#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<vector<vector<vector<vector <int>>>>> v(5 , vector<vector<vector<vector<int>>>> (5 , vector<vector<vector<int>>>(5 , vector<vector<int>>(5 , vector<int>(5 , 0)))));
int dp[][][][][];

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);

	cout << v[2][2][2][2][2];


	return 0;
}