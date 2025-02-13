/**
* @file chromosome.cpp
* @description dosyadan okunan elemanları bağlı liste oluşturarak onun içine atıyor
* @course 2 Öğretim B grubu
* @assignment 1. Ödev
* @date 22.11.2024
* @author Ferdi KAYNAR ferdi.kaynar@ogr.sakarya.edu.tr 
*/
#include <iostream>
#include <string>
#include "chromosome.hpp"

using namespace std;

Chromosome::Chromosome()
{
    head = nullptr;
    next = nullptr;
}

Chromosome::~Chromosome() 
{
    Gene* current = head;
    while (current) {
        Gene* toDelete = current;
        current = current->next;
        delete toDelete;
    }
}

void Chromosome::addGene(const std::string& sequence) 
{
    Gene* newGene = new Gene(sequence);
    if (!head) {
        head = newGene;
    } else {
        Gene* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newGene;
    }
}

int Chromosome::geneCount() const 
{
    int count = 0;
    Gene* current = head;
    while (current) {
        ++count;
        current = current->next;
    }
    return count;
}

Gene* Chromosome::getGeneAt(int index) const 
{
    Gene* current = head;
    int count = 0;
    while (current && count < index) {
        current = current->next;
        ++count;
    }
    return current;
}

void Chromosome::display() const 
{
    Gene* current = head;
    while (current) {
        std::cout << current->sequence << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void Chromosome::displaySpecial() const 
{
    if (!head) return;
    Gene* smallest = head;
    Gene* current = head->next;
    while (current) {
        if (current->sequence < head->sequence && current->sequence < smallest->sequence) {
            smallest = current;
        }
        current = current->next;
    }
    std::cout << (smallest ? smallest->sequence : head->sequence) << std::endl;
}