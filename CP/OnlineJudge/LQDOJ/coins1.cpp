#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;
double dp[3005][3005] = {1};
int main()
{
    cout.precision(9);
    int n;
    cin>>n;
    double p;
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        cin>>p;
        for(int j=0;j<=i;j++){
            dp[i][j]=dp[i-1][j-1]*p+dp[i-1][j]*(1-p);
        	//cout << i << " " << dp[i-1][j-1] << " " << dp[i - 1][j] << " " << dp[i][j] << endl;
        }
    }

    p=0;
    for(int i=n/2+1;i<=n;i++) {
    	p+=dp[n][i];
    	cout << dp[n][i] << " ";
    }
    cout<<p;
    return 0;
}