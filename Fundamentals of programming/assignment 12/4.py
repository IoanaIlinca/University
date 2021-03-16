def Backtracking():
    numberOfOnes = 0
    for i in ['1', '2', 'X']:
        if i == '1':
            numberOfOnes = 1
        else:
            numberOfOnes = 0
        
        for ii in ['1', '2', 'X']:
            if ii == '1':
                numberOfOnes = numberOfOnes + 1

            for iii in ['1', '2', 'X']:
                if iii == '1':
                    if numberOfOnes < 2:
                        numberOfOnes = numberOfOnes + 1
                    else:
                        continue

                for iv in ['1', '2']:
                    if iv == '1':
                        if numberOfOnes < 2:
                            print(i + ' ' + ii + ' ' + iii + ' ' + iv + '\n')
                            continue
                        else:
                            continue

                    print(i + ' ' + ii + ' ' + iii + ' ' + iv + '\n')
                if iii == '1':
                    numberOfOnes = numberOfOnes - 1

            if ii == '1':
                numberOfOnes = numberOfOnes - 1
        
        if i == '1':
            numberOfOnes = numberOfOnes - 1

        


def Backtracking_rec(k, li, numberOfOnes):
    if k == 4:
        print(li)
        print('\n')
        return
    
    if k == 3:
        for i in ['1', '2']:
            if i == '1':
                if numberOfOnes < 2:
                    numberOfOnes = numberOfOnes + 1
                else:
                    continue
            li.append(i)
            Backtracking_rec(k + 1, li, numberOfOnes)
            li.pop()
            if i == '1':
                numberOfOnes = numberOfOnes - 1

    else:
        for i in ['1', '2', 'X']:
            if i == '1':
                if numberOfOnes < 2:
                    numberOfOnes = numberOfOnes + 1
                else:
                    continue
            li.append(i)
            Backtracking_rec(k + 1, li, numberOfOnes)
            li.pop()
            if i == '1':
                numberOfOnes = numberOfOnes - 1

    
def main():
    li = []
    Backtracking()
    print("\n------------------------------------\n")
    Backtracking_rec(0, li, 0)

main()