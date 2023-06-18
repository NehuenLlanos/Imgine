#! /bin/bash

set -e
ROOT="$(dirname "$0")"

echo "Relocating script to '$ROOT'..."
cd "$ROOT/.."

if [ $# -eq 1 ]
then
    cat "$1" | ./bin/Compiler
elif [ $# -eq 2 -a $1 = "-g" ]
then
    cat "$2" | ./bin/Compiler $1
else
    echo "Argumentos Invalidos. Uso: ./script/start.sh [-g] path/a/archivo.imgine"
fi