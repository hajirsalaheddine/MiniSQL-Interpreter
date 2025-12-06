


INSERT INTO Client VALUES (1, 'Alaa', 'Jadallah', 35);
INSERT NTO Client (numClt, nom) VALUES (2, 'Nasrallah');

SELECT * FROM Client;
SEECT nom, prenom FROM Client WHERE numClt = 2;
SELECT * FROM Client WHERE age > 30 AND nom = 'Alaa';

UPDATE Client SET age = 36 WHERE numClt = 1;
UPDATE Client SET nom = 'Saif', age = 40 WHERE numClt = 2;

DELETE FROM Client WHERE age < 18;
DELETE F\ROM Client;

DROPp TABLE Client;
