import threading

from typing import Callable


class FizzBuzz:
    def __init__(self, n: int):
        self.n = n
        self.current = 1
        self.fizzs = threading.Semaphore(0)
        self.buzzs =  threading.Semaphore(0)
        self.fizzbuzzs =  threading.Semaphore(0)
        self.numbers =  threading.Semaphore(0)
        self.sems = (self.numbers, self.fizzs, self.buzzs, self.fizzbuzzs)
        self.release()


    # printFizz() outputs "fizz"
    def fizz(self, printFizz: 'Callable[[], None]') -> None:
        while True:
            self.fizzs.acquire()
            if self.current > self.n:
                break
            printFizz()
            self.current += 1
            self.release()


    # printBuzz() outputs "buzz"
    def buzz(self, printBuzz: 'Callable[[], None]') -> None:
        while True:
            self.buzzs.acquire()
            if self.current > self.n:
                break
            printBuzz()
            self.current += 1
            self.release()


    # printFizzBuzz() outputs "fizzbuzz"
    def fizzbuzz(self, printFizzBuzz: 'Callable[[], None]') -> None:
        while True:
            self.fizzbuzzs.acquire()
            if self.current > self.n:
                break
            printFizzBuzz()
            self.current += 1
            self.release()


    # printNumber(x) outputs "x", where x is an integer.
    def number(self, printNumber: 'Callable[[int], None]') -> None:
        while True:
            self.numbers.acquire()
            if self.current > self.n:
                break
            printNumber(self.current)
            self.current += 1
            self.release()


    def release(self) -> None:
        current = self.current
        if current > self.n:
            for sem in self.sems:
                sem.release()
        else:
            self.sems[(current % 3 == 0) + ((current % 5 == 0) << 1)].release()


def localTest():
    n = 15000

    arr = []
    fizzBuzz = FizzBuzz(n)
    threads = [
        threading.Thread(target=FizzBuzz.fizz, args=(fizzBuzz, lambda: arr.append("fizz"))),
        threading.Thread(target=FizzBuzz.buzz, args=(fizzBuzz, lambda: arr.append("buzz"))),
        threading.Thread(target=FizzBuzz.fizzbuzz, args=(fizzBuzz, lambda: arr.append("fizzbuzz"))),
        threading.Thread(target=FizzBuzz.number, args=(fizzBuzz, lambda x: arr.append(str(x))))
    ]
    for thread in threads:
        thread.start()
    for thread in threads:
        thread.join()
    
    expected_result = [(str(x), "fizz", "buzz", "fizzbuzz")[(x % 3 == 0) + ((x % 5 == 0) << 1)] for x in range(1, n + 1)]
    print(arr == expected_result)


if __name__ == "__main__":
    localTest()
