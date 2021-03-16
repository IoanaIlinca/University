from domain import Hangman
from repo import Sentences
import random

class Controller (object):
    def __init__(self):
        self.__senteces = Sentences()
        self.__hangman = Hangman(random.choice(self.__senteces.get_sentences()))

    def get_hanged(self):
        return self.__hangman.get_hanged()

    def set_hanged(self, number):
        self.__hangman.set_hanged(number)

    def get_hangman(self):
        return self.__hangman.get_hangman()
        

    def add_sentence(self, sentence):
        self.__senteces.add_sentence(sentence)

    def get_sentences(self):
        return self.__senteces.get_sentences()

    def get_sentence(self):
        return self.__hangman.get_sentence()