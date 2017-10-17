#
# FindingThePercentage.py
# HackerRank
#
# Created by Fabrizio Duroni on 18/10/17.
#
# https://www.hackerrank.com/challenges/finding-the-percentage


n = int(raw_input())
student_marks = dict()
for _ in range(n):
    line = raw_input().split()
    name, scores = line[0], line[1:]
    scores = map(float, scores)
    student_marks[name] = scores
query_name = raw_input()
scoresOfStudentSelected = student_marks[query_name]
average = sum(scoresOfStudentSelected)/len(scoresOfStudentSelected)
print("{0:.2f}".format(average))
