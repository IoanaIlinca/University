from state import State

class Menu(object):
    def __init__(self):
        self.__state = State()

    def playAgain(self):
        # This function returns True if the player wants to play again, otherwise it returns False.
        print('Do you want to play again? (yes or no)')
        return input().lower().startswith('y')


    def enterHumanTile(self):
        # Let's the human player type which tile they want to be.
        # Returns a list with the human player's tile as the first item, and the computer's tile as the second.
        tile = ''
        while not (tile == 'X' or tile == 'O'):
            print('Do you want to be X or O?')
            tile = input().upper()

        # the first element in the tuple is the human player's tile, the second is the computer's tile.
        if tile == 'X':
            return ['X', 'O']
        else:
            return ['O', 'X']


    def drawBoard(self, board):
        # draws the board
        print()
        print(' ', end='')
        for x in range(1, self.__state.getBoardWidth() + 1):
            print(' %s  ' % x, end='')
        print()

        print('+---+' + ('---+' * (self.__state.getBoardWidth() - 1)))

        for y in range(self.__state.getBoardHeight()):
            print('|   |' + ('   |' * (self.__state.getBoardWidth() - 1)))

            print('|', end='')
            for x in range(self.__state.getBoardWidth()):
                print(' %s |' % self.__state.getPosition(x, y), end='')
            print()

            print('|   |' + ('   |' * (self.__state.getBoardWidth() - 1)))

            print('+---+' + ('---+' * (self.__state.getBoardWidth() - 1)))


    def getHumanMove(self, board):
        while True:
            print('Which column do you want to move on? (1-%s, or "quit" to quit game)' % (self.__state.getBoardWidth))
            move = input()
            move = self.__state.getHumanMove(move, board)
            if move == -1:
                continue
            return move


    def run(self):
        while True:
            humanTile, computerTile = self.enterHumanTile()
            turn = self.__state.whoGoesFirst()
            print('The %s player will go first.' % (turn))
            mainBoard = self.__state.getBoard()

            while True:
                if turn == 'human':
                    self.drawBoard(mainBoard)
                    move = self.getHumanMove(mainBoard)
                    self.__state.makeMove(mainBoard, humanTile, move)
                    if self.__state.isWinner(mainBoard, humanTile):
                        winner = 'human'
                        break
                    turn = 'computer'
                else:
                    self.drawBoard(mainBoard)
                    print('The computer is thinking...')
                    move = self.__state.getComputerMove(mainBoard, computerTile)
                    self.__state.makeMove(mainBoard, computerTile, move)
                    if self.__state.isWinner(mainBoard, computerTile):
                        winner = 'computer'
                        break
                    turn = 'human'

                if self.__state.isBoardFull(mainBoard):
                    winner = 'tie'
                    break

            self.drawBoard(mainBoard)
            print('Winner is: %s' % winner)
            if not self.playAgain():
                break


