# GLSimpleSQL — Simplified SQL Interpreter

## Overview

**GLSimpleSQL** is a **simplified SQL query interpreter** implemented in **C**, designed to analyze and validate SQL queries without connecting to a real database. It demonstrates lexical, syntactic, and semantic analysis using **Flex** and **Bison**, along with detailed error handling and statistics.

---

## Features

The interpreter supports the following commands:

* **CREATE TABLE** – define tables and fields
* **INSERT INTO** – insert data into tables
* **SELECT** – query data with optional `WHERE` clauses
* **UPDATE** – modify existing records
* **DELETE** – remove rows or clear a table
* **DROP TABLE** – delete a table

**Supported Types:** `INT`, `FLOAT`, `VARCHAR(n)`, `BOOL`
**Supported Operators:**

* Comparison: `=`, `!=`, `<`, `>`, `<=`, `>=`
* Logical: `AND`, `OR`, `NOT`

---

## Project Structure

```
MiniProjet/
│── src/
│   ├── lexer.l       # Flex lexical analyzer
│   ├── parser.y      # Bison syntax analyzer
│   ├── main.c        # Program entry point
│
│── tests/
│   ├── 01_create_table.sql
│   ├── 02_insert_data.sql
│   ├── 03_select_data.sql
│   ├── 04_update_data.sql
│   ├── 05_delete_data.sql
│   ├── 06_drop_table.sql
│   ├── 07_errors.sql
│
│── build/            # Generated files (bison.tab.c, lex.yy.c)
│
│── Grammar.pdf       # Complete GLSimpleSQL grammar
│── Report.pdf        # Project report
│── README.md         # This file
```

---

## Compilation & Execution

### 1. Generate Flex/Bison files

```bash
win_bison -d parser.y  
win_flex lexer.l
gcc parser.tab.c lex.yy.c main.c -o glsql
```

### 2. Run the interpreter

```bash
./mp file_name.sql
```

### 3. Sample SQL Query

```sql
CREATE TABLE Client (
    numClt INT,
    nom VARCHAR(50),
    prenom VARCHAR(50),
    age INT
);

INSERT INTO Client VALUES (1, 'Alaa', 'Jadallah', 35);
INSERT INTO Client (numClt, nom) VALUES (2, 'Nasrallah');
```

---

## Semantic Actions & Error Handling

* Detects tables, columns, and inserted values
* Checks for table existence, column validity, and duplicates
* Verifies correct number of values in `INSERT` statements
* Handles syntax errors gracefully using **Panic Mode Recovery**

**Example Output:**

```
Reading file: 03_select_data.sql
CREATE TABLE detected: Client
INSERT INTO Client: 4 values
INSERT INTO Client: 2 columns OK
Simple SELECT, table=Client
SELECT with WHERE, table=Client
```

**Error Handling Example:**

```
Reading file: 07_errors.sql
CREATE TABLE detected: Client
INSERT INTO Client: 4 values
Syntax error at line 10
Simple SELECT, table=Client
Syntax error at line 13
SELECT with WHERE, table=Client
```

---

## Deliverables

* Complete source code
* Grammar documentation (*Grammar.pdf*)
* Detailed project report (*Report.pdf*)
* Demonstration video
* README.md

---

## Resources

* [Flex Manual](https://westes.github.io/flex/manual/)
* [Bison Manual](https://www.gnu.org/software/bison/manual/)
* [GCC Tutorial](https://www.youtube.com/watch?v=oC69vlWofJQ&t=41s)
* Visual Studio Code
* LLM: Gemini Pro

---

This project demonstrates **lexical, syntactic, and semantic analysis**, providing a practical introduction to compiler construction in C.
