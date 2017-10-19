#
# FindAString.py
# HackerRank
#
# Created by Fabrizio Duroni on 18/10/17.
#
# https://www.hackerrank.com/challenges/find-a-string


def count_substring(a_string, a_sub_string):
    starting_index = 0
    count_of_substrings = 0
    end_of_string = False
    while not end_of_string:
        index_of_substring = a_string.find(a_sub_string, starting_index, len(a_string))
        if index_of_substring == -1:
            end_of_string = True
        else:
            starting_index = index_of_substring + len(a_sub_string) - 1
            count_of_substrings = count_of_substrings + 1
    return count_of_substrings


string = raw_input().strip()
sub_string = raw_input().strip()
count = count_substring(string, sub_string)
print count
