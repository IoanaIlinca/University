USE RotaractClub
GO

SELECT * FROM Members

UPDATE Members
SET Age=23
WHERE Name='Pop Alexandru' AND Mid IS NOT NULL;

SELECT * FROM Members

SELECT * FROM Projects

UPDATE Projects
SET ProjectCoordinator=2
WHERE ProjectCoordinator=1

SELECT * FROM Projects

SELECT * FROM Meetings

UPDATE Meetings
SET Subject='Happy new year!'
WHERE Meetid = 1 OR Location LIKE '%8'

SELECT * FROM Meetings

SELECT * FROM MembersAtMeetings