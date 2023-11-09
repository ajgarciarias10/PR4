#include "VuelaFlight.h"
/**
 * @brief VuelaFlight
 */
VuelaFlight::VuelaFlight() :aeropuertos(),rutas() {}
/**
 * @brief Constructor parametrizado
 * @param vector
 * @param ruta
 */
VuelaFlight::VuelaFlight(vector<Aeropuerto> aeropuerto, list<Ruta> ruta ,map<string,Aerolinea> airlines):aeropuertos(aeropuerto),rutas(ruta),airlines(airlines) {}
/**
 * @brief Destructor
 */
VuelaFlight::~VuelaFlight() {
}
/**
 * @brief BuscarRutasOrigenDestino
 * @param idAerOrig
 * @param idAerDest
 * @return
 */
Ruta &VuelaFlight::buscarRutasOriDeS(string idAerOrig, string idAerDest) {
    list<Ruta>::iterator i;
    //Recorremos todos los aeropuertos
    for(i=rutas.begin(); i!=rutas.end();i++){
        //Obtenemos los datos
        string origenBusq = i->getOrigin()->getIata();
        string destinoBusq = i->getDestination()->getIata();
        //En caso de que se encuentre
        if(origenBusq==idAerOrig && destinoBusq==idAerDest)
            //Devolvemos el dato
            return *i;
    }
    throw std::invalid_argument("La ruta no ha sido encontrado" "\n" "Intente cambiar su origen y destino" );
}
/**
 * @brief BuscarRutasOrigen
 * @param idAerOrig
 * @return
 */
list<Ruta *> VuelaFlight::buscarRutasOrigen(string idAerOrig) {
    list<Ruta>::iterator i;
    list<Ruta *> lista;
    //Recorremos todos los aeropuertos
    for(i=rutas.begin(); i!=rutas.end();i++){
        //Obtenemos los datos
        string origenBusq = i->getOrigin()->getIata();
        //En caso de que se encuentre
        if(origenBusq==idAerOrig){
            //Devolvemos el dato
            //El iterador no es como un puntero y entonces lo que hacemos es devolver el dato * y su direccion &
            lista.push_back(&(*i));
        }
    }
    return  lista;


}

/**
 * @brief Buscar Aeropuerto por Pais
 * @param pais
 * @return
 */
vector<Aeropuerto * > VuelaFlight::buscarAeropuertoPais(string pais) {
    //Donde lo vamos a meter
    vector<Aeropuerto*> encontrado;
    //Recorremos el tamaño fisico
    for (int i = 0; i < aeropuertos.size(); ++i) {
        if(aeropuertos[i].getIsoPais() == pais){
            //Insertamso el vector de aeropuertos
            //Insertamos la direccion del vector ya que con los corchetes accedemos al dato pero tenemos que poner donde esta
            encontrado.push_back(&(aeropuertos[i]));
        }
    }
    return  encontrado;


}
/**
 * @brief Metodo para añadir nueva ruta
 * @param idAerOrig
 * @param idAerDest
 * @param aerolinea
 */
void VuelaFlight::addNuevaRuta(Aeropuerto* AerOrig, Aeropuerto* AerDest, Aerolinea* aerolineaEncontrada) {
            //Añadimos las rutas ya con la aerolinea  y los aeropertos
            rutas.push_back(Ruta(aerolineaEncontrada,AerDest,AerOrig));
            //d. Obtener la dirección del objeto ruta recién insertado en la lista (en la última posición).
            //e. Enlazar la aerolínea encontrada antes con la ruta anterior mediante
            //Aerolinea::linkAerolRuta.
            aerolineaEncontrada->linkAerolRuta(&(rutas.back()));

}

/**
 * @brief Constructor Copia
 * @param vl
 */

VuelaFlight::VuelaFlight(const VuelaFlight &vl) : aeropuertos(vl.aeropuertos), rutas(vl.rutas),work(vl.work){}
/**
 * @brief Añade aeropuerto
 * @param aeropuerto
 */

void VuelaFlight::añadeAeropuerto(const Aeropuerto aeropuerto) {
    aeropuertos.push_back(aeropuerto);

}
/**
 * @brief Metodo AddAerolinea
 * @param aerolinea
 */
void VuelaFlight::addAerolinea(string icao,Aerolinea aerolinea) {
    airlines.insert( pair<string , Aerolinea>(icao,aerolinea));

}
/**
 * @brief Metodo Buscar Aerolinea por Icao
 * @param icaoAerolinea
 * @return
 */
Aerolinea &VuelaFlight::buscaAerolinea(std::string icaoAerolinea) {
    Aerolinea aerol;
    aerol.setIcao(icaoAerolinea);
    Aerolinea *t = airlines.find(aerol);
    if(!t){
        throw std::invalid_argument("No se ha encontrado la aerolinea");
    }
    return  *t;

}
/**
 * @brief Metodo que busca las Aerolineas Activas
 * @return
 */
VDinamico<Aerolinea*> VuelaFlight::buscaAerolineasActiva() {
    VDinamico<Aerolinea*> buscaAerolinea = work.recorreInorden();
    VDinamico<Aerolinea*> devuelveAerolinea;
    for (int i = 0; i < buscaAerolinea.tamlog(); ++i) {
        if(buscaAerolinea[i]->isActivo()){
            devuelveAerolinea.insertar(buscaAerolinea[i]);
        }
    }

    return  devuelveAerolinea;

}
/**
 * @brief Metodo que busca la Aerolinea por el pais
 * @param idPais
 * @return
 */
VDinamico<Aerolinea*> VuelaFlight::getAerolineasPais(std::string idPais) {
    VDinamico<Aerolinea*> buscaAerolinea = work.recorreInorden();
    VDinamico<Aerolinea*> devuelveAerolinea;
    for (int i = 0; i < buscaAerolinea.tamlog(); ++i) {
        if(buscaAerolinea[i]->getPais() == idPais){
            devuelveAerolinea.insertar(buscaAerolinea[i]);
        }
    }

    return  devuelveAerolinea;
}
/**
 * @brief Metodo que carga las rutas que leemos
 * @param icaoRuta
 * @param origen2
 * @param destino2
 */
void VuelaFlight::cargarRutas(string icaoRuta,string origen2, string destino2){
#pragma  region   Buscar en tiempo logarítmico la aerolínea que hace la ruta en VuelaFlight::work
    Aerolinea aero2;
    aero2.setIcao(icaoRuta);
    Aerolinea *aerolineaEncontrada;
    aerolineaEncontrada = airlines.busquedaRecursiva(aero2);
#pragma  endregion
#pragma region Buscar en tiempo logarítmico en  PR2 + añadir nueva ruta
    //Declaro un aeropuerto
    Aeropuerto aero;
    //Seteo su iata de origen
    aero.setIata(origen2);
    //Compruebo la posicion dentro del vector dinamico en el que esta Tanto la ruta de origen con la de destino
    //TODO
    //Y así descubro el aeropuerto ORIGEN
    vector<Aeropuerto>::iterator  origen;
    origen = std::lower_bound(aeropuertos.begin(), aeropuertos.end(),aero);
    //Obtenemos la posicion iterada de destino
    vector<Aeropuerto>::iterator  destino;
    //Seteo su iata de destino
    aero.setIata(destino2); 
    //Y así descubro el aeropuerto destino
    destino= std::lower_bound(aeropuertos.begin(), aeropuertos.end(),aero);;
    if(origen !=-1 && posDest !=-1 && aerolineaEncontrada){
        //Añadimos nueva ruta a partir del origen el destino y el icao
        addNuevaRuta(&aeropuertos[posOrigen],&aeropuertos[posDest],aerolineaEncontrada);
    }
}
/**
 * @brief Metodo que ordena los aeropuertos
 */

void VuelaFlight::ordenarAeropuertos(){
    sort(aeropuertos.begin(),aeropuertos.end());
}
/**
 * @brief Metodo que devuelve el tamaño del vector
 */
long VuelaFlight::tamaAeropuertos() {
    return aeropuertos.size();
}
/**
 * @brief Metodo que devuelve el tamaño de la lista de rutas
 */
long VuelaFlight::tamaRutas() {
    return rutas.size();
}
/**
 * @brief Metodo que devuelve el tamaño del arbol
 */
long VuelaFlight::tamaAirlines() {
    return airlines.size();
}

