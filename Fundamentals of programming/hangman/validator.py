class Validator():

    @staticmethod
    def validate_sentence(sentence):
        if len(sentence) < 3:
            return False
        else:
            words = sentence.split(" ")
            for word in words:
                if len(word) < 3:
                    return False

        return True