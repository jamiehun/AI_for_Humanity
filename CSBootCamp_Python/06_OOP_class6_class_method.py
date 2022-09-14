# 클래스 메서드를 대체생성자로 사용
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age
    @classmethod
    def init_from_string(cls, string):
        name, age = string.split('_')
        return cls(name, int(age))
    
if __name__ == "__main__":
    p = Person.init_from_string('greg_30')
    print(p.name)
    print(p.age)