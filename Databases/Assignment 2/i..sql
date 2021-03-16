USE RotaractClub
GO

SELECT Name
FROM Members
WHERE Mid = ANY (SELECT Mid FROM MembersAtMeetings);

SELECT Name
FROM Members
WHERE Mid IN (SELECT Mid FROM MembersAtMeetings);

SELECT Name
FROM Members
WHERE Mid > ANY (SELECT Mid FROM MembersInProjects);

SELECT Name
FROM Members
WHERE Mid > (SELECT MIN(Mid) FROM MembersInProjects)

SELECT TOP 1 *
FROM Projects
WHERE ProjectCoordinator != ALL(SELECT Mid FROM Members WHERE AGE > 30)

SELECT TOP 2*
FROM Projects
WHERE ProjectCoordinator NOT IN (SELECT Mid FROM Members WHERE AGE > 30)

SELECT DISTINCT Mid
FROM MembersAtMeetings
WHERE Mid > ALL(SELECT ProjectCoordinator FROM Projects)

SELECT DISTINCT Mid 
FROM MembersAtMeetings
WHERE Mid > (SELECT MAX(ProjectCoordinator) FROM Projects)