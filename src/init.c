#include <stdio.h>
#include <stdint.h>
#include "init.h"
#include "eval_input.h"
#define clrscr() printf("\e[1;1H\e[2J") // CLEAR TERMINAL - only works on *nix systems

void init(void) {   // INIT CLI INTERFACE
    int32_t input = 0;
    clrscr();
    printf("%s","*************************\n* WWS Produktmanagement *\n*************************\n");
    printf("Optionen:\n");
    printf("1: Neues Produkt eingeben\n");
    printf("2: Neuen Kunden eingeben\n");
    printf("3: Produkt ausgeben\n");
    printf("4: Kunde ausgeben\n");
    printf("5: Alle Produkte ausgeben\n");
    printf("6: Alle Kunden ausgeben\n");
    printf("7: Beenden\n");
    printf("--------------------------\n");
    printf("Auswahl: "), scanf("%d",&input);
    eval_input(input);
}