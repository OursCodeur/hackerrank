def getBiggestRegion(grid,m,n):
    def size(i,j):
        if 0 <= i < len(grid) and 0 <= j < len(grid[i]) and grid[i][j] == 1:
            grid[i][j] = 0
            return 1 + sum(size(i2,j2) for i2 in range(i - 1,i + 2) for j2 in range(j - 1,j + 2))
        return 0
    return max(size(i,j) for i in range(n) for j in range(m))

n = int(input().strip())
m = int(input().strip())
grid = []
for grid_i in range(n):
    grid_t = list(map(int, input().strip().split(' ')))
    grid.append(grid_t)
print(getBiggestRegion(grid,m,n))
