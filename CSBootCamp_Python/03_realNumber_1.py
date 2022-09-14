# 배정도(double-precision) 표현
import sys
print(sys.float_info)
# max=1.7976931348623157e+308
# min=2.2250738585072014e-308

# ============================
# 엡실론
print(sys.float_info.epsilon)
# 2.220446049250313e-16
# 배정도의 가수부 52비트
# 1.0 다음 표현의 수 1.000000..0(0: 52개, 1:마지막비트) x 2**0
# => 두수의 차이 : 0.000...1(0: 51개, 1: 마지막비트) x 2**0
# => 10진수로 변경시 2.220446049250313e-16