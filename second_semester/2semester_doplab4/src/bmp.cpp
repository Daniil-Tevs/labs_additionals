#include "bmp.h"
bmp::bmp(std::string from) {
    std::ifstream in(from, std::ios::binary);
    in.read(reinterpret_cast<char *>(&m_header), sizeof(bmp_header));
    in.read(reinterpret_cast<char *>(&m_info), sizeof(bmp_info));
    m_height = m_info.Height;
    m_width = m_info.Width;
    std::vector<pixel> v;
    pixel tmp{};
    for (int i = 0; i < m_height; i++) {
        for (int j = 0; j < m_width; j++) {
            in.read(reinterpret_cast<char *>(&tmp), sizeof(pixel));
            v.push_back(tmp);
        }
        if ((3 * m_width) % 4 != 0)
            for (int j = 0; j < 4 - (3 * m_width) % 4; j++) {
                char c;
                in.read(&c, 1);
            }
        pixels.push_back(v);
        v.clear();
    }
    m_coordinates = new vec2d * [m_height];
    for (int i = 0; i < m_height; i++)
        m_coordinates[i] = new vec2d[m_width];

    for (int i = 0; i < m_height; i++)
        for (int j = 0; j < m_width; j++)
        {
            m_coordinates[i][j].set(0, 0, j);
            m_coordinates[i][j].set(1, 0, i);
        }

};

bmp& bmp::operator=(const bmp& image)
{
    pixels.clear();
    m_header = image.m_header;
    m_info = image.m_info;
    m_width = image.m_width;
    m_height = image.m_height;
    for (int i = 0; i < m_height; i++)
        pixels.push_back(image.pixels[i]);
    return *this;
}

bmp::~bmp(){
    for (int i = 0; i < m_height; i++)
        delete[] m_coordinates[i];
    delete[] m_coordinates;
};
void bmp::write(std::string where)
{
    std::ofstream out(where, std::ios::binary);
    out.write(reinterpret_cast<char*>(&m_header), sizeof(bmp_header));
    out.write(reinterpret_cast<char*>(&m_info), sizeof(bmp_info));
    for (int i = 0; i < m_height; i++)
    {
        for (int j = 0; j < m_width; j++)
            out.write(reinterpret_cast<char*>(&pixels[i][j]), sizeof(pixel));

        if ((3 * m_width) % 4 != 0)
            for (int j = 0; j < 4 - (3*m_width) % 4; j++)
            {
                char c = 0;
                out.write(&c, 1);
            }
    }
}
void bmp::shorthand(int power,int where_x, int where_y,const std::vector<std::string>& word)
{
    if(where_x+word[0].size()<m_width && where_y+word.size()<m_height) {
        for(int i=where_y;i<where_y+word.size();i++)
            for(int j = where_x;j<where_x+word[0].size();j++)
            {
                if(word[word.size()-(i-where_y)-1][j-where_x]!='0') {
                    if(pixels[i][j].b>=pixels[i][j].g && pixels[i][j].b>=pixels[i][j].r)
                        pixels[i][j].b-=power;
                    else if(pixels[i][j].g>=pixels[i][j].r)
                        pixels[i][j].g-=power;
                    else
                        pixels[i][j].r-=power;
                }
            }
    }
}
void bmp::filter(char color,char up_or_down,int power)
{
    if(up_or_down == 'd')
        power *= -1;
    for (int i = 0; i < m_height; i++)
        for (int j = 0; j < m_width; j++)
        {
            if(pixels[i][j].b + power > 0 && color == 'b')
                pixels[i][j].b += power;
            if (pixels[i][j].g + power > 0 && color == 'g')
                pixels[i][j].g += power;
            if (pixels[i][j].r + power > 0 && color == 'r')
                pixels[i][j].r += power;
        }
}
void bmp::rotate(double angle)
{
    vec2d T({ {
                      {(double)(m_width / 2)},
                      {(double)(m_height / 2)}
              } });

    for(int i=0;i<m_height;i++)
        for (int j = 0; j < m_width; j++)
            m_coordinates[i][j] = m_coordinates[i][j] - T;

    mat22d R({ {
                       {cos(angle), sin(angle)},
                       {-sin(angle), cos(angle)}
               } });

    for (int i = 0; i < m_height; i++)
        for (int j = 0; j < m_width; j++)
        {
            m_coordinates[i][j] = R * m_coordinates[i][j];
        }

    // 3.
    int maxX = INT_MIN;
    int minX = INT_MAX;
    int maxY = INT_MIN;
    int minY = INT_MAX;
    for (int i = 0; i < m_height; i++)
        for (int j = 0; j < m_width; j++)
        {
            if (maxX < m_coordinates[i][j].get(0, 0))
                maxX = m_coordinates[i][j].get(0, 0);
            if (minX > m_coordinates[i][j].get(0, 0))
                minX = m_coordinates[i][j].get(0, 0);
            if (maxY < m_coordinates[i][j].get(1, 0))
                maxY = m_coordinates[i][j].get(1, 0);
            if (minY > m_coordinates[i][j].get(1, 0))
                minY = m_coordinates[i][j].get(1, 0);
        }

    //       -
    maxX++;
    minX--;
    maxY++;
    minY--;

    int width = maxX - minX;
    int height = maxY - minY;

    //
    vec2d shift({ {
                          {(double)(width/2)},
                          {(double)(height/2)}
                  } });

    for (int i = 0; i < m_height; i++)
        for (int j = 0; j < m_width; j++)
            m_coordinates[i][j] = m_coordinates[i][j] + shift;

    //
    std::vector<std::vector<pixel>> new_pixels;
    vec2d** new_coordinates = new vec2d * [height];
    for (int i = 0; i < height; i++)
        new_coordinates[i] = new vec2d[width];
    std::vector<pixel> v;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++)
            v.push_back({0, 0, 0});
        new_pixels.push_back(v);
        v.clear();}
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
        {
            new_coordinates[i][j].set(0, 0, j);
            new_coordinates[i][j].set(1, 0, i);
        }

    //
    for (int i = 0; i < m_height; i++) {
        for (int j = 0; j < m_width; j++) {
            int x = (int) (m_coordinates[i][j].get(0, 0));
            int y = (int) (m_coordinates[i][j].get(1, 0));
            new_pixels[y][x] = pixels[i][j];
        }
    }

    //

    for (int i = 0; i < m_height; i++)
        delete[] m_coordinates[i];
    delete[] m_coordinates;
    pixels = new_pixels;
    m_coordinates = new_coordinates;
    int b=0,g=0,r=0;
    m_width = width;
    m_height = height;
    m_info.Width = m_width;
    m_info.Height = m_height;
    for(int i=500;i<m_height;i++)
        for(int j=500;j<m_width;j++) {
            pixels[i][j].b = interpolation(i, j, b, pixels, 'b');
            pixels[i][j].g = interpolation(i, j, g, pixels, 'g');
            pixels[i][j].r = interpolation(i, j, r, pixels, 'r');
            b=0;g=0;r=0;}
}

int bmp::getHeight() const{return m_height;}
int bmp::getWidth() const{return m_width;}

int bmp::interpolation(int i,int j, int& s,const std::vector<std::vector<pixel>>& pixels,char color)
{
    if(i<0 || i>=m_height || j<0 || j>=m_width)
        return 0;
    if(pixels[i][j].b !=0 && pixels[i][j].r !=0 && pixels[i][j].g !=0)
    {
        s++;
        if(color=='b')
            return pixels[i][j].b;
        if(color=='g')
            return pixels[i][j].g;
        if(color=='r')
            return pixels[i][j].r;
    }
    else if(s>0 && pixels[i][j].b ==0 && pixels[i][j].r ==0 && pixels[i][j].g ==0)
    {return 0;}
    else if(s>0){ s++;
        if(color=='b')
            return pixels[i][j].b;
        if(color=='g')
            return pixels[i][j].g;
        if(color=='r')
            return pixels[i][j].r; }
    s++;
    int sum= interpolation(i-1,j-1,s,pixels,color);
    sum+= interpolation(i-1,j,s,pixels,color);
    sum+= interpolation(i-1,j+1,s,pixels,color);
    sum+= interpolation(i,j-1,s,pixels,color);
    sum+= interpolation(i,j+1,s,pixels,color);
    sum+= interpolation(i+1,j-1,s,pixels,color);
    sum+= interpolation(i+1,j,s,pixels,color);
    sum+= interpolation(i+1,j+1,s,pixels,color);
    return sum/s;
}
