/* ONLINE BANK OF IIITDM KANCHEEPURAM */
#include<stdio.h>
#include<stdlib.h>

//global variables
int i,j;
int main_exit;
void menu();
int atm();
void close();

//structure for date
struct date
{
    int month,day,year;
};

struct
{
    char name[60];
    int acc_no,age;
    char address[60];
    char aadhar[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date withdraw;
}add,upd,check,rem,transaction;

//function to create a new account
void new_acc()
{
    int choice;
    FILE *ptr;
//opening file
    ptr=fopen("record.dat","a+");
    account_no:
    system("cls");
    printf("\t\t\t     ADD RECORD");
    printf("\nEnter the account number:");
    scanf("%d",&check.acc_no);
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.aadhar,&add.phone,add.acc_type,&add.amt)!=EOF)
    {
        if (check.acc_no==add.acc_no)
                goto account_no;
    }
//entering personal details
    add.acc_no=check.acc_no;
    printf("\nEnter the name:");
    scanf("%s",add.name);
    printf("\nEnter the date of birth(dd/mm/yyyy):");
    scanf("%d/%d/%d",&add.dob.day,&add.dob.month,&add.dob.year);
    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nEnter the address:");
    scanf("%s",add.address);
    printf("\nEnter Aadhar Number:");
    scanf("%s",add.aadhar);
    printf("\nEnter the phone number: ");
    scanf("%lf",&add.phone);
    printf("\nEnter the amount to deposit:");
    scanf("%f",&add.amt);
    printf("\nType of account:\n\t[1]Saving\n\t[2]Current\n\t[3]Fixed1(for 1 year)\n\t[4]Fixed2(for 2 years)\n\t[5]Fixed3(for 3 years)\n\n\tEnter your choice:");
    scanf("%s",add.acc_type);
    fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.aadhar,add.phone,add.acc_type,add.amt);
    fclose(ptr);
    printf("\nAccount created successfully!");

    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");

    if (main_exit==1)
        menu();
    else if(main_exit==0)
        close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}

//function to view customers' list
void view_list()
{
    FILE *view;
//opening file
    view=fopen("record.dat","r");
    int test=0;
    system("cls");
    printf("\nACCOUNT NUMBER \t\tNAME\t\t\t\tADDRESS\t\t\t\tPHONE\n");
    while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.aadhar,&add.phone,add.acc_type,&add.amt)!=EOF)
       {
           printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf",add.acc_no,add.name,add.address,add.phone);
           test++;
       }

    fclose(view);
    if (test==0)
        {
          system("cls");
          printf("\nNO RECORDS!!\n");
        }

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}

//function to edit customer details
void edit(void)
{
    int choice,test=0;
    FILE *old,*newrec;
//opening file
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

    printf("\nEnter the account no. of the customer whose info you want to change:");
    scanf("%d",&upd.acc_no);
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.aadhar,&add.phone,add.acc_type,&add.amt)!=EOF)
    {
        if (add.acc_no==upd.acc_no)
        {
            test=1;
            printf("\nWhich information do you want to change?\n[1]Address\n[2]Phone\n\n");
            scanf("%d",&choice);
            system("cls");
            if(choice==1)
                {
                  printf("Enter the new address:");
                  scanf("%s",upd.address);
                  fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,upd.address,add.aadhar,add.phone,add.acc_type,add.amt);
                  system("cls");
                  printf("Changes saved!");
                }
            else if(choice==2)
                {
                  printf("Enter the new phone number:");
                  scanf("%lf",&upd.phone);
                  fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.aadhar,upd.phone,add.acc_type,add.amt);
                  system("cls");
                  printf("Changes saved!");
                }

        }
        else
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.aadhar,add.phone,add.acc_type,add.amt);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

    if(test!=1)
        {
            system("cls");
            printf("\nRecord not found!!\a\a\a");
            edit_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    edit();
                else
                    {printf("\nInvalid!\a");
                    goto edit_invalid;}
        }
     else
        {
            printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
            scanf("%d",&main_exit);
            system("cls");
            if (main_exit==1)
                  menu();
            else
                  close();
        }
}

//functions to avail transactions
void transact(void)
{   int choice,test=0;
//opening file
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the account no. of the customer:");
    scanf("%d",&transaction.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.aadhar,&add.phone,add.acc_type,&add.amt)!=EOF)
   {

            if(add.acc_no==transaction.acc_no)
            {   test=1;
                if(strcmpi(add.acc_type,"fixed1")==0||strcmpi(add.acc_type,"fixed2")==0||strcmpi(add.acc_type,"fixed3")==0)
                {
                    printf("\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                    system("cls");
                    menu();

                }
                printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
                scanf("%d",&choice);
                if (choice==1)
                {
                    printf("Enter the amount you want to deposit:$ ");
                    scanf("%f",&transaction.amt);
                    add.amt+=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.aadhar,add.phone,add.acc_type,add.amt);
                    printf("\n\nDeposited successfully!");
                }
                else
                {
                    printf("Enter the amount you want to withdraw:$ ");
                    scanf("%f",&transaction.amt);
                    add.amt-=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.aadhar,add.phone,add.acc_type,add.amt);
                    printf("\n\nWithdrawn successfully!");
                }

            }
            else
               fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.aadhar,add.phone,add.acc_type,add.amt);
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test!=1)
   {
       printf("\n\nRecord not found!!");
       transact_invalid:
      printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
      scanf("%d",&main_exit);
      system("cls");
      if (main_exit==0)
        transact();
    else if (main_exit==1)
        menu();
    else if (main_exit==2)
        close();
    else
    {
        printf("\nInvalid!");
        goto transact_invalid;
    }

   }
   else
   {
       printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
   }

}

//function to remove accounts
void erase(void)
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the account no. of the customer you want to delete:");
    scanf("%d",&rem.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.aadhar,&add.phone,add.acc_type,&add.amt)!=EOF)
   {
        if(add.acc_no!=rem.acc_no)
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.aadhar,add.phone,add.acc_type,add.amt);

        else
            {test++;
            printf("\nRecord deleted successfully!\n");
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test==0)
        {
            printf("\nRecord not found!!\a\a\a");
            erase_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);

                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    erase();
                else
                    {printf("\nInvalid!\a");
                    goto erase_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
        }

}

//function to check details of a particular account
void see(void)
{
    FILE *ptr;
    int test=0,rate;
    int choice;
    float time;
    float intrst;
    ptr=fopen("record.dat","r");
    printf("Do you want to check by\n1.Account no\n2.Name\nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("Enter the account number:");
        scanf("%d",&check.acc_no);
        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.aadhar,&add.phone,add.acc_type,&add.amt)!=EOF)
        {
            if(add.acc_no==check.acc_no)
            {   system("cls");
                test=1;
                printf("\nAccount NO.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nAadhar No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$ %.2f \nDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.aadhar,add.phone,
                add.acc_type,add.amt);
            }
        }
    }
    else if (choice==2)
    {   printf("Enter the name:");
        scanf("%s",&check.name);
        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.aadhar,&add.phone,add.acc_type,&add.amt)!=EOF)
        {
            if(strcmpi(add.name,check.name)==0)
            {   system("cls");
                test=1;
                printf("\nAccount No.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nAadhar No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$%.2f \nDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.aadhar,add.phone,
                add.acc_type,add.amt);
            }
        }
    }

    fclose(ptr);
     if(test!=1)
        {
            system("cls");
            printf("\nRecord not found!!\a\a\a");
            see_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    see();
                else
                    {
                        system("cls");
                        printf("\nInvalid!\a");
                        goto see_invalid;
                    }
         }
    else
        {
            printf("\nEnter 1 to go to the main menu and 0 to exit:");
            scanf("%d",&main_exit);
        }
        if (main_exit==1)
        {
            system("cls");
            menu();
        }

        else
           {
             system("cls");
             close();
           }

}

//function to show up menu of options
void menu(void)
{   int choice;
    printf("\n\n\t\t\t       WELCOME TO BANK OF IIITDM KANCHEEPURAM");
    printf("\n\n\n\t\t WELCOME TO THE MAIN MENU");
    printf("\n\n\t\t[1] Create a new account\n\t\t[2] Update information of existing account\n\t\t[3] Transactions\n\t\t[4] Check the details of existing account\n\t\t[5] Remove existing account\n\t\t[6] View customer's list\n\t\t[7] ATM Feature\n\t\t[8] Exit\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);
    system("cls");
    switch(choice)
    {
        case 1:new_acc();
        break;
        case 2:edit();
        break;
        case 3:transact();
        break;
        case 4:see();
        break;
        case 5:erase();
        break;
        case 6:view_list();
        break;
        case 7:atm();
        break;
        case 8:close();
        break;
    }
}

//function to avail ATM
int atm()
{
    int option;
    float balance = 15000.00;
    int choose;

void mainMenu()
{
    printf("\n\n\t\t          Welcome to IIITDM ATM\n\n\n\t\t    Select your Option\n\n\t\t[1]  Check Balance\n\t\t[2]  Deposit\n\t\t[3]  Withdraw\n\t\t[4]  Exit\n\n");
}

//function to display balance
void checkBalance(float balance)
{
    printf("Your Available Balance is:   $%.2f\n\n", balance);
    printf("Take your receipt!!!\nThank you for using ATM!!!\n");
}

//function to deposit money
float moneyDeposit(float balance)
{
    float deposit;
    printf("Your Balance is: $%.2f\n\n", balance);
    printf("Enter your amount to Deposit\n");
    scanf("%f", &deposit);

    //adding money to the balance
    balance += deposit;
    printf("Your New Balance is:   $%.2f\n\n", balance);
    printf("Take your receipt!!!\nThank you for using ATM!!!\n");
    return balance;
}

//function to withdraw money
float moneyWithdraw(float balance)
{
    float withdraw;
    printf("Your Balance is: $%.2f\n\n", balance);
    printf("Enter your amount to withdraw:\n");
    scanf("%f", &withdraw);

    if (withdraw < balance)
    {
        balance -= withdraw;
        printf("Your withdrawing money is:  $%.2f\n", withdraw);
        printf("Your New Balance is:   $%.2f\n\n", balance);

    }
    else
    {
        printf("You don't have enough money\n");
        printf("Please contact to your Bank Customer Services\n");
        printf("Your Balance is:   $%.2f\n\n", balance);
    }
    printf("Take your receipt!!!\nThank you for using ATM!!!\n");
    return balance;
}

//function for login pin
int login(void)
{
  float number = 1234;
  int pass;
  printf("\n\n\t\t\tEnter the PIN No:");
  scanf("%d", &pass);

  if (pass == number)
    {
      printf("\n\nPIN Matched!\n");
      system("cls");
      mainMenu();
    }
  else
    {
      printf("Invalid Pin!!! Try Again");
      login();
    }
  return 0;
}
    login();

    printf("\nYour Selection:\t");
    scanf("%d", &option);
    system("cls");

    switch (option)
    {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                balance = moneyDeposit(balance);
                break;
            case 3:
                balance = moneyWithdraw(balance);
                break;
            case 4:
                printf("Take your receipt!!!\nThank you for using ATM!!!\n");
                return 0;
            default:
                printf("!!!Invalid Choice!!!\n");
                break;
    }
    printf("\nWould you like to do another transaction:\n");
    printf("[1] Yes\n");
    printf("[2] No\n");
    scanf("%d", &choose);
    system("cls");

    if (choose == 2)
            printf("Take your receipt!!!\nThank you for using ATM!!!\n");
    else
        	mainMenu();
    return 0;
}

//main function
int main()
{
    menu();
    return 0;
}

