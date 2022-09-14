# 정보 은닉 (파이썬으로) / 2번 : 프로퍼티 기법
class Account:
    def __init__(self, name, money):
        self.user = name
        # 인스턴스 멤버 선언이 아니라 #3의 setter 메서드를 호출
        self.balance = money             #1
    
    @property
    def balance(self):                   #2 getter method
        return self._balance
    
    @balance.setter
    def balance(self, money):        #3 setter method 
        if money < 0:
            return
        
        # 실제 인스턴스 멤버 선언이 일어나는 부분 (#1 실행시 (생성자 호출시))
        self._balance = money

if __name__ == "__main__":
    my_acnt = Account('greg', 5000)
    my_acnt.balance = -3000
    
    print(my_acnt.balance) 