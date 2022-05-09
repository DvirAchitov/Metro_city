#include <iostream>
#include "Metropolis.h"
#include "Reader.h"

using namespace std;
void run(char* o , char* t){
    Reader file;
    double** mat;
    int runs;
    int counter=1;

    mat=file.getMat(o);
    Metropolis city(mat,file.getSize());
    ifstream myFile(t);
    string line;
    if (myFile.is_open())
    {
        while(getline(myFile, line))
        {
            city.setCars(line, counter);
            counter+=1;
        }
    }
    else
    {
        cerr<<"ERROR: Invalid input."<<endl;
        return;
    }
    myFile.close();
    cin>>runs;
    city.Move(runs,0);
    city.printToxicity(file.getSize());
    city.printCars(file.getSize());
}
int main(int argc, char* argv[]) {
    char* one = argv[1];
    char* two = argv[2];
    run(one,two);
    return 0;
}
