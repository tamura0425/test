//[プログラム1]
import java.util.List;
import java.util.Map;
/**
 *
 * @author 2019 Fullness, Inc. All Rights Reserved.
 * フラグメントインタフェース
 * フラグメント（ひな型の置換指示と置換指示以外の部分）
 *
 */

public interface Fragment {
	/**
	 * 置換メソッド
	 * @param table Map型のデータ
	 *
	 *                Key | Value
	 *              ------+---------
	 *              "名前"|"情報太郎"
	 *              "明細"|"メモリ ; 5,000円","HDD ; 9,500円"
	 *              "合計"|"14,000"
	 *
	 * @return 置換後の文字列
	 */
	String replace(Map<String,List<String>> table);

}