#include<bits/stdc++.h>
 
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define alphaa "abcdefghijklmnopqrstuvwxyz"
#define ALPHAA "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define faster() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
 
using namespace std;
 
typedef double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> II;
 
const ld pi=2*acos(0);
const ll inf  = LLONG_MAX;
const ll ninf = LLONG_MIN;
const int oo = INT_MAX;
const int noo = INT_MIN;
 
string s = "";
int n;
int a[101][101];
string bin_res = "";
 
void init(){
	cin>>n;
	for (int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
}
 
 
 
void process(){
	string DP[101][101] ;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if (i == 0 || j == 0){
				if (i==0){
					if (j != 0) DP[i][j] = DP[i][j-1] + (char)(a[i][j] +0x30);	
					else DP[i][j] = (char)(a[i][j] + '0');
				}
				if (j==0){
					if (i!=0) DP[i][j] = DP[i-1][j] + (char)(a[i][j] +0x30);
					else DP[i][j] = (char)(a[i][j] +0x30);
				}
			}
			else{
				DP[i][j] = min (DP[i-1][j] , DP[i][j-1] );
				DP[i][j]+=a[i][j] + 0x30;
			}
		}
	}
	
	cout << DP[n-1][n-1];
}
 
 
int main()
{
	//freopen("robot.INP","r",stdin);
	//freopen("robot.OUT","w",stdout);
	faster();
	init();
	process();
 
	return 0;
}