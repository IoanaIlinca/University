USE RotaractClub
GO

INSERT INTO Members(Mid, Name, Age, Ocupation)
VALUES (1, 'Pop Alexandru', 22, 'student');

INSERT INTO Members(Mid, Name, Age, Ocupation)
VALUES (2, 'Anca Maria', 28, 'accountant');

INSERT INTO Members(Mid, Name, Age, Ocupation)
VALUES (3, 'Radu Gabriel', 26, 'teacher');

SELECT * FROM Members

INSERT INTO Members(Mid, Name, Age, Ocupation)
VALUES (2, 'Pop Ana', 22, 'student');

SELECT * FROM Members

INSERT INTO Meetings(Meetid, Time, Location, Subject)
VALUES (1, '2020-01-05 18:00:00', 'Str. Napoca, 8', 'First meeting of the year');

INSERT INTO Meetings(Meetid, Time, Location, Subject)
VALUES (2, '2020-01-12 19:00:00', 'Str. Napoca, 8', 'Leftover donations from Christmas');

SELECT * FROM Meetings

INSERT INTO MembersAtMeetings(Mid, Meetid)
VALUES (1, 1);

INSERT INTO MembersAtMeetings(Mid, Meetid)
VALUES (1, 2);

INSERT INTO MembersAtMeetings(Mid, Meetid)
VALUES (3, 1);

INSERT INTO MembersAtMeetings(Mid, Meetid)
VALUES (2, 1);

SELECT * FROM MembersAtMeetings

INSERT INTO Projects(Pid, ProjectCoordinator, Name, Timeframe)
VALUES (1, 1, 'Christmas Concert', '14-24 December 2019');

INSERT INTO Projects(Pid, ProjectCoordinator, Name, Timeframe)
VALUES (2, 1, 'New Year Party', '26 December 2019 - 01 January 2020');

SELECT * FROM Projects