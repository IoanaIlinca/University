USE RotaractClub
GO

SELECT Mid, Name
FROM Members
WHERE EXISTS
(SELECT ProjectCoordinator FROM Projects Where Projects.ProjectCoordinator = Members.Mid);

SELECT Mid, Name
FROM Members
WHERE EXISTS
(SELECT * FROM MembersAtMeetings Where MembersAtMeetings.Mid = Members.Mid);