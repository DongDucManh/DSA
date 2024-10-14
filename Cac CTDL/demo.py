n,q=map(int,input().split())
s=input().split()
while  q:
    l,r=map(int,input().split())
    t=s[l-1:r]
    del(s[l-1:r])
    s+=t
    q-=1
for i in s: print(i,end=' ')