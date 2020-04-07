def func1():
    print("inside func");
print("outside func");
func1();

def fact(n):
    if n<=1:
        return 1;
    return n*fact(n-1);
print(fact(5));

def power(x,y):
    if y==0:
        return 1
    res=1
    if y%2==0:
        res=power(x,y/2)
        res=res*res
    else:
        res=x
        res=res*power(x,y-1)
    return res
print(power(2,3))

def convert(miles):
    km=1.6*miles
    return str(miles)+"miles= "+str(km)+"km"
print(convert(2))

