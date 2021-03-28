#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int i,j;
char x;
int main_exit;
void menu();
FILE *fp;
 	struct customer
		{
			char *name[20];
			int ac_no;
			int mobile;
			char ac_type;
			int password[6];
			int balance;
		};
		struct customer c;
void contents();
void Add_ac(struct customer c);
void delete_ac(struct customer c);
void update_ac(struct customer c,int *a);
void view_details(struct customer c,int *a);
void deposit(struct customer c,int *a);
void withdraw(struct customer c,int *a);
void ac_balance(struct customer c,int *a);
 
int main()
{
 struct customer b;
 char pass[10],password[10]="mycap";
 int i=10;
 login_try:
 printf("\n\n\t enter the password to login");
 scanf("%s",pass);


 if(pass[i]!=13&&pass[i]!=8)
 {
   printf("");
   pass[i]=getch();
   i++;
 }
 while(pass[i]!=13)
 pass[10]='\0';
 if(strcmp(pass,password)==0)
 {
	printf("\n\n password match");
	for(i=0; i<=32762;i++)
	{
		printf(".");
	}
	system("cls");
	contents();
 }
 else
 {
	printf("\n\n wrong password");
	printf("enter 1 to retry & 0 to exit");
	scanf("%d",&main_exit);
	if(main_exit==1)
	{
		system("cls"); 
	}
	else if(main_exit=0)
	{
		system("cls");
		close();
	}
	else
	{
		printf("\n invalid");
		for(i=0;i<=32762;i++)
		{
			printf(".");
		}
		system("cls");
		goto login_try;  
	}
}

	void contents()
	{
		
		fp=fopen("BANK_a/c","w");
		struct customer
		{
			char *name[20];
			int ac_no;
			int mobile;
			char ac_type;
			int password[6];
			int balance;
		};
		struct customer c[50];
		fclose(fp);
		int ch,acc_no,a;
		char x;
		printf("WELCOME\n");
		printf("enter your account number\n");
		scanf("%d",&a);
		printf("select your choice\n");
		printf("Adding account-1\n Removing account-2\n Updating account details-3\n View account details-4\n Cash Deposit-5\n Cash Withdraw-6\n Account Balance-7\n	Exit-8\n");
		scanf("%d",ch);
		switch(ch)
		{
			case 1:
			{
			  printf("adding new account\n");
			  Add_ac(b);
			  break;	
			}
			case 2:
			{
				printf("deleting existig account\n");
				delete_ac(b);
				break;
			}
			case 3:
			{
				printf("updating accountv details\n");
				Update_ac(b,&a);
				break;
			}
			case 4:
			{
				printf("account details\n");
				View_details(b);
				break;
			}
			case 5:
			{
				printf("cash deposition\n");
				deposit(b,&a);
				break;
			}
			case 6:
			{
				printf("cash withdrawal\n");
				withdraw(b,&a);
				break;
			}
			case 7:
			{
				printf("account balance portal\n");
				ac_bal(b,&a);
				break;
			}
			case 8:
			{
				printf("exiting the portal\n");
				exit(1);
				break;
			}
			default:
			{
				printf("invalid choice\n");
				break;
			}
	    }
	    printf("Thank You\n visit again\n");
    }
	void Add_ac(struct customer c)
	{
		
		int i=0,pass[7],num;
		char x,n;
		fp=fopen("BANK_a/c","w");
		printf("please enter your details\n");
		printf("your name:");
		fscanf(stdin,"%s",&c.name);
		printf("phone number:");
		fscanf(stdin,"%d",&c.mobile);
		printf("account type:\n");
		printf("s for savings account\n b for business account\n");
		fscanf(stdin,"%c",&c.ac_type);
		for(i=0;i<3;i++)
		{
			printf("create password:\n password should be a 6 digit number\n");
			fscanf(stdin,"%d",&c.password);
			if(sizeof(c.password)!=6)
			{
				printf("invalid password\n try again\n");
			}
			else
			{   for(i=0;i<3;i++)
			    {
				    printf("confirm your password:");
					scanf("%d",&pass);
					x=*c.password;
					if(x==*pass)
					{
						printf("thanks for confirming\n");
						printf("your account has been created successfully\n");
					    num=(rand()%(400000-300000+1)+300000);
					    c.ac_no=num;
					    printf("your new account number is:%d\n",num);
					    fclose(fp);
					    break;
					}
					else
					{
						printf("password not matched\n try again\n");
					}
				}
				if(i=3&&pass!=c.password)
				{
					printf("operation failed\n");
				}
			}
		}
		printf("enter m to go to main menu\n");
		scanf("%c",&x);
		for(i=0;i<3||x!='m';i++)
		{
			if(x='m')
			 menu();
			else
			{
			 printf("invalid choice\n try again\n");
			 scanf("%c",&x);
	        }
		}
		if(x!='m')
		printf("your chance exceeded\n visit tomorrow\n");
		printf(".......................................");
		exit(0);
	}
	void delete_ac(struct customer c)
	{
		
		int n,x,i,a;
		char p;
		printf("do you have an existing account\n");
		printf("enter y for yes, n for no\n");
		scanf("%c",&p);
		if(p='y')
		{
			fp=fopen("BANK_a/c","r");
			printf("enter account number:");
			scanf("%d",&a);
			if(a=c.ac_no)
			{
			  printf("your details are: %s\t%d\t%d\t%d\n please check your details and click d for account deletion\n",c.name,&c.ac_no,&c.mobile,&c.balance);
			  scanf("%c",&n);
			  for(i=0;i<3;i++)
			  {
			   if(n='d')
			   {
			    remove("BANK_a/c");
			    printf("your account is successfully deleted\n");			
		       }
		       else
		       {
		      	printf("wrong choice\n try again\n");
			   }
		      }
			  if(n!='d')
			   printf("operation failed\n try next time\n");
		    }
		    else
		    {
		    	printf("details not found\n");
			}
		}
		else
		{
			printf("account cannot be deleted\n");
		}
		printf("enter m to go to main menu\n");
		scanf("%c",&x);
		for(i=0;i<3||x!='m';i++)
		{
			if(x='m')
			 menu();
			else
			{
			 printf("invalid choice\n try again\n");
			 scanf("%c",&x);
	        }
		}
		if(x!='m')
		printf("your chance exceeded\n visit tomorrow\n");
		printf(".......................................");
		exit(0);
	}
	void update_ac(struct customer c,int *a)
	{
		
		int x,i;
		char n,p;
		fp=fopen("BANK_a/c","a+");
		printf("your account number:%d\n",*a);
		for(i=0;i<3;i++)
		{
		 upd:
			printf("what do u want to update\n mobile number-m\n password-p\n");
			scanf("%c",&n);
			if(n='m')
			{
				printf("your old mobile number:\n");
				fprintf(stdout,"%d",&c.mobile);
				c.mobile='\0';
				printf("enter your new mobile number\n");
				fscanf(stdin,"%d",&c.mobile);
				printf("your update is successfull\n");
			}
				elseif(n='p')
				;{
					for(i=0;i!=*c.password||i<3;i++)
					{
						printf("enter your old password\n");
						fscanf(stdin,"%d",&x);
						i=x;
						if(x==*c.password)
						{
							n=*c.password;
							*c.password='\0';
							printf("enter your new password\n");
							fscanf(stdin,"%d",&c.password);
							break;
						}
						else
						{
							printf("incorrect password\n");
						}
					}
					if(x!=n)
					printf("your chances exceeded\n try tomorrow\n");
				}
		}
		fclose(fp);
		printf("enter m to go to main menu\n");
		scanf("%c",&x);
		for(i=0;i<3||x!='m';i++)
		{
			if(x='m')
			 menu();
			else
			{
			 printf("invalid choice\n try again\n");
			 scanf("%c",&x);
		    }
		}
		if(x!='m')
		printf("your chance exceeded\n visit tomorrow\n");
		printf(".......................................");
		exit(0);
    }
    void view_details(struct customer c)
    {
    	
    	int a;
    	fp=fopen("BANK_a/c","r");
    	printf("enter your account number\n");
    	scanf("%d",&a);
    	if(a==c.ac_no)
    	{
    		fprintf(stdout,"%s\t%d\t%d\t%c\t%d\n",c.name,c.ac_no,c.mobile,c.ac_type,c.balance);	
		}
		else
		{
			printf("details not found\n");
		}
		fclose(fp);
		printf("enter m to go to main menu\n");
		scanf("%c",&x);
		for(i=0;i<3||x!='m';i++)
		{
			if(x='m')
			 menu();
			else
			{
			 printf("invalid choice\n try again\n");
			 scanf("%c",&x);
		    }
		}
		if(x!='m')
		printf("your chance exceeded\n visit tomorrow\n");
		printf(".......................................");
		exit(0);
	}
	void deposit(struct customer c,int *a)
	{
		
		int x;
		fp=fopen("BANK_a/c","a+");
		printf("your account number:",*a);
		printf("enter amount to be deposited\n");
		scanf("%d",&x);
	//	c.balance+=x;
	//	p=c.balance;
		fscanf(stdin,"%d",&c.balance);
		printf("amount deposited successfully\n");
		fclose(fp);
		printf("enter m to go to main menu\n");
		scanf("%c",&x);
		for(i=0;i<3||x!='m';i++)
		{
			if(x='m')
			 menu();
			else
			{
			 printf("invalid choice\n try again\n");
		  	 scanf("%c",&x);
	        }
		}
		if(x!='m')
		printf("your chance exceeded\n visit tomorrow\n");
		printf(".......................................");
		exit(0);
	}
	void withdraw(struct customer c,int *a)
	{
		
		int x,n;
		fp=fopen("BANK_a/c","a+");
		printf("your account number\n",*a);
		printf("enter amount to be withdrawn\n");
		scanf("%d",&x);
		if(c.balance!=0)
		{
			if(c.balance>x)
			{
				c.balance-=x;
				n=c.balance;
				fprintf(fp,"%d",&c.balance);
				printf("withdrawal is successfull\n");
			}
			else
			{
				printf("insufficient balance\n");
			}
		}
		else
		{
			printf("no balance in the account\n");
		}
		fclose(fp);
		printf("enter m to go to main menu\n");
		scanf("%c",&x);
		for(i=0;i<3||x!='m';i++)
		{
			if(x='m')
			  menu();
			else
			{
			 printf("invalid choice\n try again\n");
			 scanf("%c",&x);
	    	}
	    }
		if(x!='m')
		printf("your chance exceeded\n visit tomorrow\n");
		printf(".......................................");
		exit(0);
    }
	void ac_bal(struct customer c,int *a)
	{
		int x;
		fp=fopen("BANK_a/c","r");
		x=c.balance;
		printf("your balance amount is:%d\n",x);
		fclose(fp);
		printf("enter m to go to main menu\n");
		scanf("%c",&x);
		for(i=0;i<3||x!='m';i++)
		{
			if(x='m')
			  menu();
			else
			{
			 printf("invalid choice\n try again\n");
			 scanf("%c",&x);
		    }
	    }
		     if(x!='m')
		       printf("your chance exceeded\n visit tomorrow\n");
		       printf(".......................................");
		       exit(0);	
    }
return 0;
}
