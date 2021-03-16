class Sentences (object):
    def __init__(self):
        self.__sentences = []
        self.read_from_file()

    def get_sentences(self):
        return self.__sentences

    def add_sentence(self, sentence):
        self.__sentences.append(sentence)
        self.write_to_file(sentence)

    def read_from_file(self):
        with open("hangman.txt", "r") as readFile:
            lines = readFile.readlines()
            for line in lines:
                line = line.strip()
                if line != "" and line not in self.__sentences:
                    self.__sentences.append(line.upper())

    def write_to_file(self, sentence):
        with open("hangman.txt", "a") as writeFile:
            if sentence not in self.__sentences:
                writeFile.write(sentence+"\n")

