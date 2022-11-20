
//[プログラム6]
import java.io.FileReader;
import java.io.IOException;
import java.io.Reader;

/**
 * テスト用クラス
 * @author 2019 Fullness, Inc. All Rights Reserved
 *
 */
public class TemplateTester {

	public static void main(String[] args) throws  IOException{
		try(
			Reader tReader = new FileReader("template.txt");
			Reader rReader = new FileReader("replacementTable.txt");

			){
			Template template = TemplateParser.parse(tReader);
//			//省略されたプログラム
//			Map<String,List<String>> table =
//				ReplacementTableParser.parse(rReader);
//			System.out.println(template.apply(table));
		}
	}

}