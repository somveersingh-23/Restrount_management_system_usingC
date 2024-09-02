#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for the restaurant billing system
struct restaurant
{
    char cusNm[25];
    char itemNm[30];
    float price; // Changed to single float to hold the price of an item
    int refId;   // Changed to single int to hold the reference ID of an item
    int qnt;     // This is unused, but keeping it for potential quantity use
};

// Function to calculate the sum of the array numbers which are present in the array
float sumArray(float a[], int size)
{
    int i;
    float sum = 0;
    for (i = 0; i < size; i++)
    {
        sum = sum + a[i];
    }
    return sum;
}

// Main function
int main()
{
    int ch;
    int i, itemQnt;
    float total;

    printf("\n***WELCOME TO THE UP20 CAFE***\n");
    printf("\n********************************\n");
    printf("How many items customer wants to purchase:\n");
    scanf("%d", &itemQnt);

    struct restaurant res[itemQnt]; // Array of structs to hold each item

label:
    printf("\nPlease select your preferred operation\n");
    printf("1. Generate Invoice\n");
    printf("2. Show all Invoices\n");
    printf("3. Search Invoices\n");
    printf("4. Exit\n");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        for (i = 0; i < itemQnt; i++)
        { // Changed loop from 1-indexed to 0-indexed
            printf("\nEnter the name of the Customer:\n");
            scanf("%s", res[i].cusNm);
            printf("Item quantity fetched: %d\n", itemQnt);
            printf("Enter item %d:\n", i + 1);
            printf("Item name:\n");
            scanf("%s", res[i].itemNm);
            printf("Enter the item price:\n");
            scanf("%f", &res[i].price);
            printf("Enter the reference ID:\n");
            scanf("%d", &res[i].refId);
        }
        printf("\n********************************************");
        printf("\n******************** Invoice *****************\n");
        for (i = 0; i < itemQnt; i++)
        { // Changed loop from 1-indexed to 0-indexed

            printf("Name: %s\n", res[i].cusNm);
            printf("RefId\t Items\t Cost\t total\n");
            printf("%d\t %s\t %.2f\n", res[i].refId, res[i].itemNm, res[i].price);
        }
        printf("\n******* Thanks for Servicing *****\n");
        printf("\n**** Save food ***\n");
        printf("\n***** Dane Dane par likha hai khane wale ka naam ****\n");

        goto label;

    case 2:
        printf("\n********************************************");
        printf("\n******************** Invoice *****************\n");
        for (i = 0; i < itemQnt; i++)
        { // Changed loop from 1-indexed to 0-indexed
            printf("Name: %s\n", res[i].cusNm);
            printf("RefId\t Items\t Cost\n");
            printf("%d\t %s\t %.2f\n", res[i].refId, res[i].itemNm, res[i].price);
        }
        printf("\n******* Thanks for Servicing *****\n");
        printf("\n**** Save food ***\n");
        printf("\n***** Dane Dane par likha hai khane wale ka naam ****\n");
        goto label;

    case 3:
        printf("Enter the refId of customer:\n");
        int searchId;
        scanf("%d", &searchId);
        printf("\n********************************************");
        printf("\n******************** Invoice *****************\n");
        for (i = 0; i < itemQnt; i++)
        { // Changed loop from 1-indexed to 0-indexed
            if (searchId == res[i].refId)
            {

                printf("Name: %s\n", res[i].cusNm);
                printf("RefId\t Items\t Cost\n");
                printf("%d\t %s\t %.2f\n", res[i].refId, res[i].itemNm, res[i].price);
            }
        }
        printf("\n******* Thanks for Servicing *****\n");
        printf("\n**** Save food ***\n");
        printf("\n***** Dane Dane par likha hai khane wale ka naam ****\n");
        goto label;

    case 4:
        exit(0); // Correct way to exit the program
        break;

    default:
        printf("Invalid choice\n");
        goto label;
    }

    return 0;
}
