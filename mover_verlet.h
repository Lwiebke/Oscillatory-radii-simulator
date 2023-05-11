


void mover_particulas(vector<Particula> &particulas, vector<vector<int> >& vecinos,double dt, double kn,double kt, double L, double W, double D, double t){



 
  vector<double> fuerzas;

  double pos_xa;
  double pos_ya;


  vector<double> pos_x_ant(particulas.size());
  vector<double> pos_y_ant(particulas.size());

  vector<double> fuerza_x(particulas.size());
  vector<double> fuerza_y(particulas.size());


  for (int i=0;i<particulas.size();i++){

    pos_x_ant[i] =  particulas[i].get_pos_x_a();
    pos_y_ant[i] =  particulas[i].get_pos_y_a();



    particulas[i].set_pos_x_a(particulas[i].get_pos_x());
    particulas[i].set_pos_y_a(particulas[i].get_pos_y());

    fuerzas = calcular_fuerzas(particulas,i,vecinos[i], kn,kt,W,D);

    fuerza_x[i] = fuerzas[0];
    fuerza_y[i] = fuerzas[1];

    }


    for (int i=0;i<particulas.size();i++){

    particulas[i].set_pos_x(  2*particulas[i].get_pos_x() - pos_x_ant[i] + pow(dt,2)*fuerza_x[i]/particulas[i].get_masa()   );
    particulas[i].set_pos_y(  2*particulas[i].get_pos_y() - pos_y_ant[i] + pow(dt,2)*fuerza_y[i]/particulas[i].get_masa()   );

    particulas[i].set_vel_x( (particulas[i].get_pos_x() - pos_x_ant[i])/(2*dt) );
    particulas[i].set_vel_y( (particulas[i].get_pos_y() - pos_y_ant[i])/(2*dt) );

    particulas[i].set_radio(particulas[i].actualizar_radio(t));


    }




}
