//****************************
#include <cstdio>           //
#include <iostream>         //   
#include <stdlib.h>         //   
#include <fstream>          //  
#include <stdio.h>          // Bibliotecas
#include "bitmap_image.hpp" //        
#include "ImageBMP.hpp"     //      
#include <iostream>         //   
#include <string>           //
//****************************

//***************************************
#ifdef __cplusplus                      //        
extern "C"                              //
{                                       //                     
   #endif                               //
      void negativo(unsigned char* a);  //                           
      void black(unsigned char* a);     // Externos   
      void lentes3D(unsigned char* a);  //                            
      void verano(unsigned char* a);    //  
      void serpia(unsigned char* a);    //                          
   #ifdef __cplusplus                   //          
}                                       //                     
#endif                                  //
//************************************************************
void apply(unsigned char* a,void (*func)(unsigned char* a)); //
//************************************************************

//*******************************************************************************//
//                                 MAIN                                         //
//******************************************************************************//
int main(int argc, char *argv[]) {

   system("clear");
   printf("loading...\n");

   if(argc > 2)
   {
      std::string filtro_name = argv[1];
      filtro_name.resize(filtro_name.size()-4);
      
      void (*filtro_opcion)(unsigned char*f) = 0;
      int opcion =  *argv[2]-48;

      switch(opcion)
      {
         case 1: filtro_name += "_NEGATIVE"; filtro_opcion = negativo; break;
         case 2: filtro_name += "_B&W"; filtro_opcion = black; break;
         case 3: filtro_name += "_3D"; filtro_opcion = lentes3D; break;
         case 4: filtro_name += "_VERANO"; filtro_opcion = verano; break;
         case 5: filtro_name += "_SERPIA"; filtro_opcion = serpia; break;
      }
      filtro_name += ".bmp";

      bitmap_image image(argv[1]);
      ImageBMP copia(0,0);
      copia.Read(argv[1]);

      const unsigned int altura = image.height();
      const unsigned int anchura = image.width();

      ImageBMP newImag(anchura,altura);

      //***Inicio***de***aplicacion***de***filtro***
      for (std::size_t y = 0; y < anchura; ++y)
      {
         for (std::size_t x = 0; x < altura; ++x)
         {
            Color rgb = copia.getColor(y,x);
            
            unsigned char filter[3];
            filter[0] = rgb.rojo;
            filter[1] = rgb.verde;
            filter[2] = rgb.azul;

            apply(filter, filtro_opcion);// <- 1 pixel a la vez

            rgb.rojo  = filter[0];
            rgb.verde = filter[1];
            rgb.azul  = filter[2];

            newImag.setColor(x, y, rgb);
         }
      }
      newImag.Exportar(filtro_name);
      printf("filtro aplicado con exito! :D\n");
   }
   else
   {
      printf("\nERROR: no se envio imagen o filtro :|\n\n");
   }
   fgetc(stdin);
}

//***********************************************************//
void apply(unsigned char* a, void (*func)(unsigned char* a)) //
{                                                            //     
   func(a);                                                  //         
}                                                            //
//***********************************************************//
