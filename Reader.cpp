//
// Created by dvir on 14/12/2021.
//

#include "Reader.h"

using namespace std;

double **Reader::getMat(const char *s) {
    stringstream l;
    string line,line2nd;
    int size;
    int count=0;
    int count2nd=0;
    ifstream theFile (s);
    if (theFile.is_open())
    {
        getline (theFile,line);
        l<<line;
        l>>size;
        this->size=size;
        double** mat;
        mat= new double*[size];
        for (int i = 0; i < size; ++i) {
            mat[i] = new double[size];
        }
        while ( getline (theFile,line) ){
            stringstream d(line);
            stringstream c(line);
            while(!c.eof()){
                c>>line2nd;
                count2nd++;
            }
            if(count2nd!=size){
                cerr<<"ERROR: Invalid input.";
                return 0;
            }
            count2nd=0;
            for(int i=0;i<size;i++){
                d>>mat[i][count];
            }
            count++;
        }
        if(count!=size)
            cerr<<"invalid input.";
        theFile.close();
        return mat;
    }
    else cerr<<"ERROR: Invalid input."<<endl;
    return 0;
}

