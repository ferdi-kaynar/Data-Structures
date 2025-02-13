/**
* @file dna.cpp
* @description dosya okunarak çaprazlama,mutasyon,otomatik işlemler ve ekrana yaz işlemleri burada gerçekleşiyor.
* @course 2 Öğretim B grubu
* @assignment 1. Ödev
* @date 22.11.2024
* @author Ferdi KAYNAR ferdi.kaynar@ogr.sakarya.edu.tr 
*/
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "dna.hpp"

using namespace std;

DNA::DNA()
{
    head = nullptr;
}

DNA::~DNA()
{
    Chromosome* current = head;
    while (current) {
        Chromosome* toDelete = current;
        current = current->next;
        delete toDelete;
    }
}

void DNA::addChromosome(Chromosome* chromosome)
{
    if (!head) {
        head = chromosome;
    } else {
        Chromosome* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = chromosome;
    }
}

Chromosome* DNA::getChromosomeAt(int index) const 
{
    Chromosome* current = head;
    int count = 0;
    while (current && count < index) {
        current = current->next;
        ++count;
    }
    return current;
}

void DNA::display() const 
{
    Chromosome* current = head;
    int index = 0;
    while (current) {
        std::cout << "Chromosome " << index++ << ": ";
        current->display();
        current = current->next;
    }
}

void DNA::displaySpecial() const 
{
    Chromosome* current = head;
    while (current) {
        current->displaySpecial();
        current = current->next;
    }
}

void DNA::loadFromFile(const std::string& filename) 
{
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "[x] Hata!!! Dosya Acilmadi: " << filename << std::endl;
        cout << "[i] Cikis.." << endl;
        exit(1);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string geneSequence;
        Chromosome* chromosome = new Chromosome();
        while (iss >> geneSequence) {
            chromosome->addGene(geneSequence);
        }
        addChromosome(chromosome);
    }
}

void DNA::crossover(int index1, int index2) 
{
    Chromosome* chrom1 = getChromosomeAt(index1);
    Chromosome* chrom2 = getChromosomeAt(index2);

    if (!chrom1 || !chrom2) {
        std::cerr << " Caprazlama için geçersiz kromozom indeksleri" << std::endl;
        return;
    }

    int count1 = chrom1->geneCount();
    int count2 = chrom2->geneCount();

    int mid1 = count1 / 2;
    int mid2 = count2 / 2;

    Chromosome* newChrom1 = new Chromosome();
    Chromosome* newChrom2 = new Chromosome();

    for (int i = 0; i < mid1; ++i) {
        newChrom1->addGene(chrom1->getGeneAt(i)->sequence);
    }
    for (int i = mid2; i < count2; ++i) {
        newChrom1->addGene(chrom2->getGeneAt(i)->sequence);
    }

    for (int i = mid1; i < count1; ++i) {
        newChrom2->addGene(chrom1->getGeneAt(i)->sequence);
    }
    for (int i = 0; i < mid2; ++i) {
        newChrom2->addGene(chrom2->getGeneAt(i)->sequence);
    }

    addChromosome(newChrom1);
    addChromosome(newChrom2);
}

void DNA::mutate(int chromIndex, int geneIndex) {
    Chromosome* chrom = getChromosomeAt(chromIndex);
    if (!chrom) {
        std::cerr << "[x] Mutasyon icin gecersiz kromozom indeksi." << std::endl;
        return;
    }

    Gene* gene = chrom->getGeneAt(geneIndex);
    if (!gene) {
        std::cerr << "[x] Mutasyon icin gecersiz gen indeksi" << std::endl;
        return;
    }

    gene->sequence = "X";
}

void DNA::performAutomaticOperations(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Dosya acilirken hata olustu: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        char operation;
        int index1, index2;

        iss >> operation >> index1 >> index2;

        if (operation == 'C') {
            crossover(index1, index2);
        } else if (operation == 'M') {
            mutate(index1, index2);
        }
    }

    std::cout << "Islem tamamlandi " << std::endl;
}