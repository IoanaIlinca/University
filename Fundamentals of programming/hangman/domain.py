class Hangman (object):
    def __init__(self, sentence):
        """
            This function initialises the hangman game
            Input: the sentence, string
            Hangman is a list of the letters in the word hangman
            Hanged is how many wrong letters have been put in
        """
        self.__sentence = sentence
        self.__hangman = "hangman"
        self.__hanged = 0

    def get_sentence(self):
        # returns the sentence
        return self.__sentence

    def get_hangman(self):
        # returns hangman
        return self.__hangman

    def get_hanged(self):
        # returns the number of wrong letters
        return self.__hanged

    def set_hanged(self, number):
        # sets the number of wrong letters
        self.__hanged = number




