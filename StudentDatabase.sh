clear
while [ 1 ]
do
        echo "1.Create\n2.Display\n3.Insert\n4.Search\n5.Modify\n6.Delete\n7.exit"
        echo "Ent
while [ 1 ]
do 
	echo "1.Create\n2.Display\n3.Insert\n4.Search\n5.Modify\n6.Delete\n7.exit"
	echo "Enter choice=\c"
	read ch
	case $ch in
		1)
			echo -n "Enter File name:"
			read fname
			if [ -e $fname ]
			then
				echo "File Already Exists"
			else
				>> $fname
				echo "File Created Successfully"
			fi
			;;
		2)
			echo -n "Enter File Name:"
		        read fname
			if [ -e $fname ]
			then
				echo "The Content Of File"
				sort -n $fname
			else
				echo"File name does not exist"
			fi
			;;
		3)
			echo -n "Enter File Name:"
                        read fname
                        if [ -e $fname ]
                        then
				echo "Enter the roll number"
				read roll
				grep -w "$roll" $fname
				flag=$?
				if [ $flag -eq 0 ]
				then
					echo "The roll number already exists"
				else
					echo "Enter the name of students"
					read name 
					echo $roll $name >> $fname
					echo "Record Inserted successfully"
				fi
			else
				echo"The file does not exist"
			fi
			;;
		7)
			exit
			;;
		*)
			echo "Wrong choice please try again"
			;;


	       				       
	esac
done
