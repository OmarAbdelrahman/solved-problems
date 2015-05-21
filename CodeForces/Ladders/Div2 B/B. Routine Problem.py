a, b, c, d = map(int, raw_input().split())

p = abs(a * d - b * c)
q = max(a * d, b * c)
from fractions import gcd
g = gcd(p, q)

print "%d/%d" % (p / g, q / g)
