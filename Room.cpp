#include <vector>
#include <string>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <sstream>
//#include <time.h>


#include "Particula.h"
#include "Archivo.h"
#include "set_particulas.h"
#include "Cell_index.h"
#include "Fuerzas.h"
#include "mover_verlet.h"





using namespace std;

int main(int argc, char *argv[]){

  vector<Particula> particulas;

  //Estos se pueden modificar manualmente
    double kn = 1000;
    double kt = 3000;

    double L = 10;
    double W = 2;
    double D = 0.5;

    double max_time = 15;
    double dt = 0.0001;
    double dt_escritura = 0.25;

    int N_deseado = 200;
    double v_deseada = 5;
    double tau = 0.9;
    double masa = 0.01;

    double radio_base = 0.05;
    double amplitud_radio = 0.01;
    double frecuencia = 5;

    int seed = 44;
    string path = "./Output/";


  if (argc == 18){
    kn = atof(argv[1]);
    kt = atof(argv[2]);

    L = atof(argv[3]);
    W = atof(argv[4]);
    D = atof(argv[5]);

    N_deseado = atoi(argv[6]);
    v_deseada = atof(argv[7]);
    tau = atof(argv[8]);
    masa = atof(argv[9]);

    max_time = atof(argv[10]);
    dt = atof(argv[11]);
    dt_escritura = atof(argv[12]);

    radio_base = atof(argv[13]);
    amplitud_radio = atof(argv[14]);
    frecuencia = atof(argv[15]);

    seed = atoi(argv[16]);
    path = argv[17];

  }


  srand(seed);

  string nombre_salida = "Room";
  int num_escrito = 0;
  ofstream t_salidas(path+"Tiempos_salida.txt", ofstream::app);


  int N;

  particulas = ubicar_particulas(W, L, D,N_deseado, radio_base, amplitud_radio,frecuencia,v_deseada,tau,masa);//tengo las particulas en sus posiciones iniciales
  N = particulas.size();

  vector <bool> ya_salidas;
  ya_salidas.resize(N);
  for (int p=0; p < N; p++){
    ya_salidas[p] = 0;
  }

  cout << N <<"\n";
  vector<vector<int> > vecinos;
  escribir_posiciones(path,nombre_salida+"_0.txt",particulas,0);
  vector<double> fuerzas;


  double t = 0;
  int cont_escritura = 0;
  int max_pasos = int(max_time/dt);
  cout << int(dt_escritura/dt)<<endl;
  string tiempo_formated;
//  clock_t timer;
 // timer = clock();
  for (int i = 0; i < max_pasos; i++){ //for de pasos temporales
    
    vecinos = calcular_vecinos(particulas,W,L);
    mover_particulas(particulas,vecinos,dt, kn, kt, L, W, D,t);
    
    t += dt;
    cont_escritura++;



//Anotar tiempo de las particulas que salieron:
  for (int p = 0; p < particulas.size();p++){
    if (particulas[p].get_pos_y() + particulas[p].get_radio() < 0 && !ya_salidas[p]){
      anotar_t_salida(t_salidas,t);
      ya_salidas[p] = 1;
    }
  }
//Reingresar partículas luego de que ya salieron
    for (int p = 0; p < particulas.size();p++){
      if (particulas[p].get_pos_y() + particulas[p].get_radio() < -L/10){
        reubicar_particula(particulas,p,W,L);
        ya_salidas[p]=0;
       

      }
    }

    if (cont_escritura == int(dt_escritura/dt) ){
      num_escrito++;
      cout<< nombre_salida + "_" + to_string(num_escrito) <<".txt" << " escrito." <<endl;
      escribir_posiciones(path,nombre_salida +"_"+ to_string(num_escrito) +".txt",particulas,t);
      cont_escritura = 0;

    }
  }
  t_salidas.close();
  cout << "Fin" << endl;

//  timer = clock() - timer;
//  printf ("%f seconds).\n",((float)timer)/CLOCKS_PER_SEC);
  return 0;
}
