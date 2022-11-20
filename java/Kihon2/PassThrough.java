//[プログラム3]
import java.util.List;
import java.util.Map;
/**
 * 置換指示以外処理クラス
 * @author 2019 Fullness, Inc. All Rights Reserved.
 *
 */

//*****
//設問1 a ウ implemets
//Fragmentはインタフェース
//インタフェースを実装する際は「implements」を使用
//*****
public class PassThrough implements Fragment {
	//文字列
	final String str;

	/**
	 * コンストラクタ（初期化処理）
	 * @param cs char値のシーケンスを表すインタフェース(APIの説明より)
	 *
	 */
	PassThrough(CharSequence cs){
		//引数の値（charの文字列）をStringに変換し、strに代入する
		str = cs.toString();

	}
	/**
	 * 置換メソッド
	 */
	@Override
	public String replace(Map<String, List<String>> table) {
		//フィールドの文字列を返す
		return str;
	}

}