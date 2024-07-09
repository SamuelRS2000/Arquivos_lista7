
/*
Lista10
Exercicio 3
Autor: Samuel Rodrigues dos Santos
Data: 01/07/2024
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

// Função para criar o arquivo altura.txt a partir de uma string fornecida
void cria_altura(const string& data) {
    ofstream outputFile("altura.txt");
    if (!outputFile.is_open()) {
        cerr << "Erro ao abrir o arquivo altura.txt" << endl;
        exit(1);
    }
    outputFile << data;
    outputFile.close();
}

// Função para criar o arquivo peso.txt a partir de uma string fornecida
void cria_peso(const string& data) {
    ofstream outputFile("peso.txt");
    if (!outputFile.is_open()) {
        cerr << "Erro ao abrir o arquivo peso.txt" << endl;
        exit(1);
    }
    outputFile << data;
    outputFile.close();
}

// Função para ler medidas de um arquivo e armazenar em um map
unordered_map<string, double> readMeasurementsFromFile(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Erro ao abrir o arquivo " << filename << endl;
        exit(1);
    }

    unordered_map<string, double> measurements;
    string line;
    string code;
    double value;

    while (getline(inputFile, line)) {
        code = line;
        if (getline(inputFile, line)) {
            value = stod(line);
            measurements[code] = value;
        }
    }
    inputFile.close();

    return measurements;
}

int main() {
    // Dados de exemplo para criar arquivos de teste
    string data_altura = "P1\n1.75\nP2\n1.80\nP3\n1.65";
    string data_peso = "P1\n70.5\nP2\n80.2\nP3\n65.0";

    // Cria os arquivos de teste altura.txt e peso.txt
    cria_altura(data_altura);
    cria_peso(data_peso);

    // Lê as medidas de altura e peso dos arquivos
    unordered_map<string, double> alturas = readMeasurementsFromFile("altura.txt");
    unordered_map<string, double> pesos = readMeasurementsFromFile("peso.txt");

    // Identifica a pessoa com a maior altura
    string maior_altura_pessoa;
    double maior_altura = 0.0;
    for (const auto& entry : alturas) {
        if (entry.second > maior_altura) {
            maior_altura = entry.second;
            maior_altura_pessoa = entry.first;
        }
    }

    // Identifica a pessoa com o maior peso
    string maior_peso_pessoa;
    double maior_peso = 0.0;
    for (const auto& entry : pesos) {
        if (entry.second > maior_peso) {
            maior_peso = entry.second;
            maior_peso_pessoa = entry.first;
        }
    }

    // Exibe os resultados
    cout << "Pessoa com maior altura: " << maior_altura_pessoa << " (" << maior_altura << " metros)" << endl;
    cout << "Pessoa com maior peso: " << maior_peso_pessoa << " (" << maior_peso << " kg)" << endl;

    return 0;
}
