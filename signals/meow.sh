#!/bin/bash

trap "echo 'Вот это почему не рассчитано?'" SIGUSR1;
trap "echo 'Извините, я коооот'" SIGUSR2;

echo "Send SIGUSR1 or SIGUSR2 signal, e. g.: kill -SIGUSR1 $$";

sleep 3;

for (( i=0; i <= 10; i++ )) do
    echo 'мяу';
    echo;
    sleep 1;
done