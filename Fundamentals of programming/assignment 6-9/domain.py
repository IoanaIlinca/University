import datetime
class Person(object):
    # person class
    def __init__(self, personId, name, phoneNumber):
        # constructor: personId - integer, name - string, phoneNumber - integer
        self._personId = personId
        self._name = name
        self._phoneNumber = phoneNumber

    @property
    def personId(self):
        # returns the person id
        return self._personId

    @property
    def name(self):
        #returns the person's name
        return self._name

    @property
    def phoneNumber(self):
        #returns the phone number
        return self._phoneNumber

    def __eq__(self, other):
        # checks if two people are the same
        return self._personId == other._personId

    def __str__(self):
        # prepares the variable for printing
        return str(self._personId)+": "+self._name+" "+str(self._phoneNumber)

    @staticmethod
    def read_person(line):
        parts = line.split(",")
        return Person(int(parts[0].strip()), parts[1].strip(), parts[2].strip())

    @staticmethod
    def write_person(person):
        return str(person._personId) + ", " + person._name + ", " + person._phoneNumber

class Activity(object):
    def __init__(self, activityId, personIdList, dateTime, description):
        # constructor, activityId - integer, personIdList - list, dateTime - date, description - string
        self._activityId = activityId
        self._personIdList = personIdList
        self._dateTime = dateTime
        self._description = description

    @property
    def activityId(self):
        # returns the activity id
        return self._activityId

    @property
    def personIdList(self):
        # returns the person id list
        return self._personIdList

    @property
    def dateTime(self):
        # returns the date and time
        return self._dateTime

    @property
    def description(self):
        # returns the description
        return self._description

    def __eq__(self, other):
        # checks if two activities are equal
        return self._activityId == other._activityId

    def __str__(self):
        # prepares an activity for printing
        finalString = str(self._activityId)+": "+self._description+" on "+ str(self._dateTime) +" with "
        for personId in self._personIdList:
            finalString += str(personId)+", "
        return finalString[:-2]

    def __lt__(self, other):
        return self._dateTime < other._dateTime
    
    def is_going(self, person):
        # checks if a person is in the list of this activity
        if person.personId in self._personIdList:
            return True
        return False

    @staticmethod
    def read_activity(line):
        parts = line.split(",")
        return Activity(int(parts[0].strip()), parts[3].strip(), parts[1].strip(), parts[2].strip())

    @staticmethod
    def write_activity(activity):
        return str(activity._activityId) + ", " + str(activity._dateTime) + ", " + activity._description + ", " + str(activity._personIdList)