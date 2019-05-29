#include<iostream>
#include<eigen3/Eigen/Dense>
double producto(Eigen::Matrix4f X,Eigen::Matrix4f Y);//función que calcula la traza entre dos de una matriz.
int main()
{
  Eigen::Matrix4f Jx,Jy,Jz,Kx,Ky,Kz;
  Eigen::MatrixXd Kill(6,6);
  //generadores de Rotaciones 
  Jx << 0,0,0,0
    ,0,0,0,0
    ,0,0,0,1,
    0,0,-1,0;
  Jy << 0,0,0,0,
    0,0,0,-1,
    0,0,0,0,
    0,1,0,0;
  Jz << 0,0,0,0
    ,0,0,1,0,
    0,-1,0,0,
    0,0,0,0;
  //generadores de Boosts
  Kx << 0,-1,0,0,
    -1,0,0,0,
    0,0,0,0,
    0,0,0,0;
  Ky << 0,0,-1,0,
    0,0,0,0,
    -1,0,0,0,
    0,0,0,0;
  Kz << 0,0,0,-1,
    0,0,0,0,
    0,0,0,0,
    -1,0,0,0;
  Kill(0,0)=producto(Jx,Jx);
  Kill(0,1)=producto(Jx,Jy);
  Kill(0,2)=producto(Jx,Jz);
  Kill(0,3)=producto(Jx,Kx);
  Kill(0,4)=producto(Jx,Ky);
  Kill(0,5)=producto(Jx,Kz);

  Kill(1,0)=producto(Jy,Jx);
  Kill(1,1)=producto(Jy,Jy);
  Kill(1,2)=producto(Jy,Jz);
  Kill(1,3)=producto(Jy,Kx);
  Kill(1,4)=producto(Jy,Ky);
  Kill(1,5)=producto(Jy,Kz);

  Kill(2,0)=producto(Jz,Jx);
  Kill(2,1)=producto(Jz,Jy);
  Kill(2,2)=producto(Jz,Jz);
  Kill(2,3)=producto(Jz,Kx);
  Kill(2,4)=producto(Jz,Ky);
  Kill(2,5)=producto(Jz,Kz);

  Kill(3,0)=producto(Kx,Jx);
  Kill(3,1)=producto(Kx,Jy);
  Kill(3,2)=producto(Kx,Jz);
  Kill(3,3)=producto(Kx,Kx);
  Kill(3,4)=producto(Kx,Ky);
  Kill(3,5)=producto(Kx,Kz);

  Kill(4,0)=producto(Ky,Jx);
  Kill(4,1)=producto(Ky,Jy);
  Kill(4,2)=producto(Ky,Jz);
  Kill(4,3)=producto(Ky,Kx);
  Kill(4,4)=producto(Ky,Ky);
  Kill(4,5)=producto(Ky,Kz);

  Kill(5,0)=producto(Kz,Jx);
  Kill(5,1)=producto(Kz,Jy);
  Kill(5,2)=producto(Kz,Jz);
  Kill(5,3)=producto(Kz,Kx);
  Kill(5,4)=producto(Kz,Ky);
  Kill(5,5)=producto(Kz,Kz);
    
  std::cout <<"métrica de Killing= \n"<< Kill <<std::endl;
  std::cout <<"inversa de la métrica de Killing= \n"<< Kill.inverse() <<std::endl;
  std::cout <<"Prueba métrica= \n"<< Kill.inverse()*Kill <<std::endl;

  
  return 0;
}
double producto(Eigen::Matrix4f X,Eigen::Matrix4f Y)
{
  int a;
  Eigen::Matrix4f S;
  S=X*Y;
  a=0;
  a=1/2.0*(S.trace());
  return a;
}

