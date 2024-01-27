#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "../list/list.h"

/**
 * @brief Creates a new, empty queue.
 *
 * @return A pointer to the newly created queue.
 */
 Queue* createQueue() {
     Queue* q = (Queue*)malloc(sizeof(Queue));
     q->front = NULL;
     q->rear = NULL;
     return q;
}


/**
 * @brief Checks whether the queue is empty.
 *
 * @param q The queue to check.
 * @return 1 if the queue is empty, 0 otherwise.
 */
int isQueueEmpty(Queue q) {
    if (q.front == NULL) {
        return 1;
    }
    return 0;
}


/**
 * @brief Prints all the elements in the queue, from front to rear.
 *
 * @param q The queue to print.
 */
void queuePrint(Queue q) {
    if (isQueueEmpty(q)) {
        printf("[]\n");
    }
    else {
        printf("[");
        Cell* temp = q.front;
        while (temp != NULL) {
            printf("%d", temp->value);
            if (temp->nextCell != NULL) {
                printf(",");
            }
            temp = temp->nextCell;
        }
        printf("]\n");
    }
}


/**
 * @brief Adds an element to the rear of the queue.
 *
 * @param q A pointer to the queue to add the element to.
 * @param data The data to be added to the queue.
 */
void enqueue(Queue* q, int data) {
    Cell* newCell = (Cell*)malloc(sizeof(Cell));
    newCell->value = data;
    newCell->nextCell = NULL;
    if (isQueueEmpty(*q)) {
        q->front = newCell;
        q->rear = newCell;
    } else {
        q->rear->nextCell = newCell;
        q->rear = newCell;
    }
}

/**
 * @brief Removes and returns the front element of the queue.
 *
 * @param q A pointer to the queue to remove the front element from.
 * @return The value stored in the front element of the queue.
 */
int dequeue(Queue* q) {
    if (isQueueEmpty(*q)) {
        printf("Error: queue is empty\n");
        return -1;
    }
    int value= q->front->value;
    Cell* temp = q->front;
    q->front = q->front->nextCell;
    free(temp);
    return value;

}


/**
 * @brief Returns the value of the front node but doesn't modify the queue
 *
 * @param q The queue to get the front value.
 * @return The value of the front node.
 */
int queueGetFrontValue(Queue q) {
    if (isQueueEmpty(q)) {
        printf("Error: queue is empty\n");
        return -1;
    }
    return q.front->value;
}
