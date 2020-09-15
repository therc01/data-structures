#include<stdio.h>
#include<stdlib.h>


void display(int * a){
    int i;
    
    printf("Array is ");
    for(i=0;i<5;i++){
        printf("%d\t", a[i]);
        
    }
};
int ub = 5;
void insert(int *a, int loc, int item)
{
  /* Shift elements towards right */
  int i=0;
  for(i=ub-1;i>loc-1;i--)
	a[i] = a[i-1];
  a[i]=item;
};
void delete(int *a, int loc)
{
  /* Shift elements towards left */
  int i;
  for(i=loc-1;i<ub;i++)
	a[i] = a[i+1];
  a[i]=0;
};
void reverse(int *a)
{
  int i, temp;
  for(i=0; i<ub/2;i++)
  {
    temp = a[i];
    a[i] = a[(ub-1)-i];
    a[(ub-1)-i] = temp;
   }
};
void bubblesort(int *a)
{
  int i,j,flag,temp;
  for(i=0; i<ub;i++)
  {
    for(j=0; j<ub-i-1;j++)
    {
      flag = 0;
      if (a[j]>a[j+1])
      {
	temp = a[j];
	a[j] = a[j+1];
	a[j+1] = temp;
	flag = 1;
      }
   }
   if (flag == 0)
       break;
 }
};
void linearsearch(int *a, int num)
{
  int i;
  for(i=0; i<ub;i++)
  {
    //printf("%d",i);
    if(a[i] == num)
    {

      printf(" The element %d is present at %dth position ", num, i+1);
      return;
   }
  }
};
void binarysearch(int *a, int num)
{
  int first, last, middle;
  first=0;
  last=ub-1;
  middle=(first+last)/2;
  while (first<=last)
  {
     if (a[middle]<num)
        first=middle+1;
     else if (a[middle]==num)
      {
         printf("%d Location", middle+1);
         break;
      }
     else
          last = middle-1;
    middle=(first+last)/2;
    }
    if (first>last)
       printf("Search is Unsuccessful");
};

void main(){
    int a[5];
    int i, choice,x;
    i = 0;
    for(i=0;i<5;i++){
        printf("Enter 5 values for 1d array");
        scanf("%d", &a[i]);
    };
    display(a);
    
    printf("\n1. Insert an element in the Array");
    printf("\n2. Delete an element in the Array");
    printf("\n3. Reverse the Array");
    printf("\n4. Sort the Array");
    printf("\n5. Searching an element in the Array");
    printf("\n6. Exit") ;
    int item,loc,num;

    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        
        printf("\nEnter the no to enter");
        scanf("%d",&item);
        printf("Enter the loctaion to insert");
        scanf("%d",&loc);
        insert(a, loc, item);
        display(a);
        break;
    case 2:
        printf("Enter the loctaion to deleted");
        scanf("%d",&loc);
        delete(a,loc);
        display(a);
        break;
    case 3:
        reverse(a);
        display(a);
        break;
    case 4:
        bubblesort(a);
        display(a);
        break;
    case 5:
        printf("\nTo use binary search press 1");
        printf("\t and for linear search press 2");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            printf("enter no to search");
            scanf("%d",&num);
            binarysearch(a, num);
            display(a);
            break;
        case 2:
            printf("enter no to search");
            scanf("%d",&num);
            linearsearch(a, num);
            display(a);
            break;
        default:
            break;
        }
    default:
        break;
    }
    
}
