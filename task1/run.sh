#!/usr/bin/env bash

while [ -n "$1" ]
do
case $1 in
"--input_folder")
input_folder=$2
;;
"--extension")
extension=$2
;;
"--backup_folder")
backup=$2
;;
"--backup_archive_name")
name=$2
;;
esac
shift 2
done

mkdir $backup
find $input_folder -name "*.$extension" | xargs cp --parents -t $backup
tar -czf $name $backup
echo done
