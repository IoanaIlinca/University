from domain import *
from repo import Repo
from Iterator import Iterator
import unittest
import datetime

class Tests(unittest.TestCase):
    def __init__(self):
        pass

    def test_add_person(self):
        person0 = Person(101, "Dan", 1234567890)
        repoPerson = Repo([])
        repoPerson.add_element(person0)
        self.assertTrue(int(repoPerson.list[0].personId) == 101)
        self.assertTrue(repoPerson.list[0].name == "Dan")
        self.assertTrue(int(repoPerson.list[0].phoneNumber) == 1234567890)

    def test_add_activity(self):
        date0 = datetime.datetime.strptime("30-11-2019 15:30","%d-%m-%Y %H:%M")
        activity0 = Activity(11, [101,104], date0, "camping")
        repoActivity = Repo([])
        repoActivity.add_element(activity0)
        self.assertTrue(repoActivity.list[0].activityId == 11)
        self.assertTrue(repoActivity.list[0].personIdList == [101,104])
        self.assertTrue(repoActivity.list[0].dateTime == date0)
        self.assertTrue(repoActivity.list[0].description == "camping")


    def test_Iterator(self):
        person0 = Person(99, "Dan", 1234567890)
        person1 = Person(101, "Ana", 1234567890)
        person2 = Person(80, "Mihai", 1234567890)
        lis = Iterator([person0, person1, person2])
        self.assertTrue(len(lis) == 3)
        lis.remove(0)
        self.assertTrue(len(lis) == 2)
        lis.append(person0)
        self.assertTrue(len(lis) == 3)
        lis.clear
        self.assertTrue(len(lis) == 0)

        


def run_all_tests():
    test = Tests()
    test.test_add_person()
    test.test_add_activity()


