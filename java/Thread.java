package test;

import java.util.ArrayList;
import java.util.Scanner;

class ThreadSample extends Thread {
    public void run() {
        for (int i = 0; i < 5; i++) {
            System.out.println(""Thread i = " + i);
        }
    }
}

public class Main {
	static Scanner sc = new Scanner(System.in);
	static ArrayList<Integer> intArray = new ArrayList<Integer>();
	static ArrayList<String> strArray = new ArrayList<String>();
	public static void main(String[] args) {
		
		
        ThreadSample threadSample = new ThreadSample();
        threadSample.start();

	}

}

/*
JavaでThreadを使った非同期処理とは
※Thread　自分で作成しなくても最初から入っている。

スレッド(thread)とは、プログラムが処理を実行する単位をプログラマの必要に応じて増やせるものです。


https://www.bold.ne.jp/engineer-club/java-thread
 */

