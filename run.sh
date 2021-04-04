#!/bin/bash

#path_to_project=$HOME/bin/CP_Java_template
#below one for testing
path_to_project=$HOME/E/Projects/CP_Java_template-git

get_file_name(){
	if [[ $# == 0 ]]
	then
	filename="SampleClass"
	else
	filename=$1
	fi

	echo $filename
}

check_if_file_exist_and_not_continue(){
	path_to_project=$1
	full_filename=$2
	
	FILE=$path_to_project/$full_filename
    	if [[ -f "$FILE" ]]; then
   		echo "file name $full_filename already exist"
   		echo "Do you want to continue?[y/n]"
   		read answer
   		if [[ answer == 'N' ]] || [[ answer == 'n' ]]
   		then
   		return 0
   		fi
	fi
	
	return 1
}

get_template_name(){
	temp_no=$2
	no_of_arguments=$#
	
	
	if [[ $no_of_arguments -le 1 ]] || [[ $temp_no == 4 ]]
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

################################################################################################
##################THIS PART NOT WORKING PROPERLY################################################

# check_if_file_exist_and_not_continue $path_to_project $full_filename
# donot_want_to_continue=$?
# if [[ donot_want_to_continue == 1  ]]
# then
# exit
# fi
# touch $full_filename

################################################################################################

template_name="$(get_template_name $*)"


sed 's/MainClass/'$filename'/g' ./templates/$template_name > $full_filename 2> error.txt
return_sed_create=$?
if [[ $return_sed_create == 0 ]]
then
echo "file created!"
else
rm $full_filename
echo "failed to create file! please check error file to check for errors."
fi





