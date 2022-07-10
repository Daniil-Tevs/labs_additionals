#include <fstream>
#include <string>
#include <vector>
#include "matrix.h"
#pragma pack(1)
struct pixel
{
    unsigned char b;
    unsigned char g;
    unsigned char r;
};
#pragma pack()
#pragma pack()
class bmp{
public:
    bmp(std::string from);
    bmp(const bmp& image)
    {
        m_header = image.m_header;
        m_info = image.m_info;
        m_width = image.m_width;
        m_height = image.m_height;
        for (int i = 0; i < m_height; i++)
            pixels.push_back(image.pixels[i]);
    }
    bmp& operator=(const bmp& image);

    ~bmp();
    void write(std::string where);
    void shorthand(int power,int where_x, int where_y,const std::vector<std::string>& word);
    void filter(char color,char up_or_down,int power);
    void rotate(double angle);
    int getHeight() const;
    int getWidth() const;
private:
    int interpolation(int i,int j, int& s,const std::vector<std::vector<pixel>>& pixels,char color);
#pragma pack(1)
    struct bmp_header
    {
        unsigned short    Type;
        unsigned int      Size;
        unsigned short    Reserved1;
        unsigned short    Reserved2;
        unsigned int      OffBits;
    };
#pragma pack()
#pragma pack(1)
    struct bmp_info
    {
        unsigned int    Size;
        int             Width;
        int             Height;
        unsigned short  Planes;
        unsigned short  BitCount;
        unsigned int    Compression;
        unsigned int    SizeImage;
        int             XPelsPerMeter;
        int             YPelsPerMeter;
        unsigned int    ClrUsed;
        unsigned int    ClrImportant;
    };
#pragma pack()

    int m_height, m_width;
    bmp_header m_header;
    bmp_info m_info;
    std::vector<std::vector<pixel>> pixels;
    vec2d** m_coordinates = nullptr;
};