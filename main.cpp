#include <cstdlib>
#include <iostream>
#include <conio.h>
using namespace std;
//variables globales

int flag = 0; 
int movil[2];
int caja[2];
int pos_x = 0;
int pos_y = 12;
int cm_y =9;
int cm_x =11;
//prototipos 
void dibuja_tablero(int &pos_x, int &pos_y, int &cm_x, int &cm_y, char tecla);
void resetea_posiciones();
int main(int argc, char *argv[])
{
    char tecla;
    int x = 22;
    int y = 20;

    // se guarda en variables globales la informacion de la posicion inicial 
    movil[0] = pos_x;
    movil[1] = pos_y;
    caja[0] = cm_x;
    caja[1] = cm_y;
    
    
    
    do{
                 
        system("cls");  
        // se le pasa por referencia las variables de la posicion del movil y la caja asi como la tecla presionada. 
        dibuja_tablero(pos_x,pos_y,cm_x,cm_y,tecla);
        cout << "use las teclas a w s d para moverse: \n";
        tecla=getch();
       
      
    }while(tecla != 32);
    
   

    system("PAUSE");
    return EXIT_SUCCESS;
}

void dibuja_tablero(int &pos_x, int &pos_y, int &cm_x, int &cm_y, char tecla){
    char p=179;
    char r=196;
    char c=197;
    char t=180;
    char t_=195;
    char t__=194;
    char t___=193;
    char laa=218;
    char lca=191;
    char lab=192;
    char lcb=217;
    char icon = 169;
    char pp = 219;
    
    int x = 22;
    int y = 20;
    //posicion caja de madera 
    char cm = 176;
    int n_pos_x=pos_x;
    int n_pos_y=pos_y;
    int n_cm_x=cm_x;
    int n_cm_y=cm_y;
   //se inicializa el contenido del char en ascii 176(un cuadro blanco)
  
      
    char a[20][22] ={
                 {32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32},
                 {32,32,32,pp,pp,pp,pp,pp,pp,pp,pp,pp,pp,pp,pp,pp,pp,pp,pp,32,32,32},
                 {32,32,32,pp,32,32,32,32,32,32,32,32,32,32,32,32,32,32,pp,32,32,32},
                 {32,32,32,pp,32,32,32,32,32,32,32,32,32,32,32,32,32,32,pp,32,32,32},
                 {32,32,32,pp,32,32,32,pp,pp,pp,pp,pp,pp,pp,pp,pp,32,32,pp,32,32,32},
                 {32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,pp,32,32,pp,32,32,32},
                 {32,32,32,32,32,32,32,pp,32,32,32,32,32,32,32,pp,32,32,pp,32,32,32},
                 {32,32,32,pp,32,32,32,pp,32,32,32,32,32,32,32,pp,32,32,32,32,32,32},
                 {32,32,32,pp,32,32,32,pp,32,32,32,32,32,32,32,pp,32,32,32,32,32,32},
                 {32,32,32,pp,32,32,32,pp,32,32,32,32,32,32,32,pp,32,32,32,32,32,32},
                 {32,32,32,pp,32,32,32,pp,32,32,32,32,32,32,32,pp,32,32,32,32,32,32},
                 {32,32,32,pp,32,32,32,pp,32,32,32,32,32,32,32,pp,32,32,pp,32,32,32},
                 {32,32,32,pp,32,32,32,pp,pp,pp,pp,pp,pp,pp,pp,pp,32,32,pp,32,32,32},
                 {32,32,32,pp,32,32,32,32,32,32,32,32,32,32,32,32,32,32,pp,32,32,32},
                 {32,32,32,pp,32,32,32,32,pp,32,32,32,32,32,pp,32,32,32,pp,32,32,32},
                 {32,32,32,pp,32,32,32,32,pp,32,pp,pp,pp,32,pp,32,32,32,pp,32,32,32},
                 {32,32,32,pp,32,32,32,32,pp,32,32,32,32,32,pp,32,32,32,pp,32,32,32},
                 {32,32,32,pp,32,32,32,32,32,32,32,32,32,32,32,32,32,32,pp,32,32,32},
                 {32,32,32,pp,pp,pp,pp,pp,pp,pp,pp,32,pp,pp,pp,pp,pp,pp,pp,32,32,32},
                 {32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32},
                 };
     
        // se ubica la caja en su posicion 
     if(a[cm_y][cm_x] == 32){
        a[cm_y][cm_x]=cm;     
     }
   
    //______________________________________________
     // movimientos 
      // se mueve a la izq
    if(tecla == 97){
        n_pos_x =  n_pos_x -1;
        n_cm_x =  n_cm_x -1;

    }
 // se mueve a la derecha
    if(tecla == 100){
         n_pos_x =  n_pos_x +1;
         n_cm_x =  n_cm_x +1;
         
    }
    // se mueve a la para abajo
    if(tecla == 115){
        n_pos_y =  n_pos_y +1;
        n_cm_y =  n_cm_y +1;
    }
// se mueve para arriba
    if(tecla == 119){
        n_pos_y =  n_pos_y -1;
        n_cm_y =  n_cm_y -1;
    }
   
   // verifico que en la nueva posicion no se salga y si se sale se resetea las posiciones 
    if(n_pos_x < 0 || n_pos_x > 21 || n_pos_y < 0 || n_pos_y > 19 ){
         a[pos_y][pos_x]=32;
        resetea_posiciones();
    } else if(a[n_pos_y][n_pos_x] == 32){
        // verifico que a donde se este moviendo este vacio, se le asigna la nueva pos del movil a las variables principales 
            pos_x = n_pos_x;
            pos_y = n_pos_y;
        }else if(a[n_pos_y][n_pos_x] == cm){
        
            // verifico si haciadonde se mueve esta la caja, ser asi la caja se mueve y el movil toma su posicion 
            // si esta la caja, mirio si la nueva posicion de la caja no esta fuera 
            if(n_cm_x < 0 || n_cm_x > 21 || n_cm_y < 0 || n_cm_y > 19 ){
                 a[pos_y][pos_x]=32;
                 a[cm_y][cm_x]=32;
                 resetea_posiciones();
                }else if(a[n_cm_y][n_cm_x] == 32){
                    // verifico que a donde se este moviendo este vacio, se le asigna la nueva pos del movil a las variables principales 
                     a[pos_y][pos_x]=32;
                     a[cm_y][cm_x]=32;
                     cm_x = n_cm_x;
                     cm_y = n_cm_y;
                     pos_x = n_pos_x; 
                     pos_y = n_pos_y;
                     
                 }
        }
   
    cout<<"tecla: "<<tecla <<" pos_x:"<<n_pos_x<<" pos_y:"<<n_pos_y<< " value: "<<a[n_pos_y][n_pos_x];
     //se coloca la posicion el movil
     if(a[pos_y][pos_x] == 32){
        a[pos_y][pos_x]=icon;     
     }
     // se ubica la caja en su posicion 
     if(a[cm_y][cm_x] == 32){
        a[cm_y][cm_x]=cm;     
     }
         
   
    
    //--------------------------------------------------------------------
    // muestro en pantalla el cuadro 

     for (int i = 0; i < y; ++i)
    {
      // dibuja el indice horizontal arriba 
      if(i == 0){
           cout<<"\n";
          // cout<<"\t";
           cout<<"  ";
          
             for (int j = 0; j < x; ++j)
            {
              cout<<" ";
              cout<<j;
              if(j<10){cout<<" ";}
            
            
            }
       }  
         
         
         
         
         
       // dibuja la linea horizontal de arriba
      if(i == 0){
           cout<<"\n";
           //cout<<"\t";
           cout<<"  ";
           cout<<laa;
             for (int j = 0; j < x; ++j)
            {
            
              cout<<r;
              cout<<r;
              if(j < x-1){
                   cout<<t__;
              }else{
                // si llega al final cierre el cuadro 
                   cout<<lca;
              }
            }
       }   
            
       //dibuja las casillas internas 
       cout<<"\n";
       //cout<<"\t";
       if(i < 10){ 
            cout<<" "<<i;
             }else{
            cout<< i;
       }
       
       cout<<p;
        for (int j = 0; j < x; ++j)
        {
         
          cout<<a[i][j];
          cout<<a[i][j];
          cout<<p;
        }
        
       // dibuja la linea horizontal 
       if(i<y-1){
           cout<<"\n";
          // cout<<"\t";
           cout<<"  ";
           cout<<t_;
             for (int j = 0; j < x; ++j)
            {
            
              cout<<r;
              cout<<r;
              if(j < x-1){
                   cout<<c;
              }else{
                // si llega al final cierre el cuadro 
                   cout<<t;
              }
            }
       }
        // dibujo la ultima linea
        if(i == y-1){
           cout<<"\n";
           //cout<<"\t";
           cout<<"  ";
           cout<<lab;
             for (int j = 0; j < x; ++j)
            {
            
              cout<<r;
              cout<<r;
              if(j < x-1){
                   cout<<t___;
              }else{
                // si llega al final cierre el cuadro 
                   cout<<lcb;
              }
            }
       } 
    }
    cout<<"\n";
     
     
     
     
     }

void resetea_posiciones(){
                     
     pos_x=movil[0];
     pos_y=movil[1];
     cm_x=caja[0];
     cm_y=caja[1];                     


}
