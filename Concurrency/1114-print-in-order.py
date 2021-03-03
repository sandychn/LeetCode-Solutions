import threading

from typing import Callable


class Foo:
    def __init__(self):
        self.firstLock = threading.Lock()
        self.secondLock = threading.Lock()
        self.firstLock.acquire()
        self.secondLock.acquire()


    def first(self, printFirst: 'Callable[[], None]') -> None:
        # printFirst() outputs "first". Do not change or remove this line.
        printFirst()
        self.firstLock.release()


    def second(self, printSecond: 'Callable[[], None]') -> None:
        with self.firstLock:
            # printSecond() outputs "second". Do not change or remove this line.
            printSecond()
        self.secondLock.release()


    def third(self, printThird: 'Callable[[], None]') -> None:
        with self.secondLock:
            # printThird() outputs "third". Do not change or remove this line.
            printThird()


def localTest():
    foo = Foo()
    threads = [
        threading.Thread(target=Foo.first, args=(foo, lambda: print("first", end=""))),
        threading.Thread(target=Foo.second, args=(foo, lambda: print("second", end=""))),
        threading.Thread(target=Foo.third, args=(foo, lambda: print("third", end="")))
    ]
    for thread_id in (1, 3, 2):
        threads[thread_id - 1].start()
    for thread in threads:
        thread.join()


if __name__ == "__main__":
    localTest()
