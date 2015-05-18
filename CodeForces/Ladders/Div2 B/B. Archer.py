a, b, c, d = map(float, raw_input().split())
x, y = a / b, c / d
tie = (1 - x) * (1 - y)
print x / (1 - tie)
