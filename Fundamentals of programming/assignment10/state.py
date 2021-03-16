from board import Board
import random
import copy
import sys

class State(object):
    def __init__(self):
        self.__board = Board()

    def getBoardWidth(self):
        # returns the board width
        return int(self.__board.getBoardWidth())
        
    def getBoardHeight(self):
        # returns the board height
        return  int(self.__board.getBoardHeight())

    def getNewBoard(self):
        # makes a new board
        board = Board()
        return board.getNewBoard

    def getBoard(self):
        # returns the board
        return self.__board

    def getPosition(self, x, y):
        # returns the position
        return self.__board.getPosition(x, y)

    def setPosition(self, x, y, val):
        # sets the position
        self.__board.setPosition(x, y, val)

    def getHumanMove(self, move, board):
        if move.lower().startswith('q'):
                sys.exit()
        if not move.isdigit():
            return -1
        move = int(move) - 1
        if self.isValidMove(board, move):
            return move

    def getComputerMove(self, board, computerTile):
        potentialMoves = self.getPotentialMoves(board, computerTile, 2)
        bestMoveScore = max([potentialMoves[i] for i in range(self.__board.getBoardWidth()) if self.isValidMove(board, i)])
        bestMoves = []
        for i in range(len(potentialMoves)):
            if potentialMoves[i] == bestMoveScore:
                bestMoves.append(i)
        return random.choice(bestMoves)

    def getPotentialMoves(self, board, playerTile, lookAhead):
        if lookAhead == 0:
            return [0] * self.__board.getBoardWidth()

        potentialMoves = []

        if playerTile == 'X':
            enemyTile = 'O'
        else:
            enemyTile = 'X'

        # Returns (best move, average condition of this state)
        if self.isBoardFull(board):
            return [0] * self.__board.getBoardWidth()

        # Figure out the best move to make.
        potentialMoves = [0] * self.__board.getBoardWidth()
        for playerMove in range(self.__board.getBoardWidth()):
            dupeBoard = copy.deepcopy(board)
            if not self.isValidMove(dupeBoard, playerMove):
                continue
            self.makeMove(dupeBoard, playerTile, playerMove)
            if self.isWinner(dupeBoard, playerTile):
                potentialMoves[playerMove] = 1
                break
            else:
                # do other player's moves and determine best one
                if self.isBoardFull(dupeBoard):
                    potentialMoves[playerMove] = 0
                else:
                    for enemyMove in range(self.__board.getBoardWidth()):
                        dupeBoard2 = copy.deepcopy(dupeBoard)
                        if not self.isValidMove(dupeBoard2, enemyMove):
                            continue
                        self.makeMove(dupeBoard2, enemyTile, enemyMove)
                        if self.isWinner(dupeBoard2, enemyTile):
                            potentialMoves[playerMove] = -1
                            break
                        else:
                            results = self.getPotentialMoves(dupeBoard2, playerTile, lookAhead - 1)
                            potentialMoves[playerMove] += (sum(results) / dupeBoard2.getBoardWidth()) / dupeBoard2.getBoardWidth()
        return potentialMoves


    def whoGoesFirst(self):
        # Randomly choose the player who goes first.
        if random.randint(0, 1) == 0:
            return 'computer'
        else:
            return 'human'

    def makeMove(self, board, player, column):
        for y in range(board.getBoardHeight()-1, -1, -1):
            if board.getPosition(column, y) == ' ':
                board.setPosition(column, y, player)
                return

    def isValidMove(self, board, move):
        if move < 0 or move >= (self.__board.getBoardWidth()):
            return False

        if self.getPosition(move, 0) != ' ':
            return False

        return True

    def isBoardFull(self, board):
        for x in range(self.__board.getBoardWidth()):
            for y in range(self.__board.getBoardHeight()):
                if self.getPosition(x, y) == ' ':
                    return False
        return True

    def isWinner(self, board, tile):
        # check horizontal spaces
        for y in range(self.__board.getBoardHeight()):
            for x in range(self.__board.getBoardWidth() - 3):
                if self.getPosition(x, y) == tile and self.getPosition(x + 1, y) == tile and self.getPosition(x + 2, y) == tile and self.getPosition(x + 3, y) == tile:
                    return True

        # check vertical spaces
        for x in range(self.__board.getBoardWidth()):
            for y in range(self.__board.getBoardHeight() - 3):
                if self.getPosition(x, y) == tile and self.getPosition(x, y + 1) == tile and self.getPosition(x, y + 2) == tile and self.getPosition(x, y + 3) == tile:
                    return True

        # check / diagonal spaces
        for x in range(self.__board.getBoardWidth() - 3):
            for y in range(3, self.__board.getBoardHeight()):
                if self.getPosition(x, y) == tile and self.getPosition(x + 1, y - 1) == tile and self.getPosition(x + 2, y - 2) == tile and self.getPosition(x + 3, y - 3) == tile:
                    return True

        # check \ diagonal spaces
        for x in range(self.__board.getBoardWidth() - 3):
            for y in range(self.__board.getBoardHeight() - 3):
                if self.getPosition(x, y) == tile and self.getPosition(x + 1, y + 1) == tile and self.getPosition(x + 2, y + 2) == tile and self.getPosition(x + 3, y + 3) == tile:
                    return True

        return False