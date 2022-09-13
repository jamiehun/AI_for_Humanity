# 함수의 중첩과 nonlocal 사용
def outer():
    a = 2
    b = 3

    def inner():
        nonlocal a 
        a = 100
    inner()
    
    print(
        "locals in outer : a = {}, b = {}".format(a, b))

if __name__ == "__main__":
    outer()