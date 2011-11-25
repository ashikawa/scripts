# /bin/sh

WORK_DIR="workdir"

rm -r $WORK_DIR/*
mkdir $WORK_DIR/{1..100}

for FILE_NAME in `ls src_dir/*.png`
do
	
	NEW_FILE=`echo $FILE_NAME | sed -E "s|^.*/([0-9]+)-([abc])-.*$|\1/\2.jpg|g"`
	
###	other ###
#	NEW_FILE=`echo $NEW_FILE | sed -E "s|hoge\.png|moge.png|g"`
	

	NEW_FILE=$WORK_DIR"/"$NEW_FILE
	
#	echo $FILE_NAME
	echo $NEW_FILE
	
	cp $FILE_NAME $NEW_FILE

done

