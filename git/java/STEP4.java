import java.util.*;

public class STEP4 {
    public static void main(String[] args) throws Exception {

       ArrayList<Integer> intArray = new ArrayList<Integer>();
		Scanner sc = new Scanner(System.in);
		int ans = 0;
		
		int loop = sc.nextInt(); //ループ回数

		for(int i = 0; i < loop; i++){
			int input1 = sc.nextInt();
			int input2 = sc.nextInt();
            intArray.add(0,input1);
            intArray.add(1,input2);

			if(intArray.get(0) == intArray.get(1)){
				ans += intArray.get(0) * intArray.get(1);
			}
			else{
				ans += intArray.get(0) + intArray.get(1);
            }
        }
        System.out.println(ans);
	}
}
