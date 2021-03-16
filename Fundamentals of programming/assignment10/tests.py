import unittest
from state import *
from board import *

class Tests(unittest.TestCase):
    def __init__(self):
        pass

    def test_makeMove(self):
        board = Board()
        state = State()
        state.makeMove(board, 'X', 3)

    def test_getComputerMove(self):
        state = State()
        board = Board()
        computerTile = 'X'
        move = state.getComputerMove(board, computerTile)
        self.assertTrue(move != 0)

    def test_getHumanMove(self):
        state = State()
        board = Board()
        move = state.getHumanMove(4, board)
        self.assertTrue(move == 4)

