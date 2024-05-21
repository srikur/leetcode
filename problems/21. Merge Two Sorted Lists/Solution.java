/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode toMerge, merged;
        if (list1 == null && list2 == null) return list1;
        if (list1 == null) return list2;
        if (list2 == null) return list1;

        boolean retval = true;
        if (list1.val >= list2.val) {
            toMerge = list1;
            merged = list2;
        } else {
            toMerge = list2;
            merged = list1;
            retval = false;
        }

        ListNode merged_next = merged.next;
        while (toMerge != null) {
            if ((merged_next == null) || (toMerge.val <= merged_next.val)) {
                merged.next = toMerge;
                ListNode tmp = toMerge.next;
                toMerge.next = merged_next;
                toMerge = tmp;
            }
            merged = merged.next;
            merged_next = merged.next;
        }

        return (retval == true) ? list2 : list1;
    }
}