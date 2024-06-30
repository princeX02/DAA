
#include <stdio.h>

int count, w[10], d, x[10];

void subset(int cs, int k, int r)
{
    int i;
    if (cs == d)
    {
        printf("\nSubset solution = %d\n", ++count);
        for (i = 0; i < k; i++)
        {
            if (x[i] == 1)
                printf("%d\n", w[i]);
        }
        return;
    }
    if (k >= 10 || cs > d)
        return;
    if (cs + w[k] <= d)
    {
        x[k] = 1;
        subset(cs + w[k], k + 1, r - w[k]);
    }
    if (cs + r - w[k] >= d)
    {
        x[k] = 0;
        subset(cs, k + 1, r - w[k]);
    }
}

int main()
{
    int sum = 0, i, n;
    printf("Enter number of elements\n");
    scanf("%d", &n);
    printf("Enter the elements in ascending order\n");
    for (i = 0; i < n; i++)
        scanf("%d", &w[i]);
    printf("Enter the required sum\n");
    scanf("%d", &d);
    for (i = 0; i < n; i++)
        sum += w[i];
    if (sum < d)
    {
        printf("No solution exists\n");
        return 0;
    }
    printf("The solution is\n");
    count = 0;
    subset(0, 0, sum);
    if (count == 0)
    {
        printf("No solution exists\n");
    }
    return 0;
}
