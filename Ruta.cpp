#include "Ruta.h"

Ruta::~Ruta() {
}

Ruta::Ruta():company(nullptr),origin(nullptr),destination(nullptr),flightRou() {}
Ruta::Ruta(const Ruta &orig) :company(orig.company),origin(orig.origin),destination(orig.destination),flightRou(orig.flightRou) {}
Ruta::Ruta( Aerolinea  *aerolinea, Aeropuerto *dest, Aeropuerto *orig) :company(aerolinea),origin(orig),destination(dest),flightRou() {}




Aeropuerto *Ruta::getDestination() const {
    return destination;
}

Aeropuerto *Ruta::getOrigin()  {
    return origin;
}

Aerolinea *Ruta::getCompany()  {
    return company;
}

void Ruta::setDestination(Aeropuerto *destination) {
    Ruta::destination = destination;
}

void Ruta::setOrigin(Aeropuerto *origin) {
    Ruta::origin = origin;
}

void Ruta::setCompany(Aerolinea *company) {
    Ruta::company = company;
}
/**
 * @brief Metodo que añade el vuelo a la lista dentro de rutas flightRou
 * @param v
 * @return
 */

bool Ruta::addVuelo(Vuelo *v) {
    // Verificar que la aerolínea y los aeropuertos de origen y destino
    // coinciden con los de la ruta
    if(v->getAirpOrigin()->getIata() == this->origin->getIata()&&
       v->getAirpDest()->getIata() == this->destination->getIata()&&
       v->getAerolinea()->getIcao() == this->company->getIcao()){
        flightRou.push_back(v);
        return true;
    }
    return false;

}
/**
 * @brief Obtiene el numero de vuelos
 * @return
 */
long int Ruta::getNumVuelos() {
    return flightRou.size();
}
list<Vuelo*> Ruta::getVuelos() {
    return flightRou;
}

