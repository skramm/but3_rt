# Determine if given command is builtin, a program, or not available

set +x
out=out.csv
if [ -f $out ]; then rm $out; fi

while IFS=";" read -a line
do
#	echo -n "line=$line"
	if [ ${#line} != 0 ]
	then
		echo -n "${line[0]};${line[1]};${line[2]};${line[3]};" >> $out
		type ${line[0]} 1>/tmp/commandtype 2>/dev/null
		ret=$?
		if [ $ret != 0 ]
		then
			echo "NI" >> $out
		else
			grep shell /tmp/commandtype 1>/dev/null
			if [ $? = 0 ]
			then
				echo "_builtin_" >> $out
			else
				echo "_installed_" >> $out
			fi
		fi
	fi
	
done < linux_commands.csv


