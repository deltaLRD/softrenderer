#include "Picture.h"
#include "Windows.h"

int main(int argc, char* argv[])
{
    LRD::Picture pic(800, 600, "./pic_test.ppm");
    for(int i=300;i<500;i++)
    {
        for(int j=200;j<400;++j)
        {
            if(j%3==0)
            {
                pic.at(i,j)={255, 0, 0};

            }
            if(j%3==1)
            {
                pic.at(i,j)={0, 255, 0};

            }
            if(j%3==2)
            {
                pic.at(i,j)={0, 0, 255};

            }
        }
    }
    pic.writeToFile();
    return 0;
}