import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int times = scanner.nextInt();
        long sum = 0;
        
        for (int i = 0; i < times; i++) {
            long tmp[] = new long[2];
            tmp[0] = scanner.nextInt();
            tmp[1] = scanner.nextInt();

            if (tmp[0] != tmp[1]) {
                sum += (tmp[0] + tmp[1]);
            } else {
                sum += (tmp[0] * tmp[1]);
            }
        }

        System.out.println(sum);

        scanner.close();
    }
}
