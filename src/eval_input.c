#include <stdio.h>
#include <stdint.h>
#include "eval_input.h"
#include "data.h"
#include "init.h"
#define clrscr() printf("\e[1;1H\e[2J") // CLEAR TERMINAL - only works on *nix systems

void eval_input(const int32_t id_argument) {   // EVALUATE USER INPUT AND CALL FUNCTION WITH ITS CORRECT ID
    switch (id_argument) {
        
        /*------------------------------------------------------------------------------------------------*/

        case 1: // NEW PRODUCT
            clrscr();
            printf("%s","**********************\n* WWS Produkteingabe *\n**********************\n");

            if (data_handler(id_argument) == -2) {  // ERROR CASE CHECK
                printf("\nERROR -2:\nProduktinformation ist illegal!\n");
                printf("\nDrücken Sie ENTER...\t");
                while (getchar() != '\n') {}
                getchar();
            }
            break;

        /*------------------------------------------------------------------------------------------------*/

        case 2: // NEW CUSTOMER
            clrscr();
            printf("%s","**********************\n* WWS Kundeneingabe *\n**********************\n");

            if (data_handler(id_argument) == -2) {  // ERROR CASE CHECK
                printf("\nERROR -2:\nKundeninformation ist illegal!\n");
                printf("\nDrücken Sie ENTER...\t");
                while (getchar() != '\n') {}
                getchar();
            }
            break;

        /*------------------------------------------------------------------------------------------------*/

        case 3: // PRINT PRODUCT
            clrscr();
            printf("%s","**********************\n* WWS Produktausgabe *\n**********************\n");
        
            if (data_handler(id_argument) == -1) {  // ERROR CASE CHECK
                printf("\nERROR -1:\nID des Produkt exestiert nicht!\n");
            }

            printf("\n\nDrücken Sie ENTER...\t");
            while (getchar() != '\n') {}
            getchar();
            break;

        /*------------------------------------------------------------------------------------------------*/

        case 4: // PRINT CUSTOMER
            clrscr();
            printf("%s","**********************\n* WWS Kundenausgabe *\n**********************\n");

            if (data_handler(id_argument) == -1) {  // ERROR CASE CHECK
                printf("\nERROR -1:\nID des Kunden exestiert nicht!\n");
            }

            printf("\n\nDrücken Sie ENTER...\t");
            while (getchar() != '\n') {}
            getchar();
            break;

        /*------------------------------------------------------------------------------------------------*/

        case 5: // PRINT LIST OF PRODUCTS
            clrscr();
            printf("%s","**********************\n* WWS Produktausgabe *\n**********************\n");

            data_handler(id_argument);
            printf("\n\nDrücken Sie ENTER...\t");
            while (getchar() != '\n') {}
            getchar();
            break;

        /*------------------------------------------------------------------------------------------------*/

        case 6: // PRINT LIST OF CUSTOMERS
            clrscr();
            printf("%s","**********************\n* WWS Kundenausgabe *\n**********************\n");
        
            data_handler(id_argument);
            printf("\n\nDrücken Sie ENTER...\t");
            while (getchar() != '\n') {}
            getchar();
            break;

        /*------------------------------------------------------------------------------------------------*/

        case 7: // END CASE
            clrscr();
            printf("\nEinen schönen Tag noch :)\n\n");
            return;

        /*------------------------------------------------------------------------------------------------*/

        default:    // Just skip to the end which calls the cli interface
            break;
    }
    init();     // RETURN TO CLI INTERFACE
}