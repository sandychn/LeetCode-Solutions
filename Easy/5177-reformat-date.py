class Solution:
    def reformatDate(self, date: str) -> str:
        day, month, year = date.split()
        months = ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"]
        day = day.rstrip(string.ascii_lowercase)
        return '%s-%02d-%02d' % (year, months.index(month) + 1, int(day))
