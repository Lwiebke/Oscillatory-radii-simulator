#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Apr 28 13:15:58 2022

@author: lucas
"""

import os
    
here = os.getcwd()


configuraciones = ["config1.txt", "config2.txt"]


#path_to_bin:  path to the compiled file. 
path_to_bin = "./Room.exe"


for configuracion in configuraciones:
    path = here + "/outputs/" + configuracion[0:-4]
    comando1 = "mkdir -p "+path
    os.system(comando1)
    with open(configuracion) as conf:
        Kn = conf.readline().split(" ")[2].strip()
        Kt = conf.readline().split(" ")[2].strip()
        
        L = conf.readline().split(" ")[2].strip()
        W = conf.readline().split(" ")[2].strip()
        D = conf.readline().split(" ")[2].strip()
        
        N = conf.readline().split(" ")[2].strip()
        v_deseada = conf.readline().split(" ")[2].strip()
        tau = conf.readline().split(" ")[2].strip()
        masa = conf.readline().split(" ")[2].strip()
        
        
        tiempo_fin = conf.readline().split(" ")[2].strip()
        dt = conf.readline().split(" ")[2].strip()
        dt_escritura = conf.readline().split(" ")[2].strip()
        
       
        
        radio_base = conf.readline().split(" ")[2].strip()
        amplitud = conf.readline().split(" ")[2].strip()
        frecuencia = conf.readline().split(" ")[2].strip()
        
        seed = conf.readline().split(" ")[2].strip()
        
        
        
        
    comando = (path_to_bin +" "+Kn+" "+Kt+" "+L+" "+W+" "+D+" "
                + N + " " + v_deseada + " " + tau+ " " + masa +" " 
                +tiempo_fin+" "+dt+" "+ dt_escritura + " " 
                +radio_base + " " +amplitud + " " +frecuencia +" "
                + seed +" "+path+"/") 
    os.system(comando)
