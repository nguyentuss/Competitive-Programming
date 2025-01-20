#include <bits/stdc++.h>

using namespace std;

#define int long long

int deck[52];
char suitnames[4]={'S', 'D', 'C', 'H'};
char ranknames[14]={'0' , 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
map<char , int> m;
map<char , int> m1;
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    m['A'] = 1 , m['2'] = 2 , m['3'] = 3 , m['4'] = 4 , m['5'] = 5, m['6'] = 6 , m['7'] = 7 , m['8'] = 8 , m['9'] = 9;
    m['T'] = 10 , m['J'] = 11 , m['Q'] = 12 , m['K'] = 13;
    m1['S'] = 0 , m1['D'] = 1 , m1['C'] = 2 , m1['H'] = 3;
    map<int , int> m2;
    m2[1] = 14;
    for (int i = 1 ; i <= 52 ; i++) {
        deck[i] = i;
    }
    string a , b , c , d , e; cin >> a >> b >> c >> d >> e;
    int R[5]; // = {4, 7, 6, 3, 5}; // rank of the first 5 cards
    int S[6]; 
    R[0] = m[a[0]]  , R[1] = m[b[0]], R[2] = m[c[0]], R[3] = m[d[0]], R[4] = m[e[0]];
    S[0] = m1[a[1]] , S[1] = m1[b[1]] , S[2] = m1[c[1]] , S[3] = m1[d[1]] , S[4] = m1[e[1]]; 
    bool swapped = false;
    do
    {
        // 1 pass of the bubble sort
        swapped = false;
        for(int i=0; i<4; i++)
        {
            if(R[i] > R[i+1])
            {
                int temp = R[i];
                R[i] = R[i+1];
                R[i+1] = temp;
                swapped = true;
            }
        }
    }
    while(swapped == true);
    bool foundsam = false , foundthu = false;
    for (int i = 0 ; i < 3 ; i++)  {
        if (R[i] == R[i + 1] && R[i + 1] == R[i + 2]) {
            foundsam = true;
            break;
        }
    }
    for (int i = 0 ; i < 4 ; i++) {
        for (int j = i + 2 ; j < 4 ; j++) {
            if (R[i] == R[i + 1] && R[j] == R[j + 1]) {
                foundthu = true;
            }
        }
    }
    // for(int i=0; i<5; i++)
    // {
    //     cout << ranknames[R[i]] << " of " << suitnames[S[i]]<< "\n";
    // }
    if((R[1]==R[0]+1 && R[2]==R[1]+1 && R[3]==R[2]+1 && R[4]==R[3]+1 && S[0] == S[1] && S[1]==S[2] && S[2]==S[3] && S[3]==S[4]) || (R[2]==R[1]+1 && R[3]==R[2]+1 && R[4]==R[3]+1 && m2[R[0]] == R[4] + 1 && S[0] == S[1] && S[1]==S[2] && S[2]==S[3] && S[3]==S[4])) {
        cout << "Thung pha sanh";
    }
    else if ((R[0] == R[1] && R[1] == R[2] && R[2] == R[3]) || (R[1] == R[2] && R[2] == R[3] && R[3] == R[4])) {
        cout << "Tu quy";
    }
    else if ((R[0] == R[1] && R[1] == R[2] && R[2] != R[3] && R[3] == R[4]) || (R[0] == R[1] && R[1] != R[2] && R[2] == R[3] && R[3] == R[4])) {
        cout << "Cu lu";
    }
    else if(S[0] == S[1] && S[1]==S[2] && S[2]==S[3] && S[3]==S[4])
    {
        cout << "Thung";
    }
    else if((R[1]==R[0]+1 && R[2]==R[1]+1 && R[3]==R[2]+1 && R[4]==R[3]+1) || (R[2]==R[1]+1 && R[3]==R[2]+1 && R[4]==R[3]+1 && m2[R[0]] == R[4] + 1)) 
    {
        cout << "Sanh";
    }
    else if (foundsam){
        cout << "Sam";
    }
    else if (foundthu) {
        cout << "Thu";
    }
    else if(R[0] == R[1] || R[1]==R[2] || R[2]==R[3] || R[3]==R[4])
    {
        cout << "Doi" << endl;
    }
    else {
        cout << "Mau thau";
    }
    

    // Check for 4 of R kind

    // Check for full house
    return 0;
}