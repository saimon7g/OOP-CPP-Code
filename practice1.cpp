#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

namespace infrastructure
{
class pool
{
    int height;
    int width;
    int depth;
    char painted_color[10];

public:
    void set_properties(int h, int w, int d, char *pc)
    {
        height=h;
        width=w;
        depth=d;
        strcpy( painted_color,pc );
    }
    void show()
    {
        cout<<height<<"x"<<width<<"x"<<depth<<endl;
        cout<<painted_color<<endl;
    }
};

}

namespace sports
{
class pool
{
    char table_ingredient[20];
    char table_color[10];

public:
    void set_properties(char *ti, char* tc)
    {
        strcpy(table_ingredient,ti);
        strcpy(table_color,tc);

    }
    void show()
    {
        cout<<table_ingredient<<endl;
        cout<<table_color<<endl;
    }
};

}


int main()
{
    {
        using namespace infrastructure;
        pool p1;
        p1.set_properties(3,4,5,"red");
        p1.show();
    }
{
        using namespace sports;
        pool p1;
        p1.set_properties("wood","yellow");
        p1.show();
    }
    return 0;
}
