#
# DesignerDoorMat.py
# HackerRank
#
# Created by Fabrizio Duroni on 22/10/17.
#
# https://www.hackerrank.com/challenges/designer-door-mat


N, M = map(int, raw_input().split())
for i in xrange(1, N, 2):
    print((".|." * i).center(M, "-"))
print("WELCOME".center(M, "-"))
for i in xrange(N - 2, -1, -2):
    print((".|." * i).center(M, "-"))
