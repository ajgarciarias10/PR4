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
#pragma  region Cargar Vuelos
#pragma  endregion
    cout<< "Tamaño Aerolineas: " << vl.tamaAirlines() <<endl
        << "Tamaño aeropuertos: " << vl.tamaAeropuertos() << endl
        << "Tamaño rutas: " << vl.tamaRutas() << endl
       <<"Tamaño Vuelos: "<< vl.tamaVuelos() << endl <<endl;
//BuscaVuelos
 vector<Vuelo*> vectorsito = vl.buscaVuelos("RYR5318");
    for (int i = 0; i < vectorsito.size(); ++i) {
        cout<< vectorsito[i]->getFlightNumber()<<endl<<endl;

    }
//Metodo BuscaAeroPor
    Fecha f(13,04,18);
    vector<Vuelo*> vectorsito21 = vl.vuelosOperadosPor("RYR5318",f);
    for (int i = 0; i < vectorsito.size(); ++i) {
        cout<< vectorsito21[i]->getDatoMeteo()<<endl<<endl;

    }

    set<string> vuelos = vl.buscaVuelosDestAerop("ES", "LHR");
    set<string>::iterator setter = vuelos.begin();
    for (setter; setter != vuelos.end(); ++setter) {
        // Resto del bucle
        cout<<*setter<<endl;
    }
/*
try{
#pragma region Visualiza toda la información de la aerolínea Ryanair, RYR

    cout<<endl<<"------------------------------Información de la aerolínea Ryanair------------------------------"<<endl<<endl;
    Aerolinea aerolinea =  vl.buscaAerolinea("RYR");
    cout<<"Id: "<<aerolinea.getId() <<" Aerolinea: "<< aerolinea.getNombre() <<  " Icao : "<<  aerolinea.getIcao() << " Pais: " << aerolinea.getPais() << endl;

#pragma endregion

#pragma  region Muestra todas las aerolíneas activas.

    cout<<endl<<"--------------------------Aerolíneas activas--------------------------"<<endl<<endl;
    vector<Aerolinea*> vectorActivas(vl.buscaAerolineasActiva());
    cout<<"Numero de aerolineas activas: "<< vectorActivas.size()<<endl<<endl;
    for (int i = 0; i < vectorActivas.size(); ++i) {
        string activo = " ";
        vectorActivas[i]->isActivo() ? activo = "Si" : activo ="No";
        cout<< "Id: "<< vectorActivas[i]->getId() << " Nombre: "<< vectorActivas[i]->getNombre()<< " Pais: " << vectorActivas[i]->getPais() <<" Activo: "<< activo <<endl;
    }

#pragma endregion

#pragma  region Busca todos los aeropuertos (origen) en los que opera Iberia Airlines, con icao IBE

    cout<<endl<<"------------------------------Aeropuertos (origen) en los que opera Iberia Airlines-------------------------------"<<endl<<endl;
    Aerolinea iberiaAirlines = vl.buscaAerolinea("IBE");
    vector<Aeropuerto*> aeropuertosIberia  =  iberiaAirlines.getAeropuertosOrig();
    cout<<"Numero de aeropuertos que operan con iberia: "<< aeropuertosIberia.size()<<endl<<endl;
    for (int j = 0; j < aeropuertosIberia.size(); ++j) {
        cout<<"Id: "<<aeropuertosIberia[j]->getId()<<" Aeropuerto: "<< aeropuertosIberia[j]->getNombre() <<  " Iata : "
            <<  aeropuertosIberia[j]->getIata() << " Iso Pais: " << aeropuertosIberia[j]->getIsoPais() <<endl;

    }

#pragma  endregion

#pragma  region   Busca todas las rutas operadas por Iberia Airlines con origen en el aeropuerto de Málaga(AGP).

    cout<<endl<<"-----------------Rutas operadas por Iberia Airlines con origen en el aeropuerto de Málaga(AGP)-----------------"<<endl<<endl;
    //AeroRutasAGP
    deque<Ruta*> aerorutasAGP = iberiaAirlines.getRutasAeropuerto("AGP");
    deque<Ruta*> aerorutasMalaga;
    for (int j = 0; j < aerorutasAGP.size(); ++j) {
        if(aerorutasAGP[j]->getOrigin()->getNombre() == "Málaga-Costa del Sol Airport"){
            aerorutasMalaga.push_back(aerorutasAGP[j]);
        }
    }

    cout<<"Numero de rutas: "<< aerorutasMalaga.size()<<endl<<endl;
    for (int i = 0; i < aerorutasMalaga.size(); ++i) {
        cout<<"Origen: "<<aerorutasMalaga[i]->getOrigin()->getNombre()<<"---> Destino: "<< aerorutasMalaga[i]->getDestination()->getNombre() <<endl;

    }

#pragma  endregion

#pragma region Aerolíneas que operan en España.

        cout<<endl<<"------------------------------Aerolíneas que operan en España------------------------------"<<endl<<endl;
        vector<Aerolinea*> aerolineaEsp =  vl.getAerolineasPais("Spain");
        cout<<"Numero de aerolineas que operan en España: "<<aerolineaEsp.size()<<endl<<endl;
        for (int i = 0; i < aerolineaEsp.size(); ++i) {
            cout<< "Id: "<< aerolineaEsp[i]->getId() << " Nombre: "<< aerolineaEsp[i]->getNombre()<< " Pais: " << aerolineaEsp[i]->getPais() <<endl;
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
    */
    return 0;
}
