#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<sys/stat.h>
#include<dirent.h>
/**********************************************************Function Declaration*************************************************/
void Admin_menu();
void Customer_menu();
void Add_records();
void Update_records();
void Delete_records();
void Display_records();
void Create_directory();
void Add_media();
void Update_media();
void Delete_media();
void Display_media();
void Add_temporary();
void Update_temporary();
void Delete_temporary();
void Display_temporary();
void Add_userdata();
void Update_userdata();
void Delete_userdata();
void Display_userdata();
void User_account();
void Display_user_acc();
/**************************************************************Library Structure*************************************************/
struct library
{
    char bookId[25];
    char bookName[30];
    char authorName[30];
    char publisherName[30];
    char ISBN[20];
    int edition;
    int cost;
    char department[10];
    char location[20];        
    char status[20];        
    char loanedDate[20];
    char dueDate[20];
    char loanedTo[20];
};
/*****************************************************Racks Structure**************************************************************/
struct Racks
{
    int no_of_books_available;
    int no_of_sections;
    int totalCapacity;
    char assignedAlphabet;
}; 
/*****************************************************Department Structure*******************************************************/
struct Department
{
    char deptId[20];
    char departmentName[10];
    int totalRacks;
    //Racks *allRacks;
};
/*****************************************************Media Items Structure*******************************************************/
struct Item
{
    char itemId[30];
    char itemName[30];
    char itemType[30];         //Video - audio - DVD- Documentary
    int itemPrice;
    char creator[30];
    char publisher[30];
    char status[30]; //Available - Loaned - Requested - Hold
    char loanDate[30];
    char dueDate[30];
    char loanedTo[30];
};
/****************************************************Temporary Book Structure*************************************************/
struct Custody
{
    char temporaryId[30];
    char bookName[30];
    char author[30];
    char publisher[30];
    char ISBN[30];
    int edition;
    int cost;
    int no_of_time_voted;
};
/****************************************************User Data Structure********************************************************/
struct UserData
{
    int AccountNo;
    char FullName[30];
    char RollNumber[30];
    char Address[30];
    int phoneNumber;
    char emailAddress[30];
    char sex[10];
    char dob[30];
};
/******************************************************User Structure***********************************************************/
struct User
{
    int AccountNo;
    char username[20];
    char password[20];
    char Role[20];     //Student - Staff - Alumni - Faculty - Librarian 
    int no_of_books_taken;    
    int no_of_items_taken;
    int total_amount_due;
};
/********************************************************Transaction Structure*******************************************************/
struct Transaction
{
    char uniqueTransactionID[30];
    char typeOfTransaction[40]; //books issuing to user or collecting returned 
    char timeOfTransaction[30]; //date month and year
//    struct Books *;     //You can also declare book array of 25.
//    struct Items *;     //you can also declare item array of 3. Because this is maximum number any one can take.
    char userId[30];
    int no_of_books;
    int no_of_items;
    int no_of_temporaryBooks;
    int amounts_if_any; //Amounts charged here must reflect in the transaction slip.
};
/************************************************************Main*********************************************************************/
int main()
{
	char password[15],username[30];
	int i,j;
    FILE *dat;
    dat=fopen("password.bin","wb");//open password.bin for store all passwords 
    if(!dat)

   {
      printf("File cannot be open\n");
//      exit(0);
   }
   printf("Enter user name: ");
   	gets(username);                               
    printf("Enter the password: ");
    for(i=0;i<15;i++) //loop for password entry
    {
    	password[i]=getch();//take charecter form key board
     	if(password[i]==13) //'13' is the ascii code of the key "Enter"
     	{
    		password[i]='\0'; break; //end the password entry
     	}
     	printf("*");  //print charecter * for every stroke from key board
    }
	fputs(password,dat);//store password into a file 
	
	j=((strcmp(password,"Librarian")) && (strcmp(username,"Admin"))); //comapre entered password with some string
	if(j==0)
	{
	    printf("\n\nYou entered correct password");
	    printf("\nWelcome to Application\n");
	    Admin_menu();
	}
	else
	{
		struct User acc;
		FILE *fz;
		fz = fopen("LMS/Library/user.bin","rb");
		while (fread(&acc,sizeof(acc),1,fz)==1)
		{
			if ((strcmp(password,acc.password)==0) && (strcmp(username,acc.username)==0))
			{
				Customer_menu();
				break;
			}
			else
			{
				printf("\n *** Invalid user name or password! Try again ***");
			}
		}
		fclose(fz);	
	}
	fclose(dat);//close the file 
	fflush(stdin);
	getchar();	
}
/****************************************************************Admin Menu**************************************************/
void Admin_menu()
{
	int choice;
	fflush(stdin);
	while(1)
	{
		printf("\n          +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++          \n\n");
		printf("\n                     *** MENU for a Librarian/Admin user ***                   \n\n");
		printf("\n          +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++           \n\n");
		printf("\n  0. Exit\n");
		printf("  1. Add records\n");
		printf("  2. Update records\n");
		printf("  3. Delete records\n");
		printf("  4. Display records\n");		
		printf("  5. Create Directory\n");		
		printf("  6. Add Media\n");		
		printf("  7. Update Media\n");		
		printf("  8. Delete Media\n");		
		printf("  9. Dispaly Media\n");
		printf(" 10. Add Temporary\n");
		printf(" 11. Update Temporary\n");
		printf(" 12. Delete Temporary\n");
		printf(" 13. Display Temporary\n");
		printf(" 14. Add Userdata\n");
		printf(" 15. Update Userdata\n");
		printf(" 16. Delete Userdata\n");
		printf(" 17. Display Userdata\n");
		printf(" 18. User Account\n");			
		printf(" 19. Display User Account\n");		
		printf("\nYour Choice : ");
		scanf("%d",&choice);
		fflush(stdin);	
		printf("\n");
		switch(choice)
		{
			case 1:
				Add_records();
				break;	
			case 2:
				Update_records();
				break;				
			case 3:
				Delete_records();
				break;				
			case 4:
				Display_records();
				break;				
			case 5:
				Create_directory();
				break;				
			case 6:
				Add_media();
				break;				
			case 7:
				Update_media();
				break;					
			case 8:
				Delete_media();
				break;				
			case 9:
				Display_media();
				break;				
			case 10:
				Add_temporary();
				break;				
			case 11:
				Update_temporary();
				break;			
			case 12:
				Delete_temporary();
				break;				
			case 13:
				Display_temporary();
				break;				
			case 14:
				Add_userdata();
				break;			
			case 15:
				Update_userdata();
				break;				
			case 16:
				Delete_userdata();
				break;			
			case 17:
				Display_userdata();
				break;				
			case 18:
				User_account();
				break;					
			case 19:
				Display_user_acc();
				break;					
			case 0:
				exit(0);						
		}
	}
}
/*************************************************************Customer Menu**************************************************/
void Customer_menu()
{
	int choice;
	fflush(stdin);
//	while(1)
//	{
		printf("\n    +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++           \n\n");
		printf("\n                  *** MENU for a Library Customer ***                     \n\n");
		printf("\n    +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++           \n\n");
		printf("\n1. Search for a book based on parameters\n");
		printf("2. Display books which are loaned by you\n");
		printf("3. Renew a book\n");
		printf("4. Endorse a temporary book / vote for book , you need temporary book id\n");
		printf("5. Logoff\n");
//	}
}
/****************************************************Add Records*************************************************************/
void Add_records()
{
	int count=0,c,c1=0;
	char temp1[5],temp2[8],temp[3]="",temp4[30],temp5[10]="",id_no[30],path[50];
	char str[5],str1[5]="",str2[5]="",str3[5];
	FILE *fs,*fp,*fq,*fr;
	fp = fopen ( "book1.dat", "ab" ) ;
	fs = fopen ("book1.dat","rb+");
	struct library book,b;
	fflush(stdin);
	strcpy(path,"LMS/Book/");
	strcpy(book.bookId,"");
	strcpy(book.bookName,"");
	strcpy(book.authorName,"");
	strcpy(book.publisherName,"");
	strcpy(book.ISBN,"");
	strcpy(book.department,"");
	strcpy(book.location,"");
	strcpy(book.status,"");
	strcpy(book.loanedDate,"");
	strcpy(book.dueDate,"");
	strcpy(book.loanedTo,"");		
	printf("\nEnter the details of the book:-\n");
	printf("\nBook name: ");
	gets(book.bookName);
	fflush(stdin);	
	printf("Author name: ");
	gets(book.authorName);
	fflush(stdin);
	printf("Publisher name: ");
	gets(book.publisherName);
	fflush(stdin);
	printf("ISBN: ");
	gets(book.ISBN);
	fflush(stdin);
	printf("Edition: ");
	scanf("%d",&book.edition);
	fflush(stdin);
	printf("Cost: ");
	scanf("%d",&book.cost);
	fflush(stdin);
	printf("Department: ");
	gets(book.department);
	fflush(stdin);
	strcat(path,book.department);
	strcat(path,"/");
	printf("Status: ");
	gets(book.status);
	fflush(stdin);
	printf("Loaned date: ");
	gets(book.loanedDate);
	fflush(stdin);
	printf("Due date: ");
	gets(book.dueDate);
	fflush(stdin);
	printf("Loaned to: ");
	gets(book.loanedTo);
	fflush(stdin);
	strcpy(book.bookId,book.department);
	strcat(book.bookId," ");
	temp1[0]='R';
	temp1[1]=book.bookName[0];
	temp1[2]='\0';
	strcat(path,temp1);
	strcat(path,".bin");
	fq = fopen(path,"ab");
	fr = fopen(path,"rb+");
	strcat(book.bookId,temp1);
	strcat(book.bookId," ");
	temp2[0]=book.ISBN[0];
	temp2[1]=book.ISBN[1];
	temp2[2]=book.ISBN[2];
	temp2[3]='\0';
	strcat(book.bookId,temp2);	
	strcat(book.bookId,"-");
	itoa(book.edition,str,10);
	strcat(book.bookId,str);
	strcat(book.bookId," ");
	strcpy(temp4,book.bookId);
	while (fread(&b,sizeof(b),1,fs)==1)
	{
		count++;	
	}
	c1=count;
	if (count==0)
	{
		c=1;
		strcpy(temp,"00");
		itoa(c,str3,10);
		strcat(temp,str3);
		strcat(temp4,temp);
		strcpy(book.bookId,temp4);
	}
	else
	{			
		if (c1>0 && c1<9)
		{
			strcpy(temp,"00");
			c1++;
		}
		if (c1>9 && c1<99)
		{
			strcpy(temp,"0");
			c1++;
		}
		if (c1>99)
		{
			c1++;
		}
		itoa(c1,str3,10);
		strcat(temp,str3);
		strcat(temp4,temp);
		strcpy(book.bookId,temp4);
	}
	temp5[0]=book.bookId[0];
	temp5[1]=book.bookId[1];
	temp5[2]=book.bookId[2];
	temp5[3]=book.bookId[3];
	temp5[4]=book.bookId[4];
	temp5[5]='\0';
	strcat(book.location,temp5);
	fwrite(&book,sizeof(book),1,fp);
	fwrite(&book,sizeof(book),1,fq);
	fclose(fp);
	fclose(fs);
	fclose(fq);
	fclose(fr);
	fflush(stdin);
}
/****************************************************Update Records****************************************************************/
void Update_records()
{
	char id_no[30];
	FILE *fs,*ft;
	fs = fopen ("book1.dat","rb+");
	ft= fopen ("temp.dat","wb");
	struct library book,b;
	fflush(stdin);
	printf("\nEnter the bookId of the book you want to Update: ");
	gets(id_no);
	while(fread(&book,sizeof(book),1,fs)==1)
	{
		if (strcmp(book.bookId,id_no)==0)
		{
			strcpy(b.bookId,book.bookId);
			strcpy(b.bookName,book.bookName);
			strcpy(b.authorName,book.authorName);
			strcpy(b.publisherName,book.publisherName);
			strcpy(b.ISBN,book.ISBN);
			strcpy(b.department,book.department);
			strcpy(b.location,book.location);
			fflush(stdin);
			printf("\nCost: ");
			scanf("%d",&b.cost);
			fflush(stdin);
			printf("Status: ");
			gets(b.status);
			fflush(stdin);
			printf("Loaned date: ");
			gets(b.loanedDate);
			fflush(stdin);
			printf("Due date: ");
			gets(b.dueDate);
			fflush(stdin);
			printf("Loaned to: ");
			gets(b.loanedTo);
			fflush(stdin);
			fwrite(&b,sizeof(b),1,ft);
		}
		else
		{
			fwrite(&book,sizeof(book),1,ft);	
		}	
	}
	fclose(fs);
	fclose(ft);
	remove("book1.dat");
	rename("temp.dat","book1.dat");		
}
/****************************************************Delete Records****************************************************************/
void Delete_records()
{
	char id_no[30];
	FILE *fs;
	fs = fopen ("book1.dat","rb+");
	struct library book;
	printf("\nEnter the bookId of the book you want to delete: ");
	gets(id_no);
	FILE *ft;
	ft = fopen("Temp.dat","wb");
	while (fread(&book,sizeof(book),1,fs)==1)
	{
		if (strcmp(book.bookId,id_no)==0)
		{
		
		}
		else
		{
			fwrite(&book,sizeof(book),1,ft);
		}
	}
	fclose(fs);
	fclose(ft);
	remove("book1.dat");
	rename("Temp.dat","book1.dat");
}
/****************************************************Display Records*********************************************************/
void Display_records()
{
	FILE *fs;
	struct library book;
	fs = fopen ("book1.dat","rb+");
	while (fread(&book,sizeof(book),1,fs)==1)
	{
		printf("\n\nBook Id: %s\n",book.bookId);
		printf("Book name: %s\n",book.bookName);
		printf("Author name: %s\n",book.authorName);
		printf("Publisher name: %s\n",book.publisherName);
		printf("ISBN: %s\n",book.ISBN);
		printf("Edition: %d\n",book.edition);
		printf("Cost: %d\n",book.cost);
		printf("Department: %s\n",book.department);
		printf("Location: %s\n",book.location);
		printf("Status: %s\n",book.status);
		printf("Loaned date: %s\n",book.loanedDate);
		printf("Due date: %s\n",book.dueDate);
		printf("Loaned to: %s\n\n",book.loanedTo);
	}
	fclose(fs);
}
/****************************************************Create directory*********************************************************/
void Create_directory()
{
	char path[50];
	struct Department dep;
	mkdir ("LMS");
	mkdir ("LMS/Book");
	printf("\nEnter the department: ");
	gets(dep.departmentName);
	strcpy(path,"LMS/Book/");
	strcat(path,dep.departmentName);
	mkdir (path);
	mkdir ("LMS/Magazines");
	mkdir ("LMS/Media");
	mkdir ("LMS/Library");
}
/****************************************************Add Media*****************************************************************/
void Add_media()
{
	char path1[50],tem[10],tem1[10],st[10],tem2[10];
	int count=0,c=0,c1=0;
	struct Item media,m;
	FILE *fb,*fc;
	strcpy(path1,"LMS/Media/");
	strcat(path1,"media.bin");
	fb = fopen(path1,"ab");
	fc = fopen(path1,"rb+");
	strcpy(media.itemName,"");
	strcpy(media.itemType,"");
	strcpy(media.creator,"");
	strcpy(media.publisher,"");
	strcpy(media.status,"");
	strcpy(media.loanDate,"");
	strcpy(media.dueDate,"");
	strcpy(media.loanedTo,"");
	printf("\nEnter the details of the media: \n\n");
	printf("Item name: ");
	gets(media.itemName);
	fflush(stdin);
	printf("Item type: ");
	gets(media.itemType);
	fflush(stdin);
	printf("Price: ");
	scanf("%d",&media.itemPrice);
	fflush(stdin);
	printf("Creator: ");
	gets(media.creator);
	fflush(stdin);
	printf("Publisher: ");
	gets(media.publisher);
	fflush(stdin);
	printf("Status: ");
	gets(media.status);
	fflush(stdin);	
	printf("Loaned date: ");
	gets(media.loanDate);
	fflush(stdin);
	printf("Due date: ");
	gets(media.dueDate);
	fflush(stdin);
	printf("Loaned to: ");
	gets(media.loanedTo);
	fflush(stdin);
	strcpy(media.itemId,"");
	strcat(media.itemId,media.itemType);
	strcat(media.itemId," ");
	strcat(media.itemId,"M");
	tem[0]=media.itemName[0];
	tem[1]='\0';
	strcat(media.itemId,tem);
	strcat(media.itemId," ");
	strcat(tem2,media.itemId);
	printf("\nName: %s\n",media.itemName);
	while (fread(&m,sizeof(m),1,fc)==1)
	{
		count++;
		
	}
	c1=count;
	if (count==0)
	{
		c=1;
		strcpy(tem1,"00");
		itoa(c,st,10);
		strcat(tem1,st);
		strcat(tem2,tem1);
		strcpy(media.itemId,tem2);
	}
	else
	{			
		if (c1>0 && c1<9)
		{
			strcpy(tem1,"00");
			c1++;
		}
		if (c1>9 && c1<99)
		{
			strcpy(tem1,"0");
			c1++;
		}
		if (c1>99)
		{
			c1++;
		}
		itoa(c1,st,10);
		strcat(tem1,st);
		strcat(tem2,tem1);
		strcpy(media.itemId,tem2);
	}
	printf("\nName: %s\n",media.itemName);
	fwrite(&media,sizeof(media),1,fb);
	printf("\nGenetrated item: %s\n",media.itemId);
	fclose(fb);
	fclose(fc);	
}
/****************************************************Update Media*********************************************************/
void Update_media()
{
	char id_no[30];
	struct Item media,m;
	FILE *fc,*fd;
	fc = fopen("LMS/Media/media.bin","rb+");
	fd = fopen("LMS/Media/temp.bin","wb");
	printf("\nEnter the itemId you want to update: ");
	gets(id_no);
	while(fread(&media,sizeof(media),1,fc)==1)
	{
		if(strcmp(media.itemId,id_no)==0)
		{
			strcpy(m.itemId,media.itemId);
			strcpy(m.itemName,media.itemName);
			strcpy(m.itemType,media.itemType);
			strcpy(m.creator,media.creator);
			strcpy(m.publisher,media.publisher);
			printf("\nPrice: ");
			scanf("%d",&m.itemPrice);
			fflush(stdin);
			printf("Status: ");
			gets(m.status);
			fflush(stdin);
			printf("Loaned date: ");
			gets(m.loanDate);
			fflush(stdin);
			printf("Due date: ");
			gets(m.dueDate);
			fflush(stdin);
			printf("Loaned to: ");
			gets(m.loanedTo);
			fflush(stdin);
			
			fwrite(&m,sizeof(m),1,fd);
		}
		else
		{
			fwrite(&media,sizeof(media),1,fd);	
		}	
	}
	fclose(fc);
	fclose(fd);	
	remove("LMS/Media/media.bin");
	rename("LMS/Media/temp.bin","LMS/Media/media.bin");						
}
/****************************************************Delete Media*********************************************************/
void Delete_media()
{
	char id_no[20];
	FILE *fc;
	fc = fopen("LMS/Media/media.bin","rb+");
	struct Item media;
	printf("\nEnter the itemId you want to delete: ");
	gets(id_no);
	FILE *fe;
	fe = fopen("LMS/Media/temp.bin","wb");
	while(fread(&media,sizeof(media),1,fc)==1)
	{
		if (strcmp(media.itemId,id_no)==0)
		{
		
		}
		else
		{
			fwrite(&media,sizeof(media),1,fe);
		}
	}
	fclose(fc);
	fclose(fe);	
	remove("LMS/Media/media.bin");
	rename("LMS/Media/temp.bin","LMS/Media/media.bin");	
}
/****************************************************Dispaly Media*****************************************************************/
void Display_media()
{
	FILE *fc;
	fc = fopen("LMS/Media/media.bin","rb+");
	struct Item media;	
	while(fread(&media,sizeof(media),1,fc)==1)
	{
		printf("\nItem Id: %s\n",media.itemId);
		printf("Item name: %s\n",media.itemName);
		printf("Item type: %s\n",media.itemType);
		printf("Price: %d\n",media.itemPrice);
		printf("Creator: %s\n",media.creator);
		printf("Publisher: %s\n",media.publisher);
		printf("Status: %s\n",media.status);
		printf("Loaned date: %s\n",media.loanDate);
		printf("Due date: %s\n",media.dueDate);
		printf("Loaned to: %s\n",media.loanedTo);
	}
	fclose(fc); 
}
/**************************************************Add Temporary Books*************************************************************/
void Add_temporary()
{
	char path2[50],st[10],st1[10],st2[10],st3[10],st4[10],st5[10];
	int count=0,c=0,c1=0;
	struct Custody temp,t;
	FILE *fg,*fh;	
	strcpy(path2,"LMS/");
	strcat(path2,"custodybooks.bin");	
	fg = fopen(path2,"ab");
	fh = fopen(path2,"rb+");	
	strcpy(temp.temporaryId,"");
	strcpy(temp.bookName,"");
	strcpy(temp.author,"");
	strcpy(temp.publisher,"");
	strcpy(temp.ISBN,"");	
	printf("\nEnter the details of temporary books: \n");	
	printf("\nBook name: ");
	gets(temp.bookName);
	fflush(stdin);
	printf("Author: ");
	gets(temp.author);
	fflush(stdin);
	printf("Publisher: ");
	gets(temp.publisher);
	fflush(stdin);
	printf("ISBN: ");
	gets(temp.ISBN);
	fflush(stdin);
	printf("Edition: ");
	scanf("%d",&temp.edition);
	fflush(stdin);
	printf("Cost: ");
	scanf("%d",&temp.cost);
	fflush(stdin);	
	strcpy(temp.temporaryId,"");	
	st5[0]=temp.ISBN[0];
	st5[1]=temp.ISBN[1];
	st5[2]=temp.ISBN[2];
	st5[3]=temp.ISBN[3];
	st5[4]='\0';
	strcat(temp.temporaryId,st5);
	strcat(temp.temporaryId," T");
	st2[0]=temp.bookName[0];
	st2[1]='\0';
	strcat(temp.temporaryId,st2);
	strcat(temp.temporaryId,"-");
	itoa(temp.edition,st3,10);
	strcat(temp.temporaryId,st3);
	strcat(temp.temporaryId," ");
	strcpy(st4,temp.temporaryId);	
	while (fread(&t,sizeof(t),1,fh)==1)
	{
		count++;
	}	
	c1=count;
	if (count==0)
	{
		c=1;
		strcpy(st,"00");
		itoa(c,st1,10);
		strcat(st,st1);
		strcat(st4,st);
		strcpy(temp.temporaryId,st4);
	}	
	else
	{			
		if (c1>0 && c1<9)
		{
			strcpy(st,"00");
			c1++;
		}
		if (c1>9 && c1<99)
		{
			strcpy(st,"0");
			c1++;
		}
		if (c1>99)
		{
			c1++;
		}
		itoa(c1,st1,10);
		strcat(st,st1);
		strcat(st4,st);
		strcpy(temp.temporaryId,st4);
	}
	fwrite(&temp,sizeof(temp),1,fg);
	printf("\nGenterate: %s\n",temp.temporaryId);
	fclose(fg);
	fclose(fh);
}
/*************************************************Update Temporary Books************************************************/
void Update_temporary()
{
	char id_no[30];
	struct Custody temp,t;
	FILE *fh,*fi;
	fh = fopen("LMS/custodybooks.bin","rb+");
	fi = fopen("LMS/ext.bin","wb");	
	printf("Enter the temporary book_Id you want to Update: ");
	gets(id_no);
	while(fread(&temp,sizeof(temp),1,fh)==1)
	{
		if (strcmp(temp.temporaryId,id_no)==0)
		{
			strcpy(t.temporaryId,temp.temporaryId);
			strcpy(t.bookName,temp.bookName);
			strcpy(t.author,temp.author);
			strcpy(t.publisher,temp.publisher);
			strcpy(t.ISBN,temp.ISBN);
			t.edition=temp.edition;
			printf("\nCost: ");
			scanf("%d",&t.cost);		
			fwrite(&t,sizeof(t),1,fi);	
		}
		else
		{
			fwrite(&temp,sizeof(temp),1,fi);	
		}
		fclose(fh);
		fclose(fi);	
		remove("LMS/custodybooks.bin");
		rename("LMS/ext.bin","LMS/custodybooks.bin");	
	}	
}
/**************************************************Delete Temporary Book******************************************************/
void Delete_temporary()
{
	char id_no[30];
	struct Custody temp;
	FILE *fh,*fj;
	fh = fopen("LMS/custodybooks.bin","rb+");
	fj = fopen("LMS/ext.bin","wb");	
	printf("Enter the temporary book_Id you want to delete: ");
	gets(id_no);
	while(fread(&temp,sizeof(temp),1,fh)==1)
	{
		if (strcmp(temp.temporaryId,id_no)==0)
		{
			
		}
		else
		{
			fwrite(&temp,sizeof(temp),1,fj);
		}
	}
	fclose(fh);
	fclose(fj);
	remove("LMS/custodybooks.bin");
	rename("LMS/ext.bin","LMS/custodybooks.bin"); 
}
/***********************************************Display Temporary Book*************************************************/
void Display_temporary()
{
	struct Custody temp;
	FILE *fh;
	fh = fopen("LMS/custodybooks.bin","rb+");
	while(fread(&temp,sizeof(temp),1,fh)==1)
	{
		printf("\nTemporary Book Id: %s\n",temp.temporaryId);
		printf("Book name: %s\n",temp.bookName);
		printf("Author: %s\n",temp.author);
		printf("Publisher: %s\n",temp.publisher);
		printf("ISBN: %s\n",temp.ISBN);
		printf("Edition: %d\n",temp.edition);
		printf("Cost: %d\n",temp.cost);
	}
	fclose(fh);
}
/*********************************************************Add User data*************************************************/
void Add_userdata()
{
	char path[50];
	struct UserData data;
	strcpy(path,"LMS/Library/");
	strcat(path,"userdata.bin");
	FILE *fk;
	fk = fopen(path,"ab+");
	strcpy(data.FullName,"");
	strcpy(data.RollNumber,"");
	strcpy(data.Address,"");
	strcpy(data.emailAddress,"");
	strcpy(data.sex,"");
	strcpy(data.dob,"");
	printf("Account No: ");
	scanf("%d",&data.AccountNo);
	fflush(stdin);
	printf("Full Name: ");
	gets(data.FullName);
	fflush(stdin);
	printf("Roll Number: ");
	gets(data.RollNumber);
	fflush(stdin);
	printf("Address: ");
	gets(data.Address);
	fflush(stdin);
	printf("Phone Number: ");
	scanf("%d",&data.phoneNumber);
	fflush(stdin);
	printf("Email Address: ");
	gets(data.emailAddress);
	fflush(stdin);
	printf("Sex: ");
	gets(data.sex);
	fflush(stdin);
	printf("Data of Birth: ");
	gets(data.dob);
	fflush(stdin);	
	fwrite(&data,sizeof(data),1,fk);
	fclose(fk);	
}
/****************************************************************Update User Data****************************************************/
void Update_userdata()
{
	int acc_no;
	struct UserData data,d;
	printf("\nEnter the account no. you want to Update: ");
	scanf("%d",&acc_no);
	fflush(stdin);
	FILE *fo,*fv;
	fo = fopen("LMS/Library/userdata.bin","rb+");
	fv = fopen("LMS/Library/data.bin","wb");	
	while (fread(&data,sizeof(data),1,fo)==1)
	{
		if (data.AccountNo==acc_no)
		{
			d.AccountNo=data.AccountNo;
			strcpy(d.FullName,data.FullName);
			strcpy(d.RollNumber,data.RollNumber);
			strcpy(d.Address,data.Address);
			d.phoneNumber=data.phoneNumber;
			strcpy(d.sex,data.sex);
			strcpy(d.dob,data.dob);
			printf("\nEmail Address: ");
			gets(d.emailAddress);
			fflush(stdin);
			fwrite(&d,sizeof(d),1,fv);
		}
		else
		{
			fwrite(&data,sizeof(data),1,fv);
		}
	}
	fclose(fo);
	fclose(fv);	
	remove("LMS/Library/userdata.bin");
	rename("LMS/Library/data.bin","LMS/Library/userdata.bin");	
}
/****************************************************************Delete User Data****************************************************/
void Delete_userdata()
{
	int acc_no;
	struct UserData data;
	printf("\nEnter the account no. you want to delete: ");
	scanf("%d",&acc_no);
	FILE *fm,*fn;
	fm = fopen("LMS/Library/userdata.bin","rb+");
	fn = fopen("LMS/Library/data.bin","wb");
	while (fread(&data,sizeof(data),1,fm)==1)
	{
		if (data.AccountNo==acc_no)
		{
			
		}
		else
		{
			fwrite(&data,sizeof(data),1,fn);
		}
	}
	fclose(fm);
	fclose(fn);		
	remove("LMS/Library/userdata.bin");
	rename("LMS/Library/data.bin","LMS/Library/userdata.bin");	
}
/****************************************************************Display User Data***************************************************/
void Display_userdata()
{
	char accNo[30];
	struct UserData data;
	FILE *fl;
	fl = fopen("LMS/Library/userdata.bin","rb");	
	while (fread(&data,sizeof(data),1,fl)==1)
	{
		printf("\nAccount No: %d\n",data.AccountNo);
		printf("Full Name: %s\n",data.FullName);
		printf("Roll Number: %s\n",data.RollNumber);
		printf("Address: %s\n",data.Address);
		printf("Phone Number: %d\n",data.phoneNumber);
		printf("Email Address: %s\n",data.emailAddress);
		printf("Sex: %s\n",data.sex);
		printf("Data of Birth: %s\n",data.dob);
	}
	fclose(fl);
}
/***************************************************************User Account***********************************************************/
void User_account()
{
	char path5[50];
	strcpy(path5,"LMS/Library/");
	strcat(path5,"user.bin");
	struct User acc;
	FILE *fx;
	fx = fopen(path5,"ab+");
	printf("Account No: ");
	scanf("%d",&acc.AccountNo);
	fflush(stdin);
	printf("User Name: ");
	gets(acc.username);
	fflush(stdin);
	printf("Password: ");
	gets(acc.password);
	fflush(stdin);
	printf("Role: ");
	gets(acc.Role);
	fflush(stdin);	
	fwrite(&acc,sizeof(acc),1,fx);
	fclose(fx);	
}
/************************************************************Display User Account****************************************/
void Display_user_acc()
{
	struct User acc;
	FILE *fy;
	fy = fopen("LMS/Library/user.bin","rb");	
	while (fread(&acc,sizeof(acc),1,fy)==1)
	{
		printf("\nAccount No: %d\n",acc.AccountNo);
		printf("User Name: %s\n",acc.username);
		printf("Password: %s\n",acc.password);
		printf("Role: %s\n",acc.Role);
	}
	fclose(fy);
}
