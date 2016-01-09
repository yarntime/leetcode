/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
public class Solution {
    public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
        List<Interval> result = new ArrayList<Interval>();
        int currentStart = newInterval.start;
        int currentEnd = newInterval.end;
        for (Interval interval: intervals) {
            if (currentStart < interval.start
                    && currentEnd > interval.end) {
                continue;
            } else if (interval.start > currentEnd) {
                result.add(new Interval(currentStart, currentEnd));
                currentStart = interval.start;
                currentEnd = interval.end;
            } else if (interval.end < currentStart) {
                result.add(interval);
            } else {
                currentEnd = Math.max(interval.end, currentEnd);
                currentStart = Math.min(interval.start, currentStart);
            }
        }
        result.add(new Interval(currentStart, currentEnd));
        return result;
    
    }
}