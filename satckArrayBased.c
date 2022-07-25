#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define StackEntry int
#define MAXSTACK 20
typedef struct stack {
     int top;
     StackEntry entry[MAXSTACK];
} stack;
void CreateStack(stack *ps);
bool StackFull(stack *ps);
void push(StackEntry e, stack *ps);
bool StackEmpty(stack *ps);
void pop(StackEntry *pe, stack *ps);
void StackTop(StackEntry *pe, stack *ps);
int StackSize(stack *ps);
void ClearStack(stack *ps);
void TraverseStack(stack *ps, void(*pf)(StackEntry));
void Display(StackEntry e);
int main(){
     return 0;
}
void CreateStack(stack *ps){
     ps->top=0;
}
bool StackFull(stack *ps){
     return ps->top==MAXSTACK;
}
void push(StackEntry e, stack *ps){
     ps->entry[ps->top] = e;
     ps->top++;
}
bool StackEmpty(stack *ps){
     return ps->top==0;
}
void TraverseStack(stack *ps, void(*pf)(StackEntry)){
     for(int i=(ps->top);i>0;i--){
         pf(ps->entry[i-1]);
     }
}
void Display(StackEntry e){
     printf("%d\n",e);
}
void pop(StackEntry *pe, stack *ps){
     *pe = ps->entry[ps->top-1];
     ps->top--;
}
void StackTop(StackEntry *pe, stack *ps){
     *pe=ps->entry[ps->top-1];
}
int StackSize(stack *ps){
     return ps->top;
}
void ClearStack(stack *ps){
     ps->top=0;
}