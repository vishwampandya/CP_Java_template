echo "enter file name"
read filename
full_filename=$filename".java"
touch $full_filename
sed 's/MainClass/'$filename'/g' templates/template_4_Scanner_class.txt > $full_filename
echo "file created!"
