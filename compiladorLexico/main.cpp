#include <iostream>
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
using namespace std;
int nodo = 1;
int indice = 0; //Indice de cadena
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
bool buscarLetra(string cadena) { //busca si el caracter apuntado por el indice es una palabra permitida
    for (char i : abc) {
        if (cadena[indice] == i) {
            return  true;
        }
    }
    return false;
}

int main() {
    string cadena;
    cout << "Inserte cadena: ";
    cin >> cadena;

    bool FDC = false;

    do {
    switch (nodo) {
        case 1:
            if (buscarLetra(cadena)) {
                nodo = 2;
                FDC = true;
            }
            break;
    }
    }while (FDC == false);
    cout << nodo << endl;
}