package paiza;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
public class Main {
	static Scanner sc = new Scanner(System.in);
	static ArrayList<Integer> intArray = new ArrayList<Integer>();
	static ArrayList<String> strList = new ArrayList<String>();
	static HashMap<Integer,Integer> MapBonus = new HashMap<>();
	public static void main(String[] args){

		        String s1 = sc.next();
		        String s2 = sc.next();

		        // PAIZA表記の文字列を10進数のint型に変換
		        int num1 = convertToDecimal(s1);
		        int num2 = convertToDecimal(s2);

		        // 10進数で足し算
		        int sum = num1 + num2;

		        // 10進数をPAIZA表記の文字列に変換
		        String result = convertToPaiza(sum);

		        System.out.println(result);
		    }

		    // PAIZA表記の文字列を10進数のint型に変換するメソッド
		    public static int convertToDecimal(String s) {
		        int num = 0;
		        for (int i = 0; i < s.length(); i++) {
		            char c = s.charAt(i);
		            int digit = c - 'A';
		            num = num * 5 + digit;
		        }
		        return num;
		    }

		    // 10進数をPAIZA表記の文字列に変換するメソッド
		    public static String convertToPaiza(int num) {
		        if (num == 0) {
		            return "A";
		        }

		        String result = "";
		        while (num > 0) {
		            int digit = num % 5;
		            char c = (char)('A' + digit);
		            result = c + result;
		            num /= 5;
		        }
		        return result;
		    }
		}




/*
入力はScannerクラスを使って受け取ります。まず、S1とS2を文字列として受け取ります。
次に、それらを10進数のint型に変換し、足し算を行います。
最後に、足し算の結果をPAIZA表記の文字列に変換して出力します。

10進数からPAIZA表記の文字列に変換するには、10進数を5で割りながら余りを求め、
余りに対応する文字（A, B, C, D, E）を文字列の先頭に付け加えていくことで実現できます。
例えば、10進数の値が13の場合、13÷5=2余り3なので、先頭に文字Dを付け加えます。
次に、商が2であるため、2÷5=0余り2となります。余り2に対応する文字はCなので、次にCを付け加えます。
これを繰り返していくことで、10進数をPAIZA表記の文字列に変換できます。

*/
