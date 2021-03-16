USE RotaractClub
GO


/* a */

CREATE PROCEDURE ChangeColumn AS
	ALTER TABLE AspiringMemebers
	ALTER COLUMN Age varchar(50);
	PRINT ('Changing Age column type')
GO

CREATE PROCEDURE ChangeColumnUndo AS
	ALTER TABLE AspiringMemebers
	ALTER COLUMN Age int;
	PRINT ('Changing Age column type')
GO

/* b */

CREATE PROCEDURE AddColumn AS
	ALTER TABLE AspiringMemebers
	ADD TimeActive int;
	PRINT ('Adding column TimeActive to adpiring members')
GO

CREATE PROCEDURE AddColumnUndo AS
	ALTER TABLE AspiringMemebers
	DROP COLUMN TimeActive;
GO

/* c */

CREATE PROCEDURE AddConstraint AS
	ALTER TABLE AspiringMemebers
	ADD CONSTRAINT AM_Names
	DEFAULT 'Sandnes' FOR Name;
GO

CREATE PROCEDURE AddConstraintUndo AS
	ALTER TABLE AspiringMemebers
	DROP AM_Names;
GO

/* d */

CREATE PROCEDURE RemovePrimaryKey AS
	ALTER TABLE Sponsors
	DROP CONSTRAINT Sid;
GO

CREATE PROCEDURE RemovePrimaryKeyUndo AS
	ALTER TABLE Sponsors
	ADD CONSTRAINT Sid PRIMARY KEY (Sid);
GO

/* e - candidate key */

CREATE PROCEDURE AddCandidateKey AS
	ALTER TABLE Board
	ADD CONSTRAINT President UNIQUE (PresidentId);
GO

CREATE PROCEDURE AddCandidateKeyUndo AS
	ALTER TABLE Sponsors
	DROP CONSTRAINT President;
GO


/* f */

CREATE PROCEDURE AddForeignKey AS
	ALTER TABLE Spronsors
	ADD FOREIGN KEY (Mid) REFERENCES Members(Mid);
GO

CREATE PROCEDURE RemoveForeignKeyUndo AS
	ALTER TABLE Spronsors
	DROP Constraint Mid;
GO

/* g */

CREATE PROCEDURE CreateTable AS
	CREATE TABLE Orders (
    OrderID int NOT NULL,
    Name varchar(50)
);
GO


CREATE PROCEDURE CreateTableUndo AS
	DROP TABLE Orders
GO


/* Change versions */

CREATE PROCEDURE ChangeVersion (@vers INT) AS
	SELECT * FROM Members
GO

EXEC ChangeVersion 2



