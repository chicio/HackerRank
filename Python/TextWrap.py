#
# TextWrap.py
# HackerRank
#
# Created by Fabrizio Duroni on 21/10/17.
#
# https://www.hackerrank.com/challenges/text-wrap


import textwrap


def wrap(string, max_width):
    return textwrap.fill(string, max_width)


string, max_width = raw_input(), int(raw_input())
result = wrap(string, max_width)
print result
