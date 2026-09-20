class MyCalendar:

    def __init__(self):
        self.tree = [(-1,-1)]
        
    def book(self, startTime: int, endTime: int) -> bool:
        self.tree.sort()
        for val in self.tree:
            if (val[0] <= startTime and startTime < val[1]) or \
            (val[0] <= endTime - 1 and endTime - 1 < val[1]) or \
            (startTime <= val[0] and val[0] < endTime) or \
            (startTime <= val[1] - 1 and val[1] - 1 < endTime):
                return False
        self.tree.append((startTime,endTime))
        return True

# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(startTime,endTime)