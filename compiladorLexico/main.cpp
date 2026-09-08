#include <iostream>
#include <cctype>
#include <vector>
#include  <string>

using namespace std;

string cadena;
char caracter;
int nodo = 1;
int indice = -1;
bool FDC = false;
bool real = false;
bool error = false;
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
vector<int> nodosInvalidos = {7,8,13};
vector<int> nodosEnterosReal = {4,6,27};
vector<int> nodosVariables = {2,3};
vector<int> nodosSignoSimple = {17,25,15,20,18,5,9,23};
vector<int> nodosSignoCompuesto = {26,16,14,12,22,21,10,11,24};
vector<int> nodosComentario = {19};

void mostrarError(int codigoError) {
    error = true;
    cout << endl;
    switch(codigoError) {
        case 1001: cout << "Error 1001: Caracter invalido"; break;
        case 1002: cout << "Error 1002: Cadena vacia"; break;
        case 1003: cout << "Error 1003: Se esperaba un Numero"; break;
        case 1004: cout << "Error 1004: Se esperaba una letra, numero o '_'"; break;
        case 1005: cout << "Error 1005: Se esperaba un numero, '.' o exponencial"; break;
        case 1006: cout << "Error 1006: Se esperaba un numero o '+'"; break;
        case 1007: cout << "Error 1007: Se esperaba un exponencial o un numero"; break;
        case 1008: cout << "Error 1008: Se esperaba un numero, '+', o '-'"; break;
        case 1009: cout << "Error 1009: Se esperaba '&'"; break;
        case 1010: cout << "Error 1010: Simbolo invalido por si solo."; break;
        case 1011: cout << "Error 1011: Se esperaba '-' o un numero"; break;
        case 1012: cout << "Error 1012: Se esperaba FDC para el simbolo '++'"; break;
        case 1013: cout << "Error 1013: Se esperaba FDC para el simbolo '- -'"; break;
        case 1014: cout << "Error 1014: Se esperaba FDC para el simbolo '&&'"; break;
        case 1015: cout << "Error 1015: Se esperaba '|'"; break;
        case 1016: cout << "Error 1016: Simbolo '|' invalido por si solo."; break;
        case 1017: cout << "Error 1017: Se esperaba FDC para el simbolo '||'"; break;
        case 1018: cout << "Error 1018: Se esperaba '/'"; break;
        case 1019: cout << "Error 1019: Se esperaba FDC para el simbolo '//'"; break;
        case 1020: cout << "Error 1020: Caracter invalido despues de simbolo simple"; break;
        case 1021: cout << "Error 1021: Se esperaba FDC para obtener una cadena"; break;
        case 1022: cout << "Error 1022: Se esperaba '>' o '='"; break;
        case 1023: cout << "Error 1023: Se esperaba FDC para el simbolo '<='"; break;
        case 1024: cout << "Error 1024: Se esperaba FDC para el simbolo '<>'"; break;
        case 1025: cout << "Error 1025: Se esperaba '='"; break;
        case 1026: cout << "Error 1026: Se esperaba FDC para el simbolo '>='"; break;
        case 1027: cout << "Error 1027: Se esperaba FDC para el simbolo '=='"; break;
        case 1028: cout << "Error 1028: Se esperaba FDC o un numero para obtener un numero cientifico"; break;
        case 1029: cout << "Error 1029: Se esperaba un Numero"; break;
        case 1030: cout << "Error 1030: Se esperaba un numero, '.' o exponencial"; break;
        case 1031: cout << "Error 1031: Se esperaba un numero o '+'"; break;
        case 1032: cout << "Error 1032: Se esperaba un exponencial o un numero"; break;
        case 1033: cout << "Error 1033: Se esperaba un numero, '+', o '-'"; break;
        case 1034: cout << "Error 1034: Se esperaba '&'"; break;
        case 1035: cout << "Error 1035: Se esperaba '&'"; break;
        case 1036: cout << "Error 1036: Se esperaba '-' o un numero"; break;
        case 1037: cout << "Error 1037: Se esperaba FDC para el simbolo '++', pero se obtuvo un numero"; break;
        case 1038: cout << "Error 1038: Se esperaba FDC para el simbolo '++', pero se obtuvo un simbolo simple"; break;
        case 1039: cout << "Error 1039: Se esperaba FDC para el simbolo '- -', pero se obtuvo un numero"; break;
        case 1040: cout << "Error 1040: Se esperaba FDC para el simbolo '- -', pero se obtuvo un simbolo simple"; break;
        case 1041: cout << "Error 1041: Se esperaba FDC para el simbolo '&&', pero se obtuvo un numero"; break;
        case 1042: cout << "Error 1042: Se esperaba FDC para el simbolo '&&', pero se obtuvo un simbolo simple"; break;
        case 1043: cout << "Error 1043: Se esperaba '|', pero se obtuvo un numero"; break;
        case 1044: cout << "Error 1044: Se esperaba '|', pero se obtuvo un simbolo simple"; break;
        case 1045: cout << "Error 1045: Se esperaba FDC para el simbolo '||', pero se obtuvo un numero"; break;
        case 1046: cout << "Error 1046: Se esperaba FDC para el simbolo '||', pero se obtuvo un simbolo simple"; break;
        case 1047: cout << "Error 1047: Se esperaba '/', pero se obtuvo un numero"; break;
        case 1048: cout << "Error 1048: Se esperaba '/', pero se obtuvo un simbolo simple"; break;
        case 1049: cout << "Error 1049: Se esperaba FDC para el simbolo '//', pero se obtuvo un numero"; break;
        case 1050: cout << "Error 1050: Se esperaba FDC para el simbolo '//', pero se obtuvo un simbolo simple"; break;
        case 1051: cout << "Error 1051: Caracter invalido despues de simbolo simple, pero se obtuvo un numero"; break;
        case 1052: cout << "Error 1052: Caracter invalido despues de simbolo simple, pero se obtuvo un simbolo simple"; break;
        case 1053: cout << "Error 1053: Se esperaba FDC para obtener una cadena, pero se obtuvo un numero"; break;
        case 1054: cout << "Error 1054: Se esperaba FDC para obtener una cadena, pero se obtuvo un simbolo simple"; break;
        case 1055: cout << "Error 1055: Se esperaba '>' o '=', pero se obtuvo un numero"; break;
        case 1056: cout << "Error 1056: Se esperaba '>' o '=', pero se obtuvo un simbolo simple"; break;
        case 1057: cout << "Error 1057: Se esperaba FDC para el simbolo '<=', pero se obtuvo un numero"; break;
        case 1058: cout << "Error 1058: Se esperaba FDC para el simbolo '<=', pero se obtuvo un simbolo simple"; break;
        case 1059: cout << "Error 1059: Se esperaba FDC para el simbolo '<>', pero se obtuvo un numero"; break;
        case 1060: cout << "Error 1060: Se esperaba FDC para el simbolo '<>', pero se obtuvo un simbolo simple"; break;
        case 1061: cout << "Error 1061: Se esperaba '=', pero se obtuvo un numero"; break;
        case 1062: cout << "Error 1062: Se esperaba '=', pero se obtuvo un simbolo simple"; break;
        case 1063: cout << "Error 1063: Se esperaba FDC para el simbolo '>=', pero se obtuvo un numero"; break;
        case 1064: cout << "Error 1064: Se esperaba FDC para el simbolo '>=', pero se obtuvo un simbolo simple"; break;
        case 1065: cout << "Error 1065: Se esperaba FDC para el simbolo '==', pero se obtuvo un numero"; break;
        case 1066: cout << "Error 1066: Se esperaba FDC para el simbolo '==', pero se obtuvo un simbolo simple"; break;
        case 1067: cout << "Error 1067: Se esperaba FDC o un numero para obtener un numero cientifico, pero se obtuvo un simbolo simple"; break;
        default: cout << "Error desconocido: " << codigoError; break;
    }
    cout << ". En el caracter: "<< indice + 1 << endl;
}

bool buscarLetra() {
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
        getline(cin,cadena);

        if (cadena.empty()) {
            mostrarError(1002);
            continue;
        }
        do {
            indice++;
            try {
                caracter = cadena.at(indice);
                switch (nodo) {
                    case 1:
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
                            mostrarError(1001);
                            FDC = true;
                        }
                        break;
                    case 2:
                        if (isdigit(caracter)) {
                            nodo = 3;
                        }else if (caracter != '_' && !buscarLetra()) {
                            mostrarError(1004);
                            FDC = true;
                        }
                        break;
                    case 3:
                        if (!isdigit(caracter)) {
                            mostrarError(1003);
                            FDC = true;
                        }
                        break;
                    case 4:
                        if (caracter == '.') {
                            real = true;
                            nodo = 6;
                        }else if (caracter == 'e' || caracter == 'E') {
                            nodo = 7;
                        }
                        else if (!isdigit(caracter)) {
                            mostrarError(1005);
                            FDC = true;
                        }
                        break;
                    case 5:
                        if (isdigit(caracter)) {
                            nodo = 4;
                        }else if (caracter == '+') {
                            nodo = 10;
                        }else {
                            mostrarError(1006);
                            FDC = true;
                        }
                        break;
                    case 6:
                        if (caracter == 'e' || caracter == 'E') {
                            nodo = 7;
                        }else if (!isdigit(caracter)) {
                            mostrarError(1007);
                            FDC = true;
                        }
                        break;
                    case 7:
                        if (caracter == '+' || caracter == '-' || isdigit(caracter)) {
                            nodo = 27;
                        }else {
                            mostrarError(1008);
                            FDC = true;
                        }
                        break;
                    case 8:
                        if (caracter == '&') {
                            nodo = 12;
                        }else {
                            mostrarError(1009);
                            FDC = true;
                        }
                        break;
                    case 9:
                        if (caracter == '-') {
                            nodo = 11;
                        }else if (isdigit(caracter)) {
                            nodo = 4;
                        }else {
                            mostrarError(1011);
                            FDC = true;
                        }
                        break;
                    case 10:
                        if (buscarLetra()) {
                            mostrarError(1012);
                        } else {
                            mostrarError(1001);
                        }
                        FDC = true;
                        break;
                    case 11:
                        if (buscarLetra()) {
                            mostrarError(1013);
                        } else {
                            mostrarError(1001);
                        }
                        FDC = true;
                        break;
                    case 12:
                        if (buscarLetra()) {
                            mostrarError(1014);
                        } else {
                            mostrarError(1001);
                        }
                        FDC = true;
                        break;
                    case 13:
                        if (caracter== '|') {
                            nodo =  14;
                        }else {
                            mostrarError(1015);
                            FDC = true;
                        }
                        break;
                    case 14:
                        if (buscarLetra()) {
                            mostrarError(1017);
                        } else {
                            mostrarError(1001);
                        }
                        FDC = true;
                        break;
                    case 15:
                        if (caracter == '/') {
                            nodo = 16;
                        }else {
                            mostrarError(1018);
                            FDC = true;
                        }
                        break;
                    case 16:
                        if (buscarLetra()) {
                            mostrarError(1019);
                        } else {
                            mostrarError(1001);
                        }
                        FDC = true;
                        break;
                    case 17:
                        if (buscarLetra()) {
                            mostrarError(1020);
                        } else {
                            mostrarError(1001);
                        }
                        FDC = true;
                        break;
                    case 18:
                        if (caracter == '"') {
                            nodo = 19;
                        }
                        break;
                    case 19:
                        if (buscarLetra()) {
                            mostrarError(1021);
                        } else {
                            mostrarError(1001);
                        }
                        FDC = true;
                        break;
                    case 20:
                        if (caracter == '=') {
                            nodo = 21;
                        }else if (caracter == '>') {
                            nodo = 22;
                        }else {
                            mostrarError(1022);
                            FDC = true;
                        }
                        break;
                    case 21:
                        if (buscarLetra()) {
                            mostrarError(1023);
                        } else {
                            mostrarError(1001);
                        }
                        FDC = true;
                        break;
                    case 22:
                        if (buscarLetra()) {
                            mostrarError(1024);
                        } else {
                            mostrarError(1001);
                        }
                        FDC = true;
                        break;
                    case 23:
                        if (caracter == '=') {
                            nodo = 24;
                        }else {
                            mostrarError(1025);
                            FDC = true;
                        }
                        break;
                    case 24:
                        if (buscarLetra()) {
                            mostrarError(1026);
                        } else {
                            mostrarError(1001);
                        }
                        FDC = true;
                        break;
                    case 25:
                        if (caracter == '=') {
                            nodo = 26;
                        }else {
                            mostrarError(1025);
                            FDC = true;
                        }
                        break;
                    case 26:
                        if (buscarLetra()) {
                            mostrarError(1027);
                        } else {
                            mostrarError(1001);
                        }
                        FDC = true;
                        break;
                    case 27:
                        if (!isdigit(caracter)) {
                            mostrarError(1028);
                            FDC = true;
                        }
                        break;
                }
            }catch (const out_of_range& e) {
                FDC = true;
            }
        }while (FDC == false);
        cout << endl;
        if (!error) {
            if (buscarEnArreglo(nodosSignoCompuesto)) {
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
            }else if (buscarEnArreglo(nodosInvalidos)) {
                mostrarError(1010);
                cout << endl;
            }
        }
            cout << endl;
            real = false;
            FDC = false;
            error = false;
            indice = -1;
            nodo = 1;
    }
}