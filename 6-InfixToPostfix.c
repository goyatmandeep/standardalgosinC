#include <stdio.h>   // Infix to postfix conversion.
#include <stdlib.h>
#define MAX 200   // Max size of stack and input.
char stack[MAX];
int top = -1;
char pop(){                     // Stack's pop function.
    if(top >= 0)
        return stack[top--];
    printf("Nothing to pop\n");
    exit(1);
}
void push(char a){              // Stack's push function.
    stack[++top] = a;
    return;
}
char peek(){
    if(top >= 0)                    // Stack top element.
        return stack[top];
}
int isempty(){                  // Stack empty check
    if(top == -1)
        return 1;
    else return 0;
}
int isoperator(char input){   // to check if input character is operator or not.
    if(input == '+' || input == '-' || input == '^' || input == '%' || input == '/' || input == '*' || input == '(')
        return 1;
    return 0;
}
int isoperand(char input){      // to check if input character operand or not.
    if(input >= 48 && input <= 57 || input >= 65 && input <= 90 || input >= 97 && input <= 122)
        return 1;
    return 0;
}
int inprec(char input){     // function to return precedence value if operator is present in stack.
    switch(input){
    case '+':
    case '-':
        return 2;
    case '*':
    case '%':
    case '/':
        return 4;
    case '^':
        return 5;
    case '(':
        return 0;
    }
}
int outprec(char input){  // function to return precedence value if operator is present outside stack.
    switch(input){
    case '+':
    case '-':
        return 1;
    case '*':
    case '%':
    case '/':
        return 3;
    case '^':
        return 6;
    case '(':
        return 100;
    }
}
void intopost(char *input){  // function to transfer infix to postfix.
    int i = 0;
    while(input[i] != '\0'){        // while input character is not equal to NULL, iterate.
        if(isoperand(input[i])){    // if character a operand,simply print.
            printf("%c",input[i]);
        }
        else if(isoperator(input[i])){        // if input character a operator
            if(isempty() || outprec(input[i])>inprec(peek())) // if stack empty or out precedence greater than in precedence
                push(input[i]);                                // push the operand.
            else{
                while(!isempty() && outprec(input[i])<inprec(peek())){  //else pop while in precedence greater than out precedence.
                    printf("%c",pop());
                }
                push(input[i]);         // push the current input character.
            }
        }
        else if(input[i] == ')'){   // condition for opening bracket
            while(peek() != '('){
                printf("%c",pop());
                if(isempty()){          // if opening bracket not present then give error.
                    printf("Wrong input\n");
                    exit(1);
                }
            }
           pop();       // pop the opening bracket.
        }
        i++;
    }
    while(!isempty()){          // pop the remaining operators in the stack.
        if(peek() == '('){
            printf("\n Wrong input\n");
            exit(1);
           }
        printf("%c",pop());
    }
}
int main(){                 // main function
    char input[MAX];
    printf("Enter the input infix expression\n");
    scanf("%[^\n]s",&input);    //Enter the input expression ([^\n] is used to allow spaces in input)
    printf("Post order of given expression\n");
    intopost(&input);
}







