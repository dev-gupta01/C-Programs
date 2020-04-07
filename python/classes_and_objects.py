class Robot:
    def __init__(self,name,color,age):
        self.name=name
        self.color=color
        self.age=age
    def intro(self):
        print("My name is: "+self.name)
        print("My color is: "+self.color)
        print("My age is: ",end="")
        print(self.age)
        print()

r1=Robot("Devashish","Red",20)
r2=Robot("Shubhashish","White",19)
r3=Robot("Nita","Yellow",42)

r1.intro()
r2.intro()
r3.intro()

class Person:
    def __init__(self,n,p,i):
        self.name=n
        self.personality=p
        self.is_sitting=i
    def sit_down(self):
        self.is_sitting=True
    def stand_up(self):
        self.is_sitting=False

p1=Person("Rajat","Normal",False)
p2=Person("Adi","Rich",True)

p1.robot=r1
p2.robot=r2

p1.robot.intro()