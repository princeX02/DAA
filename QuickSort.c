#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int partition(int a[],int low,int high)
{
	int i,j,temp,pivot;
	pivot=a[low];
	i=low+1;
	j=high;
	while(1)
	{
		while(i<high&&a[i]<=pivot)
		i++;
		while(a[j]>pivot)
		j--;
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
		else
		{
			temp=a[j];
			a[j]=a[low];
			a[low]=temp;
			return j;
		}
	}
}

void  quick_sort(int a[],int low,int high)
{
	int j;
	if(low<high)
	{
		j=partition(a,low,high);
		quick_sort(a,low,j-1);
		quick_sort(a,j+1,high);
	}
}

int main()
{
	int i, n,a[200000];
      double clk;
      clock_t starttime,endtime;
	printf("Enter the number of students records: \n");
	scanf("%d",&n);
       for(i=0;i<n;i++) 
       {
        	 a[i]=rand()%100;
         	printf("The roll numbers are \t%d",a[i]);
        }
        starttime=clock();
	quick_sort(a,0,n-1);
      endtime=clock();
      clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
	printf("\nSorted roll numbers are: \n");
	for(i=0;i<n;i++)
	printf("\t%d",a[i]);
      printf("\nThe run time is %f\n",clk);
}
