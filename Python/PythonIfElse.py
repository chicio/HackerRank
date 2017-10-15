#
# PythonIfElse.py
# HackerRank
#
# Created by Fabrizio Duroni on 14/10/17.
#
# https://www.hackerrank.com/challenges/py-if-else

n = int(raw_input())

if n % 2 != 0:
    print "Weird"
else:
    if 2 <= n <= 5:
        print "Not Weird"
    if 6 <= n <= 20:
        print "Weird"
    if n > 20:
        print "Not Weird"
