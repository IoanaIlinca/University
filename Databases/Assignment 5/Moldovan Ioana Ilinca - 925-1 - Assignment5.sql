USE RotaractClub
GO

CREATE TABLE Chefs ( --Ta
Cid INT PRIMARY KEY IDENTITY, --aid
Name VARCHAR(50),
Age INT, --a2
ContestId INT UNIQUE
)

DROP TABLE Chefs

CREATE TABLE Dishes ( --Tb
Did INT PRIMARY KEY IDENTITY, --bid
DName VARCHAR(50),
DQuantity INT, --b2
DOrigin VARCHAR (50)
)

CREATE TABLE Placements ( --Tc
Pid INT PRIMARY KEY IDENTITY, --cid
Cid INT FOREIGN KEY REFERENCES Chefs(Cid), --aid
Did INT FOREIGN KEY REFERENCES Dishes(Did) --bid
)

DROP TABLE Placements

SELECT * FROM Chefs
SELECT * FROM Dishes
SELECT * FROM Placements


INSERT INTO Chefs VALUES('Maria Burlacu', 48, 12)
INSERT INTO Chefs VALUES('Gabriela Pascaru', 35, 11)
INSERT INTO Chefs VALUES('Nicolai Tand', 45, 10)
INSERT INTO Chefs VALUES('Orlando Zaharia', 38, 9)
INSERT INTO Chefs VALUES('Gabi Toader', 33, 8)
INSERT INTO Chefs VALUES('Stefan Popescu', 35, 7)
INSERT INTO Chefs VALUES('Antonio Passarelli', 48, 6)
INSERT INTO Chefs VALUES('Simona Pope', 32, 5)
INSERT INTO Chefs VALUES('Florin Ivan', 47, 4)
INSERT INTO Chefs VALUES('Catalin Scarlatescu', 48, 3)
INSERT INTO Chefs VALUES('Sorin Bontea', 50, 2)
INSERT INTO Chefs VALUES('Florin Dumitrescu', 34, 1)

INSERT INTO Dishes VALUES('Macarons', 500, 'French')
INSERT INTO Dishes VALUES('Biscuits', 600, 'British')
INSERT INTO Dishes VALUES('Cake Pops', 450, 'American')
INSERT INTO Dishes VALUES('Butter Cookies With Raspberry Jam', 300, 'Italian')
INSERT INTO Dishes VALUES('Wedding Cookies', 550, 'Mexican')
INSERT INTO Dishes VALUES('Foie Gras', 300, 'French')
INSERT INTO Dishes VALUES('Carbonara Pasta', 500, 'Italian')
INSERT INTO Dishes VALUES('Mussels', 450, 'Greek')
INSERT INTO Dishes VALUES('Burger', 600, 'American')
INSERT INTO Dishes VALUES('Gomboti', 350, 'Romanian')

INSERT INTO Placements VALUES(2, 1)
INSERT INTO Placements VALUES(2, 3)
INSERT INTO Placements VALUES(2, 4)
INSERT INTO Placements VALUES(8, 1)
INSERT INTO Placements VALUES(8, 2)
INSERT INTO Placements VALUES(8, 5)
INSERT INTO Placements VALUES(12, 6)
INSERT INTO Placements VALUES(12, 7)
INSERT INTO Placements VALUES(7, 7)
INSERT INTO Placements VALUES(4, 7)
INSERT INTO Placements VALUES(10, 8)
INSERT INTO Placements VALUES(1, 8)
INSERT INTO Placements VALUES(5, 8)
INSERT INTO Placements VALUES(5, 9)
INSERT INTO Placements VALUES(6, 9)
INSERT INTO Placements VALUES(9, 9)
INSERT INTO Placements VALUES(3, 10)
INSERT INTO Placements VALUES(11, 10)

--a--
if EXISTS(SELECT name FROM sys.indexes WHERE name = N'idx_Ag' )
	DROP INDEX N_idx_Age on Chefs;
GO

CREATE NONCLUSTERED INDEX N_idx_Age ON Chefs(Age);
GO

SELECT Cid FROM Chefs ORDER BY Cid --clustered index scan
SELECT Age FROM Chefs ORDER BY Age --nonclustered index scan
SELECT ContestId  FROM Chefs ORDER BY ContestId --nonclustered index scan
SELECT Cid FROM Chefs WHERE Cid > 5 --clustered index seek
SELECT ContestId FROM Chefs WHERE ContestId > 9 --nonclustered index seek
SELECT Age FROM Chefs WHERE Age < 40 --nonclustered index seek
--KEY LOOK-UP
SELECT C.Cid, P.Cid FROM Placements P
INNER JOIN Chefs C
on C.Cid = P.Cid
WHERE C.ContestId BETWEEN 10 AND 12
GO

EXEC sp_helpindex 'Chefs'

SELECT TableName = t.name, IndexName = ind.name, IndexId = ind.index_id, ColumnId = ic.index_column_id,
 ColumnName = col.name, ind.*, ic.*, col.*
FROM sys.indexes ind
INNER JOIN sys.index_columns ic ON ind.object_id = ic.object_id and ind.index_id = ic.index_id
INNER JOIN sys.columns col ON ic.object_id = col.object_id and ic.column_id = col.column_id
INNER JOIN sys.tables t ON ind.object_id = t.object_id
WHERE ind.is_primary_key = 0 AND ind.is_unique = 0 AND ind.is_unique_constraint = 0
 AND t.is_ms_shipped = 0
ORDER BY t.name, ind.name, ind.index_id, ic.index_column_id;

SELECT i2.name, i1.user_scans, i1.user_seeks, i1.user_updates,i1.last_user_scan,i1.last_user_seek,
i1.last_user_update
FROM sys.dm_db_index_usage_stats i1
inner join sys.indexes i2 on i1.index_id = i2.index_id
WHERE i1.object_id = OBJECT_ID('Chefs') and i1.object_id = i2.object_id

SELECT OBJECT_NAME(A.[OBJECT_ID]) AS [OBJECT NAME], I.[NAME] AS [INDEX NAME], A.LEAF_INSERT_COUNT,
 A.LEAF_UPDATE_COUNT, A.LEAF_DELETE_COUNT
FROM SYS.DM_DB_INDEX_OPERATIONAL_STATS (NULL,NULL,NULL,NULL ) A
 INNER JOIN SYS.INDEXES AS I ON I.[OBJECT_ID] = A.[OBJECT_ID] AND I.INDEX_ID = A.INDEX_ID
WHERE OBJECTPROPERTY(A.[OBJECT_ID],'IsUserTable') = 1






--b--

SELECT * FROM Dishes WHERE DQuantity <= 400

IF EXISTS (SELECT name FROM sys.indexes WHERE name = N'N_idx')
 DROP INDEX N_idx_Quantity ON Dishes;
GO 

CREATE NONCLUSTERED INDEX N_idx ON Dishes(DName, DQuantity, DOrigin)
	WHERE DQuantity < 500;
GO

--c--

CREATE VIEW test
AS
SELECT c.Name, c.Age, d.DName, d.DOrigin, d.DQuantity
FROM Chefs c INNER JOIN Placements p ON c.Cid=p.Cid
INNER JOIN Dishes d ON p.Did=d.Did
WHERE Age BETWEEN 30 and 40 OR DQuantity > 500
GO
SELECT * FROM test