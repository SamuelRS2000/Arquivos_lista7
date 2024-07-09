
/*
Lista10
Exercicio 1
Autor: Samuel Rodrigues dos Santos
Data: 01/07/2024
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Função para criar o arquivo vetores.txt a partir de uma string fornecida
void createVectorsFile(const string& data) {
    ofstream outputFile("vetores.txt");
    if (!outputFile.is_open()) {
        cerr << "Erro ao abrir o arquivo vetores.txt" << endl;
        exit(1);
    }
    outputFile << data;
    outputFile.close();
}

// Função para ler vetores do arquivo e retornar um vetor de vetores de inteiros
vector<vector<int>> readVectorsFromFile(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Erro ao abrir o arquivo " << filename << endl;
        exit(1);
    }

    vector<vector<int>> vectors; // Vetor de vetores de inteiros
    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        vector<int> vec; // Vetor para armazenar os inteiros de uma linha
        int number;
        while (ss >> number) {
            vec.push_back(number);
        }
        vectors.push_back(vec); // Adiciona o vetor lido ao vetor de vetores
    }
    inputFile.close();

    return vectors;
}

// Função para somar todos os vetores linha por linha
vector<int> sumVectors(const vector<vector<int>>& vectors) {
    vector<int> result;

    for (const auto& vec : vectors) {
        int sum = 0;
        for (int number : vec) {
            sum += number;
        }
        result.push_back(sum);
    }

    return result;
}

int main() {
    // String de exemplo que será usada para criar o arquivo vetores.txt
    string data = "1 2\n2 5 7\n2 2 2 2 2";

    // Cria o arquivo vetores.txt a partir da string fornecida
    createVectorsFile(data);

    // Lê os vetores do arquivo "vetores.txt"
    vector<vector<int>> vectors = readVectorsFromFile("vetores.txt");

    // Soma os vetores lidos linha por linha
    vector<int> result = sumVectors(vectors);

    // Abre o arquivo "soma.txt" para escrever o resultado
    ofstream outputFile("soma.txt");
    if (!outputFile.is_open()) {
        cerr << "Erro ao abrir o arquivo soma.txt" << endl;
        return 1;
    }

    // Escreve o resultado da soma no arquivo
    for (size_t i = 0; i < result.size(); ++i) {
        outputFile << result[i];
        if (i != result.size() - 1) {
            outputFile << "\n";
        }
    }
    outputFile << endl;
    outputFile.close();

    cout << "A soma dos vetores foi salva em soma.txt" << endl;

    return 0;
}
