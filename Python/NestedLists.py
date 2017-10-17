#
# NestedLists.py
# HackerRank
#
# Created by Fabrizio Duroni on 17/10/17.
#
# https://www.hackerrank.com/challenges/nested-list


students = list()

for _ in range(int(raw_input())):
    name = raw_input()
    score = float(raw_input())
    students.append([name, score])

values = sorted(set(map(lambda x:x[1], students)))
studentsOrderedByGrade = [[y[0] for y in students if y[1] == x] for x in values]
studentsWithSecondLowestGrade = studentsOrderedByGrade[1]
studentsWithSecondLowestGrade.sort()

for p in studentsWithSecondLowestGrade:
    print(p)
