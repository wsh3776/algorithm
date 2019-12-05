//简单的剪刀、石头、布游戏
import java.util.Scanner;
/**
* switch实现石头、剪刀、布并判断胜负
* @author：Wilson79
*/

public class RockPaperScissors {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Please choice.");
        System.out.println("1.Rock");
        System.out.println("2.Scissors");
        System.out.println("3.Paper");
        // 用户输入
        int choice = scanner.nextInt();
        int random = 1 + (int) (Math.random() * 3);
        System.out.println("Mine:" + (choice == 1 ? "Rock" : choice == 2 ? "Scissors" : "Paper")
                           + " VS Machine:" + (random == 1 ? "Rock" : random == 2 ? "Scissors" : "Paper"));

        switch (choice - random) {
        case 0:
            System.out.println("--->Equal");
            break;
        case 1:
        case -2:
            System.out.println("--->Lose");
            break;
        default:
            System.out.println("--->Win");
            break;
        }

    }
}