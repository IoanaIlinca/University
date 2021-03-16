class ValidatorError(Exception):
    pass

class ValidatorPerson():
    def __init__(self):
        pass

    def validate_person(self, person):
        # validates a person, person - Person
        errors = ""
        if len(person.name) == 0:
            errors += "name cannot be empty!\n"
        if len(person.phoneNumber) != 10:
            errors += "phone number invalid!(must be 10 digits)\n"
        try:
            phoneNumberInt = int(person.phoneNumber)
        except Exception:
            errors += "phone number invalid!(must be only digit characters)\n"
        if len(errors) > 0:
            raise ValidatorError(errors)

class ValidatorActivity():
    def __init__(self):
        pass
    
    def validate_activity(self, activity):
        # validates an activity, activity - Activity
        errors = ""
        if len(activity.description) == 0:
            errors += "description cannot be empty!\n"
        if len(errors) > 0:
            raise ValidatorError(errors)