#include <iostream>
#include "VuelaFlight.h"

using  namespace std;
/**
 * @brief Practica 4 EEDD
 * @date 20/11/2023
 * @author Antonio José Garcia Arias, ajga001@red.ujaen.es
 * @author Abraham Garcia Hurtado, agh00040@red.ujaen.es
 * @param argc
 * @param argv
 * @return
 */


/**
* @brief Metodo que muestra todos los vuelos/
* @post Modo True para mostrar como en Busca vuelos
* @post Modo False para mostrar modelos de aviones en  vuelos operados por
* @param vector
*/

void muestraVuelos(vector<Vuelo *> vector, bool modo) {
        if (modo) {
            //Datos de la aerolínea que los opera ( nombre completo y país al que pertenece) e iata
            //de los aeropuertos de origen, destino

            cout << "Aerolinea : " << vector[0]->getAerolinea()->getNombre() << endl
                 << "Pais :" << vector[0]->getAerolinea()->getPais() << endl
                 << "Iata Origen: " << vector[0]->getAirpOrigin()->getIata() << endl
                 << "Iata Destino: " << vector[0]->getAirpDest()->getIata() << endl << endl;
            //Listado con todas las fechas y estado del tiempo en las que se ha efectuado en
            //condiciones de lluvia o chubascos
            for (int i = 0; i < vector.size(); ++i) {
                string datoMeteo = vector[i]->getDatoMeteo();
                if (datoMeteo.substr(0, 9) == "Chubascos" || datoMeteo.substr(0, 6) == "Lluvia") {
                    cout << "Fecha: " << vector[i]->getFecha().cadena().substr(0, 7)
                         << ", Tiempo: " << datoMeteo << endl;
                }

            }
            cout << "----------------------------------" << endl << endl;


        } else {
            set<string> modAVun;

            //Mostrar los modelos de aviones (únicos) utilizados en vuelos operados por Vueling, VLG, el 13/4/2018
            for (int i = 0; i < vector.size(); ++i) {
                modAVun.insert(vector[i]->getPlane());
            }
            set<string>::iterator itModAVUN = modAVun.begin();
            for (itModAVUN; itModAVUN != modAVun.end(); ++itModAVUN) {
                cout << "Modelo de Avion : " << *itModAVUN << endl;
            }

        }

    }

int main(int argc, const char * argv[]) {
//Declaro clase VuelaFlight
    VuelaFlight vl;
try {
#pragma region Ejercicio 1
    //BuscaVuelos
    cout << "----------------AEA5201----------------"  << endl;
    vector<Vuelo *> vector1 = vl.buscaVuelos("AEA5201");
    //Le pasamos vector 1 modo true modo buscaVuelos
    muestraVuelos(vector1, true);
    cout << "----------------VLG----------------" << endl;
    //Le pasamos vector 2 modo true modo buscaVuelos
    vector<Vuelo *> vector2 = vl.buscaVuelos("VLG2021");
    muestraVuelos(vector2, true);
#pragma endregion
#pragma region Ejercicio 2
    //Metodo BuscaAeroPor
    cout << "---------VuelosOperadosPor---------" << endl;
    Fecha f(13, 04, 18);
    vector<Vuelo *> vectorsito21 = vl.vuelosOperadosPor("VLG", f);
    //Le pasamos vector 2 modo false modo vuelos operados por
    muestraVuelos(vectorsito21, false);
    cout << "----------------------------------" << endl << endl;
#pragma endregion
#pragma region Ejercicio 3
    //Mostrar identificadores de vuelo (únicos) con destino a Londres (LHR, STN, LTN,LGW)
    //desde cualquier aeropuerto español
    cout << "-----------VuelosLondon-----------" << endl;
    set<string> vuelosLHR = vl.buscaVuelosDestAerop("ES", "LHR");
    set<string> vuelosSTN = vl.buscaVuelosDestAerop("ES", "STN");
    set<string> vuelosLTN = vl.buscaVuelosDestAerop("ES", "LTN");
    set<string> vuelosLGW = vl.buscaVuelosDestAerop("ES", "LGW");
    //Hacemos un par con todos los vuelosdeLondres
    set<string> vuelosLondres;
    vuelosLondres.insert(vuelosSTN.begin(), vuelosSTN.end());
    vuelosLondres.insert(vuelosLHR.begin(), vuelosLHR.end());
    vuelosLondres.insert(vuelosLTN.begin(), vuelosLTN.end());
    vuelosLondres.insert(vuelosLGW.begin(), vuelosLGW.end());
    cout << "El total de vuelos a londres son: " << vuelosLondres.size() << endl;
    set<string>::iterator vuelosLondresIT = vuelosLondres.begin();
    for (vuelosLondresIT; vuelosLondresIT != vuelosLondres.end(); vuelosLondresIT++)
        cout << "Vuelo: " << *vuelosLondresIT << endl;
    cout << "----------------------------------" << endl << endl;

#pragma endregion
#pragma region Ejercicio 4 PAREJAS
    cout << "-----------EJEPAREJAS-----------" << endl;
    vector<Aeropuerto*> vAeropuertos = vl.buscaAeropuertosAerolinea("EVE");
    for (int i = 0; i < vAeropuertos.size(); ++i) {
        cout << "Aeropuerto : " << vAeropuertos[i]->getNombre() << endl;
    }
    cout << "----------------------------------" << endl << endl;

#pragma endregion
}catch (invalid_argument &e){
    cout<<e.what()<<endl;
}
catch(out_of_range &o){
    cout<<o.what()<<endl;
}
catch(bad_alloc &b){
    cout<<b.what()<<endl;
}

    return 0;
}
