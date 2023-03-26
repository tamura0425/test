from PIL import Image
import os
import logging

# まとめたい jpg ファイルが入っているフォルダを指定します
input_folder = r"O:/プログラミング資料テキスト/黒本_Java Silver"

# 出力する pdf ファイルの名前を指定します
output_file = r"C:\Users\tamur\Desktop\123\output_file.pdf"

# 1ページあたりの解像度を指定します（デフォルトは 72dpi）
dpi = 300

# ログファイルのパスとログレベルを設定
logging.basicConfig(filename='example.log', level=logging.ERROR)

# jpg ファイルを読み込み、PDF ファイルに変換します
def convert_to_pdf(input_folder, output_file, dpi):
    try:
            images = []
                    for filename in sorted(os.listdir(input_folder)):
                                if filename.endswith(".JPG"):
                                                filepath = os.path.join(input_folder, filename)
                                                                img = Image.open(filepath)
                                                                                images.append(img)

                                                                                        # 画像をPDFにまとめます
                                                                                                if images:
                                                                                                            images[0].save(output_file, save_all=True, append_images=images[1:], dpi=(dpi,dpi))
                                                                                                                except Exception as e:
                                                                                                                        logging.error(e)

                                                                                                                        try:
                                                                                                                            convert_to_pdf(input_folder, output_file, dpi)
                                                                                                                            except Exception as e:
                                                                                                                                print(e)
                                                                                                                                    logging.error(e)

