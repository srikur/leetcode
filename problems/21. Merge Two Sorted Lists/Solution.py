# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if ((list1 == None) and (list2 == None)): return list1
        if list1 == None: return list2
        if list2 == None: return list1

        retBool = False
        toMerge, merged = None, None
        if list1.val >= list2.val:
            toMerge = list1
            merged = list2
            retBool = True
        else:
            toMerge = list2
            merged = list1

        merged_next = merged.next
        while (toMerge != None):
            if ((merged_next == None) or (toMerge.val <= merged_next.val)):
                tmp = toMerge.next
                merged.next = toMerge
                toMerge.next = merged_next
                toMerge = tmp
            merged = merged.next
            merged_next = merged.next

        return list2 if retBool else list1