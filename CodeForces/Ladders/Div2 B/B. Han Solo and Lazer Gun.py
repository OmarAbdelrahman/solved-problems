n, x, y = map(int, raw_input().split())

visited = set()
for i in range(n):
    a, b = map(float, raw_input().split())
    visited.add((a - x) / (b - y) if b - y != 0 else float("INF"))

print len(visited)
