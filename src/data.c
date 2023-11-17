#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "data.h"
#include "init.h"
#define CHAR_MAX 31      // MAX LENGTH OF CHAR ARRAY
#define DATA_MAX 100   // MAXIMUM SIZE OF DATABASE

typedef struct struct_customer { // CUSTOMER DATABASE STRUCT -> GLOBAL
    uint64_t id;
    char first_name[CHAR_MAX];
    char last_name[CHAR_MAX];
} customer;
customer customer_database[DATA_MAX];

typedef struct struct_product { // PRODUCT DATABASE STRUCT -> GLOBAL
    uint64_t id;
    char name[CHAR_MAX];
    double price;
    uint32_t amount;
} product;
product product_database[DATA_MAX];

uint32_t customer_index = 0; // CUSTOMER DATABASE ARRAY INDEX
uint32_t product_index = 0;  // PRODUCT DATABASE ARRAY INDEX

bool data_handler(const int32_t id_argument) {      // HANDLES DATA, MODIFIES AND PRINTS IT
    bool is_valid = false;
    int32_t id = 0, amount = 0;
    double price = 0;

    switch (id_argument) {       // SWITCH STATEMENT FOR ADDING OR PRINTING DATA

        /*######################################################################*/

        case 1:     // ADD PRODUCT TO PRODUCT DATABASE
        printf("ID: "), scanf("%d", &id);
        if (id <= 0) {
            return false;  // ID CANNOT BE UNDER OR 0!
        }
        product_database[product_index].id = id;

        printf("Name: ");
        scanf("%s", product_database[product_index].name);

        printf("Preis: "), scanf("%lf", &price);
        product_database[product_index].price = price;
        
        printf("Anzahl: "), scanf("%d", &amount);
        if (amount <= 0) {
            return false;  // AMOUNT CANNOT BE UNDER OR 0!
        }
        product_database[product_index].amount = amount;
        product_index += 1;   // INCREMENT DATABASE ARRAY VALUE
        break;

        /*######################################################################*/

        case 2:     // ADD CUSTOMER TO CUSTOMER DATABASE
        printf("ID: "), scanf("%d", &id);
        if (id <= 0) {
            return false;  // ID CANNOT BE UNDER OR 0!
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

        for (int32_t i = 0; i < DATA_MAX; i++) {
            if (product_database[i].id == id && id != 0) {
                id = i;
                is_valid = true;
                break;
            }
        }
        if (is_valid == false) {
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
        scanf("%d", &id);

        for (int32_t i = 0; i < DATA_MAX; i++) {
            if (customer_database[i].id == id && id != 0) {
                id = i;
                is_valid = true;
                break;
            }
        }
        if (is_valid == false) {
            return is_valid;
        }
        //printf("ID: %d\n", customer_database[id].id);     We kinda know the ID since we input it so...
        printf("VORNAME: %s\n", customer_database[id].first_name);
        printf("NACHNAME: %s\n", customer_database[id].last_name);
        break;

        /*######################################################################*/

        case 5:     // PRINT LIST OF ALL PRODUCTS
        for (int32_t i = 0; i < DATA_MAX; i++) {
            if (product_database[i].id != 0) {
                printf("ID: %ld\n", product_database[i].id);
                printf("NAME: %s\n", product_database[i].name);
                printf("PREIS: %.2lf €\n", product_database[i].price);
                printf("ANZAHL: %hu\n", product_database[i].amount);
                printf("INSGESAMT: %.2lf €\n\n", product_database[i].price*(double)product_database[id].amount);
            }
        }
        break;

        /*######################################################################*/

        case 6:     // PRINT LIST OF ALL CUSTOMERS
        for (int32_t i = 0; i < DATA_MAX; i++) {
            if (customer_database[i].id != 0) {
                printf("ID: %ld\n", customer_database[i].id);
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
    return true;
}