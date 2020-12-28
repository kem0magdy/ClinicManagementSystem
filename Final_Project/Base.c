#include<stdio.h>
#include <stdlib.h>
#include"Std.h"

#define SIZE		30
#define SizeGen 	10
#define SizeRev     6

u8 count =5;
char arrS[SizeRev][50]={"2    Pm to 2:30 Pm" ,"2:30 Pm to 3    Pm" , "3    Pm to 3:30 Pm", "4    Pm to 4:30 Pm" , "4:30 Pm to 5    Pm" , "Not Reserved"};
char arrN[SizeRev]={0,0,0,0,0,1};

typedef struct n{
	
	u8 			name[SIZE];
	u8			age;
	u8			gender[SizeGen];
	s32			ID;
	u8			Res;			
	struct n* 	Link;
}Node;

 
Node *	 Add		  (Node * S);
void     Display      (Node * S);
void	Edit		  (Node * S);
void    Reserve       (Node * S);
void 	Cancel		  (Node * S);
void	View	      (Node * S);

/* Adding New Users */

Node * Add(Node * S)
{
	/* Create Node */
	Node * temp = (Node *)malloc(sizeof(Node));
	s32 count=0; // to check
	s32 id; 
	Node *ptr= S; 
	
	printf("ID     :  ");
	scanf("%d",&id);
	if (ptr == NULL ) // check if linked list is empty so no IDs 
	{
		/*Inserting all Data in temp */
		printf("Name   :  ");
		scanf("%s",temp->name); 
		printf("Age    :  ");
		scanf("%d",&temp->age);
		printf("Gender :  ");
		scanf("%s",temp->gender);
		temp->ID=id;
		temp->Res = 5; // client has no reservetions yet 
	} // end of if condition 
	/* Linked list not empty */
	else
	{
		
		while ( ptr != NULL)
		{
			/* If id exists increament the counter */
		if( ptr->ID == id )
			count++;
	
			ptr=ptr->Link; // move the pointer to next node if entred id not in node
		} // end of while loop 
	
		if ( count > 0) 
			printf("Id Already Exists\n");
		else
	    {
		printf("Name   :  ");
		scanf("%s",temp->name); 
		printf("Age    :  ");
		scanf("%d",&temp->age);
		printf("Gender :  ");
		scanf("%s",temp->gender);
		temp->ID=id;
		temp->Res = 5 ;
    	}// end of else condition 
	}
		temp->Link = S;
		S  = temp;
		return S; // return first node 
}

/* Displaying Info Of Users With ID */

void   Display        (Node * S )
{
	 
	s32 id;
	u8 True = 5 ; // true value to check 
	printf("\n\nEnter The Id : ");
	scanf("%d",&id); // Taking id from user
	Node * pn = S;
	
	while(pn != NULL)
	{
		if(id == pn->ID ) // if id exists print info of the user 
		{
			printf("Name   : %s\n",pn->name);
			printf("Age    : %d \n",pn->age);
			printf("Gender : %s \n",pn->gender);
			//printf("ID     : %d \n\n",pn->ID);
			True=1;
		} // end of if condition
		pn = pn->Link; // move the pointer to next node 
	}// end of while loop
	if( True != 1) // if true value not true so id not exists 
		printf("Id not in the System");
}

void	Edit		  (Node * S)
{
	s32 id;
	Node * ptr = S;
	s32 pos=0; // position of id 
	printf("\n\nEnter The Id To Edit : ");
	scanf("%d",&id); // Taking id from user
	while ( ptr != NULL)
	{
		if ( ptr->ID == id )
		{
			pos++;
			break;
		}
		ptr=ptr->Link;
	}// end of while loop
	if( pos > 0)
	{
		printf("Name : ");
		scanf("%s",ptr->name); 
		printf("Age: ");
		scanf("%d",&ptr->age);
		printf("Gender : ");
		scanf("%s",ptr->gender);
	}// end of if condition
	else
		printf("incorrect ID !");
	
	
}
void    Reserve       (Node * S)
{
	
	s32 id;
	Node * ptr = S;
	s32 pos=0; // position of id 
	u8 check=0; // check if user can reserver or not 
	u8 resv=0;
	printf("\n\nEnter The Id To Reserve : ");
	scanf("%d",&id); // Taking id from user
	while ( ptr != NULL)
	{
		
		if ( ptr->ID == id )
		{
			pos++;
			break;
		}
		
		ptr=ptr->Link;
	}// end of while loop
	
	if( pos > 0)
	{
		for (u8 i=0 ; i < count ; i++ )
	{
		if(arrN[i]==0)
			printf("%d- %s\n",i+1,arrS[i]);
		else
		{
			check++;
		}
	}
		if(check>=5)
		{
			printf("\n Sorry No Availble Reservetions !");
			return;
		}
		else
		{
			printf("\nYou Choice = ");
			scanf("%d",&resv);
		}
		if( resv > 0 && resv <= 5)
		{
		ptr->Res = resv-1;
		arrN[resv-1]=1;
		}
		else
			printf("Wrong Choice !");
	}// end of if condition
	else
		printf("incorrect ID !");
	
}
/* Cancel Reservetions */

void 	Cancel		  (Node * S)
{
	s32 id;
	Node * ptr = S;
	s32 pos=0; // position of id 


	printf("\n\nEnter The Id To Cancel Reserve : ");
	scanf("%d",&id); // Taking id from user
	while ( ptr != NULL)
	{
		
		if ( ptr->ID == id )
		{
			pos++;
			break;
		}
		
		ptr=ptr->Link;
	}// end of while loop
	
	if( pos > 0)
	{
	
		if(arrN[ptr->Res]==1)
		{
			printf("Your Reservetion: ( %s ) is cancelled \n",arrS[ptr->Res]);
			arrN[ptr->Res]=0;
			ptr->Res = 5;
			
		}
		
		else
		{
			printf("This ID didn't reseverd !");
		}
		
	}// end of if condition
	else
		printf("incorrect ID !");
	
}
/* View All reservertions with patient ID */

void	View	      (Node * S)
{
	
	u8 i = 0 ; // true value to check 
	Node * ptr = S;
	
	if( ptr == NULL) // if true value not true so id not exists 
		printf("No Clients in Systems !");
		
	else
	{
	while(ptr != NULL)
	{
		 // if id exists print info of the user 
		i++;
		printf("%d- ID: %d ( %s ) \n", i , ptr->ID , arrS[ptr->Res]);
			
		ptr = ptr->Link; // move the pointer to next node 
	}// end of while loop
	}

}
	
	
	

