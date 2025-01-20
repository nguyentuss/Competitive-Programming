s = input()
t = " "
for i in  s:
    if i == " " :
        if t[-1] != " " : t += i
    else : t  += i
if t[0] == " "  : t = t[1:]
if t[-1] == " " : t = t[:-1]
if t[0] == " " and t[-1] : t = t[1:-1]
for i in t :
    print(i , end="")
