/**
 * Description: 7.6 LAB*: Program: Online shopping cart (Part 1)
 *              main.c - main() function
 * Author names: Reshaj Maskey, Shannon Luu
 * Author emails: reshaj.maskey@sjsu.edu, shannon.luu@sjsu.edu
 * Last modified date: 11/12/2023
 * Creation date: 11/12/2023
 **/

/*
 * (1) Create three files to submit:

        ItemToPurchase.h - Struct definition and related function declarations
        ItemToPurchase.c - Related function definitions
        main.c - main() function

    Build the ItemToPurchase struct with the following specifications:

        Data members (3 pts)
            char itemName [ ]
            int itemPrice
            int itemQuantity
        Related functions
            MakeItemBlank() (2 pts)
                Has a pointer to an ItemToPurchase parameter.
                Sets item's name = "none", item's price = 0, item's quantity = 0
            PrintItemCost()
                Has an ItemToPurchase parameter.


    Ex. of PrintItemCost() output:

    Bottled Water 10 @ $1 = $10


    (2) In main(), prompt the user for two items and create two objects of the ItemToPurchase struct. Before
    prompting for the second item, enter the following code to allow the user to input a new string. c is
    declared as a char. (2 pts)

    c = getchar();
    while(c != '\n' && c != EOF) {
       c = getchar();
    }


    Ex:

    Item 1
    Enter the item name:
    Chocolate Chips
    Enter the item price:
    3
    Enter the item quantity:
    1

    Item 2
    Enter the item name:
    Bottled Water
    Enter the item price:
    1
    Enter the item quantity:
    10


    (3) Add the costs of the two items together and output the total cost. (2 pts)

    Ex:

    TOTAL COST
    Chocolate Chips 1 @ $3 = $3
    Bottled Water 10 @ $1 = $10

    Total: $13

 */
#include <stdio.h>
#include <string.h>

#include "ItemToPurchase.h"

int main(void) {

    // char itemName1[100];
    // int itemPrice1;
    // int itemQuantity1;
    ItemToPurchase item1;

    printf("Item 1\n");
    printf("Enter the item name:\n");
    scanf("%[^\n]%*c", item1.itemName);
    printf("Enter the item price:\n");
    scanf("%d", &item1.itemPrice);
    printf("Enter the item quantity:\n");
    scanf("%d", &item1.itemQuantity); 

    char c;
    c = getchar();
    while(c != '\n' && c != EOF) {
       c = getchar();
    }

    // char itemName2[100];
    // int itemPrice2;
    // int itemQuantity2;

    ItemToPurchase item2;

    printf("\nItem 2\n");
    printf("Enter the item name:\n");
    scanf("%[^\n]%*c", item2.itemName);
    printf("Enter the item price:\n");
    scanf("%d", &item2.itemPrice);
    printf("Enter the item quantity:\n");
    scanf("%d", &item2.itemQuantity);

    printf("\nTOTAL COST:\n");
    int totalPrice1 = PrintItemCost(&item1);
    int totalPrice2 = PrintItemCost(&item2);
    printf("Total price: $%d", totalPrice1+totalPrice2);

    return 0;
}