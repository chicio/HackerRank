#
# WriteAFunction.py
# HackerRank
#
# Created by Fabrizio Duroni on 16/10/17.
#
# https://www.hackerrank.com/challenges/python-print

import sys

n = int(input())
for i in range(0, n):
    sys.stdout.write("%d" % (i + 1))

sys.stdout.flush()
