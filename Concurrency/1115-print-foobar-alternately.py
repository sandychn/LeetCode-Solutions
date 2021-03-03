import threading

from typing import Callable


class FooBar:
    def __init__(self, n):
        self.n = n
        self.fooLock = threading.Lock()
        self.barLock = threading.Lock()
        self.barLock.acquire()


    def foo(self, printFoo: 'Callable[[], None]') -> None:
        for i in range(self.n):
            self.fooLock.acquire()
            # printFoo() outputs "foo". Do not change or remove this line.
            printFoo()
            self.barLock.release()


    def bar(self, printBar: 'Callable[[], None]') -> None:
        for i in range(self.n):
            self.barLock.acquire()
            # printBar() outputs "bar". Do not change or remove this line.
            printBar()
            self.fooLock.release()


def local_test():
    n = 5
    fooBar = FooBar(n)
    threading.Thread(target=FooBar.foo, args=(fooBar, lambda: print("foo", end=""))).start()
    threading.Thread(target=FooBar.bar, args=(fooBar, lambda: print("bar", end=""))).start()


if __name__ == "__main__":
    local_test()
