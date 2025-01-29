/**
* @file main.cpp
* @description okunacak dosyalar tanımlanıyor ve menü ekrana bastırılıyor.
* @course 2 Öğretim B grubu
* @assignment 1. Ödev
* @date 22.11.2024
* @author Ferdi KAYNAR ferdi.kaynar@ogr.sakarya.edu.tr 
*/
#include <iostream>
#include "dna.hpp"

using namespace std;

int main() {
    DNA dna;
    dna.loadFromFile("txt/dna.txt");

    int user_input;
    do {
        std::cout << "1- Caprazlama" << endl;
        std::cout << "2- Mutasyon" << endl;
        std::cout << "3- Otomatik Islemler" << endl;
        std::cout << "4- Ekrana Yaz" << endl;
        std::cout << "5- Cikis" << endl;
        std::cout << "Seciminizi Giriniz: ";
        std::cin >> user_input;

        if (user_input == 1) {
            int index1, index2;
            std::cout << "Caprazlama icin iki kromozom indeksi girin: ";
            std::cin >> index1 >> index2;
            dna.crossover(index1, index2);
        } else if (user_input == 2) {
            int chromIndex, geneIndex;
            std::cout << "Mutasyon icin kromozom indeksi ve gen indeksi girin: ";
            std::cin >> chromIndex >> geneIndex;
            dna.mutate(chromIndex, geneIndex);
        } else if (user_input == 3) {
            dna.performAutomaticOperations("txt/operations.txt");
        } else if (user_input == 4) {
            dna.displaySpecial();
        }

    } while (user_input != 5);

    return 0;
}