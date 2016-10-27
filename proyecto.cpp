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

    cajero(string id){
      idCajero = id;
    }
    string getId(void){
      return idCajero;
    }

    list<cliente> getLista(void){
      return personas;
    }
    void agregarPesona(cliente c){
      personas.push_back(c);
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

void mostrarCajas(list<cajero> l){
  for (std::list<cajero>::iterator it = l.begin();  it != l.end(); ++it){
        cajero t = *it;
        list<cliente> t1 = t.getLista();
        for (std::list<cliente>::iterator ti = t1.begin();  ti != t1.end(); ++ti){
          cliente t2 = *ti;
          string x = t2.getToString();
          cout<<"soy "<<x<<" y estoy en el cajero "<<t.getId()<<endl;
        }
      } 
}

string cajaMenos(list<cajero> l){
  int menor = 999999999;
  string m;
  for (std::list<cajero>::iterator it = l.begin();  it != l.end(); ++it){
      cajero t = *it;
      list<cliente> t1 = t.getLista();
      if(t1.size()<menor){
        menor = t1.size();
        m = t.getId();
      }
   }
   return m;
}

list<cajero> acomodar(list<cajero> l, list<cliente> c){
  while(!c.empty()){
   string menor = cajaMenos(l);
   for (std::list<cajero>::iterator it = l.begin();  it != l.end(); ++it){
      if(((*it).getId()) == menor){
        cliente t = c.front();
        c.pop_front();
        (*it).agregarPesona(t);
      }
   }
  }
  return l;
}

int HLlaInt(string s){
  int h = std::stoi(s.substr(0,2));
  int m = std::stoi(s.substr(3,2));
  int se = std::stoi(s.substr(6,2));
  int r = (h*3600)+(m*60)+se;
  return r;
}

int TTaInt(string s){
  int m = std::stoi(s.substr(0,2));
  int se = std::stoi(s.substr(3,2));
  int r = (m*60)+se;
  return r;
}

int getTiempo(cajero c){
  list<cliente> l = c.getLista();
  cliente t = l.front();
  string p = t.getHoraLlegada();
  int p1 = HLlaInt(p);
  for (std::list<cliente>::iterator it = l.begin();  it != l.end(); ++it){
    cliente t1 = *it;
    string f = t1.getTimepoTarda();
    int w = TTaInt(f);
    p1 += w;
  }
  return p1;
}

int promedio(list<cajero> l, string ult, int numCaj){
  int ultimahoradellegada = HLlaInt(ult)+1;
  int suma = 0;
  for (std::list<cajero>::iterator it = l.begin();  it != l.end(); ++it){
    cajero t = *it;
    int a = getTiempo(t);
    if(a >= ultimahoradellegada){
      a = a - ultimahoradellegada;
      suma += a;
    }
  }
  return suma/numCaj;
}


int main(int argc, char **argv) {
  string nombreFichero = argv[1];
  fstream ficheroEntrada;
  list<cliente> clinetePremium;
  list<cliente> noClientes;
  list<cajero> cajas;
    string frase;
    string ultimahora;


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
              ultimahora = s;
            }
            if(s.size() == 5){ // tiempo que tarda
              tiempoOperacion=s;
              cout<<"agregar timpo ope"<<tiempoOperacion<<endl;
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
        cout<<""<< idCliente+","+tipoCliente+","+horaLlegada+","+tiempoOperacion<<endl;
        

    } // end for

    for(int r = 1; r <= numCajeros; r++){
      cajero a (std::to_string(r));
      cajas.push_back(a);
    }

    cajas = acomodar(cajas, clinetePremium);
    cajas = acomodar(cajas, noClientes);
    mostrarCajas(cajas);
    int prom = promedio(cajas, ultimahora, numCajeros);
    cout<<prom << " segundos"<<endl;
cout<<"-----------"<<endl;
    //mostrarLista(clinetePremium);

  /*
  *
  *  vamos a meter a todso los ceintes segun su tipo ne una pila  segun su tipo
  *
  */



    return 0;

}




