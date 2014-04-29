#! /user/bin/env python

def longestPalindrome(s):
    sub_string = ""
    for c in s:
        if sub_string[-1:] == c:
            pass
        else:
            sub_string = sub_string + c


s = "abcddcbdd"

longestPalindrome(s)
