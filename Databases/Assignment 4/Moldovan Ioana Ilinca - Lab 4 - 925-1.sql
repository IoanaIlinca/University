-- views
USE RotaractClub
GO


/*DROP TABLE MembersInProjects*/

CREATE VIEW ViewMembers AS --view for one table
SELECT Name FROM Members;




CREATE VIEW ViewMembersAtMeetings AS  -- view for 2 tables
SELECT * FROM Members
INNER JOIN MembersAtMeetings 
ON (MembersAtMeetings.MemberId = Members.Mid)



CREATE VIEW ViewProjectCoordinators AS -- view for 2 tables with group by
SELECT Mid FROM Members
INNER JOIN Projects
ON (Projects.ProjectCoordinator = Members.Mid)
GROUP BY Members.Mid


-- tested tables
DELETE FROM Tables
SELECT * FROM Tables
INSERT INTO Tables VALUES ('Projects');  --single-column primary key with foreign key
INSERT INTO Tables VALUES ('MembersAtMeetings'); --multicolumn primary key
INSERT INTO Tables VALUES ('Members');  --single-column primary key and no foreign key

CREATE TABLE InsertRules (
	TableName varchar(50),
	InsertProcedure varchar(50)
);

SELECT * FROM InsertRules
DROP TABLE InsertRules
INSERT INTO InsertRules VALUES ('Members', 'InsertIntoMembers');
INSERT INTO InsertRules VALUES ('MembersAtMeetings', 'InsertIntoMembersAtMeetings');
INSERT INTO InsertRules VALUES ('Projects', 'InsertIntoProjects');


--tested views
SELECT * FROM Views
INSERT INTO Views VALUES ('ViewMembers');
INSERT INTO Views VALUES ('ViewMembersAtMeetings');
INSERT INTO Views VALUES ('ViewProjectCoordinators');


--tests
SELECT * FROM Tests
insert into Tests values ('10 values and all views');
insert into Tests values ('100 values and all views');
insert into Tests values ('200 values and single table view');

--table tests
insert into TestTables values (1, 1, 10, 1);
insert into TestTables values (1, 2, 10, 2);
insert into TestTables values (1, 3, 10, 3);
insert into TestTables values (2, 1, 100, 1);
insert into TestTables values (2, 2, 100, 2);
insert into TestTables values (2, 3, 100, 3);
insert into TestTables values (3, 1, 200, 1);
insert into TestTables values (3, 2, 200, 2);
insert into TestTables values (3, 3, 200, 3);


--view tests - 

insert into TestViews values (1, 1);
insert into TestViews values (1, 2);
insert into TestViews values (1, 3);
insert into TestViews values (2, 1);
insert into TestViews values (2, 2);
insert into TestViews values (2, 3);
insert into TestViews values (3, 1);




--insert procedures
DROP PROCEDURE InsertIntoMembers;


CREATE PROCEDURE InsertIntoMembers (@entries INT) AS
BEGIN
	PRINT 'inserting ' + convert(varchar(50), @entries) + ' into Members'
	WHILE @entries > 0 BEGIN
		INSERT INTO Members VALUES (
			@entries,
			'Another Name',
			@entries,
			'whatever'
			)
		SET @entries = @entries - 1
	END;
END;

DROP PROCEDURE InsertIntoProjects;


CREATE PROCEDURE InsertIntoProjects (@entries INT) AS 
BEGIN
	PRINT 'inserting ' + convert(varchar(50), @entries) + ' into Projects'
	WHILE @entries > 0
	BEGIN
		INSERT INTO Projects VALUES (
			@entries,
			3,
			'whatever',
			'whatever'
			)
		SET @entries = @entries - 1
	END
END;

DROP PROCEDURE InsertIntoMembersAtMeetings;


CREATE PROCEDURE InsertIntoMembersAtMeetings (@entries INT) AS 
BEGIN
	PRINT 'inserting ' + convert(varchar(50), @entries) + ' into MembersAtMeetings'
	WHILE @entries > 0 BEGIN
		INSERT INTO MembersAtMeetings VALUES (
			@entries,
			1
			)
		SET @entries = @entries - 1
	END
END;

--delete all records from a table with the given id
DROP PROCEDURE DeleteFromTableWithId;


CREATE PROCEDURE DeleteFromTableWithId (@tableId INT) AS 
BEGIN
	DECLARE @tableName varchar(50)
	SET @tableName = (SELECT Name FROM Tables WHERE TableID = @tableId)
	DECLARE @query nvarchar(100)
	SET @query = 'delete from ' + @tableName
	PRINT 'deleting all records from table with id ' + convert(varchar(10), @tableId) + ': ' + @tableName
	EXECUTE sp_executesql @query
END;


--insert a number of records into a table with the given id
DROP PROCEDURE InsertIntoTableWithId;

CREATE PROCEDURE InsertIntoTableWithId (@tableId INT, @numberOfEntries INT) AS 
BEGIN
	
	DECLARE @startTime datetime
	DECLARE @endTime datetime
	DECLARE @tableName varchar(50)
	DECLARE @procedureName varchar(50)
	SET @tableName = (SELECT Name FROM Tables WHERE TableID = @tableId)
	SET @procedureName = (SELECT TOP 1 ir.InsertProcedure FROM InsertRules ir WHERE ir.TableName = @tableName)
	DECLARE @query nvarchar(100)
	SET @query = @procedureName + ' ' + convert(varchar(50), @numberOfEntries)
--	print 'inserting ' + convert(varchar(50), @number_of_entries) + ' entries into table with id ' + convert(varchar(50), @table_id) + ': ' + @table_name
	SET @startTime = getdate()
	EXECUTE sp_executesql @query
	SET @endTime = getdate()
--
	DECLARE @lastRunId INT
	SET @lastRunId = (SELECT TOP 1 TestRunID FROM TestRuns ORDER BY TestRunID DESC)
	INSERT INTO TestRunTables VALUES (@lastRunId, @tableId, @startTime, @endTime)
END;

--execute the view with the given id
DROP PROCEDURE ExecuteViewWithId;


CREATE PROCEDURE ExecuteViewWithId (@viewId INT) AS 
BEGIN
	DECLARE @startTime datetime
	DECLARE @endTime datetime
	DECLARE @viewName varchar(50)
	SET @viewName = (SELECT Name FROM Views WHERE ViewID = @viewId)
	DECLARE @query nvarchar(100)
	SET @query = 'SELECT * FROM ' + @viewName
	PRINT 'executing view with id ' + convert(varchar(50), @viewId) + ': ' + @viewName
	SET @startTime = getdate()
	EXECUTE sp_executesql @query
	SET @endTime = getdate()
--
	DECLARE @lastRunId INT
	SET @lastRunId = (SELECT TOP 1 TestRunID FROM TestRuns ORDER BY TestRunID DESC)
	INSERT INTO TestRunViews VALUES (@lastRunId, @viewId, @startTime, @endTime)
END



--procedure for running a test with the given id and name
DROP PROCEDURE RunTest;

CREATE PROCEDURE RunTest (@testId INT, @testName varchar(50)) AS 
BEGIN
	PRINT 'running test with id ' + convert(varchar(10), @testId) + ': ' + @testName
	INSERT INTO TestRuns VALUES (@testName, NULL, NULL)
	DECLARE @startTime datetime
	DECLARE @endTime datetime
--
-- delete
--
	SET @startTime = getdate()
	DECLARE @numberOfTablesToDeleteLeft INT
	DECLARE @deletedTableId INT
	DECLARE deleteTableCursor CURSOR FOR
		SELECT TableID FROM TestTables WHERE TestID = @testId ORDER BY Position
	OPEN deleteTableCursor
--
	SELECT @numberOfTablesToDeleteLeft = (SELECT count(*) FROM TestTables WHERE TestID = @testId)
--
	WHILE @numberOFTablesToDeleteLeft > 0 
	BEGIN
		FETCH deleteTableCursor INTO @deletedTableId
		EXECUTE DeleteFromTableWithId @deletedTableId
		SET @numberOfTablesToDeleteLeft = @numberOfTablesToDeleteLeft - 1
	END
--
	CLOSE deleteTableCursor
	DEALLOCATE deleteTableCursor
--
-- insert
--
	DECLARE @numberOfTablesToInsertLeft INT
	DECLARE @insertTableId INT
	DECLARE @insertAmmount INT
	DECLARE insertTableCursor CURSOR FOR
		SELECT TableID, NoOfRows FROM TestTables WHERE TestID = @testId ORDER BY Position DESC
	OPEN insertTableCursor
--
	SELECT @numberOfTablesToInsertLeft = (SELECT count(*) FROM TestTables WHERE TestID = @testId)
--
	WHILE @numberOfTablesToInsertLeft > 0 
	BEGIN
		FETCH insertTableCursor INTO @insertTableId, @insertAmmount
		EXECUTE InsertIntoTableWithId @insertTableId, @insertAmmount
		SET @numberOfTablesToInsertLeft = @numberOfTablesToInsertLeft - 1
	END
--
	CLOSE insertTableCursor
	DEALLOCATE insertTableCursor
--
-- views
--
	DECLARE @numberOfViewsLeft INT
	DECLARE @viewId INT
	DECLARE viewCursor CURSOR FOR
		SELECT ViewID FROM TestViews WHERE TestID = @testId
	OPEN viewCursor
--
	SELECT @numberOfViewsLeft = (SELECT count(*) FROM TestViews WHERE TestID = @testId)
--
	WHILE @numberOfViewsLeft > 0 
	BEGIN
		FETCH viewCursor into @viewId
		EXECUTE ExecuteViewWithId @viewId
		SET @numberOfViewsLeft = @numberOfViewsLeft - 1
	END
--
	CLOSE viewCursor
	DEALLOCATE viewCursor
--
	SET @endTime = getdate()
--
	DECLARE @lastRunId INT
	SET @lastRunId = (SELECT TOP 1 TestRunID FROM TestRuns ORDER BY TestRunID DESC)
	UPDATE TestRuns SET
		StartAt = @startTime,
		EndAt = @endtime
	WHERE TestRunID = @lastRunId
END;

SELECT * FROM TestRuns tr;
SELECT * FROM TestRunTables trt;
SELECT * FROM TestRunViews trv;

--iterate over the test table and call run_test for each one
EXECUTE RunAllTests;
DROP PROCEDURE RunAllTests;
CREATE PROCEDURE RunAllTests AS 
BEGIN
	PRINT ''
--	print 'deleting previous results'
--	delete from TestRunTables
--	delete from TestRunViews
--	delete from TestRuns
--
	DECLARE @numberOfTestsLeft INT
	DECLARE @testId INT
	DECLARE @testName varchar(50)
	DECLARE testCursor CURSOR FOR SELECT TestID, Name FROM Tests
	OPEN testCursor
--
	SELECT @numberOfTestsLeft = (SELECT count(*) FROM Tests)
--
	WHILE @numberOfTestsLeft > 0 
	BEGIN
		FETCH testCursor INTO  @testId, @testName
--		print 'Running test ' + @test_name
		EXECUTE RunTest  @testId , @testName
		SET @numberOfTestsLeft = @numberOfTestsLeft - 1
	END
--
	CLOSE testCursor
	DEALLOCATE testCursor
END;


