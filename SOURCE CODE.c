#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>

void funseller();
void loginseller();
void sellermenu();
void addproperty();
void updateprop();
void del();
void funbuyer();
void loginbuyer();
void buyermenu();
void filter();
void report();
void displayprop();
void comment();
void viewcomment();
void admin();
void sellerdata();
void systemdata();
void buyerdata();
void search();
void filterbytype();
void displaysold();
void buyerpurchases();
void purchase();
//FILING FUNCTIONS
void saveSellerData();
void loadseller();
void savecomment();
void loadcomment();
void savebuyer();
void loadbuyer();
void saveprop();
void loadprop();

struct sale
{
    char name[20];
    int nic;
    int contact;
    char bank[30];
    char about[100];
} seller[100];

struct buy
{
    char name[20];
    int nic;
    int contact;
} buyer[100];

struct property
{
    char name[20];
    int propid;
    char loc[20];
    char type[20];
    float price;
    char status[10];
    int sellercontact;
    int sellerid;
    int buyerid;
    int buyercontact;
}prop[100];

struct commprop
{
    int pid;
    char commentby[30];
    char text[500];
}comm[500];

//GLOBAL VARIABLES
int sellercount=1;
int propertycount=1;
int currentseller;
int buyercount=1;
int currentbuyer;
int commentCount=0;
int fetchcheck=0;

int main()
{
    if(fetchcheck==0) //prevents multiple times data read due to main call
    {
    //DATA READ FUNCTION CALLS
    loadseller();
    loadcomment();
    loadbuyer();
    loadprop();
    fetchcheck=1;
    }

    int choice1;
    printf("\n\n\t\t\t\t\t\t\t************************************\n\n");
    printf("\t\t\t\t\t\t\t @PROPERTY SALES MANAGEMENT SYSTEM\n\n");
    printf("\t\t\t\t\t\t\t************************************\n\n");

    //MENU 1
    while(1)
    {
    printf("PLEASE SELECT YOUR SCOPE\n");
    printf("\n1) SELLER\n2) BUYER\n3) SYSTEM DATA\n4) GENERTAE REPORTS/INSIGHTS\n5) EXIT\n\n");
    scanf("%d", &choice1);
    system("cls");

    switch(choice1)
    {
        case 1:
        {
            funseller();
            sellermenu();
            break;
        }
        case 2:
        {
            funbuyer();
            break;
        }
        case 3:
        {
            admin();
            break;
        }
        case 4:
        {
            report();
            break;
        }
        case 5:
        {
            printf("\n\n\nTHANK YOU FOR USING @PROPERTY SALES MANAGEMENT SYSTEM\n\nEXIT SUCCESSFULL");
            saveSellerData();
            savecomment();
            savebuyer();
            saveprop();
            exit(0);
            break;
        }
        default:
        {
            printf("INVALID SELECTION\n");
            break;
        }
    }
    }
}
//--------------------------------------------------------------------------------------------------------
void funseller()
{
    printf("\n\n\t\t\t\tWELCOME TO PROPERTY SALES MANAGEMENT SYSTEM : SELLER SERVICES\n\n");
    printf("TO SALE PROPERTIES, YOU NEED TO REGISTER FIRST\n\nENTER YOUR STATUS\n\n");
    int choice;
    printf("1) REGISTER NOW!\n2) ALREADY REGISTERED: LOG IN\n3) EXIT\n\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
        {
            lab1:
            printf("ENTER A UNIQUE ID:(KEEP THIS ID PRIVATE)\n");
            scanf(" %d", &seller[sellercount].nic);
            for(int i=0;i<sellercount;i++)
            {
                if(seller[sellercount].nic == seller[i].nic)
                {
                    system("cls");
                    printf("ID ALREADY TAKEN\n");
                    goto lab1;
                }
            }
            printf("ENTER CONTACT NUMBER:\n");
            scanf(" %d", &seller[sellercount].contact);
            printf("ENTER YOUR NAME:\n");
            scanf("%s", seller[sellercount].name);
            printf("ENTER BANK IBAN NUMBER:\n");
            scanf("%s", seller[sellercount].bank);
            printf("LET BUYERS KNOW ABOUT YOU:\n");
            scanf("%s", seller[sellercount].about);
            system("cls");
            printf("\nYOU HAVE BEEN REGISTERED SUCCESSFULLY\n\nPROCEED TO LOG IN USING YOUR UNIQUE ID\n\n");
            sellercount++;
            loginseller();
            break;
        }
        case 2:
        {
            loginseller();
            break;
        }
        case 3:
        {
            system("cls");
            main();
        }
        default:
        {
            printf("INVALID INPUT\n");
            printf(" REDIRECTING \n");
            Sleep(1500);
            system("cls");
            funseller();
            break;
        }
    }
}
//--------------------------------------------------------------------------------------------------
void loginseller()
{
    int id,found=0;
            printf("PLEASE ENTER YOUR UNIQUE ID TO LOG IN:\n");
            scanf("%d", &id);
            for(int i=0;i<sellercount;i++)
            {
                if(id == seller[i].nic)
                {
                    found=1;
                    currentseller=id;
                    system("cls");
                    printf("\n\nWELCOME %s \n\n", seller[i].name);
                    printf("PLEASE WAIT\n\nYOU ARE BEING DIRECTED TO SELLER MENU\n\n");
                    Sleep(2000);
                    system("cls");
                }
            }
                if(found==0)
                {
                    printf("INVALID ID\n\n");
                    Sleep(1500);
                    system("cls");
                    funseller();
                }
}
//-------------------------------------------------------------------------------------------
void sellermenu()
{
    int choice;
    printf("\n1) ADD PROPERTY\n2) UPDATE PROPERTY\n3) DELETE PROPERTY\n4) EXIT\n\n");
    printf("\nENTER YOUR CHOICE:\n\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
    {
        addproperty();
        break;
    }
    case 2:
    {
         updateprop();
         break;
    }
    case 3:
    {
        del();
        break;
    }
    case 4:
    {
        system("cls");
        funseller();
    } 
    default:
    system("cls");
    printf("INVALID SELECTION\n\nREDIRECTING....\n\n");
    sellermenu();
        break;
    }

}
//--------------------------------------------------------------------------------------------
void addproperty()
{
    int add;
    while(1)
    {
        printf("ENTER PROPERTY UNIQUE ID(PUBLIC ID)\n");
        scanf("%d", &prop[propertycount].propid);
        for(int i=1;i<propertycount;i++)
        {
            if(prop[propertycount].propid == prop[i].propid)
            {
                system("cls");
                printf("\n\nID ALREADY TAKEN!\n\nPLEASE USE A UNIQUE ID\n\n");
                addproperty();
            }
        }
        printf("ENTER PROPERTY NAME\n");
        scanf(" %s", &prop[propertycount].name);
        printf("ENTER PROPERTY LOCATION\n");
        scanf(" %s", &prop[propertycount].loc);
        printf("ENTER PROPERTY TYPE\n");
        scanf(" %s", &prop[propertycount].type);
        printf("ENTER RETAIL PRICE\n");
        scanf(" %f", &prop[propertycount].price);
        printf("ENTER PROPERTY STATUS(ACTIVE/SOLD)\n");
        scanf("%s", &prop[propertycount].status);
        printf("ENTER YOUR CONTACT NUMBER\n");
        scanf("%d", &prop[propertycount].sellercontact);
        printf("\n\nPROPERTY ADDED SUCCESSFULLY\n\n");
        prop[propertycount].sellerid = currentseller;
        propertycount++;
        printf("PRESS 1 TO ADD ANOTHER PROPERTY OR 0 TO EXIT\n");
        scanf("%d", &add);
        if(add==0)
        {
            // printf("DIRECTING TO LAST MENU\n");
            // Sleep(2000);
            system("cls");
            sellermenu();
        }
    }
}


//--------------------------------------------------------------------------------

void updateprop()
{
    int update,found=0;
    printf("ENTER ID OF PROPERTY TO BE UPDATED\n");
    scanf("%d", &update);

    for(int i=1;i<propertycount;i++)
    {
        if( prop[i].propid==update && prop[i].sellerid==currentseller)
        {
            found = 1;
            printf("PROPERTY ID CANNOT BE CHANGED\n\n");
            printf("ENTER NEW PROPERTY NAME\n");
            scanf(" %s", &prop[i].name);
            printf("ENTER NEW PROPERTY LOCATION\n");
            scanf(" %s", &prop[i].loc);
            printf("ENTER NEW PROPERTY TYPE\n");
            scanf(" %s", &prop[i].type);
            printf("ENTER NEW RETAIL PRICE\n");
            scanf(" %f", &prop[i].price);
            printf("ENTER NEW PROPERTY STATUS(ACTIVE/SOLD)\n");
            scanf("%s", &prop[i].status);
            printf("\n\nPROPERTY UPDATED SUCCESSFULLY\n\n");
            printf("REDIRECTING....\n\n");
            Sleep(1200);
            system("cls");
            sellermenu();
        }
    }
    if(found==0)
    {
        printf("PROPERTY NOT FOUND OR YOU DO NOT HAVE PERMISSION TO UPDATE THIS PROPERTY\n\nREDIRECTING\n\n");
        Sleep(2000);
        system("cls");
        sellermenu();
    }

}
//-----------------------------------------------------------------------------------

void del()
{
    int delete,found=0;
    printf("\nENTER ID OF PROPERTY TO BE DELETED\n\n");
    scanf("%d", & delete);

    for(int i=1;i<propertycount;i++)
    {
        if(prop[i].sellerid==currentseller && delete==prop[i].propid)
        {
            prop[i]=prop[i+1];
            found=1;
            propertycount--;
            printf("PROPERTY DELETED SUCCESSFULLY\n\n");
            printf("DIRECTING TO LAST MENU\n");
            Sleep(2000);
            system("cls");
            sellermenu();
        }
    }
        if(found==0)
        {
        printf("PROPERTY NOT FOUND OR YOU DO NOT HAVE PERMISSION TO DELETE THIS PROPERTY\n\nREDIRECTING\n\n");
        Sleep(1400);
        system("cls");
        sellermenu;
        }
}
//-------------------------------------------------------------------------------------------------
void funbuyer()
{
        printf("\n\n\t\t\t\tWELCOME TO PROPERTY SALES MANAGEMENT SYSTEM : BUYER SERVICES\n\n");
    printf("TO BUY PROPERTIES, YOU NEED TO REGISTER FIRST\n\nENTER YOUR STATUS\n\n");
    int choice;
    printf("1) REGISTER NOW!\n2) ALREADY REGISTERED: LOG IN\n3) EXIT\n\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("ENTER A UNIQUE ID:\n");
            scanf(" %d", &buyer[buyercount].nic);
            printf("ENTER CONTACT NUMBER:\n");
            scanf(" %d", &buyer[buyercount].contact);
            printf("ENTER YOUR NAME:\n");
            scanf("%s", buyer[buyercount].name);
            printf("\nYOU HAVE BEEN REGISTERED SUCCESSFULLY\n\nPROCEED TO LOG IN USING YOUR UNIQUE ID\n\n");
            buyercount++;
            loginbuyer();
            break;
        case 2:
            loginbuyer();
            break;
        case 3:
            // printf("\n\nEXITING");
            // Sleep(1500);
            system("cls");
            main();
        default:
            printf("INVALID INPUT\n");
            printf(" REDIRECTING \n");
            Sleep(1500);
            system("cls");
            funbuyer();
            break;
    }
}
//-------------------------------------------------------------------------
void loginbuyer()
{
    int id, found = 0;
    printf("PLEASE ENTER YOUR UNIQUE ID TO LOG IN:\n");
    scanf("%d", &id);
    for(int i=1; i<buyercount; i++)
    {
        if(id == buyer[i].nic)
        {
            found = 1;
            currentbuyer = id;
            system("cls");
            printf("\n\nWELCOME %s \n\n", buyer[i].name);
           printf("PLEASE WAIT\n\nYOU ARE BEING DIRECTED TO BUYER MENU\n\n");
            Sleep(2000);
            system("cls");
            buyermenu();
        }
    }
    if(found == 0)
    {
        printf("INVALID ID\n\n");
        Sleep(1500);
        system("cls");
        funbuyer();
    }
}
//----------------------------------------------------------------------------------
void buyermenu()
{
    int choice;
    printf("PLEASE SELECT DESIRED FUNCTION\n\n");
    printf("1) VIEW PROPERTIES\n2) COMMENT ON PROPERTY\n3) FILTER PROPERTIES\n4) SEE COMMENTS\n5) SEARCH PROPERTY\n6) PURCHASE PROPERTY\n7) PURCHASES BU YOU\n8) EXIT\n\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
        {
            displayprop();
            break;
        }
        case 2:
        {
            comment();
            break;
        }
        case 3:
        {
           filter();
            break;
        }
        case 4:
        {
            viewcomment();
            break;
        }
        case 5:
        {
            search();
            break;
        }
        case 6:
        {
            purchase();
            break;
        }
        case 7:
        {
            buyerpurchases();
            break;
        }
        case 8:
        {
        // printf("EXITING......\n\n");
        // Sleep(2000);
        system("cls");
        main();
         break;
        }
        default:
        {
    system("cls");
    printf("INVALID SELECTION\n\nREDIRECTING....\n\n");
    Sleep(1200);
    buyermenu();
            break;
        }
    }
}
//-----------------------------------------------------------------------------------------------
void displayprop()
{
        printf("\n\nLIST OF AVAILABLE PROPERTIES:\n\n");
    for(int i=1; i<propertycount; i++)
    {
        if(strcmp(prop[i].status, "ACTIVE") == 0 || strcmp(prop[i].status, "active") == 0)
        {
            printf("Property ID: %d\n", prop[i].propid);
            printf("Name: %s\n", prop[i].name);
            printf("Location: %s\n", prop[i].loc);
            printf("Type: %s\n", prop[i].type);
            printf("Price: %.2f\n", prop[i].price);
            printf("Status: %s\n", prop[i].status);
            printf("Seller CONTACT: %d\n\n", prop[i].sellercontact);
        }
    }
    printf("PRESS ANY KEY TO RETURN TO BUYER MENU\n");
    getch();
    system("cls");
    buyermenu();
}
//------------------------------------------------------------------------------------------
void filter()
{
    int choice;
    printf("ENTER YOUR CHOICE: \n");
    printf("1) PRICE ABOVE 100K\n2) PRICE BELOW 100K\n3) FILTER BY TYPE\n\n");
    scanf("%d", &choice);
    if(choice == 1)
    {
            printf("LIST OF PROPERTIES WITH PRICE ABOVE 100K\n");
        for(int i=0;i<=propertycount;i++)
        {
            if(prop[i].price > 100000)
            {
            printf("Property ID: %d\n", prop[i].propid);
            printf("Name: %s\n", prop[i].name);
            printf("Location: %s\n", prop[i].loc);
            printf("Type: %s\n", prop[i].type);
            printf("Price: %.2f\n", prop[i].price);
            printf("Status: %s\n", prop[i].status);
            printf("Seller CONTACT: %d\n\n", prop[i].sellercontact);
            printf("-----------------------------------------\n");
            }
        }
            printf("PRESS ANY KEY TO CONTINUE\n");
            getch();
            buyermenu();
    }
    else if(choice == 2)
    {
                printf("LIST OF PROPERTIES WITH PRICE BELOW OR EQUAL TO 100K\n");
                for(int i=1;i<propertycount;i++)
        {
            if(prop[i].price <= 100000)
            {
            printf("Property ID: %d\n", prop[i].propid);
            printf("Name: %s\n", prop[i].name);
            printf("Location: %s\n", prop[i].loc);
            printf("Type: %s\n", prop[i].type);
            printf("Price: %.2f\n", prop[i].price);
            printf("Status: %s\n", prop[i].status);
            printf("Seller CONTACT: %d\n\n", prop[i].sellercontact);
            printf("-----------------------------------------\n");
            }
        }
            printf("PRESS ANY KEY TO CONTINUE\n");
            getch();
            buyermenu();
    }
    else if(choice==3)
    {
        filterbytype();
    }
    else
    {
        printf("INVALID CHOICE\n\nREDIRECTING\n\n");
        Sleep(1200);
        buyermenu();
    }

}
//-----------------------------------------------------------------------------------
void comment()
{
    int choice,found=0;
    printf("ENTER PROPERTY ID YOU WANT TO COMMENT ON:\n");
    scanf("%d", &choice);

    for(int i=0;i<=propertycount;i++)
    {
        if(prop[i].propid == choice)
        {
            comm[commentCount].pid = choice;
            printf("ENTER YOUR NAME:\n");
            scanf("%s", comm[commentCount].commentby);
            printf("ENTER YOUR COMMENT:\n");
            scanf(" %[^\n]%*c" , comm[commentCount].text);
            found=1;
            commentCount++;
            printf("\n\nCOMMENT ADDED SUCCESSFULLY\n\n");
            buyermenu();
        }
    }
    if(found==0)
    {
        system("cls");
        printf("PROPERTY NOT FOUND\n\nREDIRECTING\n\n");
        Sleep(1200);
        buyermenu();
    }
}
//--------------------------------------------------------------------------------------
void viewcomment()
{
    int choice,found=0;
    system("cls");
    printf("ENTER PROPERTY ID TO SEE COMMENTS:\n");
    scanf("%d", &choice);
    for(int i=0;i<=commentCount;i++)
    {
        if(comm[i].pid == choice)
        {
            printf("COMMENT ADDED BY: %s\n", comm[i].commentby);
            printf("COMMENT: %s\n" ,comm[i].text);
            printf("-----------------------------------------------------\n\n");
            found=1;

        }
    }
            printf("PRESS ANY KEY TO CONTINUE\n");
            getch();
            system("cls");
            buyermenu();
    if(found==0)
    {
        printf("INVALID PROPERTY ID OR NO COMMENTS FOUND ON REFERED PROPERTY\n\nREDIRECTING\n\n");
        Sleep(2000);
        system("cls");
        buyermenu();
    }
}
//-----------------------------------------------------------------------------------------------
void admin()
{
    int pin;
    char username[10], defualtuser[10]="mubi";
    printf("\n\nONLY ADMINS CAN ACESS SYSTEM DATA\n\n");

            printf("ENTER USERNAME\n\n");
            scanf("%s", &username);

            printf("ENTER PIN: ");
            scanf("%d", &pin);

            printf("\nVERIFYING CRENDENTIALS....... PLEASE WAIT\n\n");
            Sleep(2000);
            if(pin== 123 && strcmp(username, defualtuser)==0)
            {
                printf("\nACCESS GRANTED\n\n");
                systemdata();
            }
            else
            {
                printf("ACESS DENIED\n\nYOU WILL BE DIRECTED TO MAIN MENU SOON");
                Sleep(2000);
                system("CLS");
                main();
            }

}
//--------------------------------------------------------------------------------------
void systemdata()
{
    int choice;
    printf("ENTER YOUR CHOICE:\n");
    printf("1) SELLERS DATA\n2) BUYERS DATA\n3) EXIT\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
        {
            sellerdata();
            break;
        }
        case 2:
        {
            buyerdata();
            break;
        }
        case 3:
        {
            system("cls");
            main();
            break;
        }
        default:
        {
            printf("INVALID CHOICE\n");
            systemdata();
            break;
        }
    }
}
//------------------------------------------------------------------------------------------
void sellerdata()
{
        system("cls");
        printf("ALL SELLERS : \n\n\n");
    for(int i=1;i<sellercount;i++) 
    {
        printf("NAME: %s\n", seller[i].name);
        printf("ID: %d\n", seller[i].nic);
        printf("CONTACT NUMBER: %d\n", seller[i].contact);
        printf("BANK IBAN: %s\n", seller[i].bank);
        printf("ABOUT: %s\n", seller[i].about);
        printf("\n-------------------------------------------------------\n");
    }
    printf("PRESS ANY KEY TO CONTINUE\n");
    getch();
    systemdata();
}
//-----------------------------------------------------------------------------------------
void buyerdata()
{
        system("cls");
        printf("ALL BUYERS : \n\n\n");
        for(int i=1;i<buyercount;i++)
        {
        printf("NAME: %s\n", buyer[i].name);
        printf("ID: %d\n", buyer[i].nic);
         printf("CONTACT NUMBER: %d\n", buyer[i].contact);
        printf("\n-------------------------------------------------------\n");
        }
            printf("PRESS ANY KEY TO CONTINUE\n");
    getch();
    systemdata();
}
//----------------------------------------------------------------------------------------------

void saveSellerData()
{
    FILE *file;
    file = fopen("sellerdat.txt", "w");
    if(file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
    fprintf(file,"TOTAL SELLERS= %d\n\n", sellercount);
    for(int i = 1; i < sellercount; i++)
    {
        fprintf(file, "%d\n", seller[i].nic);
        fprintf(file, "%s\n", seller[i].name);
        fprintf(file, "%d\n", seller[i].contact);
        fprintf(file, "%s\n", seller[i].bank);
        fprintf(file, "%s\n", seller[i].about);
        fprintf(file, "-----------------------------------------------------------\n\n");
    }
    fclose(file);
}
//----------------------------------------------------------------------------------------------------------
void loadseller()
{
    FILE *file;
    file = fopen("sellerdat.txt", "r");
    if(file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
    fscanf(file, "TOTAL SELLERS= %d\n\n", &sellercount);
    for(int i = 1; i< sellercount; i++)
    {
        fscanf(file, "%d\n", &seller[i].nic);
        fscanf(file, "%s\n", seller[i].name);
        fscanf(file, "%d\n", &seller[i].contact);
        fscanf(file, "%s\n", seller[i].bank);
        fscanf(file, "%s\n", seller[i].about);
        fscanf(file, "-----------------------------------------------------------\n\n");
    }
    fclose(file);
}
//--------------------------------------------------------------------------------------
void savecomment()
{
    FILE *file;
    file = fopen("comment.txt", "w");
    if(file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
    fprintf(file,"TOTAL COMMENTS= %d\n\n", commentCount);
    for(int i = 0; i < commentCount; i++)
    {
        fprintf(file,"PROPERTY ID = %d\n",comm[i].pid);
        fprintf(file,"COMMENT ADDED BY: %s\n", comm[i].commentby);
        fprintf(file,"COMMENT = %s\n ", comm[i].text);
        fprintf(file, "-----------------------------------------------------------\n\n");
    }
    fclose(file);
}
//------------------------------------------------------------------------------------
void loadcomment()
{
    FILE *file;
    file = fopen("comment.txt", "r");
    if(file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
    fscanf(file,"TOTAL COMMENTS= %d\n\n", &commentCount);
    for(int i = 0; i < commentCount; i++)
    {
        fscanf(file,"PROPERTY ID = %d\n", &comm[i].pid);
        fscanf(file,"COMMENT ADDED BY: %s\n", &comm[i].commentby);
        fscanf(file,"COMMENT = %s\n ", &comm[i].text);
        fscanf(file, "-----------------------------------------------------------\n\n");
    }
    fclose(file);
}
//----------------------------------------------------------------------------------------
void savebuyer()
{
    FILE *file;
    file =fopen("buyerdata.txt", "w");
        if(file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
        fprintf(file,"TOTAL BUYERS= %d\n\n", buyercount);
    for(int i = 1; i < buyercount; i++)
    {
        fprintf(file,"%s\n",buyer[i].name);
        fprintf(file,"%d\n",buyer[i].contact);
        fprintf(file,"%d\n", buyer[i].nic);
        fprintf(file, "-----------------------------------------------------------\n\n");
    }
    fclose(file);
}
//--------------------------------------------------------------------------------------
void loadbuyer()
{
    FILE *file;
    file =fopen("buyerdata.txt", "r");
        if(file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
    fscanf(file,"TOTAL BUYERS= %d\n\n", &buyercount);
    for(int i = 1; i <= buyercount; i++)
    {
        fscanf(file,"%s\n",buyer[i].name);
        fscanf(file,"%d\n",&buyer[i].contact);
        fscanf(file,"%d\n", &buyer[i].nic);
        fscanf(file, "-----------------------------------------------------------\n\n");
    }
    fclose(file);
}
//-----------------------------------------------------------------------------------------------
void saveprop()
{
    FILE *file;
    file = fopen("propdata.txt","w");
            if(file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
    fprintf(file,"TOTAL PROPERTIES= %d\n\n", propertycount);
        for(int i = 1; i < propertycount; i++)
        {
        fprintf(file,"%s\n", prop[i].name);
        fprintf(file,"%d\n", prop[i].sellerid);
        fprintf(file,"%s\n", prop[i].loc);
        fprintf(file,"%s\n", prop[i].status);
        fprintf(file,"%s\n", prop[i].type);
        fprintf(file,"%f\n", prop[i].price);
        fprintf(file,"%d\n", prop[i].propid);
        fprintf(file,"%d\n", prop[i].sellercontact);
        fprintf(file,"%d\n", prop[i].buyerid);
        fprintf(file,"%d\n", prop[i].buyercontact);
        // fprintf(file,"-------------------------------------------------\n\n");
        }
        fclose(file);
}
//-----------------------------------------------------------------------------------------
void loadprop()
{
    FILE *file;
    file = fopen("propdata.txt","r");
            if(file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
    fscanf(file,"TOTAL PROPERTIES= %d\n\n", &propertycount);
        for(int i = 1; i < propertycount; i++)
        {
        fscanf(file,"%s\n", &prop[i].name);
        fscanf(file,"%d\n", &prop[i].sellerid);
        fscanf(file,"%s\n", &prop[i].loc);
        fscanf(file,"%s\n", &prop[i].status);
        fscanf(file,"%s\n", &prop[i].type);
        fscanf(file,"%f\n", &prop[i].price);
        fscanf(file,"%d\n", &prop[i].propid);
        fscanf(file,"%d\n", &prop[i].sellercontact);
        fscanf(file,"%d\n", &prop[i].buyerid);
        fscanf(file,"%d\n", &prop[i].buyercontact);
        }
        fclose(file);
}
//------------------------------------------------------------------------------------------------
void report()
{
    int choice;
    printf("ENTER YOUR CHOICE\n");
    printf("1) TOTAL SELLERS\n2) TOTAL BUYERS\n3) TOTAL PROPERTIES\n4) DISPLAY SOLD PROPERTIES\n5) EXIT\n\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
        {
            printf("\nTOTAL SELLERS: %d\n", sellercount-1);
            printf("PRESS ANY KEY TO CONTINUE\n");
            getch();
            system("cls");
            report();
        }
        case 2:
        {
            printf("\nTOTAL BUYERS: %d\n", buyercount-1);
            printf("PRESS ANY KEY TO CONTINUE\n");
            getch();
            system("cls");
            report();
        }
        case 3:
        {
            printf("\nTOTAL PROPERTIES: %d\n", propertycount-1);
            printf("PRESS ANY KEY TO CONTINUE\n");
            getch();
            system("cls");
            report();
        }
        case 4:
        {
            displaysold();
            break;
        }
        case 5:
        {
            system("cls");
            main();
        }
        default:
        {
            printf("INVALID CHOICE\n");
            printf("REDIRECTING\n");
            Sleep(1200);
            report();
        }
    }
}
//-------------------------------------------------------------------------------------------------
void search()
{
    system("cls");
    int byid,cont=1;
        int chk=0;
    while(1)
    {
    printf("ENTER ID TO FIND PROPERTY\n");
    scanf("%d", &byid);
    for(int i=1;i<propertycount;i++)
    {
        if(byid == prop[i].propid)
        {
            printf("RECORD FOUND\n\n");
            printf("Property ID: %d\n", prop[i].propid);
            printf("Name: %s\n", prop[i].name);
            printf("Location: %s\n", prop[i].loc);
            printf("Type: %s\n", prop[i].type);
            printf("Price: %.2f\n", prop[i].price);
            printf("Status: %s\n", prop[i].status);
            printf("Seller CONTACT: %d\n\n", prop[i].sellercontact);
            chk=1;
        }

    }
            if(chk==0)
        {
            printf("\nNO PROPERTY FOUND AGAINST GIVEN ID\n");
        }
    printf("ENTER 0 TO GO TO MAIN MENU OR (ANY OTHER DIGIT TO CONTINUE SEARCHING)\n");
    scanf("%d", &cont);
    if(cont==0)
    {    
    printf("PLEASE WAIT ... YOU ARE BEING DIRECTED TO MAIN MENU\n");
    Sleep(2000);
    system("cls");
    buyermenu();
    }
    }
}
//---------------------------------------------------------------------------------------
void filterbytype()
{
    int choice;
    puts("ENTER YOUR CHOICE:");
    puts("1) PLOT\n2) ROOM\n3) CABIN\n4) AGRICULTURE");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
        {
            for(int i=1;i<propertycount;i++)
            {
            if(stricmp(prop[i].type,"plot")==0)
            {
            printf("Property ID: %d\n", prop[i].propid);
            printf("Name: %s\n", prop[i].name);
            printf("Location: %s\n", prop[i].loc);
            printf("Type: %s\n", prop[i].type);
            printf("Price: %.2f\n", prop[i].price);
            printf("Status: %s\n", prop[i].status);
            printf("Seller CONTACT: %d\n\n", prop[i].sellercontact);
            printf("-----------------------------------------\n");
            }
            }
            printf("PRESS ANY KEY TO CONTINUE\n");
            getch();
            buyermenu();
            break;
        }
        case 2:
        {
            
            for(int i=1;i<propertycount;i++)
            {
            if(stricmp(prop[i].type,"room")==0)
            {
            printf("Property ID: %d\n", prop[i].propid);
            printf("Name: %s\n", prop[i].name);
            printf("Location: %s\n", prop[i].loc);
            printf("Type: %s\n", prop[i].type);
            printf("Price: %.2f\n", prop[i].price);
            printf("Status: %s\n", prop[i].status);
            printf("Seller CONTACT: %d\n\n", prop[i].sellercontact);
            printf("-----------------------------------------\n");
            }
            }
            printf("PRESS ANY KEY TO CONTINUE\n");
            getch();
            buyermenu();
            break;
        }
        case 3:
        {
            for(int i=1;i<propertycount;i++)
            {
            if(stricmp(prop[i].type,"cabin")==0)
            {
            printf("Property ID: %d\n", prop[i].propid);
            printf("Name: %s\n", prop[i].name);
            printf("Location: %s\n", prop[i].loc);
            printf("Type: %s\n", prop[i].type);
            printf("Price: %.2f\n", prop[i].price);
            printf("Status: %s\n", prop[i].status);
            printf("Seller CONTACT: %d\n\n", prop[i].sellercontact);
            printf("-----------------------------------------\n");
            }
            }
                        printf("PRESS ANY KEY TO CONTINUE\n");
            getch();
            buyermenu();
            break;
        }
        case 4:
        {
            for(int i=1;i<propertycount;i++)
            {
            if(stricmp(prop[i].type,"agriculture")==0)
            {
            printf("Property ID: %d\n", prop[i].propid);
            printf("Name: %s\n", prop[i].name);
            printf("Location: %s\n", prop[i].loc);
            printf("Type: %s\n", prop[i].type);
            printf("Price: %.2f\n", prop[i].price);
            printf("Status: %s\n", prop[i].status);
            printf("Seller CONTACT: %d\n\n", prop[i].sellercontact);
            printf("-----------------------------------------\n");
            }
            }
            printf("PRESS ANY KEY TO CONTINUE\n");
            getch();
            buyermenu();
            break;
        }
        default:
        {
        printf("INVALID CHOICE\n\nREDIRECTING\n\n");
        Sleep(1200);
        system("cls");
        buyermenu();
            break;
        }
        }
    }
    //---------------------------------------------------------------------------------
    void purchase()
    {
        int id,found=0;
        puts("ENTER ID OF PROPERTY YOU WANT TO PURCHASE");
        scanf("%d", &id);
        for(int i=1;i<propertycount;i++)
        {
            if(prop[i].propid==id && (stricmp(prop[i].status,"active")==0))
            {
            prop[i].buyerid = currentbuyer;
            prop[i].buyercontact = buyer[currentbuyer].contact;
            strcpy(prop[i].status, "SOLD");
            found=1;
            puts("PROPERTY PURCHASE SUCCESSFUL");
                    printf("Press any key to continue...\n");
    getch();
    system("cls");
    buyermenu();
            }
        }
        if (found==0) {
        printf("Property not found or already sold.\n");
        printf("Press any key to continue...\n");
    getch();
    system("cls");
    buyermenu();
    }
    }
    //-----------------------------------------------------------------------------------------
    void displaysold()
    {
        {
        printf("\n\nLIST OF SOLD PROPERTIES:\n\n");
    for(int i=1; i<=propertycount; i++)
    {
        if(strcmp(prop[i].status, "sold") == 0 || strcmp(prop[i].status, "SOLD") == 0)
        {
            printf("Property ID: %d\n", prop[i].propid);
            printf("Name: %s\n", prop[i].name);
            printf("Location: %s\n", prop[i].loc);
            printf("Type: %s\n", prop[i].type);
            printf("Price: %.2f\n", prop[i].price);
            printf("Status: %s\n", prop[i].status);
            printf("Seller CONTACT: %d\n\n", prop[i].sellercontact);
        }
    }
    printf("PRESS ANY KEY TO RETURN TO BUYER MENU\n");
    getch();
    system("cls");
    report();
}
    }
    //---------------------------------------------------------------------------
    void buyerpurchases()
    {
        puts("<YOU PURCHASED FOLLOWING PROPERTIES>");
        for(int i=1;i<propertycount;i++)
        {
            if(stricmp(prop[i].status,"sold")==0 && prop[i].buyerid==currentbuyer)
            {
            printf("Property ID: %d\n", prop[i].propid);
            printf("Name: %s\n", prop[i].name);
            printf("Location: %s\n", prop[i].loc);
            printf("Type: %s\n", prop[i].type);
            printf("Price: %.2f\n", prop[i].price);
            printf("Status: %s\n", prop[i].status);
            printf("Seller CONTACT: %d\n\n", prop[i].sellercontact);
            printf("SOLD TO BUYER ID: %d\n", currentbuyer);
            }
        }
    printf("PRESS ANY KEY TO RETURN TO BUYER MENU\n");
    getch();
    system("cls");
    buyermenu();
    }
    //-------------------------------------------------------------------------------------------