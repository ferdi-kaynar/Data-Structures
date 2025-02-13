/**
* @file chromosome.hpp
* @description dosyadan okunan elemanları bağlı liste oluşturarak onun içine atıyor
* @course 2 Öğretim B grubu
* @assignment 1. Ödev
* @date 22.11.2024
* @author Ferdi KAYNAR ferdi.kaynar@ogr.sakarya.edu.tr 
*/
#include "gene.hpp"

class Chromosome {
    public:
        Gene* head;
        Chromosome* next;

        Chromosome();

        ~Chromosome();

        void addGene(const std::string& sequence);

        int geneCount() const;

        Gene* getGeneAt(int index) const;

        void display() const;

        void displaySpecial() const;
};