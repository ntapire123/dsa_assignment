#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Stack structure
typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

// Initialize stack
void initStack(Stack *s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Check if stack is full
int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// Push operation
void push(Stack *s, char item) {
    if (!isFull(s)) {
        s->items[++s->top] = item;
    }
}

// Pop operation
char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[s->top--];
    }
    return '\0';
}

// Check if character is opening bracket
int isOpeningBracket(char ch) {
    return (ch == '(' || ch == '[' || ch == '{');
}

// Check if character is closing bracket
int isClosingBracket(char ch) {
    return (ch == ')' || ch == ']' || ch == '}');
}

// Check if brackets match
int isMatchingPair(char opening, char closing) {
    return ((opening == '(' && closing == ')') ||
            (opening == '[' && closing == ']') ||
            (opening == '{' && closing == '}'));
}

// Function to check if expression has balanced parentheses
int isBalanced(char *expression) {
    Stack stack;
    initStack(&stack);
    
    for (int i = 0; i < strlen(expression); i++) {
        char current = expression[i];
        
        // If opening bracket, push to stack
        if (isOpeningBracket(current)) {
            push(&stack, current);
        }
        // If closing bracket, check for matching opening bracket
        else if (isClosingBracket(current)) {
            if (isEmpty(&stack)) {
                return 0; // No matching opening bracket
            }
            
            char top = pop(&stack);
            if (!isMatchingPair(top, current)) {
                return 0; // Brackets don't match
            }
        }
    }
    
    // Expression is balanced if stack is empty
    return isEmpty(&stack);
}

int main() {
    char expressions[][50] = {
        "a + (b - c) * (d",
        "m + [a - b * (c + d * {m)]",
        "a + (b - c)"
    };
    
    int numExpressions = sizeof(expressions) / sizeof(expressions[0]);
    
    printf("Balanced Parentheses Checker\n");
    printf("============================\n\n");
    
    for (int i = 0; i < numExpressions; i++) {
        printf("Expression %d: %s\n", i + 1, expressions[i]);
        
        if (isBalanced(expressions[i])) {
            printf("Result: BALANCED\n");
        } else {
            printf("Result: NOT BALANCED\n");
        }
        printf("\n");
    }
    
    // Test with user input
    char userExpression[100];
    printf("Enter your own expression to test: ");
    fgets(userExpression, sizeof(userExpression), stdin);
    
    // Remove newline character if present
    userExpression[strcspn(userExpression, "\n")] = '\0';
    
    printf("Your expression: %s\n", userExpression);
    if (isBalanced(userExpression)) {
        printf("Result: BALANCED\n");
    } else {
        printf("Result: NOT BALANCED\n");
    }
    
    return 0;
}