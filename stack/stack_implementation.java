import java.io.*;
import java.util.*;

class stack_implementation
{
	public static void main(String[] args) {
		Stack <Integer> stack = new Stack<Integer> ();
		stack.push(3);
		stack.push(4);
		stack.push(5);
		System.out.println(stack.peek());
		System.out.println(stack.pop());
		System.out.println(stack.pop());
		System.out.println(stack.pop());
	}
}