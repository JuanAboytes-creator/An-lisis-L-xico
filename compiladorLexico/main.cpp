#include <iostream>
#include <cctype>
using namespace std;

string cadena;
int nodo = 1;
int indice = -1; //Indice de cadena
bool FDC = false;
char abc[] =
{
    'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
    'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
};
char ss[] =
{
    '+','-','/','!','@','#','$','%','^','&','*','(',')','[',']','{','}',',','?','_','.','<','>','=','|','"',':',';'
};
string palabrasReservadas[] =
{
    "if","while","do","char","string","int","bool","switch", "for","return","false","true","cout","cin"
};
int nodosInaceptable[] = {1,8,13};
int nodosEnteros[] = {4,7,27};//Conflicto entre los enteros y reales con los nodos 7 y 27
int nodosReales[] = {6,7,27};
int nodosVariables[] = {2,3};
int nodosSignoSimple[] = {17,25,15,20,18,5,9,23};
int nodosSignoCompuesto[] = {26,16,14,12,22,21,10,11,24};
int nodosComentario[] = {19};
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

int main() {
    cout << "Inserte cadena: ";
    cin >> cadena;

    do {
        indice++;
        try {
            switch (nodo) {
                case 1:
                    if (buscarLetra()) {
                        nodo = 2;
                    }
                    break;
                case 2:
                    if (isdigit(cadena.at(indice))) {
                        nodo = 3;
                    }else if (cadena.at(indice) != '_' && !buscarLetra()) {
                        //Llamar a funcion de errores o solo poner el error
                    }
                    break;
                case 3:
                    if (!isdigit(cadena.at(indice))) {
                        //Error
                    }
                    break;
            }
        }catch (const out_of_range& e) {
            FDC = true;
            cout << "Fin de cadena en el nodo ";
        }
    }while (FDC == false);
    cout << nodo << endl;
}