#include<stdio.h>
#include "inventory.c"

void main() {
    int n;

    printf("Welcome to the inventory...\n\n");

    printf("Enter the number of products: ");
    scanf("%d",&n);

    struct Product my_inventory[n];

    setProductsDetail(my_inventory,n);

    

}