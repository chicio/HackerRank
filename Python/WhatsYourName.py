#
# WhatsYourName.py
# HackerRank
#
# Created by Fabrizio Duroni on 18/10/17.
#
# https://www.hackerrank.com/challenges/whats-your-name


def print_full_name(a_first_name, a_last_name):
    print 'Hello {0} {1}! You just delved into python.'.format(a_first_name, a_last_name)


first_name = raw_input()
last_name = raw_input()
print_full_name(first_name, last_name)
