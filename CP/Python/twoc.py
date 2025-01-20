import string

def check(tmp):
    for i in range(1 , len(tmp)):
        if tmp[i] == tmp[i-1] : return 0
    return 1

n = int(input())
s = input()
ans = 0
for i in string.ascii_lowercase:
    for j in string.ascii_lowercase:
        if (i != j):
            if s.find(i) != -1 or s.find(j) != -1: 
                t = ""
                for c in s:
                    if c == j or c == i: t += c
                if check(t) == True: ans = max(ans , len(t))
print(ans)
