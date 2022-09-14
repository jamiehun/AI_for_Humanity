# 파이썬의 클래스 알아보기
class Person:
    def __init__(self, name, money):
        self.name = name
        self.money = money
    
    def give_money(self, other, money):
        self.money -= money
        other.get_money(money)
        
    def get_money(self, money):
        self.money += money
    
    def show(self):
        print('{} : {}'.format(self.name, self.money))

if __name__ == '__main__':
    g = Person('greg', 5000)
    j = Person('john', 2000)
    
    g.show()
    j.show()
    
    g.give_money(j, 2000)
    print(' ')
    
    g.show()
    j.show()

# Person 클래스에 있는 것들 살펴보기
print(type(Person.__init__))
print(type(Person.give_money))
print(type(Person.get_money))
print(type(Person.show))

# 객체가 가진 메서드 살펴보기
print(type(g.give_money))
print(type(g.get_money))
print(type(g.show))
