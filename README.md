# push_swap

This project is about using two stacks A and B, as well as a few pre-selected stack operations to sort a list of unsorted integers. From this project, I learnt how to implement doubly linked lists in the context of stacks and stack operations / manipulation and a general overview of different types of sorts and their time and space complexities.

## Testers:
https://github.com/laisarena/push_swap_tester <br />
https://github.com/gemartin99/Push-Swap-Tester <br />
https://github.com/louisabricot/push_swap_tester

## References:
https://md.picasoft.net/ygePDdPSR4KN1PzJ50KHaw?view <br />

## Visualisation: <br />
100 numbers: https://tinyurl.com/100numsort <br />
500 numbers:  https://tinyurl.com/500numsort

## How to use:
1. Clone the repository
```bash
git clone https://github.com/rsoo23/push_swap.git push_swap
```
2. Make the executable
```bash
make
```
3. Input the arguments (int must be within the int range) (redirect the output into an output file)
```bash
./push_swap "int int ..." > out
```
4. Go to the website below, copy and paste the unsorted numbers and the moves from the output file into the respective fields
```bash
https://codepen.io/ahkoh/full/bGWxmVz
```
## Bonus: 
A checker that takes in the list of unsorted numbers and takes in moves to check if the moves sort the list 
1. Make the checker executable
```bash
make bonus
```
2. Input the arguments and press enter (int must be within the int range)
```bash
./push_swap "int int ..."

```
3. Enter your moves (press enter after every new move)
```bash
./push_swap "int int ..."
rra
sa

```
4. Press Ctrl + D to end the instruction reading and get the result (OK = sorted / KO = not sorted)
```bash
./push_swap "int int ..."
rra
sa
KO / OK
```
