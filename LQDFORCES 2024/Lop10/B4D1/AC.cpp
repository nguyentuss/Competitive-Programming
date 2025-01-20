#include<bits/stdc++.h>
using namespace std;
struct trie{
    trie* A[27];
    vector<int> flag;
    trie(){
        for(int i=0; i<26; i++) A[i]=NULL;
        flag.push_back(-1);
    }
};
trie* root;
int n,m,q,ans[100000];
string a;
vector<char> s[100008];
void add(string a,int i){
    trie* p=root;
    for(char v: a){
        if(p->A[v-'a']==NULL){
            p->A[v-'a']=new trie();
        }   
        p=p->A[v-'a'];
    }
    p->flag.push_back(i);
}
void F(int x,int y, int bit){
    trie* p=root;
    if(bit==0){
        for(int i=0; i<10; i++){
            if(y+i>m) return;
            if(p->A[s[x][y+i]-'a']!=NULL){
                p=p->A[s[x][y+i]-'a'];
                if(p->flag[0]==-1){
                    p->flag[0]=1;
                    for(int i=1; i<p->flag.size(); i++){
                        ans[p->flag[i]]=1;
                    }
                }
            }
            else return;
        }
    }
    else{
        for(int i=0; i<10; i++){
            if(x+i>n) return;
            if(p->A[s[x+i][y]-'a']!=NULL){
                p=p->A[s[x+i][y]-'a'];
                if(p->flag[0]==-1){
                    p->flag[0]=1;
                    for(int i=1; i<p->flag.size(); i++){
                        ans[p->flag[i]]=1;
                    }
                }
            }
            else return;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    root= new trie();
    cin>>n>>m>>q;
    for(int i=0; i<=n+1; i++){
        for(int j=0; j<=m+1; j++){
            s[i].push_back('a');
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>s[i][j];
        }
    }
    for(int i=1; i<=q; i++){
        cin>>a;
        add(a,i);
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            F(i,j,0);
        }
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            F(j,i,1);
        }
    }
    for(int i=1; i<=q; i++){
        cout<<ans[i];
    }
    return 0;
}