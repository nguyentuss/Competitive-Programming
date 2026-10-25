    #include<bits/stdc++.h>
    using namespace std;

    string S,X;
    bool C[30] = {false};
    long long n;
    void backtr(int i)
    {
        for(int j=0;j<n;j++)
        {
            if (!C[j])
            {
                X[i] = S[j];
                C[j] = true;
                if(i == n - 1) cout << X << endl;
                else backtr(i + 1);
                C[j] = false;
            }
        }
    }
    int main()
    {   
        //freopen("BAI43QL.inp", "r", stdin);
        //freopen("BAI43QL.out", "w", stdout);

        cin >> S;
        n = S.length();
        X = S;
        backtr(0);
        return 0;
    }