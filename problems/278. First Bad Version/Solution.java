/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        return binarySearch(1, n);
    }

    private int binarySearch(int start, int end) {
        if (start == end) return (isBadVersion(start) == true) ? start : -1;
        int pivot = (end - start) / 2;
        boolean middleBad = isBadVersion(pivot + start);
        int lower = -1, higher = -1;
        if (middleBad == false) {
            // Only need to check right side
            higher = binarySearch(start + pivot + 1, end);
        } else {
            // Only need to check left side
            lower = binarySearch(start, start + pivot);
        }
        if (lower != -1 || higher != -1) return (lower != -1) ? lower : higher;
        else return -1;
    }
}