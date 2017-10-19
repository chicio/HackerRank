#
# StringValidators.py
# HackerRank
#
# Created by Fabrizio Duroni on 18/10/17.
#
# https://www.hackerrank.com/challenges/string-validators


string = raw_input()

if any(char.isalnum() for char in string):
    print(True)
else:
    print(False)

if any(char.isalpha() for char in string):
    print(True)
else:
    print(False)

if any(char.isdigit() for char in string):
    print(True)
else:
    print(False)

if any(char.islower() for char in string):
    print(True)
else:
    print(False)

if any(char.isupper() for char in string):
    print(True)
else:
    print(False)
