import java.util.*;

public class balancedParenthesis {

    public static boolean isBalanced(String s) {
        Stack<Character> st = new Stack<>();

        for(char i:s.toCharArray()) {
            if(i=='(' || i=='{' || i=='[') {
                st.push(i);
            }
            else if(!st.isEmpty() && ((i==')' && st.peek()=='(') || (i=='}' && st.peek()=='{') || (i==']' && st.peek() =='['))) {
                st.pop();
            }
            else {
                return false;
            }
        }
        return st.isEmpty();
    }

    public static void main(String[] args) {

        String expr1 = "[()]{}{()()}";
        String expr2 = "[()";

        System.out.println(isBalanced(expr1)); 
        System.out.println(isBalanced(expr2)); 
    }
}
