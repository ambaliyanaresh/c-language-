#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<process.h>

void create();
void display();
void insertFirst();
void insertBet();
void insertLast();
void search();
void deletFirst();
void deletLast();
void deletSpacific();
void edit();
void sort();


struct linklist
{
	int data;
	struct linklist *next;

};

struct linklist *first,*temp;
int flag;

void main()
{
	int choice;

	do
	{
		clrscr();
		printf("\npress 1:create\npress 2:display\npress 3:insertFirst\npress 4:insertBet\npress 5:insertLast\npress 6:search\npress 7:deletFirst\npress 8:deletLast\npress 9:deletSpacific\npress 10:edit\npress 11:sort\npress 0:exit\n");
		printf("\nEnter your choice:");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				create();
				getch();
				break;
			case 2:
				display();
				getch();
				break;
			case 3:
				insertFirst();
				getch();
				break;
			case 4:
				insertBet();
				getch();
				break;
			case 5:
				insertLast();
				getch();
				break;
			case 6:
				search();
				getch();
				break;
			case 7:
				deletFirst();
				getch();
				break;
			case 8:
				deletLast();
				getch();
				break;
			case 9:
				deletSpacific();
				getch();
				break;
			case 10:
				edit();
				getch();
				break;
			case 11:
				sort();
				getch();
				break;
			case 0:
				exit(0);
				getch();
				break;
			default:
				printf("\nEnter proper choice\n");
				break;


		}
	}while(1);
}

void create()
{
	int noe=0,i=0;

	struct linklist *newnode;
	printf("\nHow many element you want:");
	scanf("%d",&noe);
	for(i=0;i<noe;i++)
	{
		newnode=(struct linklist *)malloc(sizeof(struct linklist *));
		printf("\nEnter element:");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		if(first==NULL)
		{
			first=newnode;

		}
		else
		{
			for(temp=first;temp->next!=NULL;temp=temp->next)
			{
				; //do nothing
			}
			temp->next=newnode;
		}

	}
}
void display()
{

	printf("\n\t\t\tlist of elements..\n");
	for(temp=first;temp!=NULL;temp=temp->next)
	{
		printf("%d ->",temp->data);

	}printf("NULL");

}
void insertFirst()
{
	struct linklist *newnode;
	newnode=(struct linklist *)malloc(sizeof(struct linklist *));
	newnode->next=NULL;
	printf("\nEnter element:");
	scanf("%d",&newnode->data);
	newnode->next=first;
	first=newnode;
	if(first==NULL)
	{
		first=newnode;
	}
	else
	{
		for(temp=first;temp->next!=NULL;temp=temp->next)
		{
			; //do nothing
		}

	}

}

void insertBet()
{
	struct linklist *newnode;
	clrscr();

	search();
	if(flag==1)
	{
		newnode=(struct linklist *)malloc(sizeof(struct linklist *));
		printf("\nEnter new element:");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		newnode->next=temp->next;
		temp->next=newnode;
	}

}

void insertLast()
{
	struct linklist *newnode;
	newnode=(struct linklist *)malloc(sizeof(struct linklist *));
	printf("\n Enter element:");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	for(temp=first;temp->next!=NULL;temp=temp->next)
	{
		; //do nothing
	}

	temp->next=newnode;
}

void search()
{
	int se=0;
	if(first==NULL)
	{
		printf("\n\t\tList is empty");
		return;
	}
	clrscr();
	printf("\nWhich element you search:");
	scanf("%d",&se);
	for(temp=first;temp!=NULL;temp=temp->next)
	{
		if(se==temp->data)
		{
			printf("%d is ",temp->data);
			printf("Found \n");
			flag=1;
			return;
		}
	}
	if(flag==0)
	{
		printf("\n\t\tNot Found\n");
	}

}

void deletFirst()
{
	int noe=0;
	if(first!=NULL)
	{
		temp=first;
		first=first->next;
		free(temp);
		printf("\n\tFirst element is deleted");
	}
	else
	{
		printf("\nList is Empty");
		noe--;
	}

}

void deletLast()
{
	int noe=0;
	if(first==NULL) //Empty List
	{
		printf("\nList is Empty");
		return;
	}
	else if(first->next==NULL)
	{
		printf("\n\t %d is free",first->data);
		free(first);
		first=NULL;
		noe--;
		return;
	}
	else
	{
		for(temp=first;temp->next->next!=NULL;temp=temp->next)
		{
			; //do nothing

		}
		free(temp->next->next);
		temp->next=NULL;
		return;
	}
}

void deletSpacific()
{
	int de=0;
	struct linklist *dummy=NULL;
	if(first==NULL)
	{
		printf("\nLink is Empty");
		return;
	}
	printf("\nWhich element you want to delet? :");
	scanf("%d",&de);
	if(first->data==de)
	{
		deletFirst();
		return;
	}
	for(temp=first;temp!=NULL;temp=temp->next)
	{
		if(de==temp->next->data)
		{
			printf("\nFound \n");
			flag=1;
			dummy=temp->next;
			temp->next=dummy->next;
			printf("\n%d is deleted\n",dummy->data);
			free(dummy);

		}
	}
	if(flag==0)
	{
		printf("\\t\tNot Found\n");
	}
}

void edit()
{
	clrscr();
	search();
	if(flag==1)
	{
		printf("\nEnter value of you want to change:");
		scanf("%d",&temp->data);
	}
}

void sort()
{
	int t=0;
	struct linklist *dummy=NULL;
	for(temp=first;temp!=NULL;temp=temp->next)
	{
		for(dummy=temp->next;dummy!=NULL;dummy=dummy->next)
		{
			if(temp->data > dummy->next->data)
			{
				t=temp->data;
				temp->data=dummy->data;
				dummy->data=t;
			}
		}
	}
}
