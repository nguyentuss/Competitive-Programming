n=int(input())
tmp=int(0)
res=int(0)
tmp=n*(n-1)//2
res=n*((tmp+1)*2-1)+(n*(n-1)//2)*2
print(res)