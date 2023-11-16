#include <stdio.h>
#include "data.h"
#include "init.h"

#define CHAR_MAX 31      // MAX LENGTH OF CHAR ARRAY
#define DATA_MAX 100   // MAXIMUM SIZE OF DATABASE

int customer_index = 0;     // CUSTOMER DATABASE ARRAY INDEX
int product_index = 0;     // PRODUCT DATABASE ARRAY INDEX

typedef struct CUSTOMER {       // CUSTOMER DATABASE INIT -> DATABASE IS GLOBAL
        int id;
        char first_name[CHAR_MAX];
        char last_name[CHAR_MAX];
    }   customer;
customer customer_database[DATA_MAX];

typedef struct PRODUCT {        // PRODUCT DATABASE INIT -> DATABASE IS GLOBAL
        int id;
        char name[CHAR_MAX];
        double price;
        unsigned short amount;
    }   product;
product product_database[DATA_MAX];

int data_handler(int id_argument) {      // HANDLES DATA, MODIFIES AND PRINTS IT
    int id = 0, is_valid = -1;
    double price = 0;
    unsigned short amount = 0;

    switch (id_argument) {       // SWITCH STATEMENT FOR ADDING OR PRINTING DATA

        /*######################################################################*/

        case 1:     // ADD PRODUCT TO PRODUCT DATABASE
        printf("ID: "), scanf("%d", &id);
        if (id == 0) {
            return -2;  // ID DARF NICHT 0 SEIN!
        }
        product_database[product_index].id = id;

        printf("Name: ");
        scanf("%s", product_database[product_index].name);

        printf("Preis: "), scanf("%lf", &price);
        product_database[product_index].price = price;
        
        printf("Anzahl: "), scanf("%hu", &amount);
        product_database[product_index].amount = amount;
        product_index += 1;   // INCREMENT DATABASE ARRAY VALUE
        break;

        /*######################################################################*/

        case 2:     // ADD CUSTOMER TO CUSTOMER DATABASE
        printf("ID: "), scanf("%d", &id);
        if (id == 0) {
            return -2;  // ID DARF NICHT 0 SEIN!
        }
        customer_database[customer_index].id = id;

        printf("Vorname: ");
        scanf("%s", customer_database[customer_index].first_name);

        printf("Nachname: ");
        scanf("%s", customer_database[customer_index].last_name);
        customer_index += 1;   // INCREMENT DATABASE ARRAY VALUE
        break;

        /*######################################################################*/

        case 3:     // PRINT PRODUCT INFO
        printf("Produkt ID: ");
        scanf("%d", &id);

        for (int i = 0; i < DATA_MAX; i++) {
            if (product_database[i].id == id && id != 0) {
                id = i;
                is_valid = 0;
                break;
            }
        }
        if (is_valid == -1) {
            return is_valid;
        }
        //printf("ID: %d\n", product_database[id].id);      We kinda know the ID since we input it so...
        printf("NAME: %s\n", product_database[id].name);
        printf("PREIS: %.2lf €\n", product_database[id].price);
        printf("ANZAHL: %hu\n", product_database[id].amount);
        printf("INSGESAMT: %.2lf €\n", product_database[id].price*(double)product_database[id].amount);
        break;

        /*######################################################################*/

        case 4:     // PRINT CUSTOMER INFO
        printf("Kunden ID: ");
        int id = 0;
        scanf("%d", &id);

        for (int i = 0; i < DATA_MAX; i++) {
            if (customer_database[i].id == id && id != 0) {
                id = i;
                is_valid = 0;
                break;
            }
        }
        if (is_valid == -1) {
            return is_valid;
        }
        //printf("ID: %d\n", customer_database[id].id);     We kinda know the ID since we input it so...
        printf("VORNAME: %s\n", customer_database[id].first_name);
        printf("NACHNAME: %s\n", customer_database[id].last_name);
        break;

        /*######################################################################*/

        case 5:     // PRINT LIST OF ALL PRODUCTS
        for (int i = 0; i < DATA_MAX; i++) {
            if (product_database[i].id != 0) {
                printf("ID: %d\n", product_database[i].id);
                printf("NAME: %s\n", product_database[i].name);
                printf("PREIS: %.2lf €\n", product_database[i].price);
                printf("ANZAHL: %hu\n", product_database[i].amount);
                printf("INSGESAMT: %.2lf €\n\n", product_database[i].price*(double)product_database[id].amount);
            }
        }
        break;

        /*######################################################################*/

        case 6:     // PRINT LIST OF ALL CUSTOMERS
        for (int i = 0; i < DATA_MAX; i++) {
            if (customer_database[i].id != 0) {
                printf("ID: %d\n", customer_database[i].id);
                printf("VORNAME: %s\n", customer_database[i].first_name);
                printf("NACHNAME: %s\n\n", customer_database[i].last_name);
            }
        }
        break;

        /*######################################################################*/

        default:    // EVALUATE INPUT AGAIN
        init();
        break;
    }
    return 0;
}