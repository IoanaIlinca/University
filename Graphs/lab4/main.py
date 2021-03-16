from menu import menu
from tests import tests

import sys
import threading

def main():
    #tests()
    sys.setrecursionlimit(150000)
    threading.stack_size(2**27)
    threading.Thread(target=menu).start()

main()