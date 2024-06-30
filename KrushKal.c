
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct edge {
    int u, v, cost;
};

typedef struct edge edge;

int find(int v, int parent[]) {
    if (parent[v] != v)
        parent[v] = find(parent[v], parent);
    return parent[v];
}

void union_ij(int i, int j, int parent[]) {
    int root_i = find(i, parent);
    int root_j = find(j, parent);
    
    if (root_i != root_j)
        parent[root_j] = root_i;
}

// Comparator function for qsort
int compare(const void* a, const void* b) {
    return ((edge*)a)->cost - ((edge*)b)->cost;
}

void kruskal(int n, edge e[], int m) {
    int count = 0, k = 0, i, sum = 0;
    int (*t)[2] = malloc((n - 1) * sizeof(int[2]));
    int *parent = malloc(n * sizeof(int));

    if (t == NULL || parent == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Sort edges based on cost
    qsort(e, m, sizeof(edge), compare);

    // Initialize parent array for union-find
    for (i = 0; i < n; i++)
        parent[i] = i;

    for (i = 0; i < m; i++) {
        int u = e[i].u;
        int v = e[i].v;

        if (find(u, parent) != find(v, parent)) {
            t[k][0] = u;
            t[k][1] = v;
            k++;
            count++;
            sum += e[i].cost;
            union_ij(u, v, parent);
        }
    }

    if (count == n - 1) {
        printf("Spanning tree exists\n");
        printf("The spanning tree is as follows:\n");
        for (i = 0; i < n - 1; i++) {
            printf("%d  %d\t", t[i][0], t[i][1]);
        }
        printf("\nThe cost of the spanning tree is %d\n", sum);
    } else {
        printf("\nSpanning tree does not exist\n");
    }

    free(t);
    free(parent);
}

int main() {
    int n, m, i;
    double clk;
    clock_t starttime, endtime;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    edge *e = malloc(m * sizeof(edge));

    if (e == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Enter the edge list (u v cost):\n");
    for (i = 0; i < m; i++) {
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].cost);
    }

    starttime = clock();
    kruskal(n, e, m);
    endtime = clock();

    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("The time taken is %f seconds\n", clk);

    free(e);
    return 0;
}
