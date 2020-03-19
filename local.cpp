#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
/*----------------------------------------------------------------*/
using namespace std;
/*----------------------------------------------------------------*/
struct data
{
    string chat;
    string friends;
    string message;
};
/*----------------------------------------------------------------*/
class Local
{
private:
public:
    static string read(string file);
    static void write(string tmp, string file);
};
/*----------------------------------------------------------------*/
string Local::read(string file)
{
    string tmp;

    ifstream readFile(file);
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

void Local::write(string tmp, string file)
{
    int len = sizeof(tmp);

    ofstream writeFile(file);
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