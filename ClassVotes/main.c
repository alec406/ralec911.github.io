#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Names_Struct {
    char name[50];
    int rank;
    int votes;
} Names;

int main(int argc, char *argv[]) {
    FILE* inFile = NULL;
    Names classMates[56];
    int index = 0;
    char lastName[50];
    char firstName[50];
    char space[5];
    int userChoice = -1;
    int indexBiggest;
    Names temp;

    //opens file
    inFile = fopen(argv[1], "r");

    if(inFile == NULL) {
        printf("File could not be opened\n");
        return -1;
    }
    
    //reads the line of the files
    while(!feof(inFile)) {
        fscanf(inFile, " %[^\n]s", classMates[index].name);
 
        classMates[index].rank = (index+1);
        classMates[index].votes = 0;
        index++; 
   
     } 

     fclose(inFile);

    //loops until user chooses to quit
    while(userChoice != 0) {

        //selection sort
        for (int i = 0; i < 54; i++) {
           // Find index of smallest remaining element
           indexBiggest = i;
           for (int j = i + 1; j < 54; j++) {
         
             if (classMates[j].votes > classMates[indexBiggest].votes ) {
                indexBiggest = j;
            }
       }
      
         // Swap numbers[i] and numbers[indexSmallest]
         temp = classMates[i];
         classMates[i] = classMates[indexBiggest];
         classMates[indexBiggest] = temp;
      }

      //set ranks
      for(int i = 0; i < 54; ++i) {
          classMates[i].rank = (i+1);
      }

      //print class mates
      for(int i = 0; i < 54; i++)
      {
          //if rank is single digit adds extra space
          if(classMates[i].rank < 10) {
                printf("Rank:%d      Votes: %d    %s\n", classMates[i].rank, classMates[i].votes, classMates[i].name);
          }
          else{
                printf("Rank:%d     Votes: %d    %s\n", classMates[i].rank, classMates[i].votes, classMates[i].name);
          }
      }
      printf("\n");

      //loops until userchoice is in appropriate range
      do {
          printf("Vote for? (0 to quit) ");
          scanf(" %d", &userChoice);

          if(userChoice < 0 || userChoice > 54) {
             printf("Not a valid rank\n");
          }
      }while(userChoice < 0 || userChoice > 54);

       //increment vote
       for(int i = 0; i < 54; ++i) {
            if(classMates[i].rank == userChoice) {
                classMates[i].votes++;
            }
        }
      

    }
    return 0;
}