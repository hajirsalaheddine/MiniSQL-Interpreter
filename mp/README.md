

#  — Mini Projet GLSimpleSQL

**Théorie des Langages et Compilation – Année 2025/2026**
**Interpréteur de requêtes SQL simplifiées (Flex & Bison)**


##  1. Description du Projet

Ce projet consiste à développer un **interpréteur de requêtes SQL simplifiées** appelé *GLSimpleSQL*.
Il a été réalisé en langage **C**, avec :

* **Flex** pour l’analyse lexicale
* **Bison** pour l’analyse syntaxique
* Une **gestion sémantique** permettant d’effectuer vérifications et statistiques

 **Important :**
Cet interpréteur **n’exécute pas les requêtes sur une vraie base de données**. Il se limite à analyser, valider et afficher des informations détaillées sur les requêtes SQL.


##  2. Objectifs Pédagogiques

Ce projet permet de :

* Maîtriser **Flex** (analyse lexicale)
* Comprendre et implémenter **Bison** (analyse syntaxique)
* Manipuler une **grammaire formelle**
* Construire des **actions sémantiques**
* Gérer une **table des symboles** (tables, champs, types)
* Détecter et afficher des **erreurs lexicales, syntaxiques et sémantiques**



##  3. Fonctionnalités Supportées

L’interpréteur reconnaît les commandes suivantes du langage **GLSimpleSQL** :

###  CREATE TABLE

Créer une table avec champs et types.

###  INSERT INTO

Insérer des valeurs dans une table.

###  SELECT

Interroger une table, avec ou sans clause WHERE.

###  UPDATE

Modifier des lignes existantes.

###  DELETE

Supprimer des lignes ou vider une table.

###  DROP TABLE

Supprimer une table entière.



##  4. Types et Opérateurs Supportés

### Types :

* `INT`
* `FLOAT`
* `VARCHAR(n)`
* `BOOL`

### Opérateurs :

* Comparaison : `=`, `!=`, `<`, `>`, `<=`, `>=`
* Logiques : `AND`, `OR`, `NOT`



##  5. Structure du Projet

```
MiniProjet/
│── src/
│   ├── lexer.l           -> Analyseur lexical (Flex)
│   ├── parser.y          -> Analyseur syntaxique (Bison)
│   ├── main.c            -> Point d’entrée du programme
│  
│
│── tests/
│   ├── 01_ceate_table.sql
│   ├── 02_insert_data.sql
│   ├── 03_select_data.sql
│   ├── 04_update_data.sql
│   ├── 05_delete_data.sql
│   ├── 06_drop_table.sql
│   ├── 07_erreurs.sql
│
│── build/
│   └── fichiers générés (bison.tab.c, lex.yy.c…)
│
│── Grammaire.pdf        -> Grammaire complète GLSimpleSQL
│── Rapport.pdf          -> Rapport détaillé
│── README.md            ->Ce fichier
```



##  6. Compilation et Exécution

### 1️ Génération des fichiers Flex/Bison

```bash
win_bison -d parser.y  
win_flex lexer.l
gcc parser.tab.c lex.yy.c main.c -o glsql
```

### 2️ Lancer l'interpréteur

```bash
./mp nom_du_fichier
```

### 3️ Lancer une requête SQL simplifiée 
*« À chaque fichier test, j’ajoute une requête SQL simplifiée !!! »*

Exemple : 
*<Pour la requête INSERT_INTO>*

```
CREATE TABLE Client (
    numClt INT,
    nom VARCHAR(50),
    prenom VARCHAR(50),
    age INT
);

INSERT INTO Client VALUES (1, 'Alaa', 'Jadallah', 35);
INSERT INTO Client (numClt, nom) VALUES (2, 'Nasrallah');
```


##  7. Actions Sémantiques Implémentées

Pour chaque requête, le programme affiche des statistiques :

### Exemple SELECT :

```
Lecture du fichier : 03_select_data.sql
CREATE TABLE detecte : Client
INSERT INTO Client : 4 valeurs
INSERT INTO Client : 2 colonnes OK
SELECT simple, table=Client
SELECT avec WHERE table=Client
SELECT avec WHERE table=Client
```

### Vérifications accomplies :

* Table existante / inexistante
* Champs valides
* Nombre de valeurs correct (INSERT)
* Duplications de tables (CREATE)
* Utilisation incorrecte de `*`
* Suppression d’une table inexistante

### Erreurs claires (exemples) :
*<< Grâce à l'implémentation du Panic Mode Recovery, l'analyseur est capable de se resynchroniser après une erreur syntaxique et de continuer le traitement du fichier sans s'interrompre>>*
```
Lecture du fichier : 07_erreurs.sql
CREATE TABLE detecte : Client
INSERT INTO Client : 4 valeurs
Erreur syntaxique ligne 10 : syntax error
SELECT simple, table=Client
Erreur syntaxique ligne 13 : syntax error
SELECT avec WHERE table=Client
```
### Tests d'erreurs traités :

1. Erreurs Syntaxiques (Gérées par Bison + Error Recovery) :
Syntaxes invalides (ex: faute de frappe sur les mots-clés SELET, NTO).

2. Erreurs Sémantiques (Gérées par le code C) :
Table inexistante (lors d'un SELECT ou INSERT).
Table déjà existante (lors d'un CREATE).
Champ inexistant (nom de colonne faux).
Nombre de valeurs incorrect (lors d'un INSERT).


##  9. Livrables Fournis

*  Code source complet
*  Grammaire complète — *Grammaire.pdf*
*  Rapport détaillé — *Rapport.pdf*
*  Vidéo de démonstration
*  README.md (ce fichier)


##  10. Auteurs

Mini projet réalisé par HAJIR SALAH EDDINE, KASRI CHOUAYB, MERIZAK FERDAOUSSE, dans le cadre du module **Théorie des Langages et Compilation (I513)**, filière **LST GL S5**.

Professeur encadrant :
**<3 Madame MOUHNI NAOUAL <3**


##  11. Ressources Utilisées

* Manuel Flex:  https://westes.github.io/flex/manual/
* Manuel Bison:  https://www.gnu.org/software/bison/manual/
* GCC: https://www.youtube.com/watch?v=oC69vlWofJQ&t=41s
* Visual Studio Code.
* LMMS(large langage models): Gemini Pro.




