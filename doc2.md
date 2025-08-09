# Question 2: Infix to Postfix Conversion and Evaluation

## Data Structure Definition

### Character Stack (for conversion)
```c
typedef struct {
    char items[MAX_SIZE];
    int top;
} CharStack;
```

### Integer Stack (for evaluation)
```c
typedef struct {
    int items[MAX_SIZE];
    int top;
} IntStack;
```

- **items**: Array to store stack elements
- **top**: Index pointing to the top element
- **MAX_SIZE**: Maximum capacity (100)

## Functions Implemented

### Stack Operations
1. **initCharStack/initIntStack**: Initialize stacks by setting top to -1
2. **isCharStackEmpty/isIntStackEmpty**: Check if stack is empty
3. **pushChar/pushInt**: Add element to top of stack
4. **popChar/popInt**: Remove and return top element
5. **peekChar**: Return top element without removing it

### Conversion Functions
1. **getPrecedence(char op)**: Returns precedence level of operators
   - +, -: precedence 1
   - *, /: precedence 2
   - ^: precedence 3
2. **isOperator(char ch)**: Checks if character is an arithmetic operator
3. **infixToPostfix(char *infix, char *postfix)**: Main conversion algorithm

### Evaluation Functions
1. **performOperation(int op1, int op2, char operator)**: Performs arithmetic operations
2. **evaluatePostfix(char *postfix)**: Evaluates postfix expression using stack

## Main Method Organization

1. **Test Cases**: Pre-defined infix expressions for testing
2. **Automated Testing**: Converts and evaluates test cases
3. **User Input**: Allows user to input custom expressions
4. **Output Display**: Shows infix, postfix, and result (if numeric)

## Algorithm Details

### Infix to Postfix Conversion (Shunting Yard Algorithm)
1. Scan infix expression left to right
2. If operand: add to postfix
3. If '(': push to stack
4. If ')': pop until '(' found
5. If operator: pop operators with higher/equal precedence, then push current
6. Pop remaining operators

### Postfix Evaluation
1. Scan postfix left to right
2. If operand: push to stack
3. If operator: pop two operands, perform operation, push result
4. Final stack element is the result

## Sample Output

```
Infix to Postfix Converter and Evaluator
========================================

Test Case 1:
Infix:    2+3*4
Postfix:  234*+
Evaluation steps:
Push 2 to stack
Push 3 to stack
Push 4 to stack
Pop 4 and 3, perform 3 * 4 = 12, push result
Pop 12 and 2, perform 2 + 12 = 14, push result
Result:   14

Test Case 2:
Infix:    A+B*C-D
Postfix:  ABC*+D-
Result:   Cannot evaluate (contains variables)

Enter an infix expression: (2+3)*4
User Input:
Infix:    (2+3)*4
Postfix:  23+4*
Result:   20
```

## Algorithm Complexity
- **Time Complexity**: O(n) for both conversion and evaluation
- **Space Complexity**: O(n) for stack storage