## Simulation of the classic Monty Hall problem in python

from random import randint
from random import choice
from random import shuffle

tests = 10000
switchWin = 0
noSwitchWin = 0
for i in range(tests):
    doors = ['car', 'goat','goat']
    shuffle(doors)
    pick = randint(0,2)

    monty = [i for i in range(len(doors)) if doors[i] == 'goat' and i != pick ]
    montysChoice = choice(monty)

    doorNums = [0,1,2]

    doorNums.remove(montysChoice)
    doorNums.remove(pick)
    
    switchedDoor = choice(doorNums)

    pickedDoor = pick

    if doors[switchedDoor] == 'car':
        switchWin += 1
    elif doors[pickedDoor] == 'car':
        noSwitchWin += 1

print(f'Percent wins by switching: {((switchWin/tests)*100) :0.2f}%')
print(f'Percent wins by not switching:{((noSwitchWin/tests)*100): 0.2f}%')
