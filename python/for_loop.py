a=[1,2,3,"Devashish","Shubhashish"]
print("printing elements of list:")
for ele in a:
    print(ele)
print()

b=[1,2,3,4,5,6]
s=0
for ele in b:
    s+=ele
print("sum of elements of list:")
print(s)
print()

b=list(range(1,100))
s=0
for ele in b:
    s+=ele
print("sum of elements less than 100:")
print(s)
print()

s=0
for i in range(1,10):
    if i%2==0:
        s+=i
print("sum of even elements less than 20:")
print(s)
print()

c=[]
for i in range(1,100):
    if i%3==0:
        c.append(i)
    elif i%5==0:
        c.append(i)
print("multiples of 3,5 that are less than 100:")
print(c)
print()

