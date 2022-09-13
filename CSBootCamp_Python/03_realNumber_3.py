# 엡실론 예제2

import sys
ep = sys.float_info.epsilon

a = (2.0) ** 53
print(a * ep)

b = a + 1.0
print(a == b)