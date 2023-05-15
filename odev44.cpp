#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define ARRAY_SIZE 20
#define GRAPH_SIZE 10
#define MAX_WEIGHT 10

// Max value for infinity
#define INFINITY INT_MAX

void generate_random_array(int array[], int size);
void bubble_sort(int array[], int size);
double find_avg_max_subarray_sum(int array[], int size);
void floyd_warshall(int graph[][GRAPH_SIZE], int dist[][GRAPH_SIZE], int size);
void print_array(int array[], int size);
void print_graph(int graph[][GRAPH_SIZE], int size);
void print_result(int dist[][GRAPH_SIZE], int size, int threshold);

int main() {
    int array[ARRAY_SIZE];
    int graph[GRAPH_SIZE][GRAPH_SIZE] = {
        { 0, 10,  3,  0,  0,  5,  0, 17,  0, 22},
        {10,  0,  5,  0,  2,  0, 13,  0,  0,  0},
        { 3,  5,  0,  2,  0,  4,  0, 21,  0, 11},
        { 0,  0,  2,  0,  7,  0,  6,  0,  0,  0},
        { 0,  2,  0,  7,  0,  6,  0,  0, 19,  0},
        { 5,  0,  4,  0,  6,  0,  9,  3,  0,  0},
        { 0, 13,  0,  6,  0,  9,  0,  4,  0,  0},
        {17,  0, 21,  0,  0,  3,  4,  0,  8,  0},
        { 0,  0,  0,  0, 19,  0,  0,  8,  0,  5},
        {22,  0, 11,  0,  0,  0,  0,  0,  5,  0}
    };
    int dist[GRAPH_SIZE][GRAPH_SIZE];
    int threshold;

    // Seed for random number generator
    srand(time(NULL));

    // Calculate execution time
    clock_t start, end;
    double time_elapsed;

    start = clock();

    generate_random_array(array, ARRAY_SIZE);
    printf("Array:\n");
    print_array(array, ARRAY_SIZE);

    bubble_sort(array, ARRAY_SIZE);
    printf("\nBubble Sort Result:\n");
    print_array(array, ARRAY_SIZE);

    threshold = (int)find_avg_max_subarray_sum(array, ARRAY_SIZE);
    printf("\nAverage Max Subarray Sum: %d\n", threshold);

    printf("\nGraph:\n");
    print_graph(graph, GRAPH_SIZE);

    floyd_warshall(graph, dist, GRAPH_SIZE);
    printf("\nFloyd Warshall Result:\n");
    print_graph(dist, GRAPH_SIZE);

    printf("\nResult for %d:\n", threshold);
    print_result(dist, GRAPH_SIZE, threshold);

    end = clock();
    time_elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nExecution Time: %f sec\n", time_elapsed);

    return 0;
}

void generate_random_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % (2 * MAX_WEIGHT) - MAX_WEIGHT;
    }
}

void bubble_sort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

double find_avg_max_subarray_sum(int array[], int size) {
    int max_sum = 0, current_sum = 0;
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (current_sum + array[i] > 0) {
            current_sum += array[i];
        }
        else {
            current_sum = 0;
        }
        if (current_sum > max_sum) {
            max_sum = current_sum;
            count++;
        }
    }

    return (double)max_sum / count;
}

void floyd_warshall(int graph[][GRAPH_SIZE], int dist[][GRAPH_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                dist[i][j] = 0;
            }
            else if (graph[i][j] != 0) {
                dist[i][j] = graph[i][j];
            }
            else {
                dist[i][j] = INFINITY;
            }
        }
    }

    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (dist[i][k] != INFINITY && dist[k][j] != INFINITY &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

void print_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
}

void print_graph(int graph[][GRAPH_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (graph[i][j] == INFINITY) {
                printf("INF ");
            }
            else {
                printf("%3d ", graph[i][j]);
            }
        }
        printf("\n");
    }
}

void print_result(int dist[][GRAPH_SIZE], int size, int threshold) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (dist[i][j] <= threshold) {
                printf("Shortest Path from %d to %d: %d\n", i, j, dist[i][j]);
            }
        }
    }
}
