#ifndef boolfile_H
#define boolfile_H
#include <string>
#include <fstream>

using std::string;
using std::ifstream;
using std::ofstream;

class BoolFile {
public: 
    BoolFile(string file, string start, string end): 
        File(file), 
        Start(start),
        End(end){}
    bool IsOk() {
        ifstream tmp(File);
        if(!tmp.is_open()){
            ofstream tmp(File);
            tmp << Start << "isis" << End;
            return true;
        }
        return false;
    }
private: 
    string File, Start, End; 
};

#endif
