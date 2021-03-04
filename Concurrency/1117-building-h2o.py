import threading

from typing import Callable, List


class H2O:
    def __init__(self):
        self.hSemaphore = threading.Semaphore(0)
        self.oSemaphore = threading.Semaphore(1)
        self.hBarrier = threading.Semaphore(2)
        self.oBarrier = threading.Semaphore(1)


    def hydrogen(self, releaseHydrogen: 'Callable[[], None]') -> None:
        self.hBarrier.acquire()
        self.oSemaphore.release()
        self.hSemaphore.acquire()
        # releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen()
        self.hBarrier.release()


    def oxygen(self, releaseOxygen: 'Callable[[], None]') -> None:
        self.oBarrier.acquire()
        self.oSemaphore.acquire()
        self.oSemaphore.acquire()
        self.hSemaphore.release()
        self.hSemaphore.release()
        # releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen()
        self.oBarrier.release()


def localTest():
    input_str = "OOHHHHHHHOHO"

    h2o = H2O()
    threads = []  # type: List[threading.Thread]
    for ch in input_str:
        if ch == "H":
            threads.append(threading.Thread(target=H2O.hydrogen, args=(h2o, lambda: print("H", end=""))))
        elif ch == "O":
            threads.append(threading.Thread(target=H2O.oxygen, args=(h2o, lambda: print("O", end=""))))
    for thread in threads:
        thread.start()
    for thread in threads:
        thread.join()


if __name__ == "__main__":
    localTest()
