SAFEGUARD = 10**8

def merge_sort(a):
    if len(a) > 1:
        mid = len(a) // 2
        left, right = a[0:mid], a[mid:]
        res = merge(merge_sort(left), merge_sort(right))
        return res
    else:
        return a


def merge(_a, _b):
    global count
    a = _a + [SAFEGUARD]
    b = _b + [SAFEGUARD]
    res = []
    i, j = 0, 0
    for _ in range(len(_a) + len(_b)):
        if a[i] > b[j]:
            res += [b[j]]
            j += 1
            count += len(_a) - i
        else:
            res += [a[i]]
            i += 1
    return res


def count_inversions(a):
    global count
    count = 0
    merge_sort(a)
    return count


t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    arr = list(map(int, input().strip().split(' ')))
    print(count_inversions(arr))
