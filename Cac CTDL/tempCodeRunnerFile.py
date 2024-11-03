n = input()
s=0
p=1
for i in n:
    s+=int(i)
    p*=int(i)
print(p%s)