# 전역변수
g_var = 10

def func():
    print("g_var = {}".format(g_var))

if __name__ == "__main__":
    func()
    
# 전역변수2
def func():
    g_var = 20
    print("g_var = {} in function".format(g_var))

if __name__ == "__main__":
    func()
    print("g_var = {} in main".format(g_var))