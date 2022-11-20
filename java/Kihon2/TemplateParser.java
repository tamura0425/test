//[プログラム4]

import java.io.IOException;
import java.io.Reader;
import java.util.ArrayList;
import java.util.List;

/**
 * ひな型変換クラス
 * @author2019 Fullness, Inc. All Rights Reserved.
 *
 */
public class TemplateParser {
	static public Template parse(Reader reader)throws IOException{
		//出力用の文字列を生成
		StringBuilder buf = new StringBuilder();
		//フラグメント（文字列の集合）を生成
		List<Fragment> fragmentList = new ArrayList<>();
		int c;
		//文字列ストリームから1文字ずつ読み込む
		while ((c = reader.read())>= 0 ){
			switch(c){
			//キー名称の開始位置
			case '<':
//*****
//設問1 b ウ
				//fragmentListの要素は<Fragment>
				//今読み込んだ内容を1文字(c)ではなく、
				//今までの文字列(buf)として
				//置換せずにフラグメントに追加するため、
				//置換指示以外のクラスPassThroughのインスタンスを生成し
				//フラグメントに追加
				fragmentList.add(new PassThrough(buf));
//*****
				//次の文字列を格納するための新しい文字列を生成
				buf = new StringBuilder();
				break;
			//キー名称の終了位置
			case '>':
//*****
//設問1 c オ
				//fragmentListの要素は<Fragment>
				//今読み込んだ内容を1文字(c)ではなく、
				//今までの文字列(buf)をキー名称として、
				//置換してフラグメントに追加
				//置換指示クラスReplacerのインスタンスをフラグメントに追加
				fragmentList.add(new Replacer(buf));
//*****
				//次の文字列を格納するための新しい文字列を生成
				buf = new StringBuilder();
				break;
//*****
//設問2  f オ
			case '\\':
				//続けてファイルを読み込み、その文字列を追加
				buf.append((char) reader.read());
				//breakしないとdefaultの命令も実行してしまい、
				//先に読み込んだc('\\')が追加されてしまう
				break;
//*****
			//それ以外の文字列
			default:
				//文字列に1文字追加
				buf.append((char)c);
			}
		}
		//文字列(buf)にある文字列を置換せずにフラグメントに追加
		fragmentList.add((new PassThrough(buf)));
//******
//設問1 d ウ
		//P58 2行目
		//このメソッドの戻り値の型はTemplateクラスであり、
		//Templateクラスのコンストラクタの引数はList<Fragment>
		//ひな型をフラグメントのリストとして保持するクラスの
		//インスタンスを返す
		return new Template(fragmentList);

	}
 }