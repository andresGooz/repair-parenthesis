Para ejecutar el código, escribir make en la terminal dentro de la carpeta
que contiene el archivo tarea1.cpp

Para probar con input desde un archivo, simplemente agregarlo en el comando
del makefile:
	./tarea1 < input.txt

Donde input es el nombre del archivo

Para crear un archivo output.txt con las soluciones, agregar: | tee output.txt
	./tarea1 < input.txt | tee output.txt

Donde output es el nombre del archivo a crear
