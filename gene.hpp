/**
* @file gene.hpp
* @description bağlı listeye nnode oluşturuyor
* @course 2 Öğretim B grubu
* @assignment 1. Ödev
* @date 22.11.2024
* @author Ferdi KAYNAR ferdi.kaynar@ogr.sakarya.edu.tr 
*/
using namespace std;
class Gene {
    public:
        string sequence;
        Gene* next;

        Gene(const string& seq);
};