import threading

from typing import Callable, List


class DiningPhilosophers:
    def __init__(self) -> None:
        self.fockLocks = [threading.Lock() for _ in range(5)]


    # call the functions directly to execute, for example, eat()
    def wantsToEat(self,
                   philosopher: int,
                   pickLeftFork: 'Callable[[], None]',
                   pickRightFork: 'Callable[[], None]',
                   eat: 'Callable[[], None]',
                   putLeftFork: 'Callable[[], None]',
                   putRightFork: 'Callable[[], None]') -> None:
        leftFockId = philosopher
        rightFockId = ((leftFockId - 1) + 5) % 5
        if philosopher & 1:
            self.fockLocks[leftFockId].acquire()
            pickLeftFork()
            self.fockLocks[rightFockId].acquire()
            pickRightFork()
            eat()
            self.fockLocks[rightFockId].release()
            putRightFork()
            self.fockLocks[leftFockId].release()
            putLeftFork()
        else:
            self.fockLocks[rightFockId].acquire()
            pickRightFork()
            self.fockLocks[leftFockId].acquire()
            pickLeftFork()
            eat()
            self.fockLocks[leftFockId].release()
            putLeftFork()
            self.fockLocks[rightFockId].release()
            putRightFork()


def makeCallback(listAppendTo: 'List[List[int]]', element: 'List[int]') -> None:
    def callback():
        listAppendTo.append(element)
    return callback


def checkRes(res, n):
    pickFromPhilosopher = [None] * 5
    eat = [0] * 5
    for philosopher, fork, oper in res:
        forks = [philosopher, ((philosopher - 1) + 5) % 5]  # left, right
        fork -= 1
        if oper == 1:
            if pickFromPhilosopher[forks[fork]] is not None:
                return False
            pickFromPhilosopher[forks[fork]] = philosopher
        elif oper == 2:
            if pickFromPhilosopher[forks[fork]] != philosopher:
                return False
            pickFromPhilosopher[forks[fork]] = None
        elif oper == 3:
            if pickFromPhilosopher[forks[0]] != philosopher or pickFromPhilosopher[forks[1]] != philosopher:
                return False
            eat[philosopher] += 1
    return eat.count(n) == 5


# pass this test does NOT mean the solution is right
def localTest():
    for n in range(1, 61):
        sol = DiningPhilosophers()
        threads = []  # type: List[threading.Thread]
        res = []

        for philosopher in range(5):
            for _ in range(n):
                threads.append(threading.Thread(target=DiningPhilosophers.wantsToEat, args=(
                    sol,
                    philosopher,
                    makeCallback(res, [philosopher, 1, 1]),
                    makeCallback(res, [philosopher, 2, 1]),
                    makeCallback(res, [philosopher, 0, 3]),
                    makeCallback(res, [philosopher, 1, 2]),
                    makeCallback(res, [philosopher, 2, 2])
                )))
        
        import random
        random.shuffle(threads)
        for thread in threads:
            thread.start()
        for thread in threads:
            thread.join()
        isCorrect = checkRes(res, n)
        if isCorrect:
            print(f"n={n}. Correct.")
        else:
            print(f"n={n}. Wrong answer. res={res}")
            break


if __name__ == "__main__":
    localTest()
