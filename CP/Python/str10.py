s = input().split()
cnt = 0;
for i in s:
    i = i[0].upper() + i[1:].lower()
    print(i, end='')
    cnt+=1
    if(cnt < len(s)):
        print(' ', end='')
