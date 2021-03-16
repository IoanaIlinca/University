USE RotaractClub
GO



SELECT Max(Age), Ocupation
FROM Members
GROUP BY Ocupation
HAVING Max(Age) < 28

SELECT Min(Mid), Meetid
FROM MembersAtMeetings
GROUP BY Meetid

Select Distinct Subject from Meetings

SELECT COUNT(Pid), ProjectCoordinator
FROM Projects
GROUP BY ProjectCoordinator
HAVING COUNT(PID) < (SELECT COUNT(Mid) FROM Members)

SELECT * from Meetings

SELECT COUNT(Meetid), Location
FROM Meetings
GROUP BY Location
HAVING Count(Meetid) NOT IN (SELECT Age FROM Members)