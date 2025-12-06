%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylineno;
int yylex();
void yyerror(const char *s);

#define MAX_TABLES 100
#define MAX_COLUMNS 64

typedef struct {
    char *name;
    int col_count;
    char *col_names[MAX_COLUMNS];
} TableEntry;

TableEntry tables[MAX_TABLES];
int table_count = 0;

char *current_col_names[MAX_COLUMNS];
int current_col_count = 0;

char *current_select_cols[MAX_COLUMNS];
int current_select_col_count = 0;
int last_select_used_star = 0;

int current_table_idx_for_condition = -1;
char *current_table_name = NULL;

char *current_insert_cols[MAX_COLUMNS];
int current_insert_col_count = 0;

void reset_current_select_cols(void) { current_select_col_count = 0; last_select_used_star = 0; }
void add_current_select_col(char *name) { current_select_cols[current_select_col_count++] = name; }

void reset_current_insert_columns(void) { current_insert_col_count = 0; }
void add_current_insert_column(char *name) { current_insert_cols[current_insert_col_count++] = name; }

int find_column_in_table(int table_idx, const char *colname) {
    for (int j = 0; j < tables[table_idx].col_count; j++)
        if (strcmp(tables[table_idx].col_names[j], colname) == 0) return j;
    return -1;
}

void reset_current_columns(void) { current_col_count = 0; }
void add_current_column(char *name) { current_col_names[current_col_count++] = name; }

int find_table(const char *name) {
    for (int i = 0; i < table_count; i++)
        if (strcmp(tables[i].name, name) == 0) return i;
    return -1;
}

int add_table(const char *name) {
    if (find_table(name) != -1) return -1;
    tables[table_count].name = strdup(name);
    tables[table_count].col_count = current_col_count;
    for (int i = 0; i < current_col_count; i++)
        tables[table_count].col_names[i] = current_col_names[i];
    table_count++;
    return 0;
}

int drop_table_entry(const char *name) {
    int idx = find_table(name);
    if (idx == -1) return -1;
    free(tables[idx].name);
    for (int j = 0; j < tables[idx].col_count; j++)
        free(tables[idx].col_names[j]);
    for (int i = idx; i < table_count - 1; i++)
        tables[i] = tables[i + 1];
    table_count--;
    return 0;
}
%}

%union {
    int ival;
    float fval;
    char* sval;
    int bval;
}

%token SELECT FROM WHERE INSERT INTO VALUES CREATE TABLE_
%token UPDATE SET DELETE DROP
%token AND OR NOT
%token INT_ FLOAT_ VARCHAR BOOL_
%token TRUE_ FALSE_
%token <ival> INT_CONST
%token <fval> FLOAT_CONST
%token <sval> STRING_CONST
%token <sval> IDENTIFIER
%token GEQ LEQ NEQ EQ GT LT
%token COMMA SEMICOLON LPAREN RPAREN STAR

%type <ival> valeurs
%type <ival> liste_champs
%type <ival> modifications
%type <ival> liste_ident

%start input

%%

input:
    | input requete
    | input error SEMICOLON { yyerrok; yyclearin; }
    ;

requete:
      create_table
    | insert_into
    | select_stmt
    | update_stmt
    | delete_stmt
    | drop_table
    ;

create_table:
    CREATE TABLE_ IDENTIFIER { reset_current_columns(); }
    LPAREN champs RPAREN SEMICOLON
    {
        if (add_table($3) == -1)
            printf("ERREUR : table '%s' existe deja.\n", $3);
        else
            printf("CREATE TABLE detecte : %s\n", $3);
    }
    ;

champs:
      champ
    | champ COMMA champs
    ;

champ:
    IDENTIFIER type { add_current_column($1); }
    ;

type:
      INT_
    | FLOAT_
    | VARCHAR
    | VARCHAR LPAREN INT_CONST RPAREN
    | BOOL_
    ;

insert_into:
    INSERT INTO IDENTIFIER VALUES LPAREN valeurs RPAREN SEMICOLON
    {
        int idx = find_table($3);
        if (idx == -1) printf("ERREUR : table '%s' inexistante.\n", $3);
        else if ($6 != tables[idx].col_count)
            printf("ERREUR : %d valeurs mais table '%s' a %d colonnes.\n",
                   $6, $3, tables[idx].col_count);
        else
            printf("INSERT INTO %s : %d valeurs\n", $3, $6);
    }
  | INSERT INTO IDENTIFIER { reset_current_insert_columns(); }
    LPAREN liste_ident RPAREN VALUES LPAREN valeurs RPAREN SEMICOLON
    {
        int idx = find_table($3);
        if (idx == -1) printf("ERREUR : table '%s' inexistante.\n", $3);
        else if ($6 != $10)
            printf("ERREUR : %d colonnes listees mais %d valeurs.\n", $6, $10);
        else {
            int ok = 1;
            for (int i = 0; i < $6; i++)
                if (find_column_in_table(idx, current_insert_cols[i]) == -1) {
                    printf("ERREUR : colonne '%s' inexistante.\n", current_insert_cols[i]);
                    ok = 0;
                }
            if (ok)
                printf("INSERT INTO %s : %d colonnes OK\n", $3, $6);
        }
    }
    ;

valeurs:
      valeur { $$ = 1; }
    | valeur COMMA valeurs { $$ = 1 + $3; }
    ;

valeur:
      INT_CONST
    | FLOAT_CONST
    | STRING_CONST
    | TRUE_
    | FALSE_
    ;

select_stmt:
    SELECT { reset_current_select_cols(); }
    select_body
    ;

select_body:
    liste_champs FROM IDENTIFIER SEMICOLON
    {
        int idx = find_table($3);
        if (idx == -1) printf("ERREUR : table '%s' inexistante.\n", $3);
        else printf("SELECT simple, table=%s\n", $3);
    }
  | liste_champs FROM IDENTIFIER
    { current_table_idx_for_condition = find_table($3); current_table_name = $3; }
    WHERE condition SEMICOLON
    {
        if (current_table_idx_for_condition == -1)
            printf("ERREUR : table '%s' inexistante.\n", $3);
        else
            printf("SELECT avec WHERE table=%s\n", $3);
    }
    ;

liste_champs:
      STAR { last_select_used_star = 1; $$ = 1; }
    | IDENTIFIER { add_current_select_col($1); $$ = 1; }
    | IDENTIFIER COMMA liste_champs { add_current_select_col($1); $$ = 1 + $3; }
    ;

liste_ident:
      IDENTIFIER { add_current_insert_column($1); $$ = 1; }
    | IDENTIFIER COMMA liste_ident { add_current_insert_column($1); $$ = 1 + $3; }
    ;

condition:
      condition OR condition_term
    | condition_term
    ;

condition_term:
      condition_term AND condition_factor
    | condition_factor
    ;

condition_factor:
      IDENTIFIER EQ valeur
    | IDENTIFIER GT valeur
    | IDENTIFIER LT valeur
    | IDENTIFIER GEQ valeur
    | IDENTIFIER LEQ valeur
    | IDENTIFIER NEQ valeur
    | LPAREN condition RPAREN
    ;

update_stmt:
    UPDATE IDENTIFIER
    {
        current_table_idx_for_condition = find_table($2);
        if (current_table_idx_for_condition == -1)
            printf("ERREUR : table '%s' inexistante.\n", $2);
    }
    SET modifications WHERE condition SEMICOLON
    {
        if (current_table_idx_for_condition != -1)
            printf("UPDATE table=%s\n", $2);
    }
    ;

modifications:
      modification { $$ = 1; }
    | modification COMMA modifications { $$ = 1 + $3; }
    ;

modification:
    IDENTIFIER EQ valeur
    ;

delete_stmt:
    DELETE FROM IDENTIFIER
    {
        current_table_idx_for_condition = find_table($3);
        if (current_table_idx_for_condition == -1)
            printf("ERREUR : table '%s' inexistante.\n", $3);
    }
    WHERE condition SEMICOLON
    {
        if (current_table_idx_for_condition != -1)
            printf("DELETE conditionnel table=%s\n", $3);
    }
  | DELETE FROM IDENTIFIER SEMICOLON
    {
        if (find_table($3) == -1)
            printf("ERREUR : table '%s' inexistante.\n", $3);
        else
            printf("DELETE total table=%s\n", $3);
    }
    ;

drop_table:
    DROP TABLE_ IDENTIFIER SEMICOLON
    {
        if (drop_table_entry($3) == -1)
            printf("ERREUR : table '%s' inexistante.\n", $3);
        else
            printf("DROP TABLE %s\n", $3);
    }
    ;

%%

void yyerror(const char *s){
    fprintf(stderr, "Erreur syntaxique ligne %d : %s\n", yylineno, s);
}