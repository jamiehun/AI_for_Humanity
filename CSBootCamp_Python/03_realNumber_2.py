# 엡실론 예제

import sys
ep = sys.float_info.epsilon
a = 9.25
# 9.25를 부동소수점 방식으로 변경시 1.00101 x 2^3

diff = (2**3)*ep
print(diff)

b = a + diff
print(b)
# 9.250000000000002
# =======================

# half 엡실론

half_diff = diff/2
print(half_diff)

c = a + half_diff
print(a==c)