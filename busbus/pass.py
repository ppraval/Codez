pain = [1,1,2,3,6,7,2,0]

for p in pain:
    pass
    if(p % 2 == 0):
        print('Pain', p)
    elif(p == 7):
        print("l ke")
        break
    else:
        print('Baal', p)
        continue
print("How did this 'turn out'?", end='huh')
        
