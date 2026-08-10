import java.util.*;

class MedianFinder{

    PriorityQueue<Integer> pqLeftMax;
    PriorityQueue<Integer> pqRightMin;

    public MedianFinder(){
        pqLeftMax = new PriorityQueue<>(Collections.reverseOrder());
        pqRightMin = new PriorityQueue<>();
    }

    public void addNum(int num){
        if (pqLeftMax.isEmpty() || num <= pqLeftMax.peek())
            pqLeftMax.offer(num);
        else
            pqRightMin.offer(num);

        if (pqLeftMax.size() > pqRightMin.size() + 1)
            pqRightMin.offer(pqLeftMax.poll());
        else if (pqRightMin.size() > pqLeftMax.size())
            pqLeftMax.offer(pqRightMin.poll());
    }

    public double findMedian() {
        if (pqLeftMax.size() == pqRightMin.size())
            return (pqLeftMax.peek() + pqRightMin.peek()) / 2.0;

        return pqLeftMax.peek();
    }

    public static void main(String[] args){

        MedianFinder obj=new MedianFinder();
        int[] nums={5,2,10,4,3};

        for (int num:nums){
            obj.addNum(num);
            System.out.println("Added: " + num +" and Median: " + obj.findMedian());
        }
    }
}
