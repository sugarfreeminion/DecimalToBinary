/*************************************************************************
 * Author:          sugarfreeoh
 * Date:            14 March 2016
 * Description:     You are given a decimal number, print its binary
 *************************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void DecToBin(unsigned int dec, string bin);

int main(int argc, char *argv[])
{
    ifstream inputFile;

    inputFile.open(argv[1]);

    if(inputFile.is_open())
    {
        string line;
        string temp;

        stringstream ss;

        unsigned int decimal;

        while(getline(inputFile,line))
        {
            ss << line;
            ss >> decimal;

            //cout << "Decimal Value: " << decimal << endl;

            //cout << "Binary Value: ";
            DecToBin(decimal,temp);

            ss.str("");
            ss.clear();
        }
    }

    return 0;
}

void DecToBin(unsigned int dec, string bin)
{
    stringstream ss;

    if(dec == 0)
    {
        bin = "0";
    }
    else
    {
        while((dec/2) >= 1)
        {
            ss << dec%2;

            bin = ss.str() + bin;

            //cout << dec%2;

            dec = dec/2;

            ss.str("");
            ss.clear();
        }
        
        ss << dec%2;
        bin = ss.str() + bin;
        //cout << dec%2;
    }

    cout << bin << endl;
}
