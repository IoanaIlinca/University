USE RotaractClub
GO

SELECT *
FROM (SELECT Name FROM Projects) AS Proj

SELECT *
FROM (SELECT Name, Ocupation FROM Members) AS Mem