/**
 * \file bst.c
 * \brief Implementation of classical functions for BST
 * \author Loïck LHOTE
 * \version 0.1
 * \date janvier 2023
 *
 * Source code of the functions declared in bst.h.
 * Thes functions are to manipulate binary search trees.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "bst.h"


/**
 * @brief Create an empty binary search tree.
 * @return A pointer to the root of the new empty tree (NULL pointer).
 */
BinarySearchTree createEmptyBST() {
    return NULL;
}

/**
 * @brief Free the memory of a binary search tree.
 * @param tree Pointer to the root of the tree.
 */
void freeBST(BinarySearchTree tree) {
    if (tree == NULL) {
        return;
    }

    freeBST(tree->leftBST);
    freeBST(tree->rightBST);

    free(tree);
}


/**
 * @brief Add a value to a binary search tree.
 * @param tree Pointer to the root of the tree.
 * @param value The value to add.
 * @return A pointer to the root of the modified tree.
 */
BinarySearchTree addToBST(BinarySearchTree tree, int value) {
    if(tree==NULL){
        BinarySearchTree newtree=malloc(sizeof(NodeBST));
        newtree->value=value;
        newtree->leftBST=NULL;
        newtree->rightBST=NULL;
        return newtree;
    }
    if(tree->value<value){
        tree->rightBST=addToBST(tree->rightBST,value);

    }
    else{
        tree->leftBST=addToBST(tree->leftBST,value);
    }

    
}


/**
 * @brief Compute the height of a binary search tree.
 * @param tree Pointer to the root of the tree.
 * @return The height of the tree.
 */
int heightBST(BinarySearchTree tree) {
    if (tree == NULL) {
        return 0;
    } else {
        int leftHeight = heightBST(tree->leftBST);
        int rightHeight = heightBST(tree->rightBST);
        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }
}


/**
 * @brief Search for a value in a binary search tree.
 * @param tree Pointer to the root of the tree.
 * @param value The value to search for.
 * @return A pointer to the node containing the value, or NULL if the value is not in the tree.
 */
BinarySearchTree searchBST(BinarySearchTree tree, int value) {
    if (tree == NULL || tree->value == value) {
        return tree;
    }
    if (value < tree->value) {
        return searchBST(tree->leftBST, value);
    }
    else {
        return searchBST(tree->rightBST, value);
    }
}


/**
 * @brief Delete the root of a binary search tree.
 * @param tree Pointer to the root of the tree.
 * @return A pointer to the root of the modified tree.
 */
BinarySearchTree deleteRootBST(BinarySearchTree tree) {
    if (tree==NULL) {
        return NULL;
    }
    return deleteFromBST(tree,tree->value);
}

/**
 * @brief Delete a value from a binary search tree.
 * @param tree Pointer to the root of the tree.
 * @param value The value to delete.
 * @return A pointer to the root of the modified tree.
 */
BinarySearchTree deleteFromBST(BinarySearchTree tree, int value) {
    if (tree == NULL) {
        return NULL;
    }
    if (value < tree->value) {
        tree->leftBST = deleteFromBST(tree->leftBST, value);
    } else if (value > tree->value) {
        tree->rightBST = deleteFromBST(tree->rightBST, value);
    } else {
        if (tree->leftBST == NULL) {
            BinarySearchTree newRoot = tree->rightBST;
            free(tree);
            return newRoot;
        } else if (tree->rightBST == NULL) {
            BinarySearchTree newRoot = tree->leftBST;
            free(tree);
            return newRoot;
        }
        BinarySearchTree successor = tree->rightBST;
        while (successor->leftBST != NULL) {
            successor = successor->leftBST;
        }
        tree->value = successor->value;
        tree->rightBST = deleteFromBST(tree->rightBST, successor->value);
    }
    return tree;
}

/**
 * @brief Build a binary search tree from a given permutation.
 * @param permutation Array of integers representing the permutation
 * @param n size of the array
 * @return A binary such tree built by successively inserting the elements of permutation.
 */
BinarySearchTree buildBSTFromPermutation(int *permutation,size_t n) {
    BinarySearchTree root = NULL;

    for (size_t i = 0; i < n; ++i) {
        int value = permutation[i];
        BinarySearchTree newNode = (BinarySearchTree)malloc(sizeof(NodeBST));
        newNode->value = value;
        newNode->leftBST = NULL;
        newNode->rightBST = NULL;

        if (root == NULL) {
            root = newNode;
        } else {
            BinarySearchTree current = root;
            BinarySearchTree parent = NULL;

            while (current != NULL) {
                parent = current;

                if (value < current->value) {
                    current = current->leftBST;
                } else {
                    current = current->rightBST;
                }
            }

            if (value < parent->value) {
                parent->leftBST = newNode;
            } else {
                parent->rightBST = newNode;
            }
        }
    }

    return root;
}


/**
 * @brief Print the elements of a binary search tree in a pretty format.
 * @param tree Pointer to the root of the tree.
 * @param space Space to be printed before the current element.
 */
void prettyPrintBST(BinarySearchTree tree, int space) {
    if (tree == NULL) {
        return;
    }
    space += 10;

    prettyPrintBST(tree->rightBST, space);

    printf("\n");
    for (int i = 10; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", tree->value);

    prettyPrintBST(tree->leftBST, space);
}

/**

Quelles conclusions pouvez-vous tirer des résultats d’expériences que vous obtenez ?

... Répondre ici.


*/
