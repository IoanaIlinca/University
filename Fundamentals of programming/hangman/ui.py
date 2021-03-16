from controller import Controller
from validator import *

class Menu(object):
    def __init__(self):
        self.__controller = Controller()

    def print_menu(self):
        print("Choose an option:")
        print("1. Add sentence")
        print("2. Start game")

    def get_option(self):
        while True:
            Inp = input()
            if Inp == "Add sentence":
                sentence = input()
                while Validator.validate_sentence(sentence) == False:
                    print("Invalid input! Add a new sentence: ")
                    sentence = input()

                self.__controller.add_sentence(sentence)
                break
            elif Inp == "Start game":
                self.start_game()
            else:
                print("Invalid input!")

    def show_hangman(self):
        letters = self.__controller.get_hanged()
        hangman = self.__controller.get_hangman()
        message = ""
        for i in range(0, letters):
            message += hangman[i]

        for i in range(letters + 1, 8):
            message += "*"
        
        print(message)

    def show_sentence(self, lis, letter):
        sentence = self.__controller.get_sentence()
        letter = letter.upper()
        if letter in sentence:
            lis.append(letter)
        else:
            self.__controller.set_hanged(self.__controller.get_hanged() + 1)

        message = ""
        for letter in sentence:
            letter = letter.upper()
            if letter in lis:
                message += letter
            else:
                message += "*"

        print(message)


    def check_sentence(self, lis):
        sentence = self.__controller.get_sentence()
        for character in sentence:
            if character not in lis:
                return False
        return True
            
    def start_game(self):
        lis = [' ']
        sentence = self.__controller.get_sentence()
        words = sentence.split(" ")
        for word in words:
            word = list(word)
            lis.append(word[0].upper())
            lis.append(word[len(word) - 1].upper())
        self.show_sentence(lis, ' ')
        self.show_hangman()
        while True:
            
            ok = False
            letter = input("Enter letter: ")
            self.show_sentence(lis, letter)
            self.show_hangman()
            ok = self.check_sentence(lis)
            if ok:
                print("You won!")
                break
            if self.__controller.get_hanged() == 7:
                print("You lost!")
                break

    def menu(self):
        self.print_menu()
        self.get_option()

        


