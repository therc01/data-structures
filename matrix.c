#include<stdio.h>

void main(){
    int a[3][3],b[3][3],c[3][3];
    int x,i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("Enter value for %d, %d",i,j);
            scanf("%d",&a[i][j]);
            //a[i][j] == x;
        }
    }
    printf("\n1. Addition Operation");
    printf("\n2. Substraction Operaition");
    printf("\n3. Multiplication Operation");
    printf("\n4. Searching an element in the Matrix");
    printf("\n5. Exit") ;
    int item,num,choice;
    display(a);
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        add(a,a);
        break;
    case 2:
        sub(a,a);
        break;
    case 3:
        mult(a,a);
    case 4:
        search(a);
    default:
        break;
    }   
}
int add(int a[3][3],int b[3][3]){
    int c[3][3],i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    printf("Added array is ");
    display(c);
};
void display(int a[][3]){
    int i,j;
    for(i=0;i<3;i++){
        printf("\n");
        for(j=0;j<3;j++){
            printf("\t%d",a[i][j]);
        }
    printf("\n");
    }
};
void sub(int a[][3],int b[][3]){
    int c[3][3],i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            c[i][j] = a[i][j] - b[i][j];
        }
    }
    printf("Substracted array is ");
    display(c);
};
void mult(int a[][3],int b[][3]){
    int c[3][3],i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            c[i][j] = a[i][j]*b[i][j];
        }
    }
    printf("multipied array is ");
    display(c);
};

void search(int c[10][10])
{  int flag= 1;
int item,i,j;
printf("Enter no to search ");
scanf("%d",&item);
for(i=0; i<3; i++)
    {
for(j =0; j<3; j++)
        {   
            if(c[i][j] == item)
{     flag = 0;
printf("\n Your item found at row %d column %d", i+1, j+1);
            }       
        }
    } 
    if(flag!=0)
printf("\n Element not found..");
}

