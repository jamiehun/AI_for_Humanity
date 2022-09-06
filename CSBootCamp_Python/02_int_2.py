# 음의 정수
minus_four = (-4).to_bytes(1, byteorder='little', signed=True)
# 첫번째 인자 = 1바이트 / 두번째 인자 = 바이트오더 / 세번째 인자 = 양수 음수 모두 표현 혹은 양수만 표현

print(minus_four) # 16진수로 표현되며 2진수로 변환하면 1111 1000

print(bin(0xfc))
