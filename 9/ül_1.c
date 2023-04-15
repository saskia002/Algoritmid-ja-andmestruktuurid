#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#define maxN 13

int matrix[maxN][maxN] = {0};
char towns[maxN][100];
int verticesCount, edgesCount;
char distFilePath[] = "./data/distances.txt";
char townFilePath[] = "./data/towns.txt";

void initTowns() {
	FILE *f = NULL;
	char town[100];
	int i=0;

	f = fopen(townFilePath, "r");

	while(!feof(f)) {
		fscanf(f, "%s", &town);
		// printf("%s\n", town);
		strcpy(towns[i], town);
		i++;
		
	}

}

void initGraph() {
	FILE *f = NULL;
	int vertice, vertice2, distance; // from, to, dist between
	int i, j;

	f = fopen(distFilePath, "r");
	fscanf(f, "%d %d", &verticesCount, &edgesCount);
	// printf("v:%d, e:%d\n", verticesCount, edgesCount);

	while(!feof(f)) {
		fscanf(f, "%d %d %d", &vertice, &vertice2, &distance);
		// printf("%d %d %d\n", vertice, vertice2, distance);
		matrix[vertice][vertice2] = distance;
        matrix[vertice2][vertice] = distance;
	}

	printf("\n%2s", "😎");
    for(i=1; i<=edgesCount; i++){
        printf("%4d", i);
    }
    printf("\n");

	for (i = 1; i <= verticesCount; i++) {
        printf("%2d", i);
        for (j = 1; j <= edgesCount; j++) {
        	printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n");

}

int minDistance(int distance[], bool checkedNode[]) {
    int min = 9999, minIndex;
  
    for (int v = 0; v < verticesCount; v++) {
    	if (checkedNode[v] == false && distance[v] <= min) {
            min = distance[v], minIndex = v;
        }
    }
        
  
    return minIndex;
}

void printSolution(int distance[], int dest, int start) {
    // printf("\nlõpp \t\t Vahemaa pikkus\n");
    // for (int i = 0; i < verticesCount; i++) {
    //     printf("%d \t\t\t\t %d\n", i, distance[i]);
    // }

	// printf("\n%s -> %s\n", towns[0], towns[1]);

    printf("\n%s -> %s\n", towns[start-1], towns[dest-1]);
    printf("Vahemaa pikkus: %d\n", distance[dest]);
}

void dijkstra(int start, int dest){
    int distance[verticesCount]; // The output array.
    bool checkedNode[verticesCount];
  
    // Initialize all distances as INFINITE
    for (int i = 0; i < verticesCount; i++) {
        distance[i] = 9999, checkedNode[i] = false;
    }
  
    distance[start] = 0; // distance source V from itself is always 0
  
    // Find shortest path for all vertices
    for (int count = 0; count < verticesCount - 1; count++) {
        int u = minDistance(distance, checkedNode);
  
        checkedNode[u] = true;
  
        for (int v = 0; v < verticesCount; v++) {
        	if (
            	!checkedNode[v] && matrix[u][v]
                && distance[u] != 9999
                && distance[u] + matrix[u][v] < distance[v]
            ) {
                distance[v] = distance[u] + matrix[u][v];
            }
        }
            
    }
  
    printSolution(distance, dest, start);
}

void main() {
	int start, dest;

	initGraph();
	initTowns();

	printf("Sisesta alguskoht: ");
    scanf("%d", &start);
    printf("Sisesta sihtkoht: ");
    scanf("%d", &dest);

    dijkstra(start, dest);

    printf("\n");

}