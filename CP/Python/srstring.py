s = input()
t = []
for i in range(0 , len(s)):
    if len(t) != 0 and t[-1] == s[i]: t.pop()
    else : t.append(s[i])
if (len(t) == 0):
    print("Empty String")
else :
    for i in range(0 , len(t)):
        print(t[i], end="")
