#!/bin/bash

# sudo chmod u+x usrgithub.sh
# ./usrgithub.sh


echo -n " Escriba un hombre de usuario de github... "
read GITHUB_USER

#set GITHUB_USER=$name


GHU="https://api.github.com/users/$GITHUB_USER"
DATA=$(curl -S $GHU)

ID=$(echo $DATA | jq '.id')
CREATED_AT=$(echo $DATA | jq '.created_at')


echo "Hola $GITHUB_USER. UserID: $ID. Cuenta fue creada el: $CREATED_AT."

#echo "Hola <github_user>. UserID:<id>. Cuenta fue creada el:<created_at>."

#cronjob

HOY=$(date '+%Y-%m-%d')
INSTANTE=$(date '+%Y-%m-%d:%H%M:%S')
DIR_LOG="/tmp/$HOY"

if [ -d "$DIR_LOG" ]
then 
    echo "Directorio existente escribir llenar logfile"
else 
    mkdir -p $DIR_LOG
fi 


LOG_FILE="$DIR_LOG/saludos.log"
echo "Hola $GITHUB_USER. UserID: $ID. Cuenta fue creada el: $CREATED_AT. time $INSTANTE."  >> $LOG_FILE 


FIVE_MINUTES="*/5 * * * * "

(crontab -l ; echo "$FIVE_MINUTES $(pwd)/usrgithub.sh") | crontab -

