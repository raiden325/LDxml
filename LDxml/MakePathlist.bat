@echo off

if exist pathlist.txt (
	echo "pathlist.txtがありました。削除します。"
	del pathlist.txt
)
echo "pathlist.txtを作成します。"
dir /b /s *.xml >> pathlist.txt
