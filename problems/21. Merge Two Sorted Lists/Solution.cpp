/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr) return list1;
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        bool ret = false;
        ListNode* toMerge = nullptr, *merged = nullptr;
        if (list1->val >= list2->val) {
            toMerge = list1;
            merged = list2;
            ret = true;
        } else {
            toMerge = list2;
            merged = list1;
        }

        ListNode* merged_next = merged->next, *tmp = nullptr;
        while (toMerge != nullptr) {
            if (merged_next == nullptr || toMerge->val <= merged_next->val) {
                tmp = toMerge->next;
                merged->next = toMerge;
                toMerge->next = merged_next;
                toMerge = tmp;
            }
            merged = merged->next;
            merged_next = merged->next;
        }

        return (ret) ? list2 : list1;
    }
};