#!/usr/bin/env python3

class Student:
    def __init__(self, name):
        self.name = name

    def __str__(self):
        return self.name



andrey = Student("Andrey")
tim = Student("Tim")

students = [andrey, tim]
print(students)



for id, student in enumerate(students):
    print(str(id) + ": " + str(student))
