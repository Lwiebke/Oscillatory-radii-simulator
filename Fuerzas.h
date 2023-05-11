#include <vector>
#include <math.h>

//#include "Particula.h"


//es para calcular las fuerzas que recibe cada Particula

using namespace std;


vector<double> calcular_fuerzas(vector <Particula> &objetos, int id, vector<int> vecinos, double kn, double kt,double W, double D){


  vector<double> fuerza;
  int N = vecinos.size();
  int id_vec;
  double superposicion, d;
  double fn[] = {0,0};
  double ft[] = {0,0};
  double v_rel[] = {0,0};
  double en[] = {0,0};
  double et[] = {0,0};
  fuerza = objetos[id].get_fuerza_migratoria();




  for (int i = 0; i < N; i++){


    //datos necesarios
    double fn[] = {0,0};
    double ft[] = {0,0};
    double en[] = {0,0};
    double et[] = {0,0};
    id_vec = vecinos[i];
    d = sqrt(pow(objetos[id_vec].get_pos_x() - objetos[id].get_pos_x(),2)+pow(objetos[id_vec].get_pos_y() - objetos[id].get_pos_y(),2));
    superposicion = (objetos[id].get_radio() + objetos[id_vec].get_radio()) - d;
    v_rel[0] = objetos[id].get_vel_x() - objetos[id_vec].get_vel_x();
    v_rel[1] = objetos[id].get_vel_y() - objetos[id_vec].get_vel_y();
    en[0] = (objetos[id_vec].get_pos_x() - objetos[id].get_pos_x())/d;
    en[1] = (objetos[id_vec].get_pos_y() - objetos[id].get_pos_y())/d;
    et[0] = -en[1];
    et[1] = en[0];
//normal

    if (superposicion > 0){

      fn[0] = -kn*superposicion*(en[0]);
      fn[1] = -kn*superposicion*(en[1]);

//tangencial
      ft[0] = -kt*superposicion*(v_rel[0]*et[0]+v_rel[1]*et[1])*et[0];
      ft[1] = -kt*superposicion*(v_rel[0]*et[0]+v_rel[1]*et[1])*et[1];

    }
    fuerza[0] += fn[0] + ft[0];
    fuerza[1] += fn[1] + ft[1];

//añadir fuerza paredes
//fuerza normal del piso es Y en positivo, por lo tanto:

  }

  //base
  if (objetos[id].get_pos_y()-objetos[id].get_radio() < 0   && (objetos[id].get_pos_x() < (W/2)-(D/2) || objetos[id].get_pos_x() > (W/2)+(D/2) ) ){
    if(objetos[id].get_pos_y()>0){
      fuerza[1] += kn*(abs(objetos[id].get_pos_y()-objetos[id].get_radio()) );
    }
  }


  //paredes v
  if(objetos[id].get_pos_x()-objetos[id].get_radio() < 0){//choca pared vertical izquierda
    fuerza[0] += kn*abs(objetos[id].get_pos_x()-objetos[id].get_radio())   ;

  }

  if(objetos[id].get_pos_x()+objetos[id].get_radio() > W){//choca pared vertical derecha
    fuerza[0] +=  -kn*abs(W - (objetos[id].get_pos_x() + objetos[id].get_radio()) ) ;
  }


  return (fuerza);
}
