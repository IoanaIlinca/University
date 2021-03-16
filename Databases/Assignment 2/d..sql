USE RotaractClub
GO

SELECT * FROM Members
INNER JOIN MembersAtMeetings ON Members.Mid=MembersAtMeetings.Mid
INNER JOIN Meetings ON Meetings.Meetid=MembersAtMeetings.Meetid
ORDER BY Members.Name

SELECT * FROM MembersAtMeetings
FULL JOIN MembersInProjects ON MembersAtMeetings.Mid=MembersInProjects.Mid
ORDER BY MembersAtMeetings.Meetid

SELECT *
FROM Projects
LEFT JOIN MembersInProjects ON Projects.Pid = MembersInProjects.Pid
ORDER BY Projects.Pid;

SELECT *
FROM Meetings
RIGHT JOIN MembersAtMeetings ON Meetings.Meetid = MembersAtMeetings.Meetid
ORDER BY Meetings.Meetid;