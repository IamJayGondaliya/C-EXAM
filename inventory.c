//C files
#include<stdio.h>
#include<string.h>

//Globals
#define msg printf

//my files
#include "functions.c"

struct Product {
    int pro_id;
    char pro_name[20];
    float price;
    int available_stock;
};

void setProductsDetail(struct Product p[],int length) {
    for(int i=0; i<length; i++) {
        msg("Product: %d/%d\n",i+1,length);

        //Entering & valicating id
        tmp:
        msg("Enter product id: ");
        p[i].pro_id = getInt();
        for(int j=0; j<i; j++) {
            if(p[i].pro_id == p[j].pro_id) {
                msg("Id is already taken, please enter another id\n");
                goto tmp;
            }
        }

        fflush(stdin);

        //Entering other details
        msg("Enter product name: ");
        gets(p[i].pro_name);
        msg("Enter product price: ");
        p[i].price = getFloat();
        msg("Enter available stock: ");
        p[i].available_stock = getInt();
    }
}

void insertProduct(struct Product p[],int *length) {
    int pos;
    struct Product product;

    msg("Enter position: ");
    pos = getInt();

    msg("Enter id: ");
    product.pro_id = getInt();
    fflush(stdin);
    msg("Enter name: ");
    gets(product.pro_name);
    msg("Enter price: ");
    product.price = getFloat();
    msg("Enter stock: ");
    product.available_stock = getInt();

    for(int i=*length; i>=pos; i--) {
        p[i] = p[i+1];
    }

    *length = *length + 1;

    msg("Product inserted at index %d...\n",pos);

}

void addProductAtLast(struct Product p[],int *length) {
    msg("Adding at last...\n");
    //Entering & valicating id
        tmp:
        msg("Enter product id: ");
        p[*length].pro_id = getInt();        
        for(int i=0; i<*length; i++) {
            for(int j=0; j<i; j++) {
                if(p[i].pro_id == p[j].pro_id) {
                    msg("Id is already taken, please enter another id\n");
                    goto tmp;
                }
            }
        }

        fflush(stdin);

        //Entering other details
        msg("Enter product name: ");
        gets(p[*length].pro_name);
        msg("Enter product price: ");
        p[*length].price = getFloat();
        msg("Enter available stock: ");
        p[*length].available_stock = getInt();

        *length = *length + 1;
    
}

void displayProducts(struct Product p[],int length) {
    msg("Id\tProduct name\tPrice\tStock\n");
    msg("======= =============== ======= =======\n");
    for(int i=0; i<length; i++) {
        msg("%d\t%s\t\t%.2f\t%d\n",p[i].pro_id,p[i].pro_name,p[i].price,p[i].available_stock);
    }
}

void searchById(struct Product p[],int length,int id) {

    int flag = 0,index;

    for(int i=0; i<length; i++) {
        if(p[i].pro_id == id) {
            flag = 1;
            index = i;
        }
    }

    if(flag) {
        msg("Product id: %d\n",p[index].pro_id);
        msg("Product name: %s\n",p[index].pro_name);
        msg("Product price: %s\n",p[index].price);
        msg("Product stock: %s\n",p[index].available_stock);
    }
    else {
        msg("Id not found...\n");
    }
}

void updateById(struct Product p[],int length,int id) {
    
    int flag = 0,index;

    for(int i=0; i<length; i++) {
        if(p[i].pro_id == id) {
            flag = 1;
            index = i;
        }
    }

    if(flag) {
        msg("Enter name: ");
        gets(p[index].pro_name);
        msg("Enter price: ");
        p[index].price = getFloat();
        msg("Enter stock: ");
        p[index].available_stock = getInt();

        msg("Product updated...");
    }
    else {
        msg("Id not found...\n");
    } 
}

void deleteProductById(struct Product p[],int *length, int id) {
     int flag = 0,index;

    for(int i=0; i<length; i++) {
        if(p[i].pro_id == id) {
            flag = 1;
            index = i;
        }
    }

    if(flag) {

        for(int i = index; i < *length; i++) {
            p[i] = p[i+1];
        }

        *length -= 1;

        msg("Product deleted...");
    }
    else {
        msg("Id not found...\n");
    }
}

void getTotalValue(struct Product p[],int length) {
    float total = 0.0;

    for(int i=0; i < length; i++) {
        total += p[i].price;
    }

    msg("Total price: %d\n",total);
}