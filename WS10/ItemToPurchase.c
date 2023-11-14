/**
 * Description: 7.6 LAB*: Program: Online shopping cart (Part 1)
 *              ItemToPurchase.c - Related function definitions
 * Author names: Reshaj Maskey, Shannon Luu
 * Author emails: reshaj.maskey@sjsu.edu, shannon.luu@sjsu.edu
 * Last modified date: 11/12/2023
 * Creation date: 11/12/2023
 **/
#include <stdio.h>
#include <string.h>
#include "ItemToPurchase.h"

void MakeItemBlank(struct ItemToPurchase *item) {
	strcpy(item->itemName, "none");
	item->itemPrice = 0;
	item->itemQuantity = 0;
}

int PrintItemCost(struct ItemToPurchase *item) {
	printf("%s %d @ $%d = $%d\n", item->itemName, item->itemQuantity, item->itemPrice, item->itemQuantity*item->itemPrice);
	return item->itemQuantity*item->itemPrice;
}
