#include <stdio.h>
#include <stdlib.h>

extern int yyparse();
extern FILE *yyin;
extern int yylineno;

int main(int argc, char **argv)
{
    printf("=== Interpreteur GLSimpleSQL ===\n");
    printf("Tapez vos requetes SQL ou fournissez un fichier.\n");
    printf("-----------------------------------------------\n");

    yylineno = 1;

    if (argc == 2) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            perror("Erreur lors de l'ouverture du fichier");
            exit(1);
        }
        printf("Lecture du fichier : %s\n", argv[1]);
    }

    yyparse();

    if (argc == 2) {
        fclose(yyin);
    }

    printf("\n=== Fin de l'analyse SQL ===\n");
    return 0;
}