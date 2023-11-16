#include <iostream>
#include "VuelaFlight.h"

using  namespace std;
/**
 * @brief Practica 3 EEDD
 * @date 02/11/2023
 * @author Antonio José Garcia Arias, ajga001@red.ujaen.es
 * @author Abraham Garcia Hurtado, agh00040@red.ujaen.es
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, const char * argv[]) {
//Declaro clase VuelaFlight
    VuelaFlight vl;
try {
#pragma region Ejercicio 1
    //BuscaVuelos
    cout << "----------------AEA5201----------------" << endl << endl;
    vector<Vuelo *> vector1 = vl.buscaVuelos("AEA5201");
    //Le pasamos vector 1 modo true modo buscaVuelos
    vl.muestraVuelos(vector1, true);
    cout << "----------------VLG----------------" << endl << endl;
    //Le pasamos vector 2 modo true modo buscaVuelos
    vector<Vuelo *> vector2 = vl.buscaVuelos("VLG2021");
    vl.muestraVuelos(vector2, true);
    cout << "----------------------------------" << endl << endl;
#pragma endregion
#pragma region Ejercicio 2
    //Metodo BuscaAeroPor
    cout << "---------VuelosOperadosPor---------" << endl << endl;
    Fecha f(13, 04, 18);
    vector<Vuelo *> vectorsito21 = vl.vuelosOperadosPor("VLG", f);
    //Le pasamos vector 2 modo false modo vuelos operados por
    vl.muestraVuelos(vectorsito21, false);
#pragma endregion
#pragma region Ejercicio 3
    //Mostrar identificadores de vuelo (únicos) con destino a Londres (LHR, STN, LTN,LGW)
    //desde cualquier aeropuerto español
    cout << "-----------VuelosLondon-----------" << endl << endl;
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
#pragma endregion
#pragma region Ejercicio 4 PAREJAS
    cout << "-----------EJEPAREJAS-----------" << endl << endl;
    vector<Aeropuerto*> vAeropuertos = vl.buscaAeropuertosAerolinea("EVE");
    for (int i = 0; i < vAeropuertos.size(); ++i) {
        cout << "Aeropuerto : " << vAeropuertos[i]->getNombre() << endl;
    }
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
