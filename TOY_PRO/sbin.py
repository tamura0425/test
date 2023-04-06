S = "iloveshibainu"
n = len(S)
ans = float('inf')

# 全ての部分文字列に対して、's', 'b', 'i', 'n' の出現位置を探索
for i in range(n):
    if S[i] != 's':
            continue
                for j in range(i+1, n):
                        if S[j] != 'b':
                                    continue
                                            for k in range(j+1, n):
                                                        if S[k] != 'i':
                                                                        continue
                                                                                    for l in range(k+1, n):
                                                                                                    if S[l] != 'n':
                                                                                                                        continue
                                                                                                                                        # 's', 'b', 'i', 'n' の順番で出現する文字列を見つけた場合
                                                                                                                                                        ans = min(ans, l-i+1)

                                                                                                                                                        # 答えを出力
                                                                                                                                                        if ans == float('inf'):
                                                                                                                                                            print('No')
                                                                                                                                                            else:
                                                                                                                                                                print(ans)

