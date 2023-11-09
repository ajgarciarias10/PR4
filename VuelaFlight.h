#include "Aeropuerto.h"
#include "Ruta.h"
#include <vector>
#include <list>
#include <deque>
#include <map>
#ifndef PRACTICA_2_VUELAFLIGHT_H
#define PRACTICA_2_VUELAFLIGHT_H
/**
 * @file VuelaFlight.h
 * @date 03/11/2023
 * @author Antonio José Garcia Arias, ajga001@red.ujaen.es
 * @author Abraham Garcia Hurtado, agh00040@red.ujaen.es
 * @brief Vuela Flight
 */

class VuelaFlight {
private:
    //Declaramos los metodo publicos y constructores
    vector<Aeropuerto> aeropuertos;
    list<Ruta> rutas;
    map<string,Aerolinea> airlines;
public:
    //Constructor por defecto
    VuelaFlight();
    //Constructor copia
    VuelaFlight(const VuelaFlight &vl);
    //Constructor parametrizado
    VuelaFlight(vector<Aeropuerto> aeropuerto, list<Ruta> ruta ,map<string,Aerolinea> airlines);
    //Destructor VuelaFlight
    ~VuelaFlight();
    //Metodos que tenemos que utilizar en esta practica
    //BuscarRutaDeOrigenDestino
    Ruta& buscarRutasOriDeS(string idAerOrig,string idAerDest);
    //BuscarRutasDeOrigen
    ListaEnlazada<Ruta*> buscarRutasOrigen (string idAerOrig);
    //Buscar AeropuertoPais
    VDinamico<Aeropuerto*> buscarAeropuertoPais(string pais);
    //AñadirNuevoAeropuerto
    void añadeAeropuerto(const Aeropuerto aeropuerto);
    //AñadirNuevaRuta
    void addNuevaRuta(Aeropuerto* AerOrig, Aeropuerto* AerDest, Aerolinea* aerolineaEncontrada);
    //Añade Aerolinea
    void addAerolinea(string icao, Aerolinea aerolinea);
    //Buscar Aerolinea por icao
    Aerolinea &buscaAerolinea(string icaoAerolinea);
    //Buscar Aerolinea activa
    VDinamico<Aerolinea*> buscaAerolineasActiva();
    //Metodo que obtiene la aerolineas por el Pais
    VDinamico<Aerolinea*> getAerolineasPais(string idPais);
    //Metodo que Carga las Rutas
    void cargarRutas(string icaoRuta,string origen2, string destino2);
    //Metodo que ordenar Aeropuertos
    void ordenarAeropuertos();
    //Devuelve el tamaño de aeropuertos
    long tamaAeropuertos ();
    //Devuelve el tamaño de rutas
    long tamaRutas();
    //Devuelve el tamaño del Arbol
    long tamaAirlines();

};


#endif //PRACTICA_2_VUELAFLIGHT_H
