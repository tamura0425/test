//[プログラム5]

import java.util.List;
import java.util.Map;

/**
 *
 * ひな型をフラグメントのリストとして保持するクラス
 * @author 2019 Fullness, Inc. All Rights Reserved.
 *
 */
public class Template {
	//フラグメントリスト
	List<Fragment> fragmentList;

	/**
	 * コンストラクタ（初期化処理）
	 * @param fragmentList
	 */
	Template(List<Fragment> fragmentList) {
		this.fragmentList = fragmentList;
	}
	/**
	 * ひな型に置換表を適用して、出力文書を文字列で返す。
	 * @param table
	 * @return 出力用の文字列
	 */
	public String apply(Map<String,List<String>> table){

		//文字列を生成
		StringBuilder sb = new StringBuilder();
		//拡張for文 リストの全要素を１つずつ取り出し、変数に代入してくれる
		//for(リストの要素の型 変数名 : リスト名）
		for(Fragment fragment : fragmentList){
//*****
//設問1 e エ
			//Fragmentインタフェースのrepleceメソッドは
			//replace(Map<String,List<String>> table)
			//引数はMap型のため、applyメソッドの引数のtableをそのまま引数に渡す
			sb.append(fragment.replace(table));
//*****

		}
		//型変換 StringBuilderをStringに変換する
		//※Stringは毎回インスタンスを生成するが、
		//　StringBuilderは同じインスタンスに文字列を追加できるため、
		//　文字列連結を何度も行う場合は、StringBuilderのほうが効率が良い
		return sb.toString();
	}
}