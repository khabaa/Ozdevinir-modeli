#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

int top = -1;
char stack[MAX];

void push(char);
char pop();
int isEmpty();
int isFull();
int check_balanced(char*);
int match_char(char,char);
int check_increment_operator(char*);

int main(){
   char expr[MAX];
   int balanced, valid;
   
   printf("Matematiksel ifadeyi giriniz > ");
   scanf("%[^\n]",expr);
    
   balanced = check_balanced(expr);
   valid = check_increment_operator(expr);
   
   if(balanced == 1 && valid == 1)
        printf("Bu bir geçerli matematiksel ifadedir.\n");
   else
        printf("Bu bir geçerli matematiksel ifade değildir!\n");
    return 0;
}

int check_balanced(char *s){
    char temp;
    int i;
    for(i=0; i<strlen(s); i++){

        if(s[i] == '[' || s[i] == '(' || s[i] == '{')
            push(s[i]);

        if(s[i] == ']' || s[i] == ')' || s[i] == '}'){

            if(isEmpty()){
                printf("Sağ parantezler soldan fazladır.\n");
                return 0;
            }
            else{
                temp = pop();
                if(!match_char(temp, s[i])){
                    printf("Eşleşmeyen parantezler.\n");
                    return 0;
                }
            }
        }

        // Sıfıra bölme kontrolü
        if ((s[i] == '/' && s[i+1] == '0') || (s[i] == '/' && s[i+2] == '0')) {
            printf("Matematiksel ifade sıfıra bölme içeriyor.\n");
            return 0;
        }
    }
    if(isEmpty()){
        printf("Parantezler düzgün bir şekilde dengelenmiştir.\n");
        return 1;
    }
    else{
        printf("Sol parantezler sağdan fazladır.\n");
        return 0;
    }
}

int check_increment_operator(char *s) {
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == '+' && s[i + 1] == '+') {
            printf("Matematiksel ifade ++ operatörü içeriyor, bu geçerli bir matematiksel ifade değil.\n");
            return 0;
        }
    }
    return 1;
}

void push(char c){
    if(isFull()){
        printf("Stack overflow\n");
        exit(1);
    }
    top++;
    stack[top] = c;
}

char pop(){
    char c;
    if(isEmpty()){
        printf("Stack underflow\n");
        exit(1);
    }
    c = stack[top];
    top--;
    return c;
}

int isEmpty(){
    if(top == -1)
        return 1;
    else
        return 0;
}

int isFull(){
    if(top == MAX-1)
        return 1;
    else
        return 0;
}

int match_char(char a, char b){
    if(a == '[' && b == ']')
        return 1;
    if(a == '(' && b == ')')
        return 1;
    if(a == '{' && b == '}')
        return 1;
    return 0;
}