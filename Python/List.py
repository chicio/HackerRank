#
# List.py
# HackerRank
#
# Created by Fabrizio Duroni on 16/10/17.
#
# https://www.hackerrank.com/challenges/python-lists


n = int(raw_input())
numberList = list()

for i in range(0, n):
    string = raw_input().split()
    command = string[0]
    if command == "insert":
        numberList.insert(int(string[1]), int(string[2]))
    elif command == "remove":
        numberList.remove(int(string[1]))
    elif command == "append":
        numberList.append(int(string[1]))
    elif command == "sort":
        numberList.sort()
    elif command == "pop":
        numberList.pop()
    elif command == "reverse":
        numberList.reverse()
    elif command == "print":
        print '[%s]' % ', '.join(map(str, numberList))
