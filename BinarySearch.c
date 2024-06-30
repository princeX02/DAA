#include<stdio.h>
#include<stdlib.h>
#include<time.h>
 int main()
{
   	int i,n,a[1000],key,bottom,top,mid,j,temp;
   	double clk;
   	clock_t starttime,endtime;
      printf("Enter the number of Products\n");
   	scanf("%d",&n);   
   	 for(i=0;i<n;i++) 
     {
      	a[i]=rand()%100;
      	printf("The Product ID  are: \t%d",a[i]);
      }
	for(i=0;i<n-1;i++)
   	{
    		for(j=0;j<n-i-1;j++)
      	{
        		if(a[j]>a[j+1])
      		{
            			temp=a[j];
            			a[j]=a[j+1];
            			a[j+1]=temp;
        		}
     		 } 
	}
printf("\n Sorted Product ID List is : \n");
for(i=0;i<n;i++)
{
   printf("\t%d",a[i]);
}
 printf("Enter the Product ID to be searched: \n");
 scanf("%d",&key);
 starttime=clock();
bottom = 1;
 top = n;
 do 
 {
 	 mid = (bottom + top) / 2;
  	if (key < a[mid])
   	top = mid - 1;
  	else if (key > a[mid])
   	bottom = mid + 1;
 } while (key != a[mid] && bottom <= top);
 
 if (key == a[mid]) 
  {
   	 printf("Product found!!\n");
    	printf("\n Product %d found in position: %d\n", key, mid + 1);
  } 
else 
{
  printf("\n  Search failed\n %d not found\n", key);
 }
 endtime=clock();
 clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
 printf("%f\n",clk);
}
