#include <stdio.h>
#include <stdlib.h>
#include "zooAnimals1.h"

#define FILENAME "dataNEW.txt"
#define FLUSH stdin=freopen(NULL,"r",stdin)


int main() {
    // Opens text file for reading
    FILE *fpStart = fopen(FILENAME, "r+");
    if (fpStart == NULL) {
        printf("Error reading file.\n");
        exit(1);
    }

    // Create linked list from file
    animal_t* list = createList(fpStart);
    fclose(fpStart);


    puts("========== Welcome to the Zoo Gallery ==========\n");
    int choice;

    do {
        puts("Please select from one of the following options:");
        puts(" 1) SHOW ALL RECORDS / VIEW DETAILS");
        puts(" 2) ADD RECORD");
        puts(" 3) EDIT RECORD");
        puts(" 4) DELETE RECORD");
        puts(" 6) SEARCH RECORD");
        puts("-1) EXIT + SAVE");
        puts("----------------------------------------------------------");
        FLUSH;
        scanf("%d", &choice);

        // Switch statements do not use cases for negative numbers
        if (choice == -1) {
            printf("\nThanks for using our app! Data has been saved to file!\n");
            break;
        }
        
        switch (choice) {
            case 1:
                displayListBrief(list);
                break;
            case 2:
                addRecord(&list);
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                printf("Invalid choice! Please try again!");

        }

    } while (choice != 0);

    // Overwrite contents of file
    FILE *fpEnd = fopen(FILENAME, "w+");
    if (fpEnd == NULL) {
        printf("Error reading file.\n");
        exit(1);
    }
    printToFile(fpEnd, list);
    fclose(fpEnd);

    // Close file pointer
    
    
    // Free linked list & contents of nodes
    deleteList(&list);

    return 0;
}

