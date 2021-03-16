USE RotaractClub
GO

SELECT * FROM Projects

DELETE FROM Projects
WHERE NOT Pid=2;

SELECT * FROM Projects

SELECT * FROM MembersAtMeetings

DELETE FROM MembersAtMeetings 
WHERE Mid IN (3, 4);

SELECT * FROM MembersAtMeetings

SELECT * FROM Members

DELETE FROM Members
WHERE Age BETWEEN 29 AND 35;


SELECT * FROM Members
