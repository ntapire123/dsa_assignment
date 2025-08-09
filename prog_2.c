#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    char items[MAX_SIZE];
    int top;
} CharStack;

typedef struct {
    int items[MAX_SIZE];
    int top;
} IntStack;

void initCharStack(CharStack *s) {
    s->top = -1;
}

void initIntStack(IntStack *s) {
    s->top = -1;
}

int isCharStackEmpty(CharStack *s) {
    return s->top == -1;
}

int isIntStackEmpty(IntStack *s) {
    return s->top == -1;
}

void pushChar(CharStack *s, char item) {
    if (s->top < MAX_SIZE - 1) {
        s->items[++s->top] = item;
    }
}

void pushInt(IntStack *s, int item) {
    if (s->top < MAX_SIZE - 1) {
        s->items[++s->top] = item;
    }
}

char popChar(CharStack *s) {
    if (!isCharStackEmpty(s)) {
        return s->items[s->top--];
    }
    return '\0';
}

int popInt(IntStack *s) {
    if (!isIntStackEmpty(s)) {
        return s->items[s->top--];
    }
    return 0;
}

char peekChar(CharStack *s) {
    if (!isCharStackEmpty(s)) {
        return s->items[s->top];
    }
    return '\0';
}

int getPrecedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

void infixToPostfix(char *infix, char *postfix) {
    CharStack stack;
    initCharStack(&stack);
    
    int i = 0, j = 0;
    char current;
    
    while ((current = infix[i++]) != '\0') {
        if (isalnum(current)) {
            postfix[j++] = current;
        }
        else if (current == '(') {
            pushChar(&stack, current);
        }
        else if (current == ')') {
            while (!isCharStackEmpty(&stack) && peekChar(&stack) != '(') {
                postfix[j++] = popChar(&stack);
            }
            if (!isCharStackEmpty(&stack)) {
                popChar(&stack);
            }
        }
        else if (isOperator(current)) {
            while (!isCharStackEmpty(&stack) && 
                   getPrecedence(peekChar(&stack)) >= getPrecedence(current)) {
                postfix[j++] = popChar(&stack);
            }
            pushChar(&stack, current);
        }
    }
    while (!isCharStackEmpty(&stack)) {
        postfix[j++] = popChar(&stack);
    }
    postfix[j] = '\0';
}

int performOperation(int operand1, int operand2, char operator) {
    switch (operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 != 0) {
                return operand1 / operand2;
            } else {
                printf("Error: Division by zero!\n");
                return 0;
            }
        case '^':
            {
                int result = 1;
                for (int i = 0; i < operand2; i++) {
                    result *= operand1;
                }
                return result;
            }
        default:
            return 0;
    }
}

int evaluatePostfix(char *postfix) {
    IntStack stack;
    initIntStack(&stack);
    
    int i = 0;
    char current;
    
    printf("Evaluation steps:\n");
    
    while ((current = postfix[i++]) != '\0') {
        if (isalnum(current)) {
            int value = current - '0'; 
            pushInt(&stack, value);
            printf("Push %d to stack\n", value);
        }
        else if (isOperator(current)) {
            if (stack.top >= 1) {
                int operand2 = popInt(&stack);
                int operand1 = popInt(&stack);
                int result = performOperation(operand1, operand2, current);
                pushInt(&stack, result);
                printf("Pop %d and %d, perform %d %c %d = %d, push result\n", 
                       operand2, operand1, operand1, current, operand2, result);
            }
        }
    }
    return popInt(&stack);
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];
    
    printf("Infix to Postfix Converter and Evaluator\n");
    printf("========================================\n\n");
    
    char testCases[][MAX_SIZE] = {
        "2+3*4",
        "A+B*C-D",
        "(A+B)*(C-D)",
        "A*B+C/D",
        "2+3*4-1"
    };
    
    int numTests = sizeof(testCases) / sizeof(testCases[0]);
    
    for (int i = 0; i < numTests; i++) {
        strcpy(infix, testCases[i]);
        infixToPostfix(infix, postfix);
        
        printf("Test Case %d:\n", i + 1);
        printf("Infix:    %s\n", infix);
        printf("Postfix:  %s\n", postfix);
        
        int canEvaluate = 1;
        for (int j = 0; j < strlen(infix); j++) {
            if (isalpha(infix[j])) {
                canEvaluate = 0;
                break;
            }
        }
        
        if (canEvaluate) {
            int result = evaluatePostfix(postfix);
            printf("Result:   %d\n", result);
        } else {
            printf("Result:   Cannot evaluate (contains variables)\n");
        }
        printf("\n");
    }
    
    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = '\0';
    
    infixToPostfix(infix, postfix);
    
    printf("\nUser Input:\n");
    printf("Infix:    %s\n", infix);
    printf("Postfix:  %s\n", postfix);
    
    int canEvaluate = 1;
    for (int i = 0; i < strlen(infix); i++) {
        if (isalpha(infix[i])) {
            canEvaluate = 0;
            break;
        }
    }
    
    if (canEvaluate) {
        int result = evaluatePostfix(postfix);
        printf("Result:   %d\n", result);
    } else {
        printf("Result:   Cannot evaluate (contains variables)\n");
    }
    
    return 0;
}