def gcd(a, b):
    if b == 0:
        return a;
    return gcd(b, a % b)


def shift(s):
    for i in range(1, len(s) + 1):
        if s == s[i:] + s[:i]:
            return i


def solve():
    n = int(input())
    s = input()
    p = [int(x)-1 for x in input().split()]
    used = [False] * n
    ans = 1
    i = 0
    while i < n:
        ss = ''
        while not used[i]:
            ss += s[i]
            used[i] = True
            i = p[i];
        i += 1
        if len(ss) == 0:
            continue
        ln = shift(ss)
        ans = ans * ln // gcd(ans, ln)
    print(ans)


t = int(input())
for _ in range(t):
    solve()