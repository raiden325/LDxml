@echo off

if exist pathlist.txt (
	echo "pathlist.txt������܂����B�폜���܂��B"
	del pathlist.txt
)
echo "pathlist.txt���쐬���܂��B"
dir /b /s *.xml >> pathlist.txt
