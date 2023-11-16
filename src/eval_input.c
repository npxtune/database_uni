#include "eval_input.h"
#include "data.h"
#include "init.h"
#include <stdio.h>
#define clrscr() printf("\e[1;1H\e[2J") // CLEAR TERMINAL - only works on *nix systems

void eval_input(int id_argument) {   // EVALUATE USER INPUT AND CALL FUNCTION WITH ITS CORRECT ID
    switch (id_argument) {
        
        /*######################################################################*/

        case 1: // NEW PRODUCT
        clrscr();
        printf("%s","**********************\n* WWS Produkteingabe *\n**********************\n");
        if (data_handler(id_argument) == -2) {
            printf("\nERROR -2:\nID des Produkt darf nicht '0' sein!\n");
            printf("\nDrücken Sie ENTER...\t");
            while (getchar() != '\n');
            getchar();
        }
        break;

        /*######################################################################*/

        case 2: // NEW CUSTOMER
        clrscr();
        printf("%s","**********************\n* WWS Kundeneingabe *\n**********************\n");
        if (data_handler(id_argument) == -2) {
            printf("\nERROR -2:\nID des Kunden darf nicht '0' sein!\n");
            printf("\nDrücken Sie ENTER...\t");
            while (getchar() != '\n');
            getchar();
        }
        break;

        /*######################################################################*/

        case 3: // PRINT PRODUCT
        clrscr();
        printf("%s","**********************\n* WWS Produktausgabe *\n**********************\n");
        if (data_handler(id_argument) == -1) {
            printf("\nERROR -1:\nID des Produkt exestiert nicht!\n");
        }
        printf("\n\nDrücken Sie ENTER...\t");
        while (getchar() != '\n');
        getchar();
        break;

        /*######################################################################*/

        case 4: // PRINT CUSTOMER
        clrscr();
        printf("%s","**********************\n* WWS Kundenausgabe *\n**********************\n");
        if (data_handler(id_argument) == -1) {
            printf("\nERROR -1:\nID des Kunden exestiert nicht!\n");
        }
        printf("\n\nDrücken Sie ENTER...\t");
        while (getchar() != '\n');
        getchar();
        break;

        /*######################################################################*/

        case 5: // PRINT LIST OF PRODUCTS
        // TODO: FORMATTING OF CHARTS
        clrscr();
        printf("%s","**********************\n* WWS Produktausgabe *\n**********************\n");
        data_handler(id_argument);
        printf("\n\nDrücken Sie ENTER...\t");
        while (getchar() != '\n');
        getchar();
        break;

        /*######################################################################*/

        case 6: // PRINT LIST OF CUSTOMERS
        // TODO: FORMATTING OF CHARTS
        clrscr();
        printf("%s","**********************\n* WWS Kundenausgabe *\n**********************\n");
        data_handler(id_argument);
        printf("\n\nDrücken Sie ENTER...\t");
        while (getchar() != '\n');
        getchar();
        break;

        /*######################################################################*/

        case 7: // END CASE
        clrscr();
        printf("\nEinen schönen Tag noch :)\n\n");
        return;

        /*######################################################################*/

        default:
        break;
    }
    init();     // RETURN TO CLI INTERFACE
}