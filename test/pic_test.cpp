#include "Picture.h"

int main(int argc, char* argv[])
{
    LRD::Picture pic(800, 600, "./pic_test.ppm");
    for(int i=300;i<500;i++)
    {
        for(int j=200;j<400;++j)
        {
            pic.at(i,j)={255, 255, 255};
        }
    }
    pic.writeToFile();
    return 0;
}