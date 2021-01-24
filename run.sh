
#!/bin/bash

#templates_path=$HOME/bin/CP_Java_template/templates
#below one for testing
templates_path=$HOME/E/Projects/CP_Java_template-git/templates

get_file_name(){
	if [[ $# == 0 ]]
	then
	filename="SampleClass"
	else
	filename=$1
	fi

	echo $filename
}



get_template_name(){
	temp_no=$2
	no_of_arguments=$#
	
	
	if [[ $no_of_arguments -lt 1 ]] || [[ $temp_no == 4 ]]
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


filename="$(get_file_name $*)"
full_filename=$filename".java"
touch $full_filename


template_name="$(get_template_name $*)"


sed 's/MainClass/'$filename'/g' $templates_path/$template_name > $full_filename 2> error.txt
return_sed_create=$?
if [[ $return_sed_create == 0 ]]
then
echo "file created!"
else
rm $full_filename
echo "failed to create file! please error file to check for errors."
fi

#what if file already created? -> ask want to proceed?

