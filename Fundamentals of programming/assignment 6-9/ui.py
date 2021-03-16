from repo import RepoError
from validator import ValidatorError
from service import ServiceError
import datetime
import copy
class UiError(Exception):
    pass

class Menu():
    def __init__(self, servicePerson, serviceActivity, serviceStack):
        self._servicePerson = servicePerson
        self._serviceActivity = serviceActivity
        self._serviceStack = serviceStack
        self._commandsDict = {
            "+p": self.add_person,
            "+a": self.add_activity,
            "up": self.update_person,
            "ua": self.update_activity,
            "-p": self.remove_person,
            "-a": self.remove_activity,
            "lp": self.list_people,
            "la": self.list_activities,
            "sp": self.search_person,
            "sa": self.search_activity,
            "lad": self.list_activities_date,
            "lap": self.list_activities_person,
            "lbd": self.list_busiest_dates,
            "undo": self.undo,
            "redo": self.redo
            }

    def print_menu(self):
        print("Command menu:")
        print("  +p  add person")
        print("  +a  add activity")
        print("  -p  remove person")
        print("  -a  remove activity")
        print("  up  update person by id")
        print("  ua  update activity by id")
        print("  lp  list all people")
        print("  la  list all activities")
        print("  sp  search for person")
        print("  sa  search for activity")
        print("  lad  list actvities for a given date")
        print("  lap  list actvities for a given person")
        print("  lbd  list busiest dates")
        print("  undo")
        print("  redo")
        print("   x  close application")
        print()

    def start(self):
        self.print_menu()
        while True:
            command = input(">>>")
            if command == "x":
                return
            if command not in self._commandsDict:
                print("UI Error: invalid command!\n")
            else:
                try:
                    self._commandsDict[command]()
                except ValidatorError as errorMessage:
                    print("Validator Error:\n"+str(errorMessage))
                except RepoError as errorMessage:
                    print("Repo Error:\n"+str(errorMessage))
                except ServiceError as errorMessage:
                    print("Service Error:\n"+str(errorMessage))
                except UiError as errorMessage:
                    print("Ui Error:\n"+str(errorMessage))

    def add_person(self):
        personId = input("input person id: ")
        try:
            personId = int(personId)
        except Exception:
            raise UiError("person id must be integer!\n")
        name = input("input name: ")
        phoneNumber = input("input phone number: ")
        self._servicePerson.add_person(personId, name, phoneNumber)
        self._serviceStack.add_action("undo", ["add_person", personId, name, phoneNumber])
        print()

    def add_activity(self):
        activityId = input("input activity id: ")
        try:
            activityId = int(activityId)
        except Exception:
            raise UiError("activity id must be integer!\n")
        numberOfPeople = input("input number of people: ")
        try:
            numberOfPeople = int(numberOfPeople)
        except Exception:
            raise UiError("number of people must be pozitive number!\n")
        if numberOfPeople < 0:
            raise UiError("number of people must be pozitive number!\n")
        personIdList = []
        for i in range(0, numberOfPeople):
            personId = input("input person id: ")
            try:
                personId = int(personId)
            except Exception:
                raise UiError("person id must be integer!\n")
            personIdList.append(personId)
        dateTime = input("input date and time (format:DD-MM-YYYY HH:MM): ")
        try:
            dateTime = datetime.datetime.strptime(dateTime,"%d-%m-%Y %H:%M")
        except Exception:
            raise UiError("date and time in invalid format!\n")
        description = input("input description: ")
        self._serviceActivity.add_activity(activityId, personIdList, dateTime, description)
        self._serviceStack.add_action("undo", ["add_activity", activityId, personIdList, dateTime, description])
        print()

    def remove_person(self):
        personId = input("input person id: ")
        try:
            personId = int(personId)
        except Exception:
            raise UiError("person id must be integer!\n")
        activitiesWithThatPersonList = copy.deepcopy(self._serviceActivity.update_activity_removed_person(personId))
        self._serviceStack.add_action("undo", ["remove_person", personId, self._servicePerson.find_person_by_id(personId)[0], self._servicePerson.find_person_by_id(personId)[1], activitiesWithThatPersonList])
        self._servicePerson.remove_person(personId)
        print()

    def remove_activity(self):
        activityId = input("input activity id: ")
        try:
            activityId = int(activityId)
        except Exception:
            raise UiError("activity id must be integer!\n")
        self._serviceStack.add_action("undo", ["remove_activity", activityId, self._serviceActivity.find_activity_by_id(activityId)[0], self._serviceActivity.find_activity_by_id(activityId)[1], self._serviceActivity.find_activity_by_id(activityId)[2]])
        self._serviceActivity.remove_activity(activityId)
        print()

    def update_person(self):
        personId = input("input person id: ")
        try:
            personId = int(personId)
        except Exception:
            raise UiError("person id must be integer!\n")
        name = input("input name: ")
        phoneNumber = input("input phone number: ")
        self._serviceStack.add_action("undo", ["update_person",personId, self._servicePerson.find_person_by_id(personId)[0], self._servicePerson.find_person_by_id(personId)[1]])
        self._servicePerson.update_person(personId, name, phoneNumber)
        print()

    def update_activity(self):
        activityId = input("input activity id: ")
        try:
            activityId = int(activityId)
        except Exception:
            raise UiError("activity id must be integer!\n")
        numberOfPeople = input("input number of people: ")
        try:
            numberOfPeople = int(numberOfPeople)
        except Exception:
            raise UiError("number of people must be pozitive number!\n")
        if numberOfPeople < 0:
            raise UiError("number of people must be pozitive number!\n")
        personIdList = []
        for i in range(0, numberOfPeople):
            personId = input("input person id: ")
            try:
                personId = int(personId)
            except Exception:
                raise UiError("person id must be integer!\n")
            personIdList.append(personId)
        dateTime = input("input date and time (format:DD-MM-YYYY HH:MM): ")
        try:
            dateTime = datetime.datetime.strptime(dateTime,"%d-%m-%Y %H:%M")
        except Exception:
            raise UiError("date and time in invalid format!\n")
        description = input("input description: ")
        self._serviceStack.add_action("undo", ["update_activity", activityId, self._serviceActivity.find_activity_by_id(activityId)[0], self._serviceActivity.find_activity_by_id(activityId)[1], self._serviceActivity.find_activity_by_id(activityId)[2]])
        self._serviceActivity.update_activity(activityId, personIdList, dateTime, description)
        print()

    def list_people(self):
        print(self._servicePerson.all_to_str())

    def list_activities(self):
        print(self._serviceActivity.all_to_str())

    def search_person(self):
        Input = input("Write the name or the phone number: ")
        res = self._servicePerson.search_person(Input)
        if len(res) == 0:
            print("There is no such person!")
        else:
            for i in res:
                print(str(i))

    def search_activity(self):
        Input = input("Write the description or the date and time (format:DD-MM-YYYY HH:MM): ")
        res = self._serviceActivity.search_activity(Input)
        if len(res) == 0:
            print("There is no such activity!")
        else:
            for i in res:
                print(str(i))

    def list_activities_date(self):
        Input = input("Input date (format:DD-MM-YYYY): ")
        li = self._serviceActivity.list_activities_date(Input)
        if len(li) == 0:
            print("No activities on this date!")
        else:
            for i in li:
                print(str(i))

    def list_activities_person(self):
        Input = input("Input person id: ")
        ok = False
        while ok == False:
            for i in self._servicePerson._repoPerson.list:
                if i.personId == int(Input):
                    ok = True

            if ok == False:
                Input = input("This person does not exist! Input a valid id: ")

        li = self._serviceActivity.list_activities_person(Input)
        if len(li) == 0:
            print("No activities for this id!")
        else:
            for i in li:
                print(str(i))

    def list_busiest_dates(self):
        activity_list = self._serviceActivity.list_busiest_dates()
        for i in activity_list:
            if len(i[1]) > 1:
                print(str(i[0]) + " - " + str(len(i[1])) + " activities:")
            else:
                print(str(i[0]) + " - " + str(len(i[1])) + " activity:")
            for j in i[1]:
                print(str(j))
            print("\n")

    def undo(self):
        self._serviceStack.undo()

    def redo(self):
        self._serviceStack.redo()