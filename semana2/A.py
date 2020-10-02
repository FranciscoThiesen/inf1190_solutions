from bisect import bisect_left

def solve(s):
    s = s.split(' ')
    l = []
    ret = 0
    for i in range(int(s[0])):
        l.append(int(raw_input()))
    
    for i in range(int(s[1])):
        a = int(raw_input())
        b = bisect_left(l, a)
        if b != len(l) and l[b] == a:
            ret += 1
    return ret

while True:
    s = raw_input()
    if s == '0 0':
        break
    print(solve(s))
