// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        return binarySearch(1, n);
    }

    int binarySearch(int start, int end) {
        if (start == end) return isBadVersion(start) ? start : -1;
        int pivot = (end - start) / 2;
        int left = -1, right = -1;
        if (isBadVersion(start + pivot)) left = binarySearch(start, start + pivot);
        else right = binarySearch(start + pivot + 1, end);
        if (left != -1 || right != -1) return left != -1 ? left : right;
        else return -1;
    }
};