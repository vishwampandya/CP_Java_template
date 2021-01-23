
#!/bin/bash

#templates_path=$HOME/bin/CP_Java_template/templates
#below one for testing
templates_path=$HOME/E/Projects/CP_Java_template-git/templates

filename=$1

get_template_name(){
	temp_no=$1
	no_of_arguments=$2
	
	
	if [[ $no_of_arguments == 1 ]] || [[ $temp_no == 4 ]]
	then
 	template_name="template_4_Scanner_class.txt"
	elif [[ $temp_no == 1 ]]
	then
 	template_name="template_1_Reader_class.txt"
	elif [[ $temp_no == 2 ]]
	then
 	template_name="template_2_FastReader_class.txt"
	elif [[ $temp_no == 3 ]]
	then
 	template_name="template_3_BufferReader_class.txt"
	else
 	echo "Enter between 1 to 4"
 	exit
	fi
	
	echo $template_name
}

template_name="$(get_template_name $2 $#)"



full_filename=$filename".java"
touch $full_filename
sed 's/MainClass/'$filename'/g' $templates_path/$template_name > $full_filename
echo "file created!"

#add if exist then file created , other wise not
