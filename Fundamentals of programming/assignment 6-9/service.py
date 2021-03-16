from domain import Person, Activity
from repo import Repo
import datetime
import copy
from random import choice
class ServiceError(Exception):
    pass

class ServicePerson():
    def __init__(self, repoPerson, validatorPerson):
        # constructor, repoPerson - repo, validatePerson - ValidatePerson
        self._repoPerson = repoPerson
        self._validatorPerson = validatorPerson
        self._idList = list(range(100))
        self._phoneNumbers = ["0745895746", "0745067980", "0734567243", "0755875464", "0723456789", "0263457836", "0745875746", "0745075980", "0751345627", "0732243598", "0734526778"]
        self._names = ["Dan",'Sam','Boib','Ross','Penny','Lupea','Hatz','Gionule','ION','Danutzu','Han solo','John','Patrick','Dora']
        
    def Initialise(self):
        #adds initial values
        for i in range(10):
            idd = choice(self._idList)
            name = choice(self._names)
            phone = choice(self._phoneNumbers)
            person = Person(idd,name,phone)
            self._repoPerson.add_element(person)
            self._idList.remove(idd)
            self._names.remove(name)
            self._phoneNumbers.remove(phone)

    def find_person_by_id(self, personId):
        for i in self._repoPerson.list:
            if i.personId == personId:
                return [i.name, i.phoneNumber]
            

    def add_person(self, personId, name, phoneNumber):
        #creates, validates and adds a new element, personId - int, name - string, phoneNumber - integer
        newPerson = Person(personId, name, phoneNumber)
        self._validatorPerson.validate_person(newPerson)
        self._repoPerson.add_element(newPerson)

    def remove_person(self, personId):
        # removes a person from the list, given the personId - integer
        person = Person(personId, None, None)
        self._repoPerson.remove_element(person)

    def update_person(self, personId, name, phoneNumber):
        #updates a person, personId - int, name - string, phonenumber - int
        key = Person(personId, None, None)
        oldPerson = self._repoPerson.search(key)
        newPerson = Person(personId, name, phoneNumber)
        self._validatorPerson.validate_person(newPerson)
        self._repoPerson.remove_element(oldPerson)
        self._repoPerson.add_element(newPerson)

    def search_person(self, var):
        li = []
        for i in self._repoPerson.list:
            result = i.name.lower().find(var.lower())
            if result > -1:
                li.append(i)
            result = str(i.phoneNumber).find(var)
            if result > -1:
                li.append(i)

        return li

    def all_to_str(self):
        # converts to string
        return self._repoPerson.all_to_str()

class ServiceActivity():
    def __init__(self, repoActivity, repoPerson, validatorActivity):
        # constructor
        self._repoActivity = repoActivity
        self._repoPerson = repoPerson
        self._validatorActivity = validatorActivity
        self._idList = list(range(100))
        self._dates = [datetime.datetime.strptime("30-11-2019 15:30","%d-%m-%Y %H:%M"),
            datetime.datetime.strptime("12-12-2019 14:30","%d-%m-%Y %H:%M"),
            datetime.datetime.strptime("22-02-2020 18:20","%d-%m-%Y %H:%M"),
            datetime.datetime.strptime("12-11-2019 10:30","%d-%m-%Y %H:%M"),
            datetime.datetime.strptime("30-03-2020 12:30","%d-%m-%Y %H:%M"),
            datetime.datetime.strptime("4-03-2020 15:30","%d-%m-%Y %H:%M"),
            datetime.datetime.strptime("15-02-2020 15:30","%d-%m-%Y %H:%M"),
            datetime.datetime.strptime("10-11-2020 18:30","%d-%m-%Y %H:%M"),
            datetime.datetime.strptime("14-08-2020 15:30","%d-%m-%Y %H:%M"),
            datetime.datetime.strptime("9-05-2020 15:30","%d-%m-%Y %H:%M")
        ]
        self._description = ["picnic", "camping", "exhibition", "dinner", "lunch", "brunch", "breakfast", "math", "football", "tennis"]

    def Initialise(self, repoPerson):
        #adds initial values
        for i in range(10):
            idd = choice(self._idList)
            li = copy.deepcopy(repoPerson)
            idpeople = []
            for i in range(0, choice(range(2, 6))):
                var = choice(li.list)
                idpeople.append(var.personId)
                li.list.remove(var)
            date = choice(self._dates)
            description = choice(self._description)
            activity = Activity(idd, idpeople, date, description)
            self._repoActivity.add_element(activity)
            self._idList.remove(idd)
            self._dates.remove(date)
            self._description.remove(description)

    def add_activity(self, activityId, personIdList, dateTime, description):
        # adds a new activity, by int, list, date and string
        newActivity = Activity(activityId, personIdList, dateTime, description)
        self._validatorActivity.validate_activity(newActivity)
        for personId in personIdList:
            person = Person(personId, None, None)
            person = self._repoPerson.search(person)
            activityList = self._repoActivity.get_all()
            for activity in activityList:
                if activity.dateTime == dateTime and activity.is_going(person):
                    raise ServiceError("time slot already alloted for at least one person in given list!\n")
        self._repoActivity.add_element(newActivity)

    def remove_activity(self, acitivityId):
        # removes an activity by activityId - int
        activity = Activity(acitivityId, None, None, None)
        self._repoActivity.remove_element(activity)

    def update_activity(self, activityId, personIdList, dateTime, description):
        # updates an activity by int, list, date and string
        key = Activity(activityId, None, None, None)
        oldActivity = self._repoActivity.search(key)
        newActivity = Activity(activityId, personIdList, dateTime, description)
        self._validatorActivity.validate_activity(newActivity)
        for personId in personIdList:
            person = Person(personId, None, None)
            person = self._repoPerson.search(person)
            activityList = self._repoActivity.get_all()
            for activity in activityList:
                if activity.activityId != activityId and activity.dateTime == dateTime and activity.is_going(person):
                    raise ServiceError("time slot already alloted for at least one person in given list!\n")
        self._repoActivity.remove_element(oldActivity)
        self._repoActivity.add_element(newActivity)

    def search_activity(self, var):
        li = []
        for i in self._repoActivity.list:
            result = i.description.lower().find(str(var).lower())
            if result > -1:
                li.append(i)
            result = str(i.dateTime).lower().find(str(var).lower())
            if result > -1:
                li.append(i)
        
        return li

    def list_activities_date(self, var):
        li = []
        for i in self._repoActivity.list:
            result = i.dateTime.strftime("%d-%m-%Y %H:%M:%S").find(str(var).lower(), 0, 10)
            if result > -1:
                li.append(i)

        for i in range(0, len(li)):
            for j in range(i + 1, len(li)):
                if li[i] > li[j]:
                    aux = li[i]
                    li[i] = li[j]
                    li[j] = aux
            
        return li

    def list_activities_person(self, var):
        li = []
        for i in self._repoActivity.list:
            if int(var) in i.personIdList:
                li.append(i)
        return li

    def make_dates_list(self):
        #li = [[date, activities on that date]]
        li = []
        for i in self._repoActivity.list:
            date = i.dateTime.strftime("%d-%m-%Y")
            ok = True
            for j in li:
                if j[0] == date:
                    ok = False
                    break

            if ok == True:
                li.append([date, self.list_activities_date(date)])


        return li

    def list_busiest_dates(self):
        li = self.make_dates_list()
        for i in range(0, len(li)):
            for j in range(i + 1, len(li)):
                if len(li[i][1]) < len(li[j][1]):
                    aux = li[i]
                    li[i] = li[j]
                    li[j] = aux

        return li

    def update_activity_removed_person(self, personId):
        li = []
        for i in self._repoActivity.list:
            for j in i.personIdList:
                if j == personId:
                    li.append(i.activityId)
                    i.personIdList.remove(j)
        return li

    def find_activity_by_id(self, activityId):
        for i in self._repoActivity.list:
            if i.activityId == activityId:
                return [i.personIdList, i.dateTime, i.description]

    def all_to_str(self):
        # turns the list into a string
        return self._repoActivity.all_to_str()


class ServiceStack():
    def __init__(self, repoPerson, repoActivity):
        self._repoUndo = Repo([])
        self._repoRedo = Repo([])
        self._repoPerson = repoPerson
        self._repoActivity = repoActivity

    def add_action(self, stackType, lis):
        if stackType == "undo":
            self._repoUndo.add_element(lis)
            #print(self._repoUndo.list[len(self._repoUndo.list) - 1])
        else:
            self._repoRedo.add_element(lis)

    def undo(self):
        cmd = copy.deepcopy((self._repoUndo.list.pop()))
        

        if cmd[0] == "add_person":
            self.add_action("redo", cmd)
            person = Person(cmd[1], None, None)
            self._repoPerson.remove_element(person)

        if cmd[0] == "remove_person":
            self.add_action("redo", cmd)
            person = Person(cmd[1], cmd[2], cmd[3])
            self._repoPerson.add_element(person)
            for i in self._repoActivity.list:
                if i.activityId in cmd[4]:
                    i.personIdList.append(cmd[1])

        if cmd[0] == "add_activity":
            self.add_action("redo", cmd)
            activity = Activity(cmd[1], None, None, None)
            self._repoActivity.remove_element(activity)

        if cmd[0] == "remove_activity":
            self.add_action("redo", cmd)
            activity = Activity(cmd[1], cmd[2], cmd[3], cmd[4])
            self._repoActivity.add_element(activity)

        if cmd[0] == "update_person":
            for i in self._repoPerson.list:
                if i.personId == cmd[1]:
                    self.add_action("redo", ["update_person", i.personId, i.name, i.phoneNumber])
                    newPerson = Person(cmd[1], cmd[2], cmd[3])
                    self._repoPerson.remove_element(i)
                    self._repoPerson.add_element(newPerson)
                    break

        if cmd[0] == "update_activity":
            for i in self._repoActivity.list:
                if i.activityId == cmd[1]:
                    self.add_action("redo", ["update_activity", i.activityId, i.personIdList, i.dateTime, i.description])
                    newActivity = Activity(cmd[1], cmd[2], cmd[3], cmd[4])
                    self._repoActivity.remove_element(i)
                    self._repoActivity.add_element(newActivity)
                    break
            


    def redo(self):
        cmd = copy.deepcopy((self._repoRedo.list.pop()))
        self.add_action("undo", cmd)

        if cmd[0] == "add_person":
            person = Person(cmd[1], cmd[2], cmd[3])
            self._repoPerson.add_element(person)

        if cmd[0] == "remove_person":
            person = Person(cmd[1], None, None)
            self._repoPerson.remove_element(person)

        if cmd[0] == "add_activity":
            activity = Activity(cmd[1], cmd[2], cmd[3], cmd[4])
            self._repoActivity.add_element(activity)

        if cmd[0] == "remove_activity":
            activity = Activity(cmd[1], None, None, None)
            self._repoActivity.remove_element(activity)

        if cmd[0] == "update_person":
            for i in self._repoPerson.list:
                if i.personId == cmd[1]:
                    self.add_action("undo", ["update_person", i.personId, i.name, i.phoneNumber])
                    newPerson = Person(cmd[1], cmd[2], cmd[3])
                    self._repoPerson.remove_element(i)
                    self._repoPerson.add_element(newPerson)
                    break


        
                    

        
