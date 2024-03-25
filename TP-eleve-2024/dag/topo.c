/**
 * @file topo.c
 *
 * @brief This file implements based on the topological ordering.
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../graph/graph.h"
#include "../stack/stack.h"

void topologicalSortUtil(Graph graph, int vertex, int *visited, Stack* stack,int parent) {
    visited[vertex] = 1;
    graph.parents[vertex] = parent;
    List temp=graph.array[vertex];
    while (temp!=NULL) {
        if (!visited[temp->value]) {
            topologicalSortUtil(graph, temp->value, visited, stack,vertex);
        }
        temp=temp->nextCell;
    }
    push(stack, vertex);
}
/**
 * @brief Function to perform a topological sort of a graph. Update the field topological_ordering of the graph.
 *
 * @param graph The graph to be sorted.
 */

void topologicalSort(Graph graph) {
    Stack* stack = createStack();
    int N = graph.numberVertices;
    int *visited = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        visited[i] = 0;
    }
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            topologicalSortUtil(graph, i, visited, stack,-1);
        }
    }
    for (int i = 0; i < N; i++) {
        graph.topological_ordering[i] = pop(stack);
    }
    free(visited);
    free(stack);
}


/**
 * @brief Function to compute the earliest start date of each vertex in a graph.
 *
 * @param graph The graph for which to compute the earliest start dates.
 * Updates the array containing the earliest start date of each vertex in the graph structure.
 */

void computeEarliestStartDates(Graph graph) {
    int N = graph.numberVertices;

    for (int i=0;i<N;i++) {
        graph.earliest_start[i] = 0;
    }
    for(int i=0;i<N;i++) {
        int node = graph.topological_ordering[i];
        List temp = graph.array[node];
        while (temp != NULL) {
            int next_node = temp->value;
            double new_start_date = graph.earliest_start[node]+distance(graph.xCoordinates[node], graph.yCoordinates[node], graph.xCoordinates[next_node], graph.yCoordinates[next_node]);
            if (new_start_date > graph.earliest_start[next_node]) {
                graph.earliest_start[next_node] = new_start_date;
            }
            temp = temp->nextCell;
        }
    }


}



/**
 * @brief Function to compute the latest start date of each vertex in a graph.
 *
 * @param graph The graph for which to compute the latest start dates.
 * Updates the array containing the latest start date of each vertex in the graph structure.
 */
void computeLatestStartDates(Graph graph) {
    int N = graph.numberVertices;
    double max_date = 0;

    for (int i=0;i<N;i++) {
        List temp = graph.array[i];
        if(temp == NULL) {
            double temp2=graph.earliest_start[i];
            if (temp2>max_date) {
                max_date = temp2;
            }
        }
    }

    for (int i=N-1;i>=0;i--) {
        int node = graph.topological_ordering[i];
        List temp = graph.array[node];
        graph.latest_start[node] = max_date;
        if (temp == NULL) {
            graph.latest_start[node] = max_date;
        }
        else {
            while (temp != NULL) {
                int next_node = temp->value;
                double new_start_date = graph.latest_start[next_node]-distance(graph.xCoordinates[node], graph.yCoordinates[node], graph.xCoordinates[next_node], graph.yCoordinates[next_node]);
                if (new_start_date < graph.latest_start[node]) {
                    graph.latest_start[node] = new_start_date;
                }
                temp = temp->nextCell;
            }
        }
    }
}
