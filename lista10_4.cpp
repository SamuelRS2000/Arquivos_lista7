
/*
Lista10
Exercicio 4
Autor: Samuel Rodrigues dos Santos
Data: 01/07/2024
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Função para cadastrar um aluno
void cadastrarAluno() {
    string nome, matricula;
    cout << "Digite o nome do aluno: ";
    cin >> nome;
    cout << "Digite a matricula do aluno: ";
    cin >> matricula;

    ofstream outputFile(nome + ".txt");
    if (!outputFile.is_open()) {
        cerr << "Erro ao criar o arquivo do aluno " << nome << endl;
        return;
    }
    outputFile << matricula << endl;
    outputFile.close();
    cout << "Aluno " << nome << " cadastrado com sucesso!" << endl;
}

// Função para adicionar uma nota a um aluno
void adicionarNota() {
    string nome, nota;
    cout << "Digite o nome do aluno: ";
    cin >> nome;

    ifstream inputFile(nome + ".txt");
    if (!inputFile.is_open()) {
        cerr << "Aluno não cadastrado." << endl;
        return;
    }
    inputFile.close();

    cout << "Digite a nota do aluno: ";
    cin >> nota;

    ofstream outputFile(nome + ".txt", ios::app);
    if (!outputFile.is_open()) {
        cerr << "Erro ao abrir o arquivo do aluno " << nome << endl;
        return;
    }
    outputFile << nota << endl;
    outputFile.close();
    cout << "Nota adicionada ao aluno " << nome << " com sucesso!" << endl;
}

// Função para calcular a média das notas de um aluno
void calcularMedia() {
    string nome;
    cout << "Digite o nome do aluno: ";
    cin >> nome;

    ifstream inputFile(nome + ".txt");
    if (!inputFile.is_open()) {
        cerr << "Aluno não cadastrado." << endl;
        return;
    }

    string line;
    vector<double> notas;
    // Ignora a primeira linha (matricula)
    getline(inputFile, line);
    while (getline(inputFile, line)) {
        double nota;
        istringstream iss(line);
        if (iss >> nota) {
            notas.push_back(nota);
        }
    }
    inputFile.close();

    if (notas.empty()) {
        cout << "Nenhuma nota encontrada para o aluno " << nome << "." << endl;
        return;
    }

    double soma = 0;
    for (double nota : notas) {
        soma += nota;
    }
    double media = soma / notas.size();
    cout << "A média das notas do aluno " << nome << " é " << media << endl;
}

int main() {
    int opcao;

    do {
        cout << "Menu:" << endl;
        cout << "1. Cadastrar aluno" << endl;
        cout << "2. Adicionar nota de um aluno" << endl;
        cout << "3. Calcular média de um aluno" << endl;
        cout << "4. Fechar o programa" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cadastrarAluno();
                break;
            case 2:
                adicionarNota();
                break;
            case 3:
                calcularMedia();
                break;
            case 4:
                cout << "Programa encerrado." << endl;
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }
    } while (opcao != 4);

    return 0;
}
