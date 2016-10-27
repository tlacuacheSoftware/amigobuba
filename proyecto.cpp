//: C02:Hello.cpp
// Saying Hello with C++
#include <iostream> // Stream declarations
#include <fstream>
#include <stack>
#include <list>
#include <stdlib.h>  
#include <stdio.h> 
#include <cstring>
#include <vector>
#include <sstream>

using namespace std;
/**
*
* el algorito va ser le sigueinte 
* tomar los cleintes y premium en un pila cada uno 
* los no clientes hasta el final 
* meter primum y clientes
* y al final los no clientes
*
*/


/**
*  sumar la hora de llegada 
*
*
*/

class cliente {
 // atributos
private:
    string idCliente;
    string tipoCliente;
    string horaLlegada;
    string tiempoOperacion;

//metodos 
public: 
  // constructor
  cliente(string id, string tipo , string llegada, string operacion){
      idCliente = id;
      tipoCliente = tipo;
      horaLlegada = llegada;
      tiempoOperacion = operacion;
  }

  //metodos 
  string getIdClinte(void){
    return idCliente;
  }
  string getTipoCliente(void){
    return tipoCliente;
  }
  string getHoraLlegada(void){
    return horaLlegada;
  }
  string getTimepoTarda(void){
    return tiempoOperacion;
  }
  string getToString(void){
    
    return idCliente+","+tipoCliente+","+horaLlegada+","+tiempoOperacion;
  }

};

class cajero{
private:
  string idCajero;
  list<cliente> personas;
public:

    cajero(string id ){
      idCajero = id;
    }
    string getId(void){
      return idCajero;
    }
    void agregarPesona(cliente c){

    }
    
    /*
    cliente getPersona(void){
      
    }
    */
    void crearArchivo(void){
      string nombreArchivo = "cajero"+idCajero+".txt";
      ofstream escribir (nombreArchivo); // se crear archivo

      for (std::list<cliente>::iterator it = personas.begin();  it != personas.end(); ++it){
        cliente t = *it;
        string x = t.getToString();
        escribir<<x<<endl;
      } 
    }

    void mostrar(void){

    }
    
  
};


void mostrarLista(list<cliente> l ){

  for (std::list<cliente>::iterator it = l.begin();  it != l.end(); ++it){
        cliente t = *it;
        string x = t.getToString();
       cout<<x<<endl;
      } 
}


int main(int argc, char **argv) {
  string nombreFichero = argv[1];
  fstream ficheroEntrada;
  list<cliente> clinetePremium;
  list<cliente> noClientes;
    string frase;


    /*
    * guarda la primer lia de el archivo que es el numero de 
    * cajeros 
    */ 
    ficheroEntrada.open (nombreFichero);
    getline(ficheroEntrada, frase);
    int numCajeros =atoi(frase.c_str());
      getline(ficheroEntrada, frase);
    int personas =atoi(frase.c_str());
    // vaamos a guarda en estas varibles los tokens 
    string idCliente;
    string tipoCliente;
    string horaLlegada;
    string tiempoOperacion;
    // recorro el archivo y lo guardo en una lista
    for (int t = 0; t < personas; t++){
       getline(ficheroEntrada, frase); 

        istringstream f(frase); // token 
        string s;  // temporal 
         int i =0;
        while (getline(f, s, ',')) { // separo por el delimitador 
            cout << s << " : "<<s.size()<<endl;
            if(i ==0){
              idCliente= s;
            }
            if(s == "C"){
              tipoCliente= s;
            }
            if(s == "P"){
              tipoCliente= s;
            }
            if(s == "N"){
              tipoCliente= s;
            }

            if(s.size() == 8){ // tiempo que llega

              horaLlegada = s;
            }
            if(s.size() == 5){ // tiempo que tarda
              cout<<"agregar timpo ope"<<tiempoOperacion<<endl;
              tiempoOperacion=s; 
            }

            i++;
        }// end while
        if(tipoCliente == "C"|| tipoCliente == "P"){ // los guardamos en la lista por que son lo que importan 
          cliente a (idCliente,tipoCliente,horaLlegada,tiempoOperacion);  /// 
          clinetePremium.push_back(a);
        }else{
          cliente a (idCliente,tipoCliente,horaLlegada,tiempoOperacion);
          noClientes.push_back(a);
        }
        // cout<<""<< idCliente+","+tipoCliente+","+horaLlegada+","+tiempoOperacion<<endl;
        

    } // end for
cout<<"-----------"<<endl;
    mostrarLista(clinetePremium);

  /*
  *
  *  vamos a meter a todso los ceintes segun su tipo ne una pila  segun su tipo
  *
  */



    return 0;

}




