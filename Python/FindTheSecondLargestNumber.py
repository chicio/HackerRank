#
# FindTheSecondLargestNumber.py
# HackerRank
#
# Created by Fabrizio Duroni on 16/10/17.
#
# https://www.hackerrank.com/challenges/find-second-maximum-number-in-a-list


n = int(raw_input())
arr = list(set(map(int, raw_input().split())))
arr.sort()
print(arr[len(arr) - 2])
