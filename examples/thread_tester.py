import threading
import time


class Sleeper (threading.Thread):
    def __init__(self, name, sleep_time):
        threading.Thread.__init__(self)
        self.name = name
        self.sleep_time = sleep_time

    def run(self):
        print("zzz at " + self.name + "\n")
        time.sleep(self.sleep_time)
        print("wakeup at " + self.name + "\n")


# Main program
thread1 = Sleeper("threadA", 5) # Will wakeup after threadB
thread2 = Sleeper("threadB", 2)

thread1.start()
thread2.start()
