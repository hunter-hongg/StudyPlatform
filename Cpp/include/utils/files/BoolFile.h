#ifndef boolfile_H
#define boolfile_H
#include <string>
#include <fstream>
#include <filesystem>

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
        if(!std::filesystem::exists(File)){
            ofstream tmp(File);
            tmp << Start << "isis" << End;
            return true;
        }
        return false;
    }
    bool CheckOk() {
        return (!std::filesystem::exists(File));
    }
private: 
    string File, Start, End; 
};

#endif
