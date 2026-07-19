import java.util.*;

/*
class RobotMessageTracker {
    private HashMap<String, Integer> map;

    public RobotMessageTracker() {
        map = new HashMap<>();
    }

    public void shouldPrintMessage(int timestamp, String message) {
        boolean canPrint = true;

        if (map.containsKey(message)) {
            int lastTime = map.get(message);
            if ((timestamp - lastTime) < 10) {
                canPrint = false;
            }
        }

        if (canPrint) {
            map.put(message, timestamp);
            System.out.println("The time it printed is " + map.get(message)
                    + " the message is " + message);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        RobotMessageTracker logger = new RobotMessageTracker();

        logger.shouldPrintMessage(1, "foo");
        logger.shouldPrintMessage(2, "bar");
        logger.shouldPrintMessage(3, "foo");
        logger.shouldPrintMessage(11, "foo");
    }
}
*/

/*
class RobotMessaageTracker{
    HashMap<String,Long> map = new HashMap<>();

    public void shouldPrintMessage(long timeStamp, String message){
        if(!map.containsKey(message)){
            map.put(message,timeStamp);
            System.out.println(message);

        }
        else{
            if(timeStamp - map.get(message)>=10){
                map.put(message,timeStamp);
                System.out.println(message);
            }
        }
    }
}*/


// follow-up

class RobotMessageTracker {

    class MessageNode {
        long timeStamp;
        String message;
        String status;
        
        MessageNode(long timeStamp, String message) {
            this.timeStamp = timeStamp;
            this.message = message;
            this.status = "ON_HOLD";
        }
    }

    public Map<String, MessageNode> messageTracker;
    public Queue<MessageNode> queue;

    public RobotMessageTracker() {
        messageTracker = new HashMap<>();
        queue = new LinkedList<>();
    }

    public void shouldPrintMessage(long timeStamp, String message){
        
        MessageNode newNode = new MessageNode(timeStamp, message);
        MessageNode prevNode = messageTracker.getOrDefault(message, null);
        
        if (prevNode != null && (newNode.timeStamp - prevNode.timeStamp) < 10) {
            prevNode.status = "CANCELLED";
            newNode.status = "CANCELLED";
        }
        messageTracker.put(message,  newNode);
        queue.offer(newNode);       
        flushQueue(timeStamp);
    }

    private void flushQueue(long timeStamp) {
        
        while (!queue.isEmpty() && (timeStamp - queue.peek().timeStamp) >= 10) {
            MessageNode node = queue.poll();
            if (node.status.equals("ON_HOLD")) {
                System.out.println(node.message + " " + node.timeStamp);
            }    
        } 
    }

}