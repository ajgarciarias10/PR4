#include "Aerolinea.h"
#include "Ruta.h"
/**
 * @brief Constructor por defecto
 */
Aerolinea::Aerolinea():id(0),icao(""),nombre(""),pais(""),activo(false),aerorutas(){}
/**
 * @brief Constructor copia
 * @param orig
 */
Aerolinea::Aerolinea(const Aerolinea &orig):id(orig.id),icao(orig.icao),nombre(orig.nombre),pais(orig.pais),activo(orig.activo),aerorutas(orig.aerorutas) {}
/**
 * @brief Constructor parametrizado
 * @param orig
 */
Aerolinea::Aerolinea(int id, std::string icao, std::string nombre, std::string pais, bool activo):id(id),icao(icao),nombre(nombre),pais(pais),activo(activo),aerorutas() {}

/**
 * @brief Metodo que obtiene los aeropuerto de origen
 * @return
 */
vector<Aeropuerto*> Aerolinea::getAeropuertosOrig() {
    //Creo un vector dinamico de aeropuertos que en el que voy a devolver los aeropuertos
    vector<Aeropuerto *> vAeroOrig;
    //Creo un map con los aeropuertos de origen
    map<string,Aeropuerto>  mapDeAeroOrig;
    //Obtengo   aerorutas
    deque<Ruta*> aerorutasMetodo = getAerorutas();
    for (int i = 0; i < aerorutasMetodo.size(); ++i) {
        //Obtenemos los aeropuertos de origen
        Aeropuerto aeropuerto = *aerorutasMetodo[i]->getOrigin();
        //Como estamos utilizando la estructura stl map no se repetiran los aeropuertos de origen al insertar
        mapDeAeroOrig.insert(pair<string,Aeropuerto>(aeropuerto.getIata(),aeropuerto));
    }
    map<string,Aeropuerto>::iterator itMapDeAeroOrig;
    for (itMapDeAeroOrig = mapDeAeroOrig.begin(); itMapDeAeroOrig != mapDeAeroOrig.end() ; ++itMapDeAeroOrig) {
        vAeroOrig.push_back(&itMapDeAeroOrig->second);
    }

    return  vAeroOrig;

}
/***
 * @brief Devuelve todas las rutas cuyo AeroPuerto de origen o destino tenga ese iata
 * @param iataAirport
 * @return
 */
deque<Ruta*> Aerolinea::getRutasAeropuerto(std::string iataAirport) {
    //Vector que vamos a llenar
    deque<Ruta*> vRutasAero;
    //Recorremos las rutas de la aerolinea
    for (int i = 0; i < aerorutas.size(); ++i) {
        string iataOrig = aerorutas[i]->getOrigin()->getIata();
        string iataDest = aerorutas[i]->getDestination()->getIata();
        //Si tiene ese iata  insertamos  la ruta
            if(iataOrig == iataAirport ||iataDest == iataAirport ){
                    vRutasAero.push_back(aerorutas[i]);
            }
    }
    //Devolvemos el vector de rutas
    return  vRutasAero;
}
/**
 * @brief Metodo que enlaza la Aerolinea con su ruta
 * @param r
 */
void Aerolinea::linkAerolRuta(Ruta *r) {
    this->aerorutas.push_back(r);
}
/**
 * @brief Destructor de Aerolinea
 */
Aerolinea::~Aerolinea() {
}
/**
 * @brief Metodo que compara si una aerolinea es menor que otra por icao
 * @param orig
 * @return
 */
bool Aerolinea::operator<(const Aerolinea &orig) const {
    return (this->icao<orig.icao);

}
/**
 * @brief  Metodo que compara si una aerolinea es mayor que otra por icao
 * @param orig
 * @return
 */
bool  Aerolinea::operator>(const Aerolinea &orig) const {
    return (this->icao>orig.icao);

}
/**
 * @brief Getter Id
 * @return
 */
unsigned int Aerolinea::getId() const {
    return id;
}
/**
 * @brief Setter Id
 * @param id
 */
void Aerolinea::setId(unsigned int id) {
    Aerolinea::id = id;
}
/**
 * @brief Getter Icao
 * @return
 */
const string &Aerolinea::getIcao() const {
    return icao;
}
/**
 * @brief Setter Icao
 * @param icao
 */

void Aerolinea::setIcao(const string &icao) {
    Aerolinea::icao = icao;
}
/**
 * @brief Getter Nombre
 * @return
 */
const string &Aerolinea::getNombre() const {
    return nombre;
}
/**
 * @brief Setter Nombre
 * @param nombre
 */

void Aerolinea::setNombre(const string &nombre) {
    Aerolinea::nombre = nombre;
}
/**
 * @brief Getter Pais
 * @return
 */
const string &Aerolinea::getPais() const {
    return pais;
}
/**
 * @brief Setter Pais
 * @param pais
 */
void Aerolinea::setPais(const string &pais) {
    Aerolinea::pais = pais;
}
/**
 * @brief Getter Activo
 * @return
 */
bool Aerolinea::isActivo() const {
    return activo;
}
/**
 * @brief Setter Activo
 * @param activo
 */
void Aerolinea::setActivo(bool activo) {
    Aerolinea::activo = activo;
}
/**
 * @brief Getter Con Acceso al private aerorutas
 * @return
 */
const deque<Ruta *> &Aerolinea::getAerorutas() const {
    return aerorutas;
}
/**
 * @brief Setter AeroRutas
 * @param aerorutas
 */

void Aerolinea::setAerorutas(const deque<Ruta *> &aerorutas) {
    Aerolinea::aerorutas = aerorutas;
}
/**
 *  @brief Metodo que añade Vuelos
 * @param v
 * @return
 */
Vuelo* Aerolinea::addVuelo(Vuelo *v) {
    //Comprobacion de nulos
    if(v->getAerolinea() && v->getAirpDest() && v->getAirpOrigin())

    return nullptr;
}



