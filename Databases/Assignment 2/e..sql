USE RotaractClub
GO

SELECT * FROM Members 
WHERE Mid IN 
(SELECT Mid FROM MembersInProjects WHERE Mid IN 
(SELECT Mid FROM MembersAtMeetings))

SELECT * FROM Projects
WHERE Pid IN (SELECT Pid FROM MembersInProjects WHERE Name='New Year Party')