t = int(input())

for q in range(t):
    s = input().split(" ")
    for i in range(3):
       s[i] = int(s[i])

    if (s.index(min(s)) == 0):
        print("First")
    elif (s.index(min(s)) == 1):
        print("Second")
    elif (s.index(min(s)) == 2):
        print("Third")