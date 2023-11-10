//
// Created by AntonioJR on 10/11/2023.
//

#include "Vuelo.h"

const string &Vuelo::getFlightNumber() const {
    return flightNumber;
}

const string &Vuelo::getPlane() const {
    return plane;
}

const string &Vuelo::getDatoMeteo() const {
    return datoMeteo;
}

const Fecha &Vuelo::getFecha() const {
    return fecha;
}

Aeropuerto *Vuelo::getAirpOrigin() const {
    return airpOrigin;
}

Aeropuerto *Vuelo::getAirpDest() const {
    return airpDest;
}

Aerolinea *Vuelo::getAerolinea() const {
    return linkAero;
}
