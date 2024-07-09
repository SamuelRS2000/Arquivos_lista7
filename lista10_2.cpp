
/*
Lista10
Exercicio 2
Autor: Samuel Rodrigues dos Santos
Data: 01/07/2024
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Função para criar o arquivo texto.txt a partir de uma string fornecida
void createtextFile(const string& data) {
    ofstream outputFile("texto.txt");
    if (!outputFile.is_open()) {
        cerr << "Erro ao abrir o arquivo vetores.txt" << endl;
        exit(1);
    }
    outputFile << data;
    outputFile.close();
}

// Função para contar ocorrências de um caractere em uma string
int countCharInLine(const string& line, char character) {
    int count = 0;
    for (char c : line) {
        if (c == character) {
            count++;
        }
    }
    return count;
}

int main() {
    // String de exemplo que será usada para criar o arquivo texto.txt
    string data = "mochileiro tem uma mochila\no mochileiro viaja muito";

    // Cria o arquivo texto.txt a partir da string fornecida
    createtextFile(data);

    // Nome do arquivo de entrada
    string filename = "texto.txt";

    // Solicita ao usuário para informar o caractere a ser contado
    char character;
    cout << "Digite o caractere a ser contado: ";
    cin >> character;

    // Abre o arquivo de entrada
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Erro ao abrir o arquivo " << filename << endl;
        return 1;
    }

    string line;
    int lineNumber = 1;
    // Lê o arquivo linha por linha
    while (getline(inputFile, line)) {
        // Conta as ocorrências do caractere na linha atual
        int count = countCharInLine(line, character);
        // Exibe o número da linha e a contagem de ocorrências
        cout << "Linha " << lineNumber << ": " << count << " ocorrências de '" << character << "'" << endl;
        lineNumber++;
    }

    inputFile.close();

    return 0;
}

