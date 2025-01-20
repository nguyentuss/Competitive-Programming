n = int(input())
for i in range(n):
    s = input()
    t = input()
    check = 0
    for j in range(0 , len(s)):
        if (s[j] == '?' or t[j] == '?'): 
            continue
        if (s[j] != t[j]):
            print(0)
            check = 1
            break
    if (check == 0) : print(1)
