#include<stdio.h>
#include <stdlib.h>
#include <string.h>


struct n
{
    char name[10];
    char gender[10];
    int age;
    int id;
    int slot;
    struct n* link;
};
typedef struct n node;

void view1 ();
void view2 ();
node* createlist();
node* insert (node* start);
node* cancel (node* start,int ID );
void ViewNodes (node* start);
void edit (node* start ,int ID);
void ViewSlots();
void reverse(int *ptr,node* start );
void CancelReverse(int *ptr,node* start);
void ViewUserDataWithID(node* start);
void AllReservation (node* strat);


int main (){
     node* end;
     int password,i,feature,flag,x,s,r,mode,id;
     int slots [5]={0,0,0,0,0};
     printf("press 1 for admin mode \n");
     printf("press 2 for user mode \n");
     scanf("%d",&mode);
/******************************************************************************************************/
     if(mode==1)
    {
         for(i=0;i<3;i++){
	      printf("Please Enter the password= ");
	      scanf("%d",&password);
          if (password==1234)
			{
                view1();
                scanf("%d",&feature);
 //////////////////////////////////////////////////////////////////////////////////////////////////
                if (feature==1)    //Add new patient
                {
                    node*start=createlist();
                    while (flag!=1)
                    {
                         printf("press 1 if you want to exist \n ");
                         printf("press 2 if you want user \n");
                         printf("press 3 if you want to continue \n ");

                         scanf("%d",&flag);
/******************************************************************************************************/
                         if(flag==1) //exist
                         {
                            break;
                         }
/******************************************************************************************************/
                         else if (flag==2) //user
                         {
                           printf("press 1 if you want to view patient record\n");
                           printf("press 2 if you want to view todays reservation\n");
                           scanf("%d",&r);
                           if(r==1)
                           {
                              ViewUserDataWithID(start);
                           }
                           if(r==2)
                           {
                              AllReservation (start);
                           }

                         }
/******************************************************************************************************/
                        else if (flag==3)//continue
                         {
                             view1();
                             scanf("%d",&x);
                             if (x==1)  //insert
                             {
                               end=insert(start);
                             }
                             else if (x==2) //edit
                             {
                             printf("enter the ID you want to edit");
                            scanf("%d",&id);
                            edit(start,id);
                            printf("After edit");
                            ViewNodes(start);
                             }
                             else if(x==3) //slots
                             {
                                ViewSlots();
                                scanf("%d",&s);
                                printf("Enter your ID = ");
                                scanf("%d",&id);
                                slots[s]=1;
                             }
                             else if(x==4) //Delete user
                             {
                                printf("the ID you want to cancel=");
                                scanf("%d",&id);
                                start=cancel(start,id);
                             }
                             else if (x==5) //reserve slot
                              {

                                ViewSlots();
                                reverse(slots,start);
                             }
                             else if (x==6) //cancel reserve slot
                             {
                                CancelReverse(slots,start);
                             }
                         }

                    }
            }
/******************************************************************************************************/
	           else if (feature==2)
                {
                  printf("No edit");
                }
////////////////////////////////////////////////////////////////////////////////////////////
	          else if  (feature==3)
               {
                 printf("No reserve");

               }
//////////////////////////////////////////////////////////////////////////////////////////
              else if (feature==4)
              {
                 printf("No Cancel");
              }
			    break;
            }
//////////////////////////////////////////////////////////////////////////////////////////
		   else
		    {
			 printf(" Incorrect Password \n ");
		    }
		         if(flag==1) //exist
                {
                      break;
                 }
       }
 }
/******************************************************************************************************/
     else if(mode==2)
     {
       view2();
       scanf("%d",feature);
       if (feature==1)
       {
         printf("No ViewUserDataWithID");
       }
       else if (feature==2)
       {
          printf("No ViewNodes");
       }
     }
     else
     {
        printf("Incorrect number");
     }
return 0;
}
/******************************************************************************************************/
//Functions

void view1 ()
{
    printf("press 1 to Add new patient\n");
    printf("press 2 to Edit patient record\n");
    printf("press 3 to reserve slot with doctor\n");
    printf("press 4 to Delete user\n");
    printf("press 5 to reserve slot\n");
    printf("press 6 to cancel reserve slot\n");

}
//////////////////////////////////////////////////////////////////////////////////////////
void view2 ()
{
    printf("press 1 to View patient record\n");
    printf("press 2 to view today's reservation\n");
}
//////////////////////////////////////////////////////////////////////////////////////////
//create linkedlist

node* createlist()
{

   int pos,i;
    node *temp=(node*)malloc (sizeof (node));
   if(temp!=NULL){

    //store data

    printf("Please Enter your name=");
    scanf("%s",&(temp->name));

    printf("Please Enter your gender=");
    scanf("%s",&(temp->gender));

    printf("Please Enter your age=");
    scanf("%d",&temp->age);

    printf("Please Enter your ID=");
    scanf("%d",&temp->id);

    //link NULL
    temp->link= NULL ;

    }

       return temp;
    }
//////////////////////////////////////////////////////////////////////////////////////////
//insert node at the end
node* insert (node* start)
{

    node* p;
  node *temp=(node*)malloc (sizeof (node));
  if(temp!=NULL){

     //store data

    printf("Please Enter your name=");
    scanf("%s",&(temp->name));

    printf("Please Enter your gender=");
    scanf("%s",&(temp->gender));


    printf("Please Enter your age=");
    scanf("%d",&temp->age);


    printf("Please Enter your ID=");
    scanf("%d",&temp->id);


    //link NULL
    temp->link= NULL ;

    //get final node
    p=start;
    while(p->link!=NULL)
    {
        p=p->link;
    }
    //insert node
    p->link=temp;
 }

    return start;
}
//////////////////////////////////////////////////////////////////////////////////////////
//edit
void edit (node* start ,int ID)
{
node* p=start;
node* cancel;

   if(p->id==ID)
   {
       start=(p->link);

         printf("Please Enter your name=");
    scanf("%s",&(p->name));
    printf("Please Enter your gender=");
    scanf("%s",&(p->gender));

       printf("enter the age=");
       scanf("%d",&(p->age));
   }
   else
   {
    while(p->link->id!=ID){
        p=p->link;
    }
    printf("Please Enter your name=");
    scanf("%s",&(p->name));
    printf("Please Enter your gender=");
    scanf("%s",&(p->gender));
    printf("enter the age=");
    scanf("%d",&(p->age));
    printf(" the age=%d",p->age);


   }
}
//////////////////////////////////////////////////////////////////////////////////////////
//view slots
void ViewSlots()
{
    printf("enter 0 if you want to book from 2 to 2:30\n");
    printf("enter 1 if you want to book from 2:30 to 3\n");
    printf("enter 2 if you want to book from 3 to 3:30\n");
    printf("enter 3 if you want to book from 4 to 4:30\n");
    printf("enter 4 if you want to book from 4:30 to 5");
}
//////////////////////////////////////////////////////////////////////////////////////////
//Delete
node* cancel (node* start,int ID )
{

node* p=start;
node* cancel;

   if(p->id==ID)
   {
       start=(p->link);
       free(p);
      return start;


   }
   else
   {
    while((p->link->id!=ID)&&(p!=NULL)){
            p=p->link;
    }
    if (p==NULL){
        printf("ID doesn't exist");
    }
    else{
       cancel=p->link;
       (p->link)=(cancel->link);
       free(cancel);
    return start;
    }
   }

}
//////////////////////////////////////////////////////////////////////////////////////////
//view nodes
void ViewNodes (node* start)
{
    node* p ;
    if(start==NULL)
    {
        printf("List is empty");
    }
    p=start;
    while(p!=NULL) {

        printf("your name=%s\n",(p->name));
        printf("your gender=%s\n",(p->gender));
        printf("your age=%d\n",(p->age));
        printf("your ID=%d\n",(p->id));

        p=p->link;
        }
}
//////////////////////////////////////////////////////////////////////////////////////////
//reserve slot
void reverse(int *ptr,node* start )
{

    int ID,y;
    printf("enter the ID if You want to reserve appointment with Doctor");
    scanf("%d",&ID);

    printf("enter 0 if you want to book from 2 to 2:30\n");
    printf("enter 1 if you want to book from 2:30 to 3\n");
    printf("enter 2 if you want to book from 3 to 3:30\n");
    printf("enter 3 if you want to book from 4 to 4:30\n");
    printf("enter 4 if you want to book from 4:30 to 5");

    scanf("%d",&y);

    if(ptr[y]==0)
{
    ptr[y]=1;
    node* p=start;

   if(p->id==ID)
   {
       start=(p->link);
       p->slot=1;

   }
   else
   {
    while(p->link->id!=ID){
        p=p->link;
    }
     p->slot=1;
   }

}
else
{
    printf("the slot is reversed");
}

}
//////////////////////////////////////////////////////////////////////////////////////////
void CancelReverse(int *ptr,node* start )
{
    int ID;
    int y;

    printf("enter the ID you want to CancelReservation of it");
    scanf("%d",&ID);

    printf("enter 0 if you  book from 2 to 2:30\n");
    printf("enter 1 if you  book from 2:30 to 3\n");
    printf("enter 2 if you  book from 3 to 3:30\n");
    printf("enter 3 if you  book from 4 to 4:30\n");
    printf("enter 4 if you  book from 4:30 to 5");
    scanf("%d",&y);

       node* p=start;
       node* cancel;
   if(p->id==ID)
   {
       start=(p->link);
       p->slot=0;
   }
   else
   {
    while(p->link->id!=ID){
        p=p->link;
    }
     p->slot=0;
   }
     ptr[y]=0;
     printf("After return slot available");
for (int i;i<5;i++)
 {
     printf("\n %d \n",ptr[i]);
 }
}
//////////////////////////////////////////////////////////////////////////////////////////
void ViewUserDataWithID(node* start )
{
    int ID;
      printf("enter the ID you want Display All of its Data");
    scanf("%d",&ID);
    //*********
    node* p=start;
    node* cancel;
   if(p->id==ID)
   {
       start=(p->link);
         printf("your name=%s\n",(p->name));
        printf("your gender=%s\n",(p->gender));
        printf("your age=%d\n",(p->age));
        printf("your ID=%d\n",(p->id));
          printf("your Slot=%d\n",(p->slot));
   }
   else
   {
    while(p->link->id!=ID){
        p=p->link;
    }
        printf("your name=%s\n",(p->name));
        printf("your gender=%s\n",(p->gender));
        printf("your age=%d\n",(p->age));
        printf("your ID=%d\n",(p->id));
        printf("your Slot=%d\n",(p->slot));
   }
}
//////////////////////////////////////////////////////////////////////////////////////////
void AllReservation (node* start)
{
    node* p =start;
    while ((p->link)!=NULL)
    {
        if((p->slot)==1)
        {
         printf("your name=%s\n",(p->name));
        printf("your gender=%s\n",(p->gender));
        printf("your age=%d\n",(p->age));
        printf("your ID=%d\n",(p->id));
          printf("your Slot=%d\n",(p->slot));
        }
    }
}
