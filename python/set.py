a=set()
a.add(1)
print(a)
a.add(0)
print(a)
a.add(2)
a.add(3)
print("A=",end="")
print(a)

b={1,1,1,2,3,"Devashish",4,5}
print("B=",end="")
print(b)

print("A_inter_B=",end="")
print(a.intersection(b))

print(2 in a)

a.update(b)
print(a)

from collections import Counter
a=Counter(['a','b','b','Dev'])
print(a)

