def move(start, dest):
    print('%d %d' % (start, dest))

def solve_recursive(n, start, temp, dest):
    if n == 1:
        move(start, dest)
    else:
        solve_recursive(n - 1, start, dest, temp)
        move(start, dest)
        solve_recursive(n - 1, temp, start, dest)

i = int(input())
cnt = 2**i - 1
print(cnt)
if i <= 20:
    solve_recursive(i, 1, 2, 3)