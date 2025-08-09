# Question 1: Balanced Parentheses Checker
items: Array to store stack elements (characters)
top: Index pointing to the top element of the stack
MAX_SIZE: Constant defining maximum stack capacity (100)

# Stack Operations

initStack(Stack *s): Initializes the stack by setting top to -1
isEmpty(Stack *s): Returns 1 if stack is empty, 0 otherwise
isFull(Stack *s): Returns 1 if stack is full, 0 otherwise
push(Stack *s, char item): Adds an element to the top of the stack
pop(Stack *s): Removes and returns the top element from the stack

# Bracket Checking Functions

isOpeningBracket(char ch): Checks if character is '(', '[', or '{'
isClosingBracket(char ch): Checks if character is ')', ']', or '}'
isMatchingPair(char opening, char closing): Verifies if brackets form a valid pair

# Main Algorithm

isBalanced(char *expression):

Traverses the expression character by character
Pushes opening brackets onto the stack
For closing brackets, pops from stack and checks if they match
Returns 1 if expression is balanced, 0 otherwise



# Main Method Organization

Test Cases: Pre-defined expressions from the assignment
Automated Testing: Loops through test cases and displays results
User Input: Allows user to test custom expressions
Output Display: Shows expression and whether it's balanced or not

# Algorithm Complexity

Time Complexity: O(n) where n is the length of the expression
Space Complexity: O(n) in worst case when all characters are opening brackets