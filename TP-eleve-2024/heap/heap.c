#include <stdio.h>
#include <stdlib.h>
#include <float.h>
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
    if (n <= 0) {
        return NULL;
    }
    Heap *h = malloc(sizeof(Heap));
    h->n = n;
    h->nbElements = 0;
    h->position = malloc(n*sizeof(int));
    h->heap = malloc(n*sizeof(int));
    h->priority = malloc(n*sizeof(double));
    for (int i=0;i<n;i++) {
        h->position[i]=-1;
        h->priority[i]=-1;
        h->heap[i]=-1;
    }
    return h;
}

/**
 * @brief Prints the elements in the Heap data structure.
 * @param h The Heap data structure to print.
 */
void printHeap(Heap h) {
    printf("\n");
    printf("n: %d\n", h.n);
    printf("nbElements: %d\n", h.nbElements);
    printf("position: [");
    for (int i=0;i<h.n;i++) {
        printf("%d ",h.position[i]);
    }
    printf("]\n");
    printf("priority: [");
    for (int k=0;k<h.n;k++) {
        printf("%.2f ",h.priority[k]);
    }
    printf("]\n");
    printf("heap: [");
    for (int j=0;j<h.nbElements;j++) {
        printf("%d ",h.heap[j]);
    }
    printf("]\n");
}

/**
 * @brief Gets the element with the smallest priority (smallest value in the priority array) from the Heap data structure.
 * @param h The Heap data structure to get the element from.
 * @return The element with the smallest priority.
 */
int getElement(Heap h) {
    if (h.nbElements == 0) {
        return -1;
    }
    double min= DBL_MAX;
    int index = -1;
    for (int i=0;i<h.nbElements;i++) {
        if (h.priority[i]<min && h.priority[i]!=-1) {
            min = h.priority[i];
            index = i;
        }
    }
    return index;
}

/**
 * @brief Inserts a new element into the Heap data structure with the given priority.
 * @param h A pointer to the Heap data structure to insert the element into.
 * @param element The element to insert.
 * @param priority The priority of the element to insert.
 */
void insertHeap(Heap *h, int element, double priority) {
    if (h->nbElements==h->n) {
        return;
    }
    h->nbElements++;
    h->priority[element]=priority;
    h->heap[h->nbElements-1]=element;
    h->position[element]=h->nbElements-1;
    int i = h->nbElements-1;
    while (i>0) {
        if (i%2==0) {
            if (h->priority[h->heap[i]]<h->priority[h->heap[(i-2)/2]]) {
                swap(h,i,(i-2)/2);
                i=(i-2)/2;

            }
            else {
                break;
            }
        }
        else {
            if (h->priority[h->heap[i]]<h->priority[h->heap[(i-1)/2]]) {
                swap(h,i,(i-1)/2);
                i=(i-1)/2;
            }
            else {
                break;
            }
        }
    }
}

/**
 * @brief Modifies the priority of an element in the Heap data structure.
 * @param h A pointer to the Heap data structure to modify.
 * @param element The element whose priority is to be modified.
 * @param priority The new priority of the element.
 */
void modifyPriorityHeap(Heap *h, int element, double priority) {
    double temp = h->priority[element];
    h->priority[element] = priority;
    int i = h->position[element];
    if (temp < priority) {
        while (i < h->nbElements) {
            int leftChild = 2 * i + 1;
            int rightChild = 2 * i + 2;
            if ((leftChild < h->nbElements && h->priority[h->heap[i]] > h->priority[h->heap[leftChild]]) ||
                (rightChild < h->nbElements && h->priority[h->heap[i]] > h->priority[h->heap[rightChild]])) {
                if (rightChild >= h->nbElements || h->priority[h->heap[leftChild]] < h->priority[h->heap[rightChild]]) {
                    swap(h, i, leftChild);
                    i = leftChild;
                } else {
                    swap(h, i, rightChild);
                    i = rightChild;
                }
            } else {
                break;
            }
        }
    } else {
        while (i > 0) {
            int parent = i % 2 == 0 ? (i - 2) / 2 : (i - 1) / 2;
            if (h->priority[h->heap[i]] < h->priority[h->heap[parent]]) {
                swap(h, i, parent);
                i = parent;
            } else {
                break;
            }
        }
    }
}


/**
 * @brief Removes the element with the smallest priority (smallest value in the priority array) from the Heap data structure.
 * @param h A pointer to the Heap data structure to remove the element from.
 * @return The element with the smallest priority that was removed from the Heap data structure.
 */
int removeElement(Heap *h) {
    if (h->nbElements == 0) {
        printf("Le tas est vide\n");
        return -1;
    }

    int minElement = h->heap[0];
    swap(h, 0, h->nbElements-1);
    h->nbElements--;

    int i = 0;
    while (i < h->nbElements) {
        int leftChild = 2*i+1;
        int rightChild = 2*i+2;

        if (leftChild >= h->nbElements) {
            break;
        }

        int index = (rightChild >= h->nbElements || h->priority[h->heap[leftChild]] < h->priority[h->heap[rightChild]]) ? leftChild : rightChild;

        if (h->priority[h->heap[i]] > h->priority[h->heap[index]]) {
            swap(h, i, index);
            i = index;
        } else {
            break;
        }
    }
    h->position[minElement] = -1;

    return minElement;
}


