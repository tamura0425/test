//[プログラム2]
import java.util.List;
import java.util.Map;
/**
 * 置換指示処理クラス
 * @author 2019 Fullness, Inc. All Rights Reserved.
 *
 */

//*****
//設問1 a ウ implemets
//Fragmentはインタフェース
//インタフェースを実装する際は「implements」を使用
//*****
public class Replacer implements Fragment {
	//キー名称
	final String key;

	/**
	 * コンストラクタ（初期化処理）
	 * @param cs char値のシーケンスを表すインタフェース(APIの説明より)
	 *
	 */
	Replacer(CharSequence cs){
		//引数の値（charの文字列）をStringに変換し、キー名称に代入する
		key = cs.toString();

	}
	/**
	 * 置換メソッド
	 */
	@Override
	public String replace(Map<String, List<String>> table) {
		//P57 (3)②より
		//置換表のキー名称に対応する置換用文字列が2つ以上あるときは、
		//各置換用文字列の間に改行を挟む
		//Stringクラスのjoinメソッドは複数の文字列の間に
		//区切り文字"\n"を挟んだ文字列を返す
		return String.join("\n", table.get(key));
	}

}