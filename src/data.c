#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include "data.h"
#include "init.h"
#define CHAR_MAX 31      // MAX LENGTH OF CHAR ARRAY
#define DATA_MAX 100   // MAXIMUM SIZE OF DATABASE
#define CHART_PAGE_MAX 5    // MAX VALUES PRINTED FOR A PAGE
/*------------------------------------------------------------------------------------------------
                                     GLOBAL STRUCTS AND VALUES
                                           DEFINED HERE
------------------------------------------------------------------------------------------------*/
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

/*------------------------------------------------------------------------------------------------*/

uint32_t customer_index = 0; // CUSTOMER DATABASE ARRAY INDEX
uint32_t product_index = 0;  // PRODUCT DATABASE ARRAY INDEX

/*-------------------------------------------------------------------------------------------------------------*/

bool product_data_exists(const uint64_t product_id) {       //  CHECK IF PRODUCT WITH ID ALREADY EXISTS
    for (int32_t i = 0; i < DATA_MAX; i++) {
        if (product_id == product_database[i].id) {
            return true;
        }
    }
    return false;
}

bool customer_data_exists(const uint64_t customer_id) {     //  CHECK IF CUSTOMER WITH ID ALREADY EXISTS
    for (int32_t i = 0; i < DATA_MAX; i++) {
        if (customer_id == customer_database[i].id) {
            return true;
        }
    }
    return false;
}

/*-------------------------------------------------------------------------------------------------------------*/

int8_t data_handler(const int32_t id_argument) {      // HANDLES DATA, MODIFIES AND PRINTS IT
    bool is_valid = false;
    int64_t id = 0;
    int32_t amount = 0;
    double price = 0;

    switch (id_argument) {       // SWITCH STATEMENT FOR ADDING OR PRINTING DATA

        /*-------------------------------------------------------------------------*/

        case 1:     // ADD PRODUCT TO PRODUCT DATABASE
            printf("ID: "), scanf("%d", &id);
            if (id <= 0 || product_data_exists(id) == true) {
                return -2;  // ID CANNOT BE UNDER OR 0!
            }

            printf("Name: ");
            scanf("%s", product_database[product_index].name);

            printf("Preis: ");
            scanf("%lf", &product_database[product_index].price);

            printf("Anzahl: "), scanf("%d", &amount);
            if (amount <= 0) {
                return false;  // AMOUNT CANNOT BE UNDER OR 0!
            }
            product_database[product_index].amount = amount;

            product_database[product_index].id = id;    // ASSIGN ID AT END TO ENSURE LEGALITY OF VALUES
            product_index += 1;   // INCREMENT DATABASE ARRAY VALUE
            break;

        /*------------------------------------------------------------------------------------------------*/

        case 2:     // ADD CUSTOMER TO CUSTOMER DATABASE
            printf("ID: "), scanf("%d", &id);
            if (id <= 0 || customer_data_exists(id) == true) {
                return -2;  // ID CANNOT BE UNDER OR 0!
            }

            printf("Vorname: ");
            scanf("%s", customer_database[customer_index].first_name);

            printf("Nachname: ");
            scanf("%s", customer_database[customer_index].last_name);

            customer_database[customer_index].id = id;  // ASSIGN ID AT END TO ENSURE LEGALITY OF VALUES
            customer_index += 1;   // INCREMENT DATABASE ARRAY VALUE
            break;

        /*------------------------------------------------------------------------------------------------*/

        case 3:     // PRINT PRODUCT INFO
            printf("Produkt ID: ");
            scanf("%d", &id);

            for (int32_t i = 0; i < product_index; i++) {
                if (product_data_exists(i) == true && id != 0) {
                    id = i;
                    is_valid = true;
                    break;
                }
            }
            if (is_valid == false) {
                return -1;
            }
            //printf("ID: %d\n", product_database[id].id);      We kinda know the ID since we input it so...
            printf("%-10s %s\n", "NAME:", product_database[id].name);
            printf("%-10s %.2lf €\n", "PREIS:", product_database[id].price);
            printf("%-10s %hu\n", "ANZAHL:", product_database[id].amount);
            printf("%-10s %.2lf €\n", "INSGESAMT:", product_database[id].price*(double)product_database[id].amount);
            break;

        /*------------------------------------------------------------------------------------------------*/

        case 4:     // PRINT CUSTOMER INFO
            printf("Kunden ID: ");
            scanf("%d", &id);

            for (int32_t i = 0; i < customer_index; i++) {
                if (customer_data_exists(i) == true && id != 0) {
                    id = i;
                    is_valid = true;
                    break;
                }
            }
            if (is_valid == false) {
                return -1;
            }
            //printf("ID: %d\n", customer_database[id].id);     We kinda know the ID since we input it so...
            printf("%-9s %s\n", "VORNAME:", customer_database[id].first_name);
            printf("%-9s %s\n", "NACHNAME:", customer_database[id].last_name);
            break;

        /*------------------------------------------------------------------------------------------------*/

        case 5:     // PRINT LIST OF ALL PRODUCTS
            for (int32_t i = 0; i < product_index; i+=CHART_PAGE_MAX) {
                for (int32_t j = 0; j < CHART_PAGE_MAX; j++) {
                    printf("| %10lu ", product_database[j].id);
                }   printf("\n");

                for (int32_t j = 0; j < CHART_PAGE_MAX; j++) {
                    printf("| %10s ", product_database[j].name);
                }   printf("\n");

                for (int32_t j = 0; j < CHART_PAGE_MAX; j++) {
                    printf("| %8.2lf € ", product_database[j].price);
                }   printf("\n");

                for (int32_t j = 0; j < CHART_PAGE_MAX; j++) {
                    printf("| %10u ", product_database[j].amount);
                }   printf("\n");

                printf("Seite %d von %d\n", i, (int32_t)round(product_index / CHART_PAGE_MAX));

                if (product_index > CHART_PAGE_MAX) {
                    printf("\nDrücken Sie ENTER...\t");
                    while (getchar() != '\n') {}
                    getchar();
                }
            }
            break;

        /*------------------------------------------------------------------------------------------------*/

        case 6:     // PRINT LIST OF ALL CUSTOMERS
            printf("\n");
            for (int32_t i = 0; i < customer_index; i+=CHART_PAGE_MAX) {
                for (int j = 0; j < CHART_PAGE_MAX; j++) {
                    printf("| %10lu ", customer_database[j].id);
                }   printf("\n");

                for (int32_t j = 0; j < CHART_PAGE_MAX; j++) {
                    printf("| %10s ", customer_database[j].first_name);
                }   printf("\n");

                for (int32_t j = 0; j < CHART_PAGE_MAX; j++) {
                    printf("| %10s ", customer_database[j].last_name);
                }   printf("\n");

                printf("\nSeite %d von %d\n", i, (int32_t)round(product_index / CHART_PAGE_MAX+1));

                if (product_index > CHART_PAGE_MAX) {
                    printf("\nDrücken Sie ENTER...\t");
                    while (getchar() != '\n') {}
                    getchar();
                }
            }
            break;

        /*------------------------------------------------------------------------------------------------*/

        default:    // EVALUATE INPUT AGAIN
            init();
            break;
        /*------------------------------------------------------------------------------------------------*/
    }
    return 0;
}