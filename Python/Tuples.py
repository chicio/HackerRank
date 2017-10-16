#
# Tuples.py
# HackerRank
#
# Created by Fabrizio Duroni on 16/10/17.
#
# https://www.hackerrank.com/challenges/python-tuples


n = int(raw_input())
integer_list = map(int, raw_input().split())
tupla = tuple(integer_list)
print(hash(tupla))
