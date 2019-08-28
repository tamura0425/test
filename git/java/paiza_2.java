import java.util.*;

public class Paiza {
    public static void main(String[] args) throws Exception {

       ArrayList<Integer> intArray = new ArrayList<Integer>();
		Scanner sc = new Scanner(System.in);
		int ans = 0;
		
		int loop = sc.nextInt(); //ループ回数

		for(int i = 0; i < loop; i++){
			int input = sc.nextInt();
			int array[] = input.split();
			intArray.add(array);

			if(intAarray[0] == intAarray[1]){
				ans += intAarray[0] * intAarray[1];
			}
			else{
				ans += intAarray[0] + intAarray[1];
			}

			System.out.println(ans);
		}
	}
}

// スペース区切りの2つの整数がn行与えられるので、2つの整数をそれぞれ足し合わせて、さらに、その結果をすべての行について足し合わせて出力してください。
// ただし、2つの整数が同じだった場合は、2つの整数を掛け合わせてから、その結果を足し合わせてください。