#!/bin/bash

#templates_path=$HOME/bin/CP_Java_template/templates
#below one for testing
templates_path=$HOME/E/Projects/CP_Java_template/templates

echo "enter file name"
read filename
full_filename=$filename".java"
touch $full_filename
sed 's/MainClass/'$filename'/g' $templates_path/template_4_Scanner_class.txt > $full_filename
echo "file created!"
