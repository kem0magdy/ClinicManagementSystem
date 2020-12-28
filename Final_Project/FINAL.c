/*
										Clinic Management System
										
			created by : Kamal Magdy Kamal Eldin
			Starts   in : 25/12/2020
			Finished in : 28/12/2020
			
			www.github.com/kem0magdy 
			
			Email: kamalmagdy18@gmail.com

*/
#include<stdio.h>
#include"Std.h"
#include"ProjHeader.h"

#define PW 1234 // password of the problem 

int main()
{
	s32 mode,pw ,try=0;
	s32 feut;
	Node * Start=NULL; // initial of linked list 
	u8 num;
	printf("=====================================================================\n\t\t Welcome In Clinc Managment System");
	while(1)
 {
	printf("\n\n=====================================================================\nChoose:\n1-Admin Mode\n2-User Mode\n\nChoice: ");
	scanf("%d",&mode);
	
	/* Choosing between admin mode and User Mode */
	switch(mode)
	{
		
	case 1:
		printf("Enter Password: ");
		while( try <= 3 )
		{
			scanf("%d",&pw);
			if(pw==PW)
				break;
			printf("Wrong Password , You Have %d Tries Left!\n",3-try);
			try++;
		}
		/* Login Success so start choice the features */
		
		if(try <= 3 )
		{
			
		printf("=====================================================================\n\t\t You Login Successfully In Admin Mode\n\n");
		while(1)
		{
		printf("\n=====================================================================\nChoose:\n1-Add new patient record.\n2-Edit patient record.\n3-Reserve a slot with the doctor.\n4-Cancel reservation.\n\nChoice: ");
		scanf("%d",&feut);
		// choosing between features
		switch(feut)
		{
			default: printf("Wrong Choice\n!");
			break;
			case 1:
				printf("\n=====================================================================\n\t\t Add Client\n"); // ADD(&START)
				Start=Add(Start);
			break;
			case 2:
				printf("\n=====================================================================\n\t\t Edit Client\n");
				Edit(Start);
			break;
			case 3:
				printf("\n=====================================================================\n\t\t Reservetion of Client\n");
				Reserve(Start);
			break;
			case 4:
				printf("\n=====================================================================\n\t\t Cancel Reservetion of Client\n");
				Cancel(Start);
			break;
			
		}// end of switch case of opertion of admin 
			printf("\n=====================================================================\n\nDo You More Operations In Admin Mode :\n1- Yes \n2- No\nChoice :  ");
			scanf("%d",&num);
			if(num == 1)
				continue;
			else
				break;
			
		}// of while loop of admin
		
		} // end of if condition when user enter corret password if <= 3 
		
		/* Access Denied Duo to Wrong Password after 3 attempts */
		else
		{
			printf("Access Denied Sorry !\n");
			try=0; // reset tries for next iteration 
		} 
		
		break; // break of Admin mode case
		
	case 2:
	
		printf("=====================================================================\n\t\t Welcome In User Mode\n\n");
	 while(1)
	 {
		printf("\n=====================================================================\nChoose:\n1-View patient record..\n2-View today reservations.\n\nChoice: ");
		scanf("%d",&feut);
		// choosing between features
		switch(feut)
		{
			default: printf("Wrong Choice!");
			break;
			case 1:
				printf("\n=====================================================================\n\t\t View Client Info \n");
				Display(Start);
			break;
			case 2:
				printf("\n=====================================================================\n\t\t View Reservetions \n");
				View(Start);
			break;
		} // end of switch case 
		
		printf("\n=====================================================================\n\nDo You More Operations In User Mode :\n1- Yes \n2- No\nChoice :  ");
			scanf("%d",&num);
			if(num == 1)
				continue;
			
			else
				break;
			
	 }// end of while loop of user mode 
		
		break; // break of case 2 in admin or user mode 
		
	default:
		printf("Wrong Choice !");
		break;
	}// end switch case of admin and user

		printf("\n=====================================================================\n\nDo You Shut Down System :\n1- Yes \n2- No\nChoice :  ");
		  scanf("%d",&num);
		  
		 if(num == 1)
			 break;
		 else
		 {
			 continue;
		 }

	
 }// end of program loop
	
	return 0;
}