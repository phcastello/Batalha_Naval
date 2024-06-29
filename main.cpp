#include<iostream>
#include<iomanip>
#include<cmath>
#include<cctype>
#include<string>
using namespace std;

int mJ1[5][5], mJ2[5][5];
int J1barcoG=1, J1barcoM=1, J1barcoP=2;
int J2barcoG=1, J2barcoM=1, J2barcoP=2;
const int G=4, M=3, P=2;


void mostrar_tabuleiro(){
    cout << "---------------------------------------------" << endl;
    cout << "1 para ocupado.\n0 para livre." <<endl<<endl;
    cout << "Tabuleiro J1:" <<endl;

    cout << "#  A B C D E";
    int p=1;
    for(int i=0; i<5; i++){      
        cout <<endl;
        cout << p << " |";
        p++; 
        for(int j=0; j<5; j++){
            cout << mJ1[i][j] << " ";
        }
    }
    cout <<endl<<endl<< "Jogador 1 tem:" <<endl;
    cout << J1barcoG << " Barco(s) Grande(s)!" <<endl;
    cout << J1barcoM << " Barco(s) Medios(s)!" <<endl;
    cout << J1barcoP << " Barco(s) Pequenos(s)!" <<endl;
    cout <<endl<<endl<<endl;

    cout << "Tabuleiro J2:" <<endl;
    cout << "#  A B C D E";
    
    p=1;
    for(int i=0; i<5; i++){
        cout <<endl;
        cout << p << " |";
        p++;
        for(int j=0; j<5; j++){
            cout << mJ2[i][j] << " ";
        }  
    }
    cout <<endl<<endl<< "Jogador 2 tem:" <<endl;
    cout << J2barcoG << " Barco(s) Grande(s)!" <<endl;
    cout << J2barcoM << " Barco(s) Medios(s)!" <<endl;
    cout << J2barcoP << " Barco(s) Pequenos(s)!" <<endl;
    cout << "---------------------------------------------" << endl;
}

bool checagem_barco(char barco){
    barco = toupper(barco);
    if(J1barcoG > 0 && barco == 'G') return true;

    else if(J1barcoM > 0 && barco == 'M') return true;

    else if(J1barcoG > 0 && barco == 'P') return true;

    else{
        return false;
        cout << "Voce nao tem mais barcos desse tipo! Digite novamente!";
    }
}

bool posicao(int tamanho, int i, int j){
    int linha = i;
    int contador=0;
    int T_barco = G-1;
    while(T_barco > 0){
        if((linha < 1 || linha > 5) && T_barco > 0){
            cout << "Direção invalida! Digite novamente!";
            return false;
        }
        else{
            contador++;
        }
        if((j < 1 || j > 5) && T_barco > 0){
            cout << "Direção invalida! Digite novamente!";
            return false;
        }
        else{
            contador++;
        }
        if(mJ1[linha-T_barco][j])
        T_barco--;
    }
}

/*
checar se segundo ponto colocado é na mesma coluna e na mesma linha que o primeiro
checar se todas as posiçoes possiveis, tanto estando dentro do tabuleiro como se sobrepoe um navio, então return false
*/

bool checagem_posicao(int i, char j, char barco){
    j = toupper(j);
    int coluna = static_cast<int>(j) - static_cast<int>('A') + 1;
    int contagemP[4];


    if(mJ1[i][coluna] == 1){
        cout << "Posicao ja ocupada! Digite novamente!" <<endl;
        return false;
    }
    else if((coluna < 1 || coluna > 5)){ 
        cout << "Coluna invalida!" <<endl;
        return false;
    }

    else if(i < 1 || i > 5){
        cout << "Linha invalida!" <<endl;
        return false;
    }
    
    if(barco == 'G'){
        
    }


}

void colocar_barco(){
    char barco;
    int i;
    char j;

    do{
        cout << "Jogador 1, coloque um barco!" <<endl;
        cout << "Tipos de barco:" <<endl;
        cout << "G para Barco Grande (4x1)" <<endl;
        cout << "M para Barco Medio (3x1)" <<endl;
        cout << "P para Barco Pequeno (2x1)" <<endl;
        cout << "Digite o tipo de barco: ";
        cin >> barco;
    }while(!(checagem_barco(barco)));

    
    do{
        char str[2];
        cout << "Digite a posicao inicial do barco (Ex: A1): ";
        cin >> str;
        j = str[0];
        i = str[1] - '0';

    }while(checagem_posicao(i,j, barco));


    

    
}

int main(){
    for(int i=0; i < 5; i++){
        for(int j=0; j < 5; j++){
            mJ1[i][j] = 0;
        }
    }
    for(int i=0; i < 5; i++){
        for(int j=0; j < 5; j++){
            mJ2[i][j] = 0;
        }
    }

    mostrar_tabuleiro();
    colocar_barco();

    



    return 0;
}