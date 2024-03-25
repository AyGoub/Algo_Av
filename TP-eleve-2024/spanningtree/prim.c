/**
 * @file graph.c
 *
 * @brief This file implements a graph data structure using a table of lists.
 */

#include <stdlib.h>
#include <stdio.h>
#include "../graph/graph.h"
#include "../heap/heap.h"
#include <limits.h>

/**
 * @brief Function that computes a minimum spanning tree of graph g of the connex component of the vertex s
 *
 * @param graph The graph
 * @param s Index of the initial vertex of the Prim procedure.
 *
 * The array parents is updated so that it contains the spanning tree
 * computed by the Prim algorithm.
 * Note that the array parents must be initialized before calling the function.
 */
void Prim(Graph g, int s)
{
   Heap *h = createHeap(g.numberVertices);
   for (int i = 0; i < g.numberVertices; ++i)
      insertHeap(h, i, UINT_MAX);

   for (int j = 0; j < g.numberVertices; ++j)
   {
      int temp = h->heap[j];
      h->priority[temp] = UINT_MAX;
   }
   h->priority[s] = 0;
   g.parents[s] = -1;
   while (h->nbElements != 0)
   {
      int u_min = removeElement(h);
      List Node = g.array[u_min];
      while (Node != NULL)
      {
         int value = Node->value;

         if ((distance(g.xCoordinates[value], g.xCoordinates[u_min], g.yCoordinates[value], g.yCoordinates[u_min]) < h->priority[value]) && g.parents[value] != u_min)
         {
            g.parents[value] = u_min;
            h->priority[value] = distance(g.xCoordinates[value], g.xCoordinates[u_min], g.yCoordinates[value], g.yCoordinates[u_min]);
            

         }

         Node = Node->nextCell;
      }
   }
}
