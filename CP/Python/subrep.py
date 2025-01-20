s = input()
t = input()
i = 0 
ans = 0
for j in range(0, len(t)):
    if (s[i] == t[j]): i += 1
    if (i >= len(s)): 
        ans += 1
        i = 0
print(ans)
