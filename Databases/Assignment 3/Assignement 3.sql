USE RotaractClub
GO


/* a */

CREATE PROCEDURE ChangeColumn AS
	ALTER TABLE AspiringMemebers
	ALTER COLUMN Age varchar(50);
	PRINT ('Changing Age column type')
	UPDATE Versions SET Version = 1
GO



CREATE PROCEDURE ChangeColumnUndo AS
	ALTER TABLE AspiringMemebers
	ALTER COLUMN Age int;
	PRINT ('Changing Age column type')
	UPDATE Versions SET Version = 0
GO

/* b */

CREATE PROCEDURE AddColumn AS
	ALTER TABLE AspiringMemebers
	ADD TimeActive int;
	PRINT ('Adding column TimeActive to adpiring members')
	UPDATE Versions SET Version = 2
GO

CREATE PROCEDURE AddColumnUndo AS
	ALTER TABLE AspiringMemebers
	DROP COLUMN TimeActive;
	PRINT ('Removing column TimeActive to adpiring members')
	UPDATE Versions SET Version = 1
GO

/* c */

CREATE PROCEDURE AddConstraint AS
	ALTER TABLE AspiringMemebers
	ADD CONSTRAINT AM_Names
	DEFAULT 'Sandnes' FOR Name;
	PRINT ('Adding constraint for Names to aspiring members')
	UPDATE Versions SET Version = 3
GO

CREATE PROCEDURE AddConstraintUndo AS
	ALTER TABLE AspiringMemebers
	DROP AM_Names;
	PRINT ('Removing constraint for Names to aspiring members')
	UPDATE Versions SET Version = 2
GO

/* d */

CREATE PROCEDURE RemovePrimaryKey AS
	ALTER TABLE Board
	DROP CONSTRAINT PK__Board__C6D111C933F6AB2A;
	PRINT ('Removing PK for Board Bid')
	UPDATE Versions SET Version = 4
GO

CREATE PROCEDURE RemovePrimaryKeyUndo AS
	ALTER TABLE Board
	ADD CONSTRAINT PK__Board__C6D111C933F6AB2A PRIMARY KEY (Bid);
	PRINT ('Adding PK for Board Bid')
	UPDATE Versions SET Version = 3
GO



/* e - candidate key */

CREATE PROCEDURE AddCandidateKey AS
	ALTER TABLE Board
	ADD CONSTRAINT President UNIQUE (PresidentId);
	PRINT ('Adding Candidate key for Board President')
	UPDATE Versions SET Version = 5
GO

CREATE PROCEDURE AddCandidateKeyUndo AS
	ALTER TABLE Board
	DROP CONSTRAINT President;
	PRINT ('Removing Candidate key for Board President')
	UPDATE Versions SET Version = 4
GO


/* f */

CREATE PROCEDURE AddForeignKey AS
	ALTER TABLE Sponsors
	ADD CONSTRAINT FK_Mid
	FOREIGN KEY (Mid) REFERENCES Members(Mid);
	PRINT ('Adding Foreign key for sponsors (responsible member)')
	UPDATE Versions SET Version = 6
GO

CREATE PROCEDURE AddForeignKeyUndo AS
	ALTER TABLE Sponsors
	DROP Constraint FK_Mid;
	PRINT ('Removing Foreign key for sponsors (responsible member)')
	UPDATE Versions SET Version = 5
GO

/* g */

CREATE PROCEDURE CreateTable AS
	CREATE TABLE Orders (
    OrderID int NOT NULL,
    Name varchar(50)
);
	PRINT ('Adding table Orders')
	UPDATE Versions SET Version = 7
GO


CREATE PROCEDURE CreateTableUndo AS
	DROP TABLE Orders
	PRINT ('Removing table Orders')
	UPDATE Versions SET Version = 6
GO

CREATE PROCEDURE UpdateVersion (@currentVersion  INT) 
AS
	if @currentVersion = 0
		exec ChangeColumn
	else if @currentVersion = 1
			exec AddColumn
	else if @currentVersion = 2
			exec AddConstraint
	else if @currentVersion = 3
			exec RemovePrimaryKey
	else if @currentVersion = 4
			exec AddCandidateKey
	else if @currentVersion = 5
			exec AddForeignKey
	else if @currentVersion = 6
			exec CreateTable
GO

CREATE PROCEDURE DowngradeVersion (@currentVersion INT)
AS
	if @currentVersion = 1
			exec ChangeColumnUndo
	else if @currentVersion = 2
			exec AddColumnUndo
	else if @currentVersion = 3
			exec AddConstraintUndo
	else if @currentVersion = 4
			exec RemovePrimaryKeyUndo
	else if @currentVersion = 5
			exec AddCandidateKeyUndo
	else if @currentVersion = 6
			exec AddForeignKeyUndo
	else if @currentVersion = 7
			exec CreateTableUndo

	
GO




/* Change versions */

CREATE PROCEDURE ChangeVersion (@vers INT) AS
	DECLARE @currentVersion INT
	SET @currentVersion = (SELECT Version FROM Versions)
	IF (@vers > 7 OR @vers < 0)
		BEGIN
			PRINT ('Invalid version!')
			RETURN 
		END

	WHILE (@vers > @currentVersion)
		BEGIN
			EXEC UpdateVersion @currentVersion
			SET @currentVersion = @currentVersion + 1
		END

	WHILE (@vers < @currentVersion)
		BEGIN
			EXEC DowngradeVersion @currentVersion
			SET @currentVersion = @currentVersion - 1
		END

	UPDATE Versions SET Version = @vers
GO

EXEC ChangeVersion 1
EXEC AddColumnUndo
EXEC AddConstraintUndo
EXEC RemovePrimaryKeyUndo
EXEC AddCandidateKeyUndo
EXEC AddForeignKey

UPDATE Versions SET Version = 3

SELECT * FROM Versions
/*
DROP PROCEDURE AddColumn
DROP PROCEDURE AddColumnUndo
DROP PROCEDURE ChangeColumn
DROP PROCEDURE ChangeColumnUndo
DROP PROCEDURE AddConstraint
DROP PROCEDURE AddConstraintUndo
DROP PROCEDURE RemovePrimaryKey
DROP PROCEDURE RemovePrimaryKeyUndo
DROP PROCEDURE AddCandidateKey
DROP PROCEDURE AddCandidateKeyUndo
DROP PROCEDURE AddForeignKey
DROP PROCEDURE AddForeignKeyUndo
DROP PROCEDURE CreateTable
DROP PROCEDURE CreateTableUndo
DROP PROCEDURE UpdateVersion
DROP PROCEDURE DowngradeVersion
DROP PROCEDURE ChangeVersion

*/

