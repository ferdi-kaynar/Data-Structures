/**
* @file dna.hpp
* @description dosya okunarak çaprazlama,mutasyon,otomatik işlemler ve ekrana yaz işlemleri burada gerçekleşiyor.
* @course 2 Öğretim B grubu
* @assignment 1. Ödev
* @date 22.11.2024
* @author Ferdi KAYNAR ferdi.kaynar@ogr.sakarya.edu.tr 
*/
#include "chromosome.hpp"

class DNA {
    public:
        Chromosome* head;

        DNA();

        ~DNA();

        void addChromosome(Chromosome* chromosome);

        Chromosome* getChromosomeAt(int index) const;

        void display() const;

        void displaySpecial() const;

        void loadFromFile(const std::string& filename);

        void crossover(int index1, int index2);

        void mutate(int chromIndex, int geneIndex);

        void performAutomaticOperations(const std::string& filename);
};