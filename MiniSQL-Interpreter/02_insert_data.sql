CREATE TABLE Client (
    numClt INT,
    nom VARCHAR(50),
    prenom VARCHAR(50),
    age INT
);

INSERT INTO Client VALUES (1, 'Alaa', 'Jadallah', 35);
INSERT INTO Client (numClt, nom) VALUES (2, 'Nasrallah');