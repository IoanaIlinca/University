USE RotaractClub
GO

SELECT Name FROM Members WHERE Name LIKE '%a'
INTERSECT
SELECT Name FROM Members WHERE Ocupation LIKE '%t'

SELECT Name 
FROM Members 
WHERE Name LIKE '%a' AND Ocupation IN (SELECT Ocupation FROM Members WHERE Ocupation LIKE '%t')

SELECT Name FROM Members WHERE Age != 23
INTERSECT
SELECT Name FROM Members WHERE Age != 28

SELECT Name 
FROM Members 
WHERE Age != 23 AND Age IN (SELECT Age FROM Members WHERE Age != 28)


