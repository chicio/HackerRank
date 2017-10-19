#
# StringSplitAndJoin.py
# HackerRank
#
# Created by Fabrizio Duroni on 18/10/17.
#
# https://www.hackerrank.com/challenges/python-string-split-and-join


def split_and_join(line):
    return "-".join(line.split(" "))


line = raw_input()
result = split_and_join(line)
print result
