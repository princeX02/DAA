#include <stdio.h>
#include<stdlib.h>
#include<time.h>
void insertion_sort(long a[], int n) {
    int i, j;
    long v = 0;
    for (i = 1; i < n; i++) {
        v = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > v) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = v;
    }

    printf("Sorted numbers are:\n");
    for (i = 0; i < n; i++) {
        printf("%ld\n", a[i]);
    }
}

int main() {
    clock_t starttime, endtime;
    starttime = clock();
    double clk;
    int i, n;
    long a[10];

    printf("Enter the value of n: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        a[i] = 9000000000 + (rand() % 999999999) + 1;
    }

    printf("\nPhone numbers are:\n");
    for (i = 0; i < n; i++) {
        printf("%ld\n", a[i]);
    }

    insertion_sort(a, n);
    endtime = clock();
    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("\nThe run time is: %f\n", clk);

    return 0;
}


