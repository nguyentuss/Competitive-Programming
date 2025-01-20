n = int(input())
for i in range(0 , n ):
    s = input()
    t = s[::-1]
    if (s == t) : print(1 , end="")
    else : print(0 , end="")
