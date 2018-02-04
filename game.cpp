#include <string>
using namespace std;
class Game{ 
    int x,y;
    std::string  name; 
    public:
    Game(){}; 
    void setSize(int x, int y)
    {
        this->x = x;
        this->y = y;
    };
    void printSize()
    {
        printf("%i x %i",this->x,this->y);
    };
    void process(){};
};
