CREATE DATABASE RotaractClub
GO
USE RotaractClub
GO

CREATE TABLE Members
(Mid INT PRIMARY KEY,
Name varchar(50),
Age INT,
Ocupation varchar(50)
)

CREATE TABLE Board
(Bid INT PRIMARY KEY,
Mandate VARCHAR(50),
PresidentId INT FOREIGN KEY REFERENCES Members(Mid),
VicePresidentId INT FOREIGN KEY REFERENCES Members(Mid),
SecretaryId INT FOREIGN KEY REFERENCES Members(Mid),
TreasurerId INT FOREIGN KEY REFERENCES Members(Mid),
PRId INT FOREIGN KEY REFERENCES Members(Mid)
)

CREATE TABLE Projects
(Pid INT PRIMARY KEY,
ProjectCoordinator INT FOREIGN KEY REFERENCES Members(Mid),
Namen varchar(50),
Timeframe varchar(50)
)

CREATE TABLE Sponsors
(Sid INT PRIMARY KEY,
Name varchar(50)
)

CREATE TABLE GroupsOfAspiringMembers
(Gid INT PRIMARY KEY,
GroupCoordinator INT FOREIGN KEY REFERENCES Members(Mid)
)

CREATE TABLE AspiringMemebers 
(MAid INT PRIMARY KEY,
Name varchar(50),
Age int,
Ocupation varchar(50),
AssignedGroup INT FOREIGN KEY REFERENCES GroupsOfAspiringMembers(Gid)
)

CREATE TABLE Meetings
(Meetid INT PRIMARY KEY,
Time datetime,
Location varchar(50),
Subject varchar(50)
)

CREATE TABLE MembersAtMeetings
(Mid INT FOREIGN KEY REFERENCES Members(Mid),
Meetid INT FOREIGN KEY REFERENCES Meetings(Meetid),
CONSTRAINT pk_MembersAtMeetings PRIMARY KEY (Mid, Meetid)
)

CREATE TABLE MembersInProjects
(Mid INT FOREIGN KEY REFERENCES Members(Mid),
Pid INT FOREIGN KEY REFERENCES Projects(Pid),
CONSTRAINT pk_MembersInProjects PRIMARY KEY (Mid, Pid)
)

CREATE TABLE SponsorsForProjects
(Sid INT FOREIGN KEY REFERENCES Sponsors(Sid),
Pid INT FOREIGN KEY REFERENCES Projects(Pid),
CONSTRAINT pk_SponsorsForProjects PRIMARY KEY (Sid, Pid),
Sum float(45)
)