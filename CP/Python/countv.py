n = int(input())
s = input()
l = 0
ans = 0
for i in range(0 , len(s)):
    if l == 0 and s[i] == 'D':
        ans = ans + 1
    if s[i] == 'U':
        l += 1
    else :
        l -= 1
print(ans)
