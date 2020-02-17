#include "Contact.h"
#include "LLContacts.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void InitContactList(llc* l) {    
    l->head = NULL;
    l->size = 0;
}

void InsertContact(llc* l, char* name, char* phoneNum) {
    ContactNode* current;
    ContactNode* next;
    ContactNode* new;
    ContactNode* previous;
    int a = 0;

    next = (ContactNode*)malloc(sizeof(ContactNode));
    new = (ContactNode*)malloc(sizeof(ContactNode));
    previous = (ContactNode*)malloc(sizeof(ContactNode));
    current = (ContactNode*)malloc(sizeof(ContactNode));


    //changes name to uppercase
    for(int i = 0; i < strlen(name); i++) {
       name[i] = toupper(name[i]);
    }

    
    //if the list is empty
    if(l->head == NULL) {
        l->head = (ContactNode*)malloc(sizeof(ContactNode));
        strcpy(l->head->contactName, name); 
        strcpy(l->head->contactPhoneNum, phoneNum);
        l->head->nextNodePtr = NULL;
    }

    else {   
        current = l->head;

        while((strcmp(current->contactName, name) < 0) && current->nextNodePtr != NULL) {
             previous = current; 
             current = current->nextNodePtr;
             a++;
        }

        //adds to the end of the list
        if(current->nextNodePtr == NULL && (strcmp(current->contactName, name) < 0)) {
            current->nextNodePtr = (ContactNode*)malloc(sizeof(ContactNode));
            next = current->nextNodePtr;
            strcpy(next->contactName, name); 
            strcpy(next->contactPhoneNum, phoneNum);
        }
        //if adding to the front of the list
        else if(a == 0) {
            l->head = new;
            l->head->nextNodePtr = current;

            strcpy(l->head->contactName, name);
            strcpy(l->head->contactPhoneNum, phoneNum);
        }
        //inserts somewhere in the middle of the list
        else {        
        
            previous->nextNodePtr = new;
            new->nextNodePtr = current;

            strcpy(new->contactName, name);
            strcpy(new->contactPhoneNum, phoneNum);
        }
    }

    l->size++;

}

void DisplayContactList(llc* l) {
    ContactNode* current = l->head;
    
    if(strcmp(current->contactName, "Empty") == 0) {
        printf("Contact List is empty\n");
    }
    else {
        for(int i = 0 ; i < l->size; i++) {
            printf("%s   %s\n", current->contactName, current->contactPhoneNum);
            current = current->nextNodePtr;
        }
    }
}