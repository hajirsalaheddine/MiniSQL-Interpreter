CREATE TABLE Client (
    numClt INT,
    nom VARCHAR(50),
    prenom VARCHAR(50),
    age INT
);
INSERT INTO Client VALUES (1, 'Mehdi', 'Jadallah', 35);
INSERT INTO Client (numClt, nom) VALUES (2, 'Nasrallah');

SELECT * FROM Client;
SELECT nom, prenom FROM Client WHERE numClt = 2;

SELECT * FROM Client WHERE age > 30 AND nom = 'Mehdi';
