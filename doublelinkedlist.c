#include<stdio.h>
#include<stdlib.h>
struct Node
{
int data;
struct Node *prev,*next;
}*head=NULL,*tail=NULL,*temp=NULL,*trav=NULL,*current=NULL,*prev=NULL;

void insertatbegin()
{
      temp=(struct Node*)malloc(sizeof(struct Node));
      printf("Enter the data\n");
      scanf("%d",&temp->data);
      if(head==NULL)
      {
            temp->next=NULL;
            temp->prev=NULL;
            head=temp;
            tail=temp;
      }
      else
      {
            temp->next=head;
            head->prev=temp;
            head=temp;
      }
}
void insertatend()
{
      temp=(struct Node*)malloc(sizeof(struct Node));
      printf("Enter the data\n");
      scanf("%d",&temp->data);
      if(head==NULL)
      {
            temp->next=NULL;
            temp->prev=NULL;
            head=temp;
            tail=temp;
      }    
      else
      {
            current=head;
            while(current->next!=NULL)
            {
                  current=current->next;
            }
            current->next=temp;
            temp->prev=current;
            temp->next=NULL;
      }
}
void deleteatbegin()
{
      if(head==NULL)
      {
            printf("Empty List\n");
      }    
      else
      {
            temp=head;
            head=head->next;
             if (head != NULL)
             { // Check if the new head is not NULL
                 head->prev = NULL; // Set prev of the new head to NULL
             }
            printf("%d",temp->data);
            free(temp);
      }
}
void deleteatend()
{
      if(head==NULL)
      {
            printf("Empty List\n");
      }    
      else
      {
                current=head;
                if (current->next == NULL)
                { // Only one node case
                  printf("%d\n", current->data);
                  free(current);
                  head = NULL; // Update head to NULL
                  return;  
                 }
                 else
                 {
                    prev=head;
                    while(current->next!=NULL)
                   {
                      prev=current;
                      current=current->next;
                   }
                 prev->next=NULL;
                 current->prev=NULL;
                 printf("%d",current->data);
                 free(current);
            }
      }
}
void insertatpos()
{
       int pos,i=0;
       printf("Enter the position:");
       scanf("%d",&pos);
       if(pos==0)
       {
            insertatbegin();
       }
       else
       {
            current=head;
            for( i=0;i<pos;i++)
            {
                prev=current;
                current=current->next;
            }
            if(current==NULL)
            {
               insertatend();
            }
            else
            {
                temp=(struct Node*)malloc(sizeof(struct Node));
                printf("Enter the data\n");
                scanf("%d",&temp->data);
                //prev->next=temp;
                //temp->next=current;
                  current->prev->next=temp;
                  temp->prev=current->prev;
                  temp->next=current;
                  current->prev=temp;
            }
       }
}
void deleteatpos()
{
       int pos,i=0;
       printf("Enter the position:");
       scanf("%d",&pos);
       if(pos==0)
       {
            deleteatbegin();
       }  
       else
       {
            current=head;
            for(i=0;i<pos;i++)
            {
                  prev=current;
                  current=current->next;
            }
            if(current==NULL)
            {
                  printf("Position out of range");
            }
            else if(current->next==NULL)
            {
                  deleteatend();
            }
            else
            {
                  if(head==NULL)
                  {
                        printf("List Empty\n");
                  }
                  else
                  {
                        //prev->next=current->next;
                        current->prev->next=current->next;
                        current->next->prev=current->prev;
                        current->prev=NULL;
                        current->next=NULL;
                        printf("%d",current->data);
                        free(current);
                  }
            }
       }
}


void main()
{
      int ch;
      do
      {
            printf("\nMenu\n----\n1. Insert At Beginning\n2. Insert At End\n3. Insert At a Specified Position\n4. Delete From Beginning\n5. Delete From End\n6. Delete From a Specified Position\n7. Exit");
            printf("\nEnter the choice:");
            scanf("%d",&ch);
            switch(ch)
            {

                  case 1:
                      insertatbegin();
                     
                      break;
                  case 2:
                      insertatend();
                     
                      break;
                  case 3:
                      insertatpos();
                     
                      break;
                  case 4:
                      deleteatbegin();
                   
                      break;
                  case 5:
                      deleteatend();
                 
                      break;
                  case 6:
                      deleteatpos();
                   
                      break;
                  case 7:
                      exit(0);
                  default:
                      printf("There is no such operation:\n");
            }
      }
      while(1);
}