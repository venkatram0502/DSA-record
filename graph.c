#include <stdio.h>
#include <stdlib.h>
define MAX 20
int adj[MAX][MAX];   // Adjacency matrix
int visited[MAX];    // Visited array
int queue[MAX];      // Queue for BFS
int front = -1, rear = -1;
void addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

void DFS(int vertex, int n) {
    printf("%d ", vertex);
    visited[vertex] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[vertex][i] == 1 && visited[i] == 0) {
            DFS(i, n);
        }
    }
}
void enqueue(int vertex) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = vertex;
}
// Dequeue operation for BFS
int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}
void BFS(int start, int n) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    enqueue(start);
    visited[start] = 1;
    printf("%d ", start);
    while (front <= rear) {
        int current = dequeue();
        for (int i = 0; i < n; i++) {
            if (adj[current][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
                printf("%d ", i);
            }
        }
    }
}
int main() {
    int n, edges, u, v, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    // Initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    printf("Enter starting vertex for traversal: ");
    scanf("%d", &start);
    printf("\nDepth First Search (DFS): ");
    for (int i = 0; i < n; i++)
        visited[i] = 0; // reset visited before DFS
    DFS(start, n);
    printf("\nBreadth First Search (BFS): ");
    front = rear = -1; // reset queue before BFS
    BFS(start, n);
    printf("\n");
    return 0;
}
