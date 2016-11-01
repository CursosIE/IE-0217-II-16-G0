#!/bin/sh

inc="$3"
echo "Generando csv..."

for j in $(seq 0 99)
do
  
  for i in $(seq 0 9)
  do
   ./linea $1 $2 $inc $4   
  done

  inc=`expr $inc + 500`

done

echo "Archivo csv generado con exito."
