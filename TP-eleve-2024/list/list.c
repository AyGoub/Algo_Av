/**
 * @file list.c
 * @brief Implementation file for a linked list
 *
 * This file contains the implementation of the linked list data structure
 * and its associated functions.
 *
 * @author Loïck Lhote
 * @date February 2023
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

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
	if (L==NULL) {
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
 * @param type If type==0, prints only the values, otherwise print the couples (key,vlaue)
 *
 * Prints the linked list in the following way if k!=0:
 * [(key 1, value 1),(key 2, value 2), … ,(key k, value k)]
 * Prints the linked list in the following way if k==0:
 * [value 1,value 2,…,value k]
 */

void printList(List L, int type) {
	if (L==NULL) {
		printf("[]\n");
	}
	else {
		printf("[");
		if (type!=0) {
			List newlist = L->nextCell;
			printf("(%s, %d)",L->key,L->value);
			while (newlist!=NULL) {
				printf(",(%s, %d)",newlist->key,newlist->value);
				newlist=newlist->nextCell;
			}
		}
		else {
			List newlist = L->nextCell;
			printf("%d",L->value);
			while (newlist!=NULL) {
				printf(", %d",newlist->value);
				newlist=newlist->nextCell;
			}
		}
		printf("]\n");
	}
	
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
	List newlist;
	newlist=L;
	while (newlist!=NULL) {
		if (strcmp(newlist->key,key)==0) {
			return newlist;
		}
		newlist=newlist->nextCell;
	}	
	return NULL;
}

/**
 * @brief Deletes a key from a linked list
 *
 * @param L Pointer to the linked list to search in
 * @param key Key to delete
 *
 * @return A pointer to the modified linked list
 * Only the first occurrence of the key is deleted.
 */
List delKeyInList(List L, string key) {
	List newlist;
	newlist=malloc(sizeof(List));
	if(L==NULL){
		return L;
	}
	else{
		
		newlist=L->nextCell;
		
	}

    return newlist;
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
	 List newlist;
	 newlist=(List)malloc(sizeof(Cell));
	 newlist->key=key;
	 newlist->value=value;
	 newlist->nextCell=L;

    return newlist;
}


