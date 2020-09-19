#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node_type
{
  int info;
  struct node_type *next;
};

typedef struct node_type node;

node *create(node *);
void display(node *);
node *insert_beginning(node *);
node *insert_end(node *);
node *insert_after(node *, int);
node *insert_before(node *, int);
void delete_beginning();
void delete_end();
void delete_spec();
void search();

node *start=NULL;

int main()
{
    int choice1, choice2, choice3;
    char c1,c2,c3;
    //node *start=NULL;
    
    start=create(start);

    printf("\nPrinting elements of the linked list: ");

    display(start);

    do
    {
    printf("1. Insert an element in the Linked List: \n");
    printf("2. Delete an element in the Linked List: \n");
    printf("3. Reverse the Linked List: \n");
    printf("4. Searching an element in the Linked List: \n");
    printf("5. Exit\n");
    printf("Enter Your Choice (1 to 5): ");
    choice1=0;
    scanf("%d",&choice1);

    switch (choice1)
    {
     case 1:
     {
      do
      {
	printf("1. Insert an element in the beginning of the Linked List: \n");
	printf("2. Insert an element in the end of the Linked List: \n");
	printf("3. Insert an element in after a given value in the Linked List: \n");
	printf("4. Insert an element in before a given value in the Linked List: \n");
	printf("5. Exit\n");
	printf("Enter Your Choice (1 to 5): ");
	choice2=0;
	scanf("%d",&choice2);
//	printf("%d\n",choice2);
	switch(choice2)
	{
	  case 1:
	  {
	    start=insert_beginning(start);
	    printf("\nLinked list after insertion: ");
	    display(start);
	    printf("\n");
	    break;
	  }
	  case 2:
	  {
	    start=insert_end(start);
	    printf("\nLinked list after insertion: ");
	    display(start);
	    break;
	  }
	  case 3:
	  {
	    start=insert_after(start,33);
	    printf("\nLinked list after insertion: ");
	    display(start);
	    break;
	  }
	  case 4:
	  {
	    start=insert_before(start,33);
	    printf("\nLinked list after insertion: ");
	    display(start);
	    break;
	  }
	  default:
//	    exit(1);
	   // printf("\n");
	    break;
	}
//	printf("\n");

      }while(choice2!=5);
      break;
     }

    case 2:
     {
	do{
	printf("1. Delete an element from the beginning of the Linked List: \n");
	printf("2. Delete an element from the end of the Linked List: \n");
	printf("3. Delete a specified element from the Linked List: \n");
	printf("4. Exit\n");
	printf("Enter Your Choice (1 to 4): ");

	scanf("%d",&choice3);
	switch(choice3)
	{
	case 1:
	{
	  delete_beginning();
	  printf("\nLinked list after deletion: ");
	  display(start);
	  break;
	}
	case 2:
	{
	  delete_end();
	  printf("\nLinked list after deletion: ");
	  display(start);
	  break;
	}
	case 3:
	{
	  delete_spec();
	  printf("\nLinked list after deletion: ");
	  display(start);
	  break;
	}

	default:
	  break;
      }
//	printf("\nDo you want to continue with deletions (y/n): ");
//	scanf("%c",&ch3);
      }while(choice3!=4);
      break;
    }
    case 3:
     {
       reverse(start);
     break;
     }
    case 4:
     {
      search(start);
      break;
     }
    default:
      exit(0);
    }
    printf("\nDo you want to continue (y/n): ");
    scanf("%c",&c1);
    }while(c1!='n');

    getch();
    return(0);
}

node *create(node *start)
{
  node *temp;
  int item;
  puts("Enter the Value:");
  scanf("%d",&item);
  while(item!=-999)
  {
    temp=(node*)malloc(sizeof(node));
    temp ->info=item;
    temp ->next=start;
    start=temp;
    puts("Enter the Value:");
    scanf("%d",&item);
   }
   return(start);
}

void display(node *start)
{
  node *ptr;
  ptr=start;
  while(ptr!=NULL)
  {
    printf("%d ", ptr ->info);
	ptr = ptr ->next;
   } printf("\n");
}

node *insert_beginning(node *start)
{
  node *temp;
  int item;
  printf("hello");
  puts("\nEnter the Value to be inserted: ");
  scanf("%d",&item);
  temp=(node*)malloc(sizeof(node));
  temp ->info=item;
  temp ->next=start;
  start=temp;
  return(start);
}

node *insert_end(node *start)
{
  node *temp, *ptr;
  int item;
  puts("Enter the Value:");
  scanf("%d",&item);
  temp=(node*)malloc(sizeof(node));
  temp ->info=item;
  temp ->next=NULL;
  if (start==NULL)
     start=temp;
  else
   {  ptr=start;
       while (ptr->next !=NULL)
	      ptr = ptr ->next;
   }
   ptr ->next=temp;
  return(start);
}

node *insert_after(node *start, int value)
{
  node *temp, *ptr;
  int item;
  puts("Enter the Value:");
  scanf("%d",&item);
  temp=(node*)malloc(sizeof(node));
  temp ->info=item;
  temp ->next=NULL;
  ptr=start;
  while (ptr!=NULL && ptr->info !=value)
	      ptr = ptr ->next;
  if (ptr ==NULL)
     puts("Item not found");
  else
  { temp ->next=ptr ->next;
     ptr ->next=temp;
   }
  return(start);
}


node *insert_before(node *start, int value)
{
  node *temp, *ptr, *save;
  int item;
  puts("Enter the Value:");
  scanf("%d",&item);
  temp=(node*)malloc(sizeof(node));
  temp ->info=item;
  temp ->next=NULL;
  ptr=start;
  if (ptr->info==value)
  {
     temp->next=ptr;
     start=temp;
  }
  else
  {
  while (ptr!=NULL && ptr->info !=value)
  {
      save=ptr;
      ptr = ptr ->next;
  }
  if (ptr ==NULL)
     puts("Item not found");
  else
  { temp ->next=save ->next;
     save ->next=temp;
  }
  }
  return(start);
}

void delete_beginning()
{
  node *ptr;
  if (start == NULL)
      return;
  else
  {
     ptr=start;
     start= start->next;
     free(ptr);
    }
}


void delete_end()
{
  node *ptr, *save;
  if (start == NULL)
      return;
  else if (start->next==NULL)
  {
      ptr=start;
      start= NULL;
      free(ptr);
      return;
    }
    else
    {  save=start;
	ptr= start->next;
	 while(ptr->next!=NULL)
	 {  save=ptr;
	     ptr= ptr->next;
	 }
	 save->next=NULL;
	 free(ptr);
    }
}


void delete_spec()
{  node *ptr, *save;
    int temp;
    printf("Enter the value to be deleted");
    scanf("%d",&temp);
    ptr=start;
    if (start == NULL)
      return;
    else if (ptr->info==temp)
    {
	start= start->next;
	free(ptr);
	return;
    }
    else
    {  save=ptr;
	ptr= ptr->next;
	 while(ptr!=NULL)
	 {  if (ptr->info==temp)
	     {   save->next= ptr->next;
		  free(ptr);
		  return; }
	     save=ptr;
	     ptr= ptr->next;
	 }
       }
}

void search(node *start)
{
  node *ptr;
  ptr=start;
  int item;
  
  printf("Enter value to search");
  scanf("%d",&item);

  while(ptr->next!=NULL)
  {
    if (ptr->info == item){
        printf("Successful");
        printf("\nValue is %d",ptr->info);
        break;
    }
    else    
        ptr = ptr ->next;
   } free(ptr);     
}
void reverse(node*start){
  node* curr,*prev,*next;
  curr = start;
  prev = NULL;
  display(curr);
  while(curr != NULL){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  start = prev;
  display(start);
}