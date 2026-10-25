#include <cstdio>
#include <cstring>
//#include <conio.h>
#define base 100000000

struct solon
{
     int so;
     int a[40];
};

solon f[122][122],T;
char s[122];
int n;

solon tong (solon A,solon B)
{
      int du = 0;
      solon C;
      if(A.so<B.so)
      {
           C = A;
           A = B;
           B = C;
      }
      for(int i = B.so+1;i<=A.so;i++) B.a[i] = 0;
      C.so = A.so;
      for(int i = 1;i<=A.so;i++)
      {
          C.a[i] = (A.a[i]+B.a[i]+du)%base;
          du = (A.a[i]+B.a[i]+du)/base;
      }
      if(du>0) {C.so++; C.a[C.so] = du;}
      return C;
}

solon hieu(solon A,solon B)
{
      int du = 0;
      solon C;
      for(int i = B.so+1;i<=A.so;i++) B.a[i] = 0;
      C.so = A.so;
      for(int i = 1;i<=A.so;i++)
      {
           C.a[i] = (A.a[i]-B.a[i]-du);
           if(C.a[i]<0) {
                   C.a[i] += base;
                   du = 1;
           }
      }
      while(C.a[C.so]==0 && C.so>1) C.so--;
      return C;
}

void print(solon A)
{
      printf("%d",A.a[A.so]);
     for(int i = A.so-1;i>=1;i--)
         printf("%08d",A.a[i]);
}

bool doixung(int i,int j)
{
     if(j-i<2)
         return (s[i]==s[j]);
     if(s[i]!=s[j]) return false;
     else return doixung(i+1,j-1);
}

int main()
{
      freopen("PAL.inp","r",stdin);
      freopen("PAL.out","w",stdout);
      scanf("%s",s);
      n = strlen(s);
      T.so = 1; T.a[1] = 1;
      for(int i = 0;i<n;i++)
      {
           f[i][i] = T;
           f[i+1][i].so = 1;
           f[i+1][i].a[1] = 0;
      }
      for(int k = 1;k<n;k++)
           for(int i =0;i+k<n;i++)
           {
                int j = i+k;
                f[i][j] = tong(f[i+1][j],f[i][j-1]);
                if(s[i]==s[j]) f[i][j] = tong(f[i][j],T);
                else f[i][j] = hieu(f[i][j],f[i+1][j-1]); 
              //  printf("%d %d %d\n",i,j,f[i][j].a[1]);
           }
      //if(doixung(0,n-1)) f[0][n-1] = hieu(f[0][n-1],T);
      print(f[0][n-1]);  
    //  getch(); 
}
