#!/user/bin/env python
    
def toarr(xx, arr):
    if xx == None:
        return arr
    arr.append(xx.val)
    return toarr(xx.next, arr)

# Accept Solution:
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @return a ListNode
    def addTwoNumbers(self, l1, l2, addition = 0):
        if l1 != None and l2 != None:
            l3 = ListNode((l1.val + l2.val + addition) % 10)
            l3.next = self.addTwoNumbers(l1.next, l2.next, (l1.val + l2.val + addition) / 10)
            return l3
        elif l1 != None:
            l3 = ListNode((l1.val + addition) % 10)
            l3.next = self.addTwoNumbers(l1.next, None, (l1.val + addition) / 10)
            return l3
        elif l2 != None:
            l3 = ListNode((l2.val + addition) % 10)
            l3.next = self.addTwoNumbers(l2.next, None, (l2.val + addition) / 10)
            return l3
        elif addition != 0:
            return ListNode(addition)

# This one looks good :P
class ListNode:
    def __init__(self, val, next = None):
        self.val = val
        self.next = next
        
L1 = ListNode(2, ListNode(4, ListNode(3)))
L2 = ListNode(5, ListNode(6, ListNode(4, ListNode(5))))
L1 = ListNode(3, ListNode(7))
L2 = ListNode(9, ListNode(2))
class Solution:
    # @return a ListNode
    def addTwoNumbers(self, l1, l2, addition = 0):
        if l1 != None and l2 != None:
            return ListNode((l1.val + l2.val + addition) % 10, self.addTwoNumbers(l1.next, l2.next, (l1.val + l2.val + addition) / 10))
        elif l1 != None:
            return  ListNode((l1.val + addition) % 10, self.addTwoNumbers(l1.next, None, (l1.val + addition) / 10))
        elif l2 != None:
            return  ListNode((l2.val + addition) % 10, self.addTwoNumbers(l2.next, None, (l2.val + addition) / 10))
        elif addition != 0:
            return ListNode(addition, None)
    
s = Solution()
print toarr(s.addTwoNumbers(L1, L2), [])

# an single function to solve this problem
def addTwoNumbers(l1, l2, addition = 0):
    if l1 != None and l2 != None:
        return ListNode((l1.val + l2.val + addition) % 10, addTwoNumbers(l1.next, l2.next, (l1.val + l2.val + addition) / 10))
    elif l1 != None:
        return  ListNode((l1.val + addition) % 10, addTwoNumbers(l1.next, None, (l1.val + addition) / 10))
    elif l2 != None:
        return  ListNode((l2.val + addition) % 10, addTwoNumbers(l2.next, None, (l2.val + addition) / 10))
    elif addition != 0:
        return ListNode(addition, None)
