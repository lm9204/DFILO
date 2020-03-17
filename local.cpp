#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
/*----------------------------------------------------------------*/
using namespace std;
/*----------------------------------------------------------------*/
struct data
{
};
/*----------------------------------------------------------------*/
class Local
{
private:
public:
    static string read();
    static void write(string tmp);
};
/*----------------------------------------------------------------*/
string Local::read()
{
    string tmp;

    ifstream readFile("name.txt");
    if (readFile.is_open())
    {
        while (!readFile.eof())
        {
            getline(readFile, tmp);
        }
    }
    readFile.close();

    return tmp;
}

void Local::write(string tmp)
{
    int len = sizeof(tmp);

    ofstream writeFile("name.txt");
    for (int i = 0; i < len; ++i)
    {
        if (i != len - 1)
        {
            tmp += "\n";
        }
        writeFile.write(tmp.c_str(), tmp.size());
    }
    writeFile.close();
}
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/