#include<bits/stdc++.h>
using namespace std;
struct trie{
    trie* A[27];
    trie(){
        for(int i=0; i<26; i++) A[i]=NULL;
    }
};
trie* root;
int n,m,q;
string s[100008];
void add(int x,int y,int bit){
    if(bit==1){
        trie* p=root;
        for(int i=0; i<10; i++){
            if(y+i>m) return;
            if(p->A[s[x][y+i]-'a']==NULL){
                p->A[s[x][y+i]-'a']=new trie();
            }
            p=p->A[s[x][y+i]-'a'];
        }

    }
    else{
        trie* p=root;
        for(int i=0; i<10; i++){
            if(x+i>n) return;
            if(p->A[s[x+i][y]-'a']==NULL){
                p->A[s[x+i][y]-'a']=new trie();
            }
            p=p->A[s[x+i][y]-'a'];
        }
    }
}
bool F(string a){
    trie* p=root;
    for(char v: a){
        if(p->A[ v-'a' ]==NULL) return false;
        p=p->A[ v-'a' ];
    }
    return true;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    root= new trie();
    cin>>n>>m>>q;
    for(int i=1; i<=n; i++) {cin>>s[i]; s[i]=' '+s[i];}
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            add(i,j,1);
        }
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            add(j,i,-1);
        }
    }
    for(int i=1; i<=q; i++){
        cin>>s[0];
        cout<<F(s[0]);
    }

    return 0;
}