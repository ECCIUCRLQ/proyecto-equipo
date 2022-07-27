#include "ImageBMP.hpp"
#include <fstream>
#include <iostream>


Color::Color() : rojo(' '), verde(' '), azul(' ')
{

}

Color::Color(unsigned char r, unsigned char g, unsigned char b) 
	: rojo(r), verde(g), azul(b)
{

}

Color::~Color()
{

}

ImageBMP::ImageBMP(int anch, int alt) :
	anchura(anch), altura(alt), imageRGB(std::vector<Color>(anch*alt))
{

}
ImageBMP::~ImageBMP()
{

}

Color ImageBMP::getColor(int anch, int alt) const
{
	return imageRGB[alt * anchura + anch];
}

void ImageBMP::setColor(int anch, int alt, Color c)
{
	imageRGB[alt * anchura + anch].rojo = c.rojo;
	imageRGB[alt * anchura + anch].verde = c.verde;
	imageRGB[alt * anchura + anch].azul = c.azul;
}

void ImageBMP::Read(const char* path){
	std::ifstream f;
	f.open(path, std::ios::in|std::ios::binary);
	if(!f.is_open()){
		printf("no se pudo abrir el archivo");
		return;
	}

	const int fileHeaderSize = 14;
	const int infoHeaderSize = 40;

	unsigned char fileHeader[fileHeaderSize];
	f.read(reinterpret_cast<char*>(fileHeader),fileHeaderSize);

	unsigned char infoFileHeader[infoHeaderSize];
	f.read(reinterpret_cast<char*>(infoFileHeader),infoHeaderSize);

	//int fileSize = fileHeader[2] + (fileHeader[3] << 8) + (fileHeader[4] << 16) + (fileHeader[5] << 24);

	anchura = infoFileHeader[4] + (infoFileHeader[5] << 8) + (infoFileHeader[6] << 16) + (infoFileHeader[7] << 24);
	altura = infoFileHeader[8] + (infoFileHeader[9] << 8) + (infoFileHeader[10] << 16) + (infoFileHeader[11] << 24);

	imageRGB.resize(anchura*altura);

	const int padding = ((4 - (anchura*3) %4)%4);

	for (int i = 0; i < anchura; ++i){
		for (int j = 0; j < altura; ++j){
			unsigned char color[3];
			f.read(reinterpret_cast<char*>(color),3);
			imageRGB[i * anchura + j].rojo = static_cast<char>(color[2]);
			imageRGB[i * anchura + j].verde = static_cast<char>(color[1]);
			imageRGB[i * anchura + j].azul = static_cast<char>(color[0]);
		}
		f.ignore(padding);
	}
	f.close();
}

void ImageBMP::Exportar(const char* path)
{
	std::ofstream f;
	f.open(path, std::ios::out | std::ios::binary);

	if(!f.is_open())
	{
		printf("No se pudo abrir el archivo\n");
		return;
	}

	unsigned char bmpPAD[3] = {0, 0, 0};
	const int padding = ((4 - (anchura * 3) % 4) % 4);

	const int fileHeaderSize = 14;
	const int infoHeaderSize = 40;
	const int fileSize = fileHeaderSize + infoHeaderSize + anchura * altura * 3 + padding * altura;

	unsigned char fileHeader[fileHeaderSize];

	fileHeader[0] = 'B';
	fileHeader[1] = 'M';

	fileHeader[2] = fileSize;
	fileHeader[3] = fileSize >> 8;
	fileHeader[4] = fileSize >> 16;
	fileHeader[5] = fileSize >> 24;

	fileHeader[6] = 0;
	fileHeader[7] = 0;
	fileHeader[8] = 0;
	fileHeader[9] = 0;

	fileHeader[10] = fileHeaderSize + infoHeaderSize;
	fileHeader[11] = 0;
	fileHeader[12] = 0;
	fileHeader[13] = 0;

	unsigned char infoHeader[infoHeaderSize];

	infoHeader[0] = infoHeaderSize;
	infoHeader[1] = 0;
	infoHeader[2] = 0;
	infoHeader[3] = 0;

	infoHeader[4] = anchura;
	infoHeader[5] = anchura >> 8;
	infoHeader[6] = anchura >> 16;
	infoHeader[7] = anchura >> 24;


	infoHeader[8]  = altura;
	infoHeader[9]  = altura >> 8;
	infoHeader[10] = altura >> 16;
	infoHeader[11] = altura >> 24;

	infoHeader[12] = 1;
	infoHeader[13] = 0;

	infoHeader[14] = 24;
	infoHeader[15] = 0;

	infoHeader[16] = 0;
	infoHeader[17] = 0;
	infoHeader[18] = 0;
	infoHeader[19] = 0;
	infoHeader[20] = 0;
	infoHeader[21] = 0;
	infoHeader[22] = 0;
	infoHeader[23] = 0;
	infoHeader[24] = 0;
	infoHeader[25] = 0;
	infoHeader[26] = 0;
	infoHeader[27] = 0;
	infoHeader[28] = 0;
	infoHeader[29] = 0;
	infoHeader[30] = 0;
	infoHeader[31] = 0;
	infoHeader[32] = 0;
	infoHeader[33] = 0;
	infoHeader[34] = 0;
	infoHeader[35] = 0;
	infoHeader[36] = 0;
	infoHeader[37] = 0;
	infoHeader[38] = 0;
	infoHeader[39] = 0;

	f.write(reinterpret_cast<char*>(fileHeader), fileHeaderSize);
	f.write(reinterpret_cast<char*>(infoHeader), infoHeaderSize);

	for(int i = 0; i < anchura; ++i){
		for(int j = 0; j < altura; ++j){

			unsigned char r = static_cast<unsigned char>(getColor(i,j).rojo);
			unsigned char g = static_cast<unsigned char>(getColor(i,j).verde);
			unsigned char b = static_cast<unsigned char>(getColor(i,j).azul);

			unsigned char color[] = {b, g, r};

			f.write(reinterpret_cast<char*>(color),3);
		}

		f.write(reinterpret_cast<char*>(bmpPAD),padding);
	}
	f.close();

}

void ImageBMP::Exportar(std::string path)
{
	std::ofstream f;
	f.open(path, std::ios::out | std::ios::binary);

	if(!f.is_open())
	{
		printf("No se pudo abrir el archivo\n");
		return;
	}

	unsigned char bmpPAD[3] = {0, 0, 0};
	const int padding = ((4 - (anchura * 3) % 4) % 4);

	const int fileHeaderSize = 14;
	const int infoHeaderSize = 40;
	const int fileSize = fileHeaderSize + infoHeaderSize + anchura * altura * 3 + padding * altura;

	unsigned char fileHeader[fileHeaderSize];

	fileHeader[0] = 'B';
	fileHeader[1] = 'M';

	fileHeader[2] = fileSize;
	fileHeader[3] = fileSize >> 8;
	fileHeader[4] = fileSize >> 16;
	fileHeader[5] = fileSize >> 24;

	fileHeader[6] = 0;
	fileHeader[7] = 0;
	fileHeader[8] = 0;
	fileHeader[9] = 0;

	fileHeader[10] = fileHeaderSize + infoHeaderSize;
	fileHeader[11] = 0;
	fileHeader[12] = 0;
	fileHeader[13] = 0;

	unsigned char infoHeader[infoHeaderSize];

	infoHeader[0] = infoHeaderSize;
	infoHeader[1] = 0;
	infoHeader[2] = 0;
	infoHeader[3] = 0;

	infoHeader[4] = anchura;
	infoHeader[5] = anchura >> 8;
	infoHeader[6] = anchura >> 16;
	infoHeader[7] = anchura >> 24;


	infoHeader[8]  = altura;
	infoHeader[9]  = altura >> 8;
	infoHeader[10] = altura >> 16;
	infoHeader[11] = altura >> 24;

	infoHeader[12] = 1;
	infoHeader[13] = 0;

	infoHeader[14] = 24;
	infoHeader[15] = 0;

	infoHeader[16] = 0;
	infoHeader[17] = 0;
	infoHeader[18] = 0;
	infoHeader[19] = 0;
	infoHeader[20] = 0;
	infoHeader[21] = 0;
	infoHeader[22] = 0;
	infoHeader[23] = 0;
	infoHeader[24] = 0;
	infoHeader[25] = 0;
	infoHeader[26] = 0;
	infoHeader[27] = 0;
	infoHeader[28] = 0;
	infoHeader[29] = 0;
	infoHeader[30] = 0;
	infoHeader[31] = 0;
	infoHeader[32] = 0;
	infoHeader[33] = 0;
	infoHeader[34] = 0;
	infoHeader[35] = 0;
	infoHeader[36] = 0;
	infoHeader[37] = 0;
	infoHeader[38] = 0;
	infoHeader[39] = 0;

	f.write(reinterpret_cast<char*>(fileHeader), fileHeaderSize);
	f.write(reinterpret_cast<char*>(infoHeader), infoHeaderSize);

	for(int i = 0; i < anchura; ++i){
		for(int j = 0; j < altura; ++j){

			unsigned char r = static_cast<unsigned char>(getColor(i,j).rojo);
			unsigned char g = static_cast<unsigned char>(getColor(i,j).verde);
			unsigned char b = static_cast<unsigned char>(getColor(i,j).azul);

			unsigned char color[] = {b, g, r};

			f.write(reinterpret_cast<char*>(color),3);
		}

		f.write(reinterpret_cast<char*>(bmpPAD),padding);
	}
	f.close();

}


