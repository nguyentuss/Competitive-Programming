try:
    print(len(input().split()))
except EOFError as e:
    print(0)
