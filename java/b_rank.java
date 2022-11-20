import java.util.*;
public class Main {
  static boolean win(char[][] t, int n, char c) {
    for (int i=0; i<n; i++) {
      boolean flg1 = true;
      for (int j=0; j<n; j++)
        if (t[i][j] != c)
          flg1 = false;
      boolean flg2 = true;
      for (int j=0; j<n; j++)
        if (t[j][i] != c)
          flg2 = false;
      if (flg1 || flg2)
        return true;
    }
    
    boolean flg1 = true;
    for (int i=0; i<n; i++)
      if (t[i][i] != c)
        flg1 = false;
    boolean flg2 = true;
    for (int i=0; i<n; i++)
      if (t[i][n-i-1] != c)
        flg2 = false;
    return flg1 || flg2;
  }
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = 5;
    char[][] t = new char[5][5];
    for (int i=0; i<n; i++)
      t[i] = sc.nextLine().toCharArray();
    if (win(t, n, 'O'))
      System.out.println('O');
    else if (win(t, n, 'X'))
      System.out.println('X');
    else
      System.out.println('D');
  }
}