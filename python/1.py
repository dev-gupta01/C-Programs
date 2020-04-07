'''
#import keyword
#print(keyword.kwlist)

a,b,_=1,2,3
print(a,b)

print(a if a>b else b)

a="Hello World!!"
print(a[0:len(a)])
print(len(a),end=",")
print(type(a))

a={"aaaa"}
a.add('z')
print(a)

a=3+4j
print(type(a),end=",")
print("a="+str(a))

a=[19,"Dev",18,"Shubh"]
b=[20,"Rajat"]
print(2*a)
print(a+b)

a={"name":"Dev","age":20,
   "name1":"Rajat","age1":21,
   "name2":"Shubh","age2":19}
for key,val in a.items():
    print("key: "+key,end=" , ")
    print("value: ",val)
print(a.keys())
print(a.values())
'''

'''
def count():
    num=10
    def inc():
        nonlocal num
        num+=1
        return num
    return inc()
print(count())
'''

'''
a="global"
def f1():
    global a
    print(a)
    a="in f1()"
    def f2():
        global a
        print(a)
        a="in f2()"
    f2()
    print(a)
print(a)
f1()
'''

def myfunc(n):
    return lambda a : a * n
mydoubler = myfunc(2)
print(mydoubler(11))

