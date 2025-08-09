# Question 1: Balanced Parentheses Checker

## Data Structure Definition

### Stack Structure
```c
typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;
```
- **items**: Array to store stack elements (characters)
- **top**: Index pointing to the top element of the stack
- **MAX_SIZE**: Constant defining maximum stack capacity (100)

## Functions Implemented

### Stack Operations
1. **initStack(Stack *s)**: Initializes the stack by setting top to -1
2. **isEmpty(Stack *s)**: Returns 1 if stack is empty, 0 otherwise
3. **isFull(Stack *s)**: Returns 1 if stack is full, 0 otherwise
4. **push(Stack *s, char item)**: Adds an element to the top of the stack
5. **pop(Stack *s)**: Removes and returns the top element from the stack

### Bracket Checking Functions
1. **isOpeningBracket(char ch)**: Checks if character is '(', '[', or '{'
2. **isClosingBracket(char ch)**: Checks if character is ')', ']', or '}'
3. **isMatchingPair(char opening, char closing)**: Verifies if brackets form a valid pair

### Main Algorithm
1. **isBalanced(char *expression)**: 
   - Traverses the expression character by character
   - Pushes opening brackets onto the stack
   - For closing brackets, pops from stack and checks if they match
   - Returns 1 if expression is balanced, 0 otherwise

## Main Method Organization

1. **Test Cases**: Pre-defined expressions from the assignment
2. **Automated Testing**: Loops through test cases and displays results
3. **User Input**: Allows user to test custom expressions
4. **Output Display**: Shows expression and whether it's balanced or not

## Sample Output

```
Balanced Parentheses Checker
============================

Expression 1: a + (b - c) * (d
Result: NOT BALANCED

Expression 2: m + [a - b * (c + d * {m)]
Result: NOT BALANCED

Expression 3: a + (b - c)
Result: BALANCED

Enter your own expression to test: {[()]}
Your expression: {[()]}
Result: BALANCED
```

## Algorithm Complexity
- **Time Complexity**: O(n) where n is the length of the expression
- **Space Complexity**: O(n) in worst case when all characters are opening brackets