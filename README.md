###To Do  
1)obviously , make this readme file  
2)Give sample input for all templates and proper comment it (all the types of inputs...)  
3)set input as var for all templates (specifically buffer reader one)</br>  
4)do something for default values if - no arguments passed , first passed but isnumber and vice versa , number out of range etc  
5)add comments all over.  
<<<<<<< HEAD
6)I have given permanent paths every where, try replacing it with relative paths. ex  ../abc instead of $path_to/fi.java  
6.2)in above, go one step back and then into sub folder(ie use ../ to mention that we are using relatie path)  
6.3)ex ../current_folder/subfolder/abc.txt  
6.4)Or try using ./ representing the current dierectory
=======
6)make a makefile for which will do all the initial setup  
7)instead of doing run.sh make it simple like run.(refer example of ls command)
>>>>>>> 826ebc69783d97eed75d1766216d57b904cef24e
###For read me  
1)added a templates_path variable for temporary and file execution  
2)add proper steps to set home dierectory path  

###Bugs


###NOTE
1) use this whenever delete the files from bin
export PATH=$PATH:$HOME/bin/CP_Java_template

or


    Open the .bashrc file in your home directory (for example, /home/your-user-name/.bashrc) in a text editor.
    Add export PATH="your-dir:$PATH" to the last line of the file, where your-dir is the directory you want to add.
    Save the .bashrc file.
    Restart your terminal.
    
2) Give permision
 chmod -R a+x CP_Java_template
