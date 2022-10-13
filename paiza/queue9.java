
import java.util.*;
public class Main {
	static Scanner sc = new Scanner(System.in);
	static ArrayList<Integer> intArray = new ArrayList<Integer>();
	static ArrayList<String> strArray = new ArrayList<String>();
	public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        
        //ループ回数を入力
        int n = sc.nextInt();
        
        LinkedList<Integer> a = new LinkedList<>();
        
        for (int i = 0; i < n; i++) {
            String job = sc.next();
            if (job.equals("in")) {
                int e = sc.nextInt();
                a.offer(e);
            } else {
                a.poll();
            }
        }

        for (int x : a) {
            System.out.println(x);
        }
    }
}
//
//LinkedList を用いた方法です。
//LinkedList は使い方次第でデータ構造の queue (キュー)を実現させることができます。
//LinkedList で空のリストを用意する方法は ArrayList のときと同じ要領で行います。
//queue に要素を追加することを enqueue と言いますが、LinkedList では、この enqueue を offer メソッドで行います。
//対して要素を削除することを dequeue と言いますが、LinkedList では、この dequeue を poll メソッド、または remove メソッドなどで行います。
//よって指示が in のときは enqueue に、out のときは dequeue に対応するメソッドを使うようにコードを書けば解けます。
