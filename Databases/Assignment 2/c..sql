USE RotaractClub
GO

SELECT Name FROM Members WHERE Name LIKE '%a'
EXCEPT
SELECT Name FROM Members WHERE Ocupation NOT LIKE '%t'

SELECT Name FROM Members 
WHERE Name LIKE '%a' AND Ocupation NOT IN (SELECT Ocupation FROM Members WHERE Ocupation NOT LIKE 'A%')

SELECT Name FROM Members WHERE Name LIKE '%a'
EXCEPT
SELECT Name FROM Members WHERE Name LIKE 'A%'


SELECT Name FROM Members 
WHERE Name LIKE '%a' AND Name NOT IN (SELECT Name FROM Members WHERE Name LIKE 'A%')

