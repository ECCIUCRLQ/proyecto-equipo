# Makefile
clean:
	rm -rf main
filter:
	g++ src/main.cpp src/ImageBMP.hpp src/ImageBMP.cpp filtro/black.s filtro/negativo.s filtro/lentes3D.s filtro/amarillo.s filtro/serpia.s -o main

help:
	@echo " "
	@echo "make clean: remover ejecutables"
	@echo "make filter: crear ejecutables"
	@echo "./main argv[1] argv[2]: correr ejecutables"
	@echo " "
	@echo "argv[1] = paht_imagen"
	@echo "argv[2] = filtro"
	@echo " "
	@echo "1- Negativo"
	@echo "2- Blanco y Negro"
	@echo "3- Lentes 3D"
	@echo "4- Verano"
	@echo "5- Serpia"
	@echo " "