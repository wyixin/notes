#!/user/bin/env/ python

def lengthOfLongestSubstring(s):
    sub_string = []
    i = j = 0
    str_len = len(s)
    max_len = 0
    for j in range(0, str_len):
        if s[j] in sub_string:
            max_len = max(max_len, j - i)
            while s[i] != s[j]:
                sub_string.remove(s[i])
                i += 1
            i += 1
        else:
            sub_string.append(s[j])
    return max(max_len, str_len - i)
s = "abcddddabcef"    
print lengthOfLongestSubstring(s)
