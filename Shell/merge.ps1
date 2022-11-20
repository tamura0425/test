$name = $Args[0]

type *_RAN > allLog.txt

#該当行以外削除

Select-String $name .\allLog.txt  | %{$_.Line} > new.txt

#カンマ（,）をタブに変換
(Get-Content "new.txt") -replace ",","`t" > sample_new.txt

