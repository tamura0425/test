package Shilver;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.logging.Logger;

public class Main {
	static final Logger logger = Logger.getAnonymousLogger();
	public static void main(String[] args) {


		Date date = new Date();

		da(date);
		da2(date);


	}


	public static void  da(Date a) {
		//System.out.println(a+"5555");
		SimpleDateFormat date2 = new SimpleDateFormat("yyyy/MM/dd");

		System.out.println(date2.format(a) + "   777");

	}
	public static void da2(Date a) {
		SimpleDateFormat date2 = new SimpleDateFormat("yyyy/MM/dd");
		date2.applyPattern("yyyy年MM月dd日 E");
        System.out.println(date2.format(a));
	}

}



