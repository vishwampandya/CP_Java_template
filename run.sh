
#!/bin/bash

#templates_path=$HOME/bin/CP_Java_template/templates
#below one for testing
templates_path=$HOME/E/Projects/CP_Java_template/templates

filename=$1

if [[ $# == 1 ]] || [[ $2 == 4 ]]
then
 template_name=template_4_Scanner_class.txt
elif [[ $2 == 1 ]]
then
 template_name=template_1_Reader_class.txt
elif [[ $2 == 2 ]]
then
 template_name=template_2_FastReader_class.txt
elif [[ $2 == 3 ]]
then
 template_name=template_3_BufferReader_class.txt
else
 echo "Enter between 1 to 4"
fi

full_filename=$filename".java"
touch $full_filename
sed 's/MainClass/'$filename'/g' $templates_path/$template_name > $full_filename
echo "file created!"

#add if exist then file created , other wise not
