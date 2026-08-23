import java.util.*;

public class evaluatePostfix {

    public static int evalPostfix(String s) {
        Stack<Integer> st = new Stack<>();
        String[] tokens = s.split(" ");

        for (String tk : tokens) {

            if (Character.isDigit(tk.charAt(0))) {
                st.push(Integer.parseInt(tk));
            }

            else {
                int b = st.pop();
                int a = st.pop();

                switch (tk) {
                    case "+": st.push(a + b); break;
                    case "-": st.push(a - b); break;
                    case "*": st.push(a * b); break;
                    case "/": st.push(a / b); break;
                }
            }
        }

        return st.pop();
    }

    public static void main(String[] args) {

        String s = "2 3 1 * + 9 -";
        System.out.println(evalPostfix(s));
    }
}
