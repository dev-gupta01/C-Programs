total=0
j=1
while j<5:
    total+=j
    j+=1
print("sum of nos. less than 5:")
print(total)
print()

a=[1,2,3,4,5,-1,-2,-3]
i=0
s=0
while i<len(a) and a[i]>0:
    s+=a[i]
    i+=1
print("sum of +ve elements of list:")
print(s)
print()

s=0
i=0
while True:
    if i>=len(a) or a[i]<0:
        break
    s+=a[i]
    i+=1
print("sum using break")
print (s)
print()

s=0
i=len(a)-1
while i>=0 and a[i]<0:
    s+=a[i]
    i-=1
print("sum of -ve elements of list:")
print(s)
print()

