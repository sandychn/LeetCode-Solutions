import threading

from typing import Callable


class ZeroEvenOdd:
    def __init__(self, n):
        self.n = n
        self.zeroLock = threading.Lock()
        self.oddLock = threading.Lock()
        self.evenLock = threading.Lock()
        self.oddLock.acquire()
        self.evenLock.acquire()
        
        
	# printNumber(x) outputs "x", where x is an integer.
    def zero(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(self.n):
            self.zeroLock.acquire()
            printNumber(0)
            if i & 1:
                self.evenLock.release()
            else:
                self.oddLock.release()
        
        
    def even(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(2, self.n + 1, 2):
            self.evenLock.acquire()
            printNumber(i)
            self.zeroLock.release()
        
        
    def odd(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(1, self.n + 1, 2):
            self.oddLock.acquire()
            printNumber(i)
            self.zeroLock.release()


def localTest():
    n = 5
    
    zeroEvenOdd = ZeroEvenOdd(n)
    printNumber = lambda x: print(x, end="")
    threads = [
        threading.Thread(target=ZeroEvenOdd.zero, args=(zeroEvenOdd, printNumber)),
        threading.Thread(target=ZeroEvenOdd.even, args=(zeroEvenOdd, printNumber)),
        threading.Thread(target=ZeroEvenOdd.odd, args=(zeroEvenOdd, printNumber))
    ]
    for thread in threads:
        thread.start()
    for thread in threads:
        thread.join()


if __name__ == "__main__":
    localTest()
