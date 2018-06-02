#include<bits/stdc++.h>
#include<conio.h>

void registration();
void log_in();
void menu();
void purchasing();
void Foods_Limitation();
void Add_Burger_Item();
void view_Burger_Item();
void delete_Burger_Item();
void increase_Burger_quantty();
void decrease_Burger_quantty();

void search_all();
void displayall();

void search_Name();
void search_Phone();
void search_Address();

void delete_Informations();
void Kitchens_Information();
void displayall_food_Info();
void displayall_equip_Info();
void kitchen_food_Info();
void kitchen_Equip_Info();
void add_food_Info();
void delete_food_Info();
void add_equip_Info();
void delete_equip_Info();
void calculator();

int main()
{
   system("cls");
   int choice;

   printf("\n");
   printf("\t\t\t\t  ###  ###  ##  # HOME #  ##  ###  ###\n\n");
   printf("\n\t\t\t\t    #-- Log In       -->   Press 1\n");
   printf("\n\t\t\t\t    #-- Registration -->   Press 2\n");


   printf("\n\n");
   printf("\n\t\t\t\t        @EXIT        -->   Press 0\n");

   printf("\n\n\n\t\t\t\tEnter Your Choice :  ");
   scanf("%d",&choice);
   system("cls");

   switch(choice){
   case 1 :
       log_in();
   break;
   case 2 :
   registration();
   break;

   case 0 :
    {
       printf("\n\t\t\t\tGOOD BYE !!!\n\n");
       system("pause");
       exit(0);
    }
   break;
   }

   return 0;
}


//functions..->

void registration()
{
   system("cls");

   char reg_username[30],reg_pass[30];

   FILE *fp;
   fp=fopen("Registration_Data.txt","a");

   if(fp==NULL)
   {
       printf("Error!");
       exit(1);
   }

   //Registration
   printf("\t\t\t\tUser registration \n\n");
   printf("\n\t\t\t\tEnter username for registration : ");
   scanf("%s",reg_username);
   printf("\n\t\t\t\tEnter password for registration: ");
   scanf("%s",reg_pass);
   fprintf(fp,"\n%s %s",reg_username,reg_pass);
   fclose(fp);

   printf("\t\t\t\tYour Registration is successful.\n");
   printf("\t\t\t\tNow its time to login \n ");
   system("cls");
   system("pause");

   main();
}

void log_in()
{
   char reg_username[30],reg_pass[30],log_pass[30],log_username[30],name[30],pass[30];
   int c=0,cnt=0;
   int flag=1,tym_3=3;
   int reg_log_button;

   FILE *fp;

   fp=fopen("Registration_Data.txt","r");
   if(fp==NULL)
   {
       printf("Error!");
       exit(1);
   }

while(flag){

    //login

   printf("\n\n\t\t\t\tYou have only %d chance for entering correct Username & Password.\n\n",tym_3);
   printf("\n\n\t\t\t\tEnter username : ");
   scanf("%s",log_username);


   printf("\n\n\t\t\t\tEnter password : ");
   int l=0;
   while(l<=9){
        log_pass[l]=getch();
        if(log_pass[l]==13)break;
        else printf("*");
        l++;
    }
    log_pass[l]='\0';

   fp=fopen("Registration_Data.txt","r");
   if(fp==NULL)
   {
       printf("Error!");
       exit(1);
   }

   //comparison
   while(fscanf(fp,"%s %s\n",name,pass)!=EOF)
        {
             if((strcmp(log_username,name)==0)&&(strcmp(log_pass,pass)==0))
             //if the combination matches value of c is increased and user id of req user is stored in user.id
             {
                system("cls");

                menu();

                system("pause");
                flag=0;
                break;
             }
         }

         tym_3--;
         if(flag){
            system("cls");
            printf("\n\n\t\t\t\tIncorrect username or password. Please try again.\n\n");
            system("pause");
            fclose(fp);
            system("cls");
            if(tym_3==0){
                    printf("\n\n\t\t\t\tTry again later . \n");
                    main();
            }
         }
    }
}



void menu()
{
    system("cls");

    int choice;
    printf("\t\t\t\t :::::::::::::::  MENU  :::::::::::::::::: \n\n");

    printf("\n\t\t\t\t Purchasing System            --- Press 1\n");
    printf("\n\t\t\t\t Check Customer's Information --- Press 2\n");
    printf("\n\t\t\t\t Check Food's Limitation      --- Press 3\n");
    printf("\n\t\t\t\t Kitchen's Information        --- Press 4\n");
    printf("\n\t\t\t\t Calculator                   --- Press 5\n");

    printf("\n\t\t\t\t Go To Home Page              --- Press 0\n");

    printf("\n\n\n\t\t\t\tEnter Your Choice : ");
    scanf("%d",&choice);

    switch(choice) {

    case 1 :
      purchasing();
      break;

    case 2 :
      search_all();
      break;

    case 3 :
      Foods_Limitation();
      //kitchen_ingredients();
      break;

    case 4 :
      Kitchens_Information();
      break;

    case 5 :
      calculator();
      break;

    case 0 :
      main();
      break;

      system("psuse");
      menu();

   }
}




void purchasing()
{
    system("cls");
    FILE *fp_par;
    FILE *data;

    float price,amount=0.0;
    int quantity,ok,y_n;

    char item_name[40],Search_name[40];
    int limit,choice;

    float local_amount,amount_with_dis,amount_with_dis_1,amount_with_dis_2;
    float discount,tax,bill;

    char cashier_name[15],waiter_name[15],customers_name[20],customers_address[30],p={'%'};
    int customers_phn[20],table_no;

    int total_q_b,total_q_d,Y_N;

    fp_par=fopen("Purchasing_data.txt","a");

    printf("\t\t\t\t\t\t\t\n::::::::::::::  ##Restaurant##  ::::::::::::::  \n\n");

    printf("\n\n\t\t\t\tEnter Customers name         : ");
    scanf("%s",customers_name);
    printf("\n\n\t\t\t\tEnter Customers Address      : ");
    scanf("%s",customers_address);

    printf("\n\n");

    printf("\n\n\t\t\t\tEnter Cashier name : ");
    scanf("%s",cashier_name);
    printf("\n\n\t\t\t\tEnter Waiter name  : ");
    scanf("%s",waiter_name);

    printf("\n\n\t\t\t\tEnter customers phone number : ");
    scanf("%s",customers_phn);
    printf("\n\n\t\t\t\tEnter Table No     : ");
    scanf("%d",&table_no);
    printf("\n");

    fprintf(fp_par,"\n%s \n%s \n%s",customers_name,customers_phn,customers_address);
    fclose(fp_par);



    data=fopen("Burgers_Item.txt","r");
    if(data==NULL)
    {
       printf("Error!");
       exit(1);
    }


     //choose item from file..
     int i=1;
     while(fscanf(data,"\n%s %f %d",item_name,&price,&limit)!=EOF)
         {
                printf("\t\t\t\t%d. \n\t\t\t\tItem  \t: %s\n\t\t\t\tPrice \t: %.2f\n\t\t\t\tLimitations \t: %d\n\n",i,item_name,price,limit);
                i++;
                printf("\t\t\t\tIf you want to take this ITEM. press 1 Or 0--> ");
                scanf("%d",&y_n);
                if(y_n==0)continue;

                printf("\t\t\t\tThis Item is taken !! \n");
                printf("\t\t\t\tEnter Quantity :  ");
                scanf("%d",&quantity);
                amount=amount+(price*quantity);
               //limit=limit-quantity;

            printf("\t\t\t\tAdded Amount is : %.2f\n\n",amount);
         }
        fclose(data);

    local_amount=amount;
    printf("\n");

    //Including_Discount..
    printf("\n\t\t\t\tIs there any Discount !? if yes press 1 or press 2 -> ");
    scanf("%d",&Y_N);
    if(Y_N==1){
            printf("\n\t\t\t\tEnter the percent of Discount: ");
            scanf("%f",&discount);
            amount=amount-(amount*discount)/100;
            amount_with_dis_1=amount;
    }

    //Including_Vat
    printf("\n\t\t\t\tEnter vat: ");
    scanf("%f",&tax);
    amount=amount+(amount*tax)/100;
    bill=amount;

    printf("\n\n\n");
    system("pause");
    system("cls");


    //printing bill
    printf("\t\t\t\t\t\t\t         BIll        \n\n");

    printf("\t\t\t\tCashier   : %s\n",cashier_name);
    printf("\t\t\t\tWaiter    : %s\n",waiter_name);
    printf("\t\t\t\tTable no  : %d\n\n",table_no);

    printf("\t\t\t\tCustomer's Name         : %s\n",customers_name);
    printf("\t\t\t\tCustomer's Phone Number : %s\n",customers_phn);
    printf("\t\t\t\tCustomer's Address      : %s\n",customers_address);
    printf("\n\n");

    if(Y_N==1)amount_with_dis=amount_with_dis_1;
    else amount_with_dis=local_amount;

    printf("\t\t\t\tDiscount (%.0f %c) on %.2f(local Amount)\n",discount,p,local_amount);
    printf("\t\t\t\tAdd Vat  (%.0f %c) on %.2f\n",tax,p,amount_with_dis);
    printf("\t\t\t\tAmount Incl of All Taxes : %.2f\n",bill);

    printf("\n\n");
    printf("\t\t\t\t       Thank You for visit\n");
    printf("\t\t\t\t        Have a Nice Day");

    printf("\n\n");
    printf("\t\t\t\tThis Bill slip have to Print.\n\n");
    system("pause");
    printf("\n\t\t\t\tPrinted successfully !!!! \n");

    system("pause");
    menu();
}



void search_all()
{
   system("cls");
   int choice;
   printf("\n\t\t\t\t ##         Search Options        ##\n\n");
   printf("\n\t\t\t\tDisplay All Information   -- Press - 1\n");
   printf("\n\t\t\t\tSearch By Name            -- Press - 2\n");
   printf("\n\t\t\t\tSearch By Address         -- Press - 3\n");
   printf("\n\t\t\t\tSearch By Phone Number    -- Press - 4\n");
   printf("\n\t\t\t\tDelete Informations       -- Press - 5\n");
   printf("\n\t\t\t\tMenu                      -- Press - 0\n");

   printf("\n\n\t\t\t\tEnter your choice :");
   scanf("%d",&choice);
   system("cls");

   switch(choice){
   case 1:
        displayall();
    break;

   case 2:
       search_Name();
    break;

   case 3:
       search_Address();
    break;

   case 4:
       search_Phone();
    break;
    case 5:
       delete_Informations();
    break;

   case 0:
        menu();
    break;
   }

   system("pause");
   search_all();
}

void displayall()
{
    system("cls");

    FILE *fp_par;

    char name[20],phone[20],address[20];
    int i=1;

    fp_par=fopen("Purchasing_data.txt","r");
    if(fp_par==NULL)
    {
       printf("Error!");
       exit(1);
    }

    printf("\t\t\t\t\t\t\tInformation of all Customer's :\n");
    printf("\t\t\t\t\t\t\t-------------------------------\n\n\n");
    printf("\t\t\t\tCustomers Name \t\t\tPhone Number \t\t\tAddress\n\n");

    while(fscanf(fp_par,"\n%s \n%s \n%s",name,phone,address)!=EOF)
         {
                printf("\t\t\t\t%d. %s \t\t\t%s \t\t\t\t%s \n\n",i,name,phone,address);
                i++;
         }
         fclose(fp_par);

         system("pause");
         search_all();

}

void search_Name()
{
    system("cls");

    FILE *fp_par;

    char search_name[20],name[20],phone[20],address[20];
    int flag=1;

    fp_par=fopen("Purchasing_data.txt","r");
    if(fp_par==NULL)
    {
       printf("Error!");
       exit(1);
    }

    printf("\n\t\t\t\tEnter a name : ");
    scanf("%s",search_name);

    system("cls");

    printf("\t\t\t\tResults : \n\n");


    //comparison
    printf("\t\t\t\tCustomers Name \t\t\tPhone Number \t\t\tAddress\n\n");
    while(fscanf(fp_par,"\n%s \n%s \n%s",name,phone,address)!=EOF)
     {
             if(strcmp(search_name,name)==0)
             //if the combination matches value of c is increased and user id of req user is stored in user.id
             {

               printf("\t\t\t\t%s \t\t\t%s \t\t\t\t%s \n\n",name,phone,address);
                flag=0;
             }
         }
         if(flag)printf("\t\t\t\tResults Not Found !!! \n");
         fclose(fp_par);
         system("pause");
         search_all();
}

void search_Phone()
{
    system("cls");

    FILE *fp_par;

    char search_Phone[20],name[20],phone[20],address[20];
    int flag=1;
    fp_par=fopen("Purchasing_data.txt","r");
    if(fp_par==NULL)
    {
       printf("Error!");
       exit(1);
    }

    printf("\t\t\t\tEnter Phone Number : ");
    scanf("%s",search_Phone);
    system("cls");

    printf("\t\t\t\tResults : \n\n");
    printf("\t\t\t\tCustomers Name \t\t\tPhone Number \t\t\tAddress\n\n");

    while(fscanf(fp_par,"\n%s \n%s \n%s",name,phone,address)!=EOF)
         {
             if(strcmp(search_Phone,phone)==0)
            {
                printf("\t\t\t\t%s \t\t\t%s \t\t\t\t%s \n\n",name,phone,address);

                flag=0;
             }
         }
         fclose(fp_par);

         if(flag)printf("\t\t\t\tResults Not Found !!! \n");
         system("pause");
         search_all();

}

void search_Address()
{
    system("cls");

    FILE *fp_par;

    char search_Address[20],name[20],phone[20],address[20];
    int flag=1;

    fp_par=fopen("Purchasing_data.txt","r");
    if(fp_par==NULL)
    {
       printf("\t\t\t\tError!");
       exit(1);
    }

    printf("\t\t\t\tEnter name : ");
    scanf("%s",search_Address);
    system("cls");

    printf("\t\t\t\tResults : \n\n");
    printf("\t\t\t\tCustomers Name \t\t\tPhone Number \t\t\tAddress\n\n");
       while(fscanf(fp_par,"\n%s \n%s \n%s",name,phone,address)!=EOF)
       {
             if(strcmp(search_Address,address)==0)
            {
                printf("\t\t\t\t%s \t\t\t%s \t\t\t\t%s \n\n",name,phone,address);

                flag=0;
             }
         }
         fclose(fp_par);

         if(flag)printf("\t\t\t\tResults Not Found !!! \n");

         system("pause");
         search_all();

}


void delete_Informations()
{
    system("cls");
    FILE *fp_par, *fp2;
    int choice;
    char search_name[20],name[20],phone[20],address[20];
    int i=0;

    fp_par=fopen("Purchasing_data.txt","r");
    if(fp_par==NULL)
    {
       printf("Error!");
       exit(1);
    }


    printf("\n\t\t\t\tContents of file Before modification : \n ");
    i=0;
    printf("\t\t\t\tCustomers Name \t\t\tPhone Number \t\t\tAddress\n\n");
     while(fscanf(fp_par,"\n%s \n%s \n%s",name,phone,address)!=EOF)
         {
               printf("\t\t\t\t%d. %s \t\t\t%s \t\t\t\t%s \n\n",i,name,phone,address);
                i++;
         }

       rewind(fp_par);

       printf("\n\t\t\t\tIf you want return to Information menu. Press 0. -->  \n\n");
       scanf("%d",&choice);
       if(choice==0){
            fclose(fp_par);
            search_all();
       }

       printf("\n\t\t\t\tEnter a name : ");
       scanf("%s",search_name);
       system("pause");
       system("cls");

    fp2 = fopen("replica.txt","w");
    while(fscanf(fp_par,"\n%s \n%s \n%s",name,phone,address)!=EOF)
    {
        if(strcmp(search_name,name)!=0)
        {
               fprintf(fp2,"%s %s %s\n",name,phone,address);
        }
    }

    fclose(fp_par);
    fclose(fp2);

    remove("Purchasing_data.txt");
    rename("replica.txt","Purchasing_data.txt");

    fp_par=fopen("Purchasing_data.txt","r");
    if(fp_par==NULL)
    {
       printf("\t\t\t\tError!");
       exit(1);
    }

     printf("\n\t\t\t\tContent of file after modification : \n");
     i=0;
     printf("\t\t\t\tCustomers Name \t\t\tPhone Number \t\t\tAddress\n\n");
     while(fscanf(fp_par,"\n%s \n%s \n%s",name,phone,address)!=EOF)
         {
               printf("\t\t\t\t%d. %s \t\t\t%s \t\t\t\t%s \n\n",i,name,phone,address);
                i++;
         }
         system("pause");

    fclose(fp_par);
    search_all();
}




void Foods_Limitation()
{
    system("cls");

    int choice;
    printf("\n\t\t\t\t   FOOD'S LIMITATION  \n\n");
    printf("\n\t\t\t\tView Food Information's    -- Press - 1\n");
    printf("\n\t\t\t\tADD More ITEM              -- Press - 2\n");
    printf("\n\t\t\t\tDelete ITEM                -- Press - 3\n");
    printf("\n\t\t\t\tIncrease Food's Quantity   -- Press - 4\n");
    printf("\n\t\t\t\tDecrease Food's Quantity   -- Press - 5\n");
    printf("\n\t\t\t\tGo Back to MENU            -- Press - 0\n");

    printf("\n\n\t\t\t\tEnter your Choice : ");
    scanf("%d",&choice);

    switch(choice){

    case 1 :
        view_Burger_Item();
        break;
    case 2 :
        Add_Burger_Item();
        break;
    case 3 :
        delete_Burger_Item();
        break;
    case 4 :
        increase_Burger_quantty();
        break;
    case 5 :
        decrease_Burger_quantty();
        break;
    case 0 :
        menu();
        break;
    }
}

void Add_Burger_Item()
{
    system("cls");
    FILE *data;

    char item_name[20];
    float price;
    int limit,choice;

    data=fopen("Burgers_Item.txt","a");

    while(1)
    {
      printf("\t\t\t\tEnter a New Item (burger) : ");
      scanf("%s",item_name);
      printf("\n\t\t\t\tEnter the price of burgers : ");
      scanf("%f",&price);
      printf("\n\t\t\t\tEnter the number of quantity : ");
      scanf("%d",&limit);

      fprintf(data,"\n%s %f %d",item_name,price,limit);

      printf("\n\t\t\t\tIf you want to Continue. press 1 or 0 --> ");
      scanf("%d",&choice);
      if(choice==0)break;
    }

    fclose(data);
    system("pause");
    Foods_Limitation();

}

void delete_Burger_Item()
{
    system("cls");
    FILE *data,*data2;

    char item_name[20],Search_name[30];
    float price;
    int limit,i=0,choice;

    data=fopen("Burgers_Item.txt","r");
    if(data==NULL)
    {
       printf("Error!");
       exit(1);
    }


     printf("\n\t\t\t\tContent of File Before modification : \n ");
     i=0;
     printf("\t\t\t\tItem Name \t\t\tPrice \t\t\tLimitations\n\n");
     while(fscanf(data,"\n%s %f %d",item_name,&price,&limit)!=EOF)
         {
             i++;
             printf("\t\t\t\t%d. \t\tItem  : %s \t\tPrice : %.2f \t\tLimitations: %d \n\n",i,item_name,price,limit);
         }
     rewind(data);

    printf("\n\t\t\t\tIf you want return to Information menu. Press 0. -->  ");
       scanf("%d",&choice);
       if(choice==0){
            fclose(data);
            Foods_Limitation();
       }

    printf("\n\t\t\t\tEnter Food Items Name :  ");
    scanf("%s",Search_name);

    system("pause");
    system("cls");

    data2 = fopen("replica4.txt","w");

     while(fscanf(data,"\n%s %f %d",item_name,&price,&limit)!=EOF)
    {
        if(strcmp(Search_name,item_name)!=0)
        {
               fprintf(data2,"\n%s %f %d",item_name,price,limit);
        }
    }

    fclose(data);
    fclose(data2);

    remove("Burgers_Item.txt");
    rename("replica4.txt","Burgers_Item.txt");

    data=fopen("Burgers_Item.txt","r");
    if(data==NULL)
    {
       printf("Error!");
       exit(1);
    }

     printf("\n\t\t\t\tContent of file after modification : \n");
     i=0;
     printf("\t\t\t\tItem Name \t\t\tPrice \t\t\tLimitations\n\n");
     while(fscanf(data,"\n%s %f %d",item_name,&price,&limit)!=EOF)
         {
             i++;
             printf("\t\t\t\t%d. \t\tItem  : %s \t\tPrice : %.2f \t\tLimitations: %d \n\n",i,item_name,price,limit);
         }
    system("pause");

    fclose(data);
    Foods_Limitation();

}

void view_Burger_Item()
{
    system("cls");
    FILE *data;

    char item_name[20];
    float price;
    int limit,i=0;

    data=fopen("Burgers_Item.txt","r");
    if(data==NULL)
    {
       printf("Error!");
       exit(1);
    }
     printf("\t\t\t\tItem Name \t\t\tPrice \t\t\tLimitations\n\n");

     while(fscanf(data,"\n%s %f %d",item_name,&price,&limit)!=EOF)
         {
             i++;
              printf("\t\t\t\t%d. \t\tItem  : %s \t\tPrice : %.2f \t\tLimitations: %d \n\n",i,item_name,price,limit);

         }
    fclose(data);
    system("pause");
    Foods_Limitation();
}

void increase_Burger_quantty()
{
    system("cls");
    FILE *data,*data2;

    char item_name[20],Search_name[30];
    float price;
    int limit,newlimit,i=0,choice;

    data=fopen("Burgers_Item.txt","r");
    if(data==NULL)
    {
       printf("Error!");
       exit(1);
    }


     printf("\n\t\t\t\tContent of File Before modification : \n ");
     i=0;

     printf("\t\t\t\tItem Name \t\t\tPrice \t\t\tLimitations\n\n");

     while(fscanf(data,"\n%s %f %d",item_name,&price,&limit)!=EOF)
         {
             i++;
             printf("\t\t\t\t%d. \t\tItem  : %s \t\tPrice : %.2f \t\tLimitations: %d \n\n",i,item_name,price,limit);
        }
     rewind(data);

    printf("\n\t\t\t\tIf you want to continue. Press 1. or 0. -->  ");
       scanf("%d",&choice);
       if(choice==0){
            fclose(data);
            Foods_Limitation();
       }

    printf("\n\t\t\t\tEnter Food Items Name :  ");
    scanf("%s",Search_name);

    system("pause");
    //system("cls");

    data2 = fopen("replica4.txt","w");
     while(fscanf(data,"\n%s %f %d",item_name,&price,&limit)!=EOF)
     {
        if(strcmp(Search_name,item_name)==0)
        {
            printf("\n\t\t\t\tHow many burgers you want to add.\n\t\t\t\tEnter your Adding Number : ");
            scanf("%d",&newlimit);
            limit=limit+newlimit;
            fprintf(data2,"\n%s %f %d",item_name,price,limit);
        }
        else fprintf(data2,"\n%s %f %d",item_name,price,limit);
     }

    fclose(data);
    fclose(data2);

    remove("Burgers_Item.txt");
    rename("replica4.txt","Burgers_Item.txt");

    data2=fopen("Burgers_Item.txt","r");
    if(data2==NULL)
    {
       printf("Error!");
       exit(1);
    }

     printf("\n\t\t\t\tContent of file after modification : \n");
     i=0;
     printf("\t\t\t\tItem Name \t\t\tPrice \t\t\tLimitations\n\n");

     while(fscanf(data,"\n%s %f %d",item_name,&price,&limit)!=EOF)
         {
             i++;
             printf("\t\t\t\t%d. \t\tItem  : %s \t\tPrice : %.2f \t\tLimitations: %d \n\n",i,item_name,price,limit);
        }
    system("pause");

    fclose(data);
    Foods_Limitation();

}

void decrease_Burger_quantty()
{
    system("cls");
    FILE *data,*data2;

    char item_name[20],Search_name[30];
    float price;
    int limit,newlimit,i=0,choice;

    data=fopen("Burgers_Item.txt","r");
    if(data==NULL)
    {
       printf("Error!");
       exit(1);
    }


     printf("\n\t\t\t\tContent of File Before modification : \n ");
     i=0;
     printf("\t\t\t\tItem Name \t\t\tPrice \t\t\tLimitations\n\n");

     while(fscanf(data,"\n%s %f %d",item_name,&price,&limit)!=EOF)
         {
             i++;
             printf("\t\t\t\t%d. \t\tItem  : %s \t\tPrice : %.2f \t\tLimitations: %d \n\n",i,item_name,price,limit);
         }
     rewind(data);

    printf("\n\t\t\t\tIf you want to continue. Press 1. or 0. -->  ");
       scanf("%d",&choice);
       if(choice==0){
            fclose(data);
            Foods_Limitation();
       }

    printf("\n\t\t\t\tEnter Food Items Name :  ");
    scanf("%s",Search_name);

    system("pause");
    //system("cls");

    data2 = fopen("replica4.txt","w");
     while(fscanf(data,"\n%s %f %d",item_name,&price,&limit)!=EOF)
     {
        if(strcmp(Search_name,item_name)==0)
        {
            printf("\n\t\t\t\tHow many burgers you want to decrease.\n\t\t\t\tEnter your Deleting Number : ");
            scanf("%d",&newlimit);
            limit=limit-newlimit;
            fprintf(data2,"\n%s %f %d",item_name,price,limit);
        }
        else fprintf(data2,"\n%s %f %d",item_name,price,limit);
     }

    fclose(data);
    fclose(data2);

    remove("Burgers_Item.txt");
    rename("replica4.txt","Burgers_Item.txt");

    data2=fopen("Burgers_Item.txt","r");
    if(data2==NULL)
    {
       printf("Error!");
       exit(1);
    }

     printf("\n\t\t\t\tContent of file after modification : \n");
     i=0;
     printf("\t\t\t\tItem Name \t\t\tPrice \t\t\tLimitations\n\n");

     while(fscanf(data,"\n%s %f %d",item_name,&price,&limit)!=EOF)
         {
             i++;
             printf("\t\t\t\t%d. \t\tItem  : %s \t\tPrice : %.2f \t\tLimitations: %d \n\n",i,item_name,price,limit);

        }
    system("pause");

    fclose(data);
    Foods_Limitation();

}




void Kitchens_Information()
{
   system("cls");
   FILE *disply, *input, *output;
   int choice;

   printf("\n\t\t\t\t\t\t\t##         Kitchens Information        ##\n\n");
   printf("\n\t\t\t\tDisplay Food Limitation's Information    -- Press - 1\n");
   printf("\n\t\t\t\tDisplay Food Ingredient's Information    -- Press - 2\n");
   printf("\n\t\t\t\tDisplay Kitchen-Equipments Information   -- Press - 3\n");

   printf("\n\t\t\t\tGo back to Menu                          -- Press - 0\n");

   printf("\n\n\t\t\t\tEnter your choice :");
   scanf("%d",&choice);
   system("cls");

   switch(choice){
   case 1:
        kitchen_food_Info();
    break;
    case 2:
        kitchen_food_Info();
    break;

   case 3:
       kitchen_Equip_Info();
    break;

   case 0:
        menu();
    break;
   }

   system("pause");
   Kitchens_Information();
}

void kitchen_food_Info()
{
    system("cls");
    int choice;

   printf("\n\t\t\t\t\t\t\t##     Food Ingredients Information      ##\n\n");
   printf("\n\t\t\t\tDisplay All Data                 -- Press - 1\n");
   printf("\n\t\t\t\tAdd Information                  -- Press - 2\n");
   printf("\n\t\t\t\tDelete Informations              -- Press - 3\n\n");
   printf("\n\t\t\t\tGo back to Kitchens Information  -- Press - 0\n\n");

    printf("\t\t\t\tEnter your choice : ");
    scanf("%d",&choice);

    switch(choice){
   case 1:
        displayall_food_Info();
    break;
    case 2:
        add_food_Info();
    break;

   case 3:
       delete_food_Info();
    break;

   case 0:
      Kitchens_Information();
    break;

   }
    system("pause");
    kitchen_food_Info();

}

void displayall_food_Info()
{
    system("cls");

    FILE *food_info;

    char name[30];
    int i=1;

    food_info=fopen("Foods_Ingredient_data.txt","r");
    if(food_info==NULL)
    {
       printf("Error!");
       exit(1);
    }

    printf("\t\t\t\t\t\t\tInformations of all Food Ingredients  :\n");
    printf("\t\t\t\t---------------------------------------\n\n\n");

    while(fscanf(food_info,"\n%s",name)!=EOF)
         {
                printf("\t\t\t\t%d.   %s\n",i,name);
                i++;
         }


        fclose(food_info);
        system("pause");
        kitchen_food_Info();

}

void add_food_Info()
{
    FILE *food_info;
    char food_name[30];
    int ok=1;

    food_info=fopen("Foods_Ingredient_data.txt","a");

    while(1)
    {
      printf("\t\t\t\tEnter a new Food Item : ");
      scanf("%s",food_name);

      fprintf(food_info,"\n%s",food_name);
      printf("\t\t\t\tIf you want to Add more info. press 1 Or 2--> ");

      scanf("%d",&ok);
      if(ok==2)break;
    }

    fclose(food_info);
    system("pause");
    kitchen_food_Info();

}

void delete_food_Info()
{
    system("cls");
    FILE *food_info, *fp3;
    int choice;
    char name[30],Search_name[30];
    int i=0;

    food_info = fopen("Foods_Ingredient_data.txt","r");
    if(food_info==NULL)
    {
       printf("\t\t\t\tError!");
       exit(1);
    }


     printf("\n\t\t\t\tContent of File Before modification : \n ");
     i=0;
     while(fscanf(food_info,"\n%s",name)!=EOF)
         {
             i++;
             printf("\t\t\t\t%d. %s\n",i,name);
         }
       rewind(food_info);

       printf("\n\t\t\t\tIf you want return to Information menu. Press 0. -->  ");
       scanf("%d",&choice);
       if(choice==0){
            fclose(food_info);
            kitchen_food_Info();
       }

       printf("\n\t\t\t\tEnter Food Items Name :  ");
       scanf("%s",Search_name);
       system("pause");
       system("cls");

    fp3 = fopen("replica3.txt","w");
    while(fscanf(food_info,"\n%s",name)!=EOF)
    {
        if(strcmp(Search_name,name)!=0)
        {
               fprintf(fp3,"%s\n",name);
        }
    }

    fclose(food_info);
    fclose(fp3);

    remove("Foods_Ingredient_data.txt");
    rename("replica3.txt","Foods_Ingredient_data.txt");

    food_info=fopen("Foods_Ingredient_data.txt","r");
    if(food_info==NULL)
    {
       printf("Error!");
       exit(1);
    }

     printf("\n\t\t\t\tContent of file after modification : \n");
     i=0;
     while(fscanf(food_info,"\n%s",name)!=EOF)
         {
                i++;
                printf("\t\t\t\t%d. %s\n",i,name);
         }
    system("pause");

    fclose(food_info);
    kitchen_food_Info();
}



// Equipment.....
void kitchen_Equip_Info()
{
    system("cls");
    int choice;

   printf("\n\t\t\t\t\t\t\t##      Display Kitchen-Equipments Information       ##\n\n");
   printf("\n\t\t\t\tDisplay All Equipments Data                -- Press - 1\n");
   printf("\n\t\t\t\tAdd Information (Equipment)                -- Press - 2\n");
   printf("\n\t\t\t\tDelete Informations (Equipment)            -- Press - 3\n\n");
   printf("\n\t\t\t\tGo back to Kitchen-Equipments Information  -- Press - 0\n\n");

    printf("\n\t\t\t\tEnter your choice : ");
    scanf("%d",&choice);

    switch(choice){
   case 1:
        displayall_equip_Info();
    break;
   case 2:
        add_equip_Info();
    break;
   case 3:
       delete_equip_Info();
    break;

   case 0:
       Kitchens_Information();
    break;

   }
    system("pause");
    kitchen_Equip_Info();

}

void displayall_equip_Info()
{
    system("cls");

    FILE *equip_info;

    char name[30];
    int i=1;

    equip_info=fopen("Kitchen_Equipments_data.txt","r");
    if(equip_info==NULL)
    {
       printf("\t\t\t\tError!");
       exit(1);
    }

    printf("\t\t\t\t\t\t\t   Informations of all Kitchen Equipments   \n");
    printf("\t\t\t\t-----------------------------------------------\n\n\n");

    while(fscanf(equip_info,"\n%s",name)!=EOF)
         {
                printf("\t\t\t\t%d .     : %s \n",i,name);
                i++;
         }
         fclose(equip_info);

         system("pause");
         kitchen_Equip_Info();

}

void add_equip_Info()
{
    FILE *equip_info;
    char equip_name[30];
    int ok=1;

    equip_info=fopen("Kitchen_Equipments_data.txt","a");

    while(1)
    {
      printf("\t\t\t\tEnter a New Equipment's Name : ");
      scanf("%s",equip_name);
      fprintf(equip_info,"%s\n",equip_name);
      printf("\n\t\t\t\tIf you want to Add more info. press 1 Or 2--> ");
      scanf("%d",&ok);
      if(ok!=1)break;
    }
    fclose(equip_info);

    system("pause");
    kitchen_Equip_Info();
}

void delete_equip_Info()
{
    system("cls");
    FILE *equip_info,*fp4;
    int choice;
    char name[30],Search_equip_name[30];
    int i;

    equip_info = fopen("Kitchen_Equipments_data.txt","r");
    if(equip_info==NULL)
    {
       printf("\t\t\t\tError!");
       exit(1);
    }

    i=0;
    printf("\n\t\t\t\tContent of file Before modification : \n ");
    while(fscanf(equip_info,"\n%s",name)!=EOF)
         {
             i++;
             printf("\t\t\t\t%d. %s \n",i,name);
         }
    rewind(equip_info);

    printf("\n\n\t\t\t\tIf you want return to Information menu. Press '0' Or Press any number. -->  ");
    scanf("%d",&choice);
    if(choice==0){
         fclose(equip_info);
         kitchen_Equip_Info();
       }

    printf("\n\n\t\t\t\tEnter Food Items Name : ");
    scanf("%s",Search_equip_name);
    system("pause");
    system("cls");

    fp4 = fopen("replica4.txt","w");
    while(fscanf(equip_info,"\n%s",name)!=EOF)
    {
        if(strcmp(Search_equip_name,name)!=0)
        {
               fprintf(fp4,"%s\n",name);
        }
    }

    fclose(equip_info);
    fclose(fp4);

    remove("Kitchen_Equipments_data.txt");
    rename("replica4.txt","Kitchen_Equipments_data.txt");

    equip_info=fopen("Kitchen_Equipments_data.txt","r");
    if(equip_info==NULL)
    {
       printf("\t\t\t\tError!");
       exit(1);
    }

    i=0;
    printf("\n\t\t\t\tContent of file after modification : \n");
    while(fscanf(equip_info,"\n%s",name)!=EOF)
         {
                i++;
                printf("\t\t\t\t%d.  %s\n",i,name);
         }
    system("pause");

    fclose(equip_info);
    kitchen_Equip_Info();
}


void calculator()
{
   system("cls");

   double a1,a2;
   int choice;
   printf("\n\t\t\t\t\t\t\t##         Calculator        ##\n\n");
   printf("\t\t\t\tAddition       (+) -- Press - 1\n");
   printf("\t\t\t\tSubtraction    (-) -- Press - 2\n");
   printf("\t\t\t\tDivision       (/) -- Press - 3\n");
   printf("\t\t\t\tMultiplication (*) -- Press - 4\n");
   printf("\t\t\t\tSquare        (^2) -- Press - 5\n");
   printf("\t\t\t\tSquare Root        -- Press - 6\n");
   printf("\n\t\t\t\tGo To Main Menu    -- Press - 0\n");

   printf("\n\n\t\t\t\tEnter your choice :");
   scanf("%d",&choice);
   system("cls");

   switch(choice)
   {

   case 1:
       {
           printf("\n\t\t\t\tAddition :\n\n");
           printf("\t\t\t\tEnter 1st Number : ");
           scanf("%lf",&a1);
           printf("\t\t\t\tEnter 1st Number : ");
           scanf("%lf",&a2);
           printf("\n\t\t\t\tResult = %.2lf\n",a1+a2);
       }
    break;

    case 2:
       {
           printf("\n\t\t\t\tSubtraction :\n\n");
           printf("\t\t\t\tEnter 1st Number : ");
           scanf("%lf",&a1);
           printf("\t\t\t\tEnter 1st Number : ");
           scanf("%lf",&a2);
           printf("\n\t\t\t\tResult = %.2lf\n",a1-a2);
       }
    break;

    case 3:
       {
          printf("\n\t\t\t\tDivision :\n\n");
          printf("\t\t\t\tEnter 1st Number : ");
          scanf("%lf",&a1);
          printf("\t\t\t\tEnter 1st Number : ");
          scanf("%lf",&a2);
          printf("\n\t\t\t\tResult = %.2lf\n",a1/a2);
       }
    break;

    case 4:
       {
          printf("\n\t\t\t\tMultiplication :\n\n");
          printf("\t\t\t\tEnter 1st Number : ");
          scanf("%lf",&a1);
          printf("\t\t\t\tEnter 1st Number : ");
          scanf("%lf",&a2);
          printf("\n\t\t\t\tResult = %.2lf\n",a1*a2);
       }
    break;

    case 5:
       {
          printf("\n\t\t\t\tSquare  :\n\n");
          printf("\t\t\t\tEnter one Number : ");
          scanf("%lf",&a1);
          printf("\n\t\t\t\tResult = %.2lf\n",a1*a1);
       }
    break;

    case 6:
       {
          printf("\n\t\t\t\tSquare Root :\n\n");
          printf("\t\t\t\tEnter one Number : ");
          scanf("%lf",&a1);
          printf("\n\t\t\t\tResult = %.2lf\n",sqrt(a1));
       }
    break;

    case 0:
          menu();
    break;
   }

   system("pause");
   calculator();
}
