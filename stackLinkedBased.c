#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define StackEntry int
typedef struct StackNode{
     StackEntry entry;
     struct StackNode *next;
} stacknode;
typedef struct stack {
     stacknode *top;
     int size;
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
     ps->top = NULL;
     ps->size=0;
}  
void push(StackEntry e, stack *ps){
     stacknode* pn;
     pn = (stacknode*)malloc(sizeof(stacknode)); //proper initialization
     pn->entry = e;
     pn->next = ps->top;
     ps->top = pn;
     ps->size++;
}
void pop(StackEntry *pe, stack *ps){
     stacknode *pn;
     *pe=ps->top->entry;
     pn=ps->top;
     ps->top=ps->top->next;
     free(pn);
     ps->size--;
}
bool StackEmpty(stack *ps){
     return ps->top==NULL;
}
bool StackFull(stack *ps){
     return 0;
}
void ClearStack(stack *ps){
     stacknode *pn;
     pn = ps->top;
     while(pn!=NULL){
     pn=pn->next;
     free(ps->top);
     ps->top=pn;
     }
     ps->size=0;
}
void StackTop(StackEntry *pe, stack *ps){
     *pe=ps->top->entry;
}
void TraverseStack(stack *ps, void(*pf)(StackEntry)){
     stacknode *pn;
     pn = ps->top;
     while(pn){
          pf(pn->entry);
          pn=pn->next;
     }
}
int StackSize(stack *ps){
     return ps->size;
}
void Display(StackEntry e){
     printf("%d\n",e);
}