package test2;

import java.util.Scanner;
import java.util.Stack;

public class Solution {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);

		String S = scan.nextLine();

		String token[] = S.split(" ");
		int length = token.length;

		Stack myStack = new Stack();
		int error_check = 0;

		for (int i = 0; i < length; i++) {
			if (token[i].equals("DUP")) {
				if (myStack.size() < 1) {
					error_check = 1;
					break;
				}

				int val = (int) myStack.peek();
				myStack.push(val);
			} else if (token[i].equals("POP")) {
				if (myStack.size() < 1) {
					error_check = 1;
					break;
				}

				myStack.pop();
			} else if (token[i].equals("+")) {
				if (myStack.size() < 2) {
					error_check = 1;
					break;
				}

				int val1 = (int) myStack.pop();
				int val2 = (int) myStack.pop();

				myStack.push(val1 + val2);
			} else if (token[i].equals("-")) {
				if (myStack.size() < 2) {
					error_check = 1;
					break;
				}

				int val1 = (int) myStack.pop();
				int val2 = (int) myStack.pop();

				myStack.push(val1 - val2);
			} else {
				int val = Integer.parseInt(token[i]);
				myStack.push(val);
			}
		}

		int ans = -1;

		if (error_check == 0) {
			ans = (int) myStack.pop();
		}	
		System.out.println(ans);
	}
}
