class Board(object):
    def __init__(self):
        self.__list = []
        self.__BOARDWIDTH = 7
        self.__BOARDHEIGHT = 6
        for x in range(self.__BOARDWIDTH):
            self.__list.append([' '] * self.__BOARDHEIGHT)

    def getBoard(self):
        # gets the board
        return self.__list

    def getPosition(self, x, y):
        # gets a certain position
        return self.__list[x][y]

    def setPosition(self, x, y, val):
        # sets a certain position
        self.__list[x][y] = val

    def getNewBoard(self):
        # creates a new board
        board = []
        for x in range(self.__BOARDWIDTH):
            board.append([' '] * self.__BOARDHEIGHT)
        return board

    def getBoardWidth(self):
        # returns the board width
        return int(self.__BOARDWIDTH)
        
    def getBoardHeight(self):
        # returns the board height
        return  int(self.__BOARDHEIGHT)