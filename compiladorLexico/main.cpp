#include <iostream>
#include <cctype>
#include <vector>
using namespace std;

string cadena;
char caracter;
int nodo = 1;
int indice = -1; //Indice de cadena
bool FDC = false;
bool real = false;
char abc[] =
{
    'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
    'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
};
char ss[] =
{
    '!','@','#','$','%','^','*','(',')','[',']','{','}',',','?','_','.',':',';'
};
string palabrasReservadas[] =
{
    "if","while","do","char","string","int","bool","switch", "for","return","false","true","cout","cin"
};
vector<int> nodosInaceptable = {1,8,13};
vector<int> nodosEnterosReal = {4,6,7,27};
vector<int> nodosVariables = {2,3};
vector<int> nodosSignoSimple = {17,25,15,20,18,5,9,23};
vector<int> nodosSignoCompuesto = {26,16,14,12,22,21,10,11,24};
vector<int> nodosComentario = {19};
bool buscarLetra() { //busca si el caracter apuntado por el indice es una palabra permitida
    try {
        for (char c : abc) {
            if (cadena.at(indice) == c) {
                return  true;
            }
        }
        return false;
    }catch (const out_of_range& e) {
        FDC = true;
    }
}

bool buscarSignoSimple() {
    try {
        for (char c : ss) {
            if (c == cadena.at(indice)) {
                return true;
            }
        }
        return false;
    }catch (const out_of_range& e) {
        FDC = true;
    }
}

bool buscarPalabraReservada() {
    for (string cad : palabrasReservadas) {
        if (cad == cadena) {
            return true;
        }
    }
    return false;
}

bool buscarEnArreglo(vector<int> arr) {
    for (int num : arr) {
        if (num == nodo) {
            return true;
        }
    }
    return false;
}

int main() {
    while (true) {
        cout << "Inserte cadena: ";
        cin >> cadena;

        do {
            indice++;
            try {
                caracter = cadena.at(indice);
                switch (nodo) {
                    case 1:                         //Variables o palabras Reservadas
                        if (buscarLetra()) {
                            nodo = 2;
                        }else if (isdigit((caracter))) {
                            nodo = 4;
                        }else if (caracter == '+') {
                            nodo = 5;
                        }else if (caracter == '&') {
                            nodo = 8;
                        }else if (caracter == '-') {
                            nodo = 9;
                        }else if (caracter== '|') {
                            nodo =  13;
                        }else if (caracter == '/') {
                            nodo = 15;
                        }else if (buscarSignoSimple()) {
                            nodo = 17;
                        }else if (caracter == '"') {
                            nodo = 18;
                        }else if (caracter == '<') {
                            nodo = 20;
                        }else if (caracter == '>') {
                            nodo = 23;
                        }else if (caracter == '=') {
                            nodo = 25;
                        }else {
                        //error
                        }
                        break;
                    case 2:
                        if (isdigit(caracter)) {
                            nodo = 3;
                        }else if (caracter != '_' && !buscarLetra()) {
                            //Error
                        }
                        break;
                    case 3:
                        if (!isdigit(caracter)) {
                            //Error
                        }
                        break;
                    case 4:
                        if (caracter == '.') {//reales
                            real = true;
                            nodo = 6;
                        }else if (caracter == 'e' || caracter == 'E') {//exponente x10^n
                            nodo = 7;
                        }
                        else if (!isdigit(caracter)) { //numeros
                            //error
                        }
                        break;
                    case 5:
                        if (isdigit(caracter)) {
                            nodo = 4;
                        }else if (caracter == '+') {
                            nodo = 10;
                        }else {
                            //error
                        }
                    case 6:
                        if (caracter == 'e' || caracter == 'E') {
                            nodo = 7;
                        }else if (!isdigit(caracter)) {
                            //Error
                        }
                        break;
                    case 7:
                        if (caracter == '+' || caracter == '-') {
                            nodo = 27;
                        }else if (!isdigit(caracter)) {
                            //error
                        }
                        break;
                    case 8:
                        if (caracter == '&') {
                            nodo = 12;
                        }else {
                            //error
                        }
                        break;
                    case 9:
                        if (caracter == '-') {
                            nodo = 11;
                        }else if (isdigit(caracter)) {
                            nodo = 4;
                        }else {
                            //error
                        }
                        break;
                    case 13:
                        if (caracter== '|') {
                            nodo =  14;
                        }else {
                            //error
                        }
                        break;
                    case 15:
                        if (caracter == '/') {
                            nodo = 16;
                        }else {
                            //error
                        }
                        break;
                    case 18:
                        if (caracter == '"') {
                            nodo = 19;
                        }else {
                            //error
                        }
                        break;
                    case 20:
                        if (caracter == '=') {
                            nodo = 21;
                        }else if (caracter == '>') {
                            nodo = 22;
                        }else {
                            //error
                        }
                        break;
                    case 23:
                        if (caracter == '=') {
                            nodo = 24;
                        }else {
                            //error
                        }
                        break;
                    case 25:
                        if (caracter == '=') {
                            nodo = 26;
                        }else {
                            //error
                        }
                        break;
                    case 27:
                        if (!isdigit(caracter)) {
                            //error
                        }
                        break;
                }
            }catch (const out_of_range& e) {
                FDC = true;
                cout << "\nFin de cadena en el nodo ";
            }
        }while (FDC == false);
        //El nodo final es el que nos dira que tipo de cadena fue ingresada
        cout << nodo << endl;
        if (buscarEnArreglo(nodosInaceptable)) {
            //error
        }else if (buscarEnArreglo(nodosSignoCompuesto)) {
            cout << "Es un signo compuesto" << endl;
        }else if (buscarEnArreglo(nodosSignoSimple)) {
            cout << "Es un signo simple" << endl;
        }else if (buscarEnArreglo(nodosVariables)) {
            if (buscarPalabraReservada()) {
                cout << "Es un palabra reservada" << endl;
            }else {
                cout << "Es una variable" << endl;
            }
        }else if (buscarEnArreglo(nodosEnterosReal)) {
            if (real) {
                cout << "Es un número real" << endl;
            }else {
                cout << "Es un número entero" << endl;
            }
        }else if (buscarEnArreglo(nodosComentario)) {
            cout << "Es un comentario" << endl;
        }
            cout << endl;
            real = false;
            FDC = false;
            indice = -1;
            nodo = 1;
    }
}