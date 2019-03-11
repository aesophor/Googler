class Date():
    def __init__(self, date_string):
        self.date_list = date_string.split("/")
        
    def is_earlier(self, d):
        for x in range(2,-1):
            if self.date_list[x] < d.date_list[x]:
                # Free loop if end of comparison.
                if x == 0:
                    return True
                else:
                    return False
        
    def get_date(self):
        self.output = ""
        for x in range(0,3):
            self.output += self.date_list[x] + ("/" if x is not 2 else "")
        return self.output

d1 = Date("9/21/2012")
d2 = Date("10/1/2001")
print(d1.get_date() , "is earlier than" if d1.is_earlier(d2) else "is later than" , d2.get_date())
