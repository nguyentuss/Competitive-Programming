#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, m;
    cin >> n>> m;
    vector <vector<long long>> prefixSum (n+1, vector<long long> (m+1, 0));
    for (long long i =1; i <= n; i++){
        for (long long j =1; j <= m; j++){
            long long num;
            cin >> num;
            if (j==1){
                prefixSum[i][j]= prefixSum[i-1][j]+num;
            }
            else{
                prefixSum[i][j]= prefixSum[i][j-1]+prefixSum[i-1][j]+num-prefixSum[i-1][j-1];
            }
            
        }
    }
    long long ans = 0;
    vector <long long> minRow (m+1,0);
    vector <long long> minColumn (n+1,0);
    vector <long long> currentMinColumnIndex (n+1,0);
    vector <long long> currentMinRowIndex (m+1,0);
    for (long long i =1; i <= n; i++){
        for (long long j =1; j <= m; j++){
            ans = max (ans, prefixSum[i][j]- minRow[j]- minColumn[i]+ prefixSum[currentMinRowIndex[j]][currentMinColumnIndex[i]]);
            long long newRow= min (minRow[j], prefixSum[i][j]);
            if (newRow != minRow[j]){
                minRow[j]= newRow;
                currentMinRowIndex[j] = i;
            }
            long long newColumn= min (minColumn[i], prefixSum[i][j]);
            if (newColumn != minColumn[i]){
                minColumn[i]= newColumn;
                currentMinColumnIndex[i] = j;
            }
            
        }
    }
    // for (long long i =0; i <=n; i++){
    //     cout << minColumn[i]<< " ";
    // }
    // cout << endl;
    // for (long long i =0; i <=m; i++){
    //     cout << minRow[i]<< " ";
    // }
    // cout << endl;
    cout << ans;
    return 0;
}
// 1 -4 3   
// 2 2 -3   4