#
# StringFormatting.py
# HackerRank
#
# Created by Fabrizio Duroni on 22/10/17.
#
# https://www.hackerrank.com/challenges/python-string-formatting


def print_formatted(number):
    number_as_binary_string = format(number, 'b')
    for current_number in range(1, number + 1):
        print("%s %s %s %s" %
              (format(current_number, "d").rjust(len(number_as_binary_string)),
               format(current_number, "o").rjust(len(number_as_binary_string)),
               format(current_number, "X").rjust(len(number_as_binary_string)),
               format(current_number, "b").rjust(len(number_as_binary_string))))


n = int(raw_input())
print_formatted(n)
