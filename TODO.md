## [ ] PARSING

[x] Create a Makefile that compiles with Libft 
[X] Receive the elements
[x] Convert str to numbers
[x] Add them to a list
[x] Convert the numbers to 0, 1, 2, 3
	PSEUDOCODE
	- Faire une loop sur la totalite de la liste B.
	a chaque nombre de la liste, compter le nombre de nombre en dessous du nombre actuel. cet indice sera ajoute a la liste A. 
	Free la liste B.
[x] Convert to double linked list (next, previous)
[ ] Handle list of ints in string

## [ ] Check for errors

[x] Make an const global variable for Error
[x] If one of the values is not a number, add error message "Error\n"
[x] If one of the values is a duplicate, add error message "Error\n"
[ ] Check if any number is bigger or small than an int
[ ] Switch to write to send errors to fd 2

## Make each of the commands work

[x] externalize initial setup
[x] sa: Swap the first 2 elements at the top of stack a.
	Do nothing if there is only one or no elements.
[x] sb: Swap the first 2 elements at the top of stack b.
	Do nothing if there is only one or no elements.
[x] ss : sa and sb at the same time.
[x] pa: Take the first element at the top of b and put it at the top of a.
	Do nothing if b is empty.
[x] pb: Take the first element at the top of a and put it at the top of b.
	Do nothing if a is empty.
[x] ra: Shift up all elements of stack a by 1.
	The first element becomes the last one.
[x] rb: Shift up all elements of stack b by 1.
	The first element becomes the last one.
[x] rr: ra and rb at the same time.
[x] rra: Shift down all elements of stack a by 1.
	The last element becomes the first one.
[x]	rrb: Shift down all elements of stack b by 1.
	The last element becomes the first one.
[x] rrr : rra and rrb at the same time.

## ALGORITHM

[x] Look into algorithms
[ ] Add visualizer : https://github.com/o-reo/push_swap_visualizer
[x] Add checker
[x] look into alogrithm complexity
[x] Find the most common algorithms
[x] Implement the algorithm

- Radix Sort : https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e

Sorting based on each digit. You first need to rank them
Then sort in base of 2 for 2 boxes using bits

- Sillicon valley lady : https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a

cases for 3, 5 100, 500.

- The mechanical turk : https://medium.com/@ayogun/push-swap-c1f5d2d41e97

Sending 2 numbers from stack A to stack B
Then send the cheapest number first, in the 


- The Korean

## ALGORITHM BREAKDOWN

[x] Check if sorted function
[x] Count number of elements in dblklist
[x] 3 numbers sort
[x] Create view 2 stacks function
[x] add asc and desc value to struct
[x] Create function that will add logic value to asc and desc
[x] Create logic loop
[x] Add logic to send to B until 3
[x] add logic to send to A
[ ] optimize
[ ] clean

