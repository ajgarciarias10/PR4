//
// Created by AntonioJR on 10/11/2023.
//

#ifndef PR4_VUELO_H
#define PR4_VUELO_H
#include <string>
#include "fecha.h"
#include "Aeropuerto.h"
using  namespace std;
class  Aerolinea;
class Vuelo {
private:
    string flightNumber;
    string plane;
    string datoMeteo;
    Fecha fecha;
    Aeropuerto *airpOrigin;
    Aeropuerto *airpDest;
    Aerolinea *linkAero;
public:
    Vuelo();

    Vuelo(const Vuelo &orig);

    Vuelo(string flightNumber,string plane,string datoMeteo,Fecha fecha,Aeropuerto *airpOrigin,Aeropuerto *airpDest,Aerolinea *linkAero);

    virtual  ~Vuelo();

    const string &getFlightNumber() const;

    const string &getPlane() const;

    const string &getDatoMeteo() const;

    const Fecha &getFecha() const;

    Aeropuerto *getAirpOrigin() const;

    Aeropuerto *getAirpDest() const;

    Aerolinea *getAerolinea() const;
};


#endif //PR4_VUELO_H
