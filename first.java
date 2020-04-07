import java.util.Scanner;

public class Application {
	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);
		System.out.println("Enter a double num: ");
		double num=input.nextDouble();
		System.out.printf("You entered: %f\n",num);

		/*string input*/

		System.out.println("Enter a string: ");
		input.nextLine();
		String s=input.nextLine();
		System.out.print("You entered: "+s);
	}
}
