#include <stdio.h>
#include <stdlib.h>
#include "Contact.h"
#include "LLContacts.h"

int main() {
    char userChoice = 'y';
    char name[50];
    char phoneNum[50];
    llc contactList;
    char c;
     
    InitContactList(&contactList);
    
    while(userChoice != 'n') {
       
       printf("Enter name:\n");
       scanf(" %[^\t\n]s", name);

       c = getchar();
       while(c != '\n' && c != EOF) {
         c = getchar();
       }
       
       printf("Enter phone number:\n");
       scanf(" %[^\t\n]s", phoneNum);
       printf("\n");

       c = getchar();
       while(c != '\n' && c != EOF) {
          c = getchar();
       }

       InsertContact(&contactList, name, phoneNum);

       printf("Enter another contact? (y/n):\n");
       scanf(" %c", &userChoice);
       printf("\n");

    }

    printf("CONTACT LIST\n");

    DisplayContactList(&contactList);

    return 0;


}