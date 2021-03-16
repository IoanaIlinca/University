USE RotaractClub
GO

SELECT Name FROM Members
UNION ALL
SELECT Name FROM Projects

SELECT  Ocupation FROM Members
WHERE Ocupation='student'
UNION
SELECT Ocupation FROM Members
WHERE Ocupation='teacher'

SELECT Ocupation FROM Members
WHERE Ocupation='student' OR Ocupation='teacher'
