#
# StringSplitAndJoin.py
# HackerRank
#
# Created by Fabrizio Duroni on 18/10/17.
#
# https://www.hackerrank.com/challenges/python-mutations


def mutate_string(string, position, character):
    return string[:position] + "k" + string[position + 1:]


s = raw_input()
i, c = raw_input().split()
s_new = mutate_string(s, int(i), c)
print s_new