#
# WriteAFunction.py
# HackerRank
#
# Created by Fabrizio Duroni on 16/10/17.
#
# https://www.hackerrank.com/challenges/write-a-function


def is_leap(year):
    leap = False
    if year % 400 == 0:
        leap = True
    if year % 4 == 0 and year % 100 != 0:
        leap = True

    return leap


anYear = int(input())
print(is_leap(anYear))
