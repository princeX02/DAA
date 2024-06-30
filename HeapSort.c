
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void heap_bottom_up(int h[], int n) {
    int i, v, k, j, heap;

    for (i = n / 2; i > 0; i--) {
        k = i;
        v = h[k];
        heap = 0;

        while (!heap && 2 * k <= n) {
            j = 2 * k;

            if (j < n && h[j] < h[j + 1]) {
                j++;
            }

            if (v >= h[j]) {
                heap = 1;
            } else {
                h[k] = h[j];
                k = j;
            }
        }
        h[k] = v;
    }
}

void heap_sort(int h[], int n) {
    int i, temp, last = n;

    if (n <= 1) {
        return;
    } else {
        heap_bottom_up(h, n);

        for (i = n; i > 1; i--) {
            temp = h[1];
            h[1] = h[i];
            h[i] = temp;

            last--;
            heap_bottom_up(h, last);
        }
    }
}

int main() {
    int n, i;
    int h[200000]; // Array to store the ranks
    double clk;
    clock_t starttime, endtime;

    printf("\nEnter the number of resumes: ");
    scanf("%d", &n);

    if (n > 200000) {
        printf("Number of records exceeds the maximum allowed size (200000).\n");
        return 1;
    }

    srand(time(0));
    for (i = 1; i <= n; i++) {
        h[i] = rand() % 100;
    }

    printf("The candidates' ranks are:\n");
    for (i = 1; i <= n; i++) {
        printf("%d ", h[i]);
    }
    printf("\n");

    starttime = clock();
    heap_sort(h, n);
    endtime = clock();

    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;

    printf("The ranks in sorted order are:\n");
    for (i = 1; i <= n; i++) {
        printf("%d ", h[i]);
    }
    printf("\nThe run time is %f seconds\n", clk);

    return 0;
}
