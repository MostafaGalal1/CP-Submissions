n = int(input())
s = input()
count = 0
w = ""

for i in range(n):
    if w != s[i]:
        w = s[i]
        count+=1
        
print(count)