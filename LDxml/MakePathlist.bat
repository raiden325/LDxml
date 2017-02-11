@echo off

if exist pathlist.txt (
	echo "pathlist.txt‚ª‚ ‚è‚Ü‚µ‚½Bíœ‚µ‚Ü‚·B"
	del pathlist.txt
)
echo "pathlist.txt‚ğì¬‚µ‚Ü‚·B"
dir /b /s *.xml >> pathlist.txt
