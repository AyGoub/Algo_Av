/**
 * @file list.c
 * @brief Implementation file for a linked list
 *
 * This file contains the implementation of the linked list data structure
 * and its associated functions.
 *
 * @author LoÃ¯ck Lhote
 * @date February 2023
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include <string.h>

/**
 * @brief Creates a new linked list
 *
 * @return A pointer to the newly created linked list
 */
List newList() {
    return NULL;
}

/**
 * @brief Frees the memory used by a linked list
 *
 * @param L Pointer to the linked list to be freed
 */
void freeList(List L) {
    if (L == NULL) {
	    return; 
    }
    freeList(L->nextCell);
    free(L);
    return;
}

/**
 * @brief Prints the contents of a linked list
 *
 * @param L Pointer to the linked list to be printed
 */
void printList(List L,int type) {
    if (L==NULL) {
    	printf("[]\n");
    }
    else {
        if (type!=0) {
	        List Aff = L->nextCell;
	        printf("[(%s, %d)", L->key, L->value);
	        while(Aff != NULL) {
		        printf(", (%s, %d)", Aff->key, Aff->value);
		        Aff = Aff->nextCell;
            }
        }
        else {
            List Aff = L->nextCell;
            printf("[%d", L->value);
            while(Aff != NULL) {
                printf(", %d", Aff->value);
                Aff = Aff->nextCell;
            }
        }
	printf("]\n");
    }
    return;
}


/**
 * @brief Finds a key in a linked list
 *
 * @param L Pointer to the linked list to search in
 * @param key Key to search for
 *
 * @return A pointer to the first cell containing the key, or NULL if the key is not found
 */
Cell* findKeyInList(List L, string key) {
    if (L==NULL) {
    	return NULL;
    }
    if (strcmp(key, L->key)==0) {
	    return L;
    }
    return findKeyInList(L->nextCell, key);
}

/**
 * @brief Deletes a key from a linked list
 *
 * @param L Pointer to the linked list to search in
 * @param key Key to delete
 *
 * @return A pointer to the modified linked list
 */
List delKeyInList(List L, string key) {
    if (L == NULL) {
	    return L;
    }

    Cell* Act = L;
    Cell* Fut = L->nextCell;

    while (strcmp(key, L->key)==0) {
	    if(Fut==NULL) {
		    free(L);
		    return NULL;
	    }
	    L=Fut;
	    free(Act);
	    Act=L;
	    Fut=Act->nextCell;
    }
    	    
    while (Fut != NULL) {
	    if(strcmp(Fut->key, key)==0) {
		    Act->nextCell=Fut->nextCell;
		    free(Fut);
		    Fut=Act->nextCell;
	    }
	    else {
		    Act=Fut;
		    Fut=Fut->nextCell;
	    }
    }
    return L;
}

/**
 * @brief Adds a key-value pair to a linked list
 *
 * @param L Pointer to the linked list to add to
 * @param key Key to add
 * @param value Value to add
 *
 * @return A pointer to the modified linked list
 *
 * The key-value pair is added at the beginning of the list
 */

 List addKeyValueInList(List L, string key, int value) {
	 List NewL = (List) malloc(sizeof(Cell));
	 NewL->value = value;
	 NewL->nextCell = L;
	 NewL->key = key;
    return NewL;
}

