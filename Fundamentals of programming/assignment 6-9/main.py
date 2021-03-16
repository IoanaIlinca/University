from ui import Menu
from test_all import run_all_tests
from service import ServiceActivity, ServicePerson, ServiceStack
from repo import Repo, fileRepo, pickleRepo
from validator import ValidatorPerson, ValidatorActivity
from domain import Person, Activity

def run():
    validatorPerson = ValidatorPerson()
    validatorActivity = ValidatorActivity()
    with open("settings.properties","r") as readFile:
        line = readFile.readline()
        line = line.split()

        if line[2] == "inMemory":
            repoPerson = Repo([])
            repoActivity = Repo([])
            servicePerson = ServicePerson(repoPerson, validatorPerson)
            servicePerson.Initialise()
            serviceActivity = ServiceActivity(repoActivity, repoPerson, validatorActivity)
            serviceActivity.Initialise(repoPerson)
            serviceStack = ServiceStack(repoPerson, repoActivity)

        elif line[2] == "fileRepo":
            line = readFile.readline()
            line = line.split()
            repoPerson = fileRepo(line[2], Person.read_person, Person.write_person)
            line = readFile.readline()
            line = line.split()
            repoActivity = fileRepo(line[2], Activity.read_activity, Activity.write_activity)
            servicePerson = ServicePerson(repoPerson, validatorPerson)
            serviceActivity = ServiceActivity(repoActivity, repoPerson, validatorActivity)
            serviceStack = ServiceStack(repoPerson, repoActivity)
            
        elif line[2] == "pickleRepo":
            line = readFile.readline()
            line = line.split()
            repoPerson = pickleRepo(line[2])                  
            line = readFile.readline()
            line = line.split()
            repoActivity = pickleRepo(line[2])  
            servicePerson = ServicePerson(repoPerson, validatorPerson)
            serviceActivity = ServiceActivity(repoActivity, repoPerson, validatorActivity)
            serviceStack = ServiceStack(repoPerson, repoActivity)

                     
            
    
    ui = Menu(servicePerson, serviceActivity, serviceStack)
    ui.start()

run_all_tests()
run()
