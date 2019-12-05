import java.util.Scanner;

public class Test {
	public static void main(String[] args) {
		System.out.print("请输入你的名字: ");
		Scanner in = new Scanner(System.in);
		System.out.println("你的名字为: " + in.nextLine());
	}
}
