/**
 * Description: 7.6 LAB*: Program: Online shopping cart (Part 1)
 *              ItemToPurchase.h - Struct definition and related function declarations
 * Author names: Reshaj Maskey, Shannon Luu
 * Author emails: reshaj.maskey@sjsu.edu, shannon.luu@sjsu.edu
 * Last modified date: 11/12/2023
 * Creation date: 11/12/2023
 **/

typedef struct ItemToPurchase {
	char itemName[100];
	int itemPrice;
	int itemQuantity;
} ItemToPurchase;

void MakeItemBlank(struct ItemToPurchase *item);
int PrintItemCost(struct ItemToPurchase *item);