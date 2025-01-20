s = input()
print(sum(1 for i in s if i.isupper()))
print(sum(1 for i in s if i.islower()))
print(sum(1 for i in s if i.isdigit()))
