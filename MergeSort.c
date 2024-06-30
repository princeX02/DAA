#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int a[500000];
void merge(int,int,int);
void merge_sort(int low,int high)
{
	 int mid;
	 if(low<high)
	 {
		mid=(low+high)/2;
		merge_sort(low,mid);
		merge_sort(mid+1,high);
		merge(low,mid,high);
 	}
}
void merge(int low,int mid,int high)
{
	 int h,i,j,b[500000],k;
	 h=low;
	 i=low;
	 j=mid+1;
	 while((h<=mid)&&(j<=high))
	{
		  if(a[h]<=a[j])
		{
			   b[i]=a[h];
			   h++;
		}
		else
		{
			b[i]=a[j];
			 j++;
  		}
  		i++;
 	}
 	if(h>mid)
 	{
  		for(k=j;k<=high;k++)
  		{
   			b[i]=a[k];
   			i++;
  		}
	}
 	else
 	{
  		for(k=h;k<=mid;k++)
  		{
   			b[i]=a[k];
  			 i++;
  		}
 	}
	for(k=low;k<=high;k++) a[k]=b[k];
}

int main()
{
 	int n,i;
 	double clk;
 	clock_t starttime,endtime;
 	printf("MERGE SORT\n");
 	printf("Enter the number of employee records:\n ");
 	scanf("%d",&n);
 	 for(i=0;i<n;i++) 
       	{
        		 a[i]=rand()%100;
         		printf("The Employee IDs are: \t%d",a[i]);
        	}
	 starttime=clock(); 
	 merge_sort(1,n);
 	endtime=clock();
 	clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
 	printf("\nEmployee IDs in sorted order:\n");
 	for(i=1;i<=n;i++) 
  	{
   		printf("\t%d",a[i]);
 	}
	printf("\nThe run time is %f\n",clk);
}
