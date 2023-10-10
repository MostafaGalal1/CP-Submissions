# Online Python compiler (interpreter) to run Python online.
# Write Python 3 code in this online editor and run it.
s = input()
n = len(s)
count = n
l = [0 for i in range(n)]
l[0] = s

for i in range(1, n):
    w = l[i-1]
    l[i] = w[-1] + w[0:-1]

o = 1
for j in range(n):
    for k in range(n):
        if (k != j and l[j] == l[k]):
            l[k] = "*" * o
            o+=1
            count-=1
        

print(count)
            