#include <vector>
#include <string>
/* Creditos: https://www.youtube.com/watch?v=NcEE5xmpgQ0&t=709s [Designed By Hugo]
 */
struct Color {
	unsigned char rojo, verde, azul;

	Color();
	Color(unsigned char r, unsigned char g, unsigned char b);
	~Color();
};

class ImageBMP {
public:

	int anchura, altura;
	std::vector<Color> imageRGB;

	ImageBMP(int anch, int alt);
	~ImageBMP();
	void setColor(int anch, int alt, Color c);
	Color getColor(int anch, int alt) const;
	void Exportar(const char* path);
	void Exportar(std::string path);
	void Read(const char* path);
};