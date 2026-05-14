class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        minHeap.push(num);
        maxHeap.push(minHeap.top());
        minHeap.pop();

        if (maxHeap.size() > minHeap.size()  + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        int n = minHeap.size(), m = maxHeap.size();

        if ((n + m) % 2 == 0) {
            return (double) (minHeap.top() + maxHeap.top()) /2;
        }
        else {
            if (n > m) {
                return minHeap.top();
            }
            else {
                return maxHeap.top();
            }
        }
    }
};
