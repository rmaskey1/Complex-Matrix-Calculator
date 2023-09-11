/**
 * file: houseSummary.c
 * author: Reshaj Maskey, Shannon Luu
 * description: program that reads the current price and last month's price of a house and give summary about price change and monthly mortgage
 */

#include <stdio.h>

void houseSummary(int currentPrice, int lastPrice) {
	printf("This house is $%d. The change is $%d since last month.\n", currentPrice, currentPrice-lastPrice);
	float mortgage = ((float)currentPrice*0.051)/12;
	printf("The estimated monthly mortgage is $%0.2f\n", mortgage);
}

int main(void) {
	int currentPrice;
	int lastPrice;
	printf("Enter the house's current price and last price (in format 'currentprice lastprice'):\n");
	scanf("%d %d", &currentPrice, &lastPrice);
	houseSummary(currentPrice, lastPrice);

	return 0;
}