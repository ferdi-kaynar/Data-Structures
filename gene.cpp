/**
* @file gene.cpp
* @description bağlı listenin node'nı oluşturuyor
* @course 2 Öğretim B grubu
* @assignment 1. Ödev
* @date 22.11.2024
* @author Ferdi KAYNAR ferdi.kaynar@ogr.sakarya.edu.tr 
*/
#include <string>
#include "gene.hpp"

Gene::Gene(const std::string& seq = "")
{
    sequence = seq;
    next = nullptr;
}