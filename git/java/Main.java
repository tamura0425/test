//文字列を切り取る Java編
import java.util.*;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        
        int beginning = sc.nextInt();
        int end = sc.nextInt();
        sc.nextLine();

        int start = beginning -1;
        end = end;
        
        
        String line = sc.nextLine();

        String str = line.substring(start,end);

        System.out.println(str);
    }
}

/*
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int start = scanner.nextInt();
        int end = scanner.nextInt();
        scanner.nextLine(); // 読み飛ばし
        String string = scanner.nextLine();

        System.out.println(string.substring(start - 1, end));

        scanner.close();
    }
}
*/