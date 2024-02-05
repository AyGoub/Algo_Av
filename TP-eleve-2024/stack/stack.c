/**
 * @file stack.c
 * @brief Implementation file for the Stack data structure.
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "../list/list.h"

/**
 * @brief Creates a new stack with no elements.
 *
 * @return A pointer to the new stack.
 */
Stack* createStack() {
    Stack* s=malloc(sizeof(Stack)); 
    *s=newList();
    return s;
}

/**
 * @brief Pushes an element onto the top of the stack.
 *
 * @param stack The stack to push onto.
 * @param data The data to push onto the stack.
 */
void push(Stack* stack, int data) {

    Cell* newCell = (Cell*)malloc(sizeof(Cell));
    if (newCell == NULL) {
        // Gestion d'erreur en cas d'échec d'allocation
        return;
    }

    newCell->value = data;
    newCell->nextCell = *stack; 
    *stack = newCell; 



    
}

/**
 * @brief Pops an element from the top of the stack.
 *
 * @param stack The stack to pop from.
 *
 * @return The data from the top element of the stack.
 */
int pop(Stack* stack) {
    int value=(*stack)->value;
    (*stack)=(*stack)->nextCell;
    return value;
}

/**
 * @brief Peeks at the top element of the stack without removing it.
 *
 * @param stack The stack to peek at.
 *
 * @return The data from the top element of the stack.
 */
int peek(Stack stack) {

    return stack->value;
}

/**
 * @brief Checks whether the stack is empty.
 *
 * @param stack The stack to check.
 *
 * @return 1 if the stack is empty, 0 otherwise.
 */
int isStackEmpty(Stack stack) {
    if(stack==NULL)
        return 1;
    return 0;
}

/**
 * @brief Prints the contents of the stack to stdout.
 *
 * @param stack The stack to print.
 */
void stackPrint(Stack stack) {
    int type=0;
    printList(stack,type);
}
