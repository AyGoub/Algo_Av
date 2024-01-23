#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

/**
 * @brief Helper function to swap two elements in the heap.
 * @param h A pointer to the Heap data structure.
 * @param i The index of the first element.
 * @param j The index of the second element.
 */
void swap(Heap *h, int i, int j) {
    int temp = h->heap[i];
    h->heap[i] = h->heap[j];
    h->heap[j] = temp;

    temp = h->position[h->heap[i]];
    h->position[h->heap[i]] = h->position[h->heap[j]];
    h->position[h->heap[j]] = temp;
}


/**
 * @brief Creates a new Heap data structure.
 * @param n The maximum number of elements that the heap can store.
 * @return A pointer to the newly created Heap data structure.
 * The elements of the arrays position and priority are initialized to -1
 */
Heap* createHeap(int n) {
    return NULL;
}

/**
 * @brief Prints the elements in the Heap data structure.
 * @param h The Heap data structure to print.
 */
void printHeap(Heap h) {
    return;
}

/**
 * @brief Gets the element with the smallest priority (smallest value in the priority array) from the Heap data structure.
 * @param h The Heap data structure to get the element from.
 * @return The element with the smallest priority.
 */
int getElement(Heap h) {
    return 0;
}

/**
 * @brief Inserts a new element into the Heap data structure with the given priority.
 * @param h A pointer to the Heap data structure to insert the element into.
 * @param element The element to insert.
 * @param priority The priority of the element to insert.
 */
void insertHeap(Heap *h, int element, double priority) {
    return;
}

/**
 * @brief Modifies the priority of an element in the Heap data structure.
 * @param h A pointer to the Heap data structure to modify.
 * @param element The element whose priority is to be modified.
 * @param priority The new priority of the element.
 */
void modifyPriorityHeap(Heap *h, int element, double priority) {
    return;
}


/**
 * @brief Removes the element with the smallest priority (smallest value in the priority array) from the Heap data structure.
 * @param h A pointer to the Heap data structure to remove the element from.
 * @return The element with the smallest priority that was removed from the Heap data structure.
 */
int removeElement(Heap *h) {
    return 0;
}


