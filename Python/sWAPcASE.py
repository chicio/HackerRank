#
# sWAPcASE.py
# HackerRank
#
# Created by Fabrizio Duroni on 18/10/17.
#
# https://www.hackerrank.com/challenges/swap-case


def swap_case(s):
    inverted_case_string = ""
    for char in s:
        if char.isupper():
            inverted_case_string += char.lower()
        else:
            inverted_case_string += char.upper()
    return inverted_case_string


s = raw_input()
result = swap_case(s)
print result



