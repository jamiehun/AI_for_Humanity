# 클래스를 사용하지 않고 캡슐화 구현
# 인스턴스 멤버 초기화
def person_init(name, money):
    obj = {'name' : name, 'money' : money}
    obj['give_money'] = Person[1]
    obj['get_money'] = Person[2]
    obj['show'] = Person[3]
    return obj

# 함수 설정
def give_money(self, other, money):
    self['money'] -= money
    other['get_money'](other, money)
    
def get_money(self, money):
    self['money'] += money
    
def show(self):
    print('{} : {}'.format(self['name'], self['money'])) 
    
# Person 설정
Person = person_init, give_money, get_money, show

# 시행
if __name__ == '__main__':
    # 객체 생성
    g = Person[0]('greg', 5000)
    j = Person[0]('john', 2000)
    
    g['show'](g)
    j['show'](j)
    print(" ")
    
    # Message Passing
    g['give_money'](g, j, 2000)
    
    g['show'](g)
    j['show'](j)