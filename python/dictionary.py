d={}
d["Devashish"]=20
d["Shubhashish"]=19
d["Nita"]=42
d[2]=4
print("dictionary is:")
print(d)
print()

print("d['Nita']=",end="")
print(d["Nita"])
print()

for key,val in d.items():
    print("key:",end="")
    print(key,end=",")
    print(" value:",end="")
    print(val)
    
