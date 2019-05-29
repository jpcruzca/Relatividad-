#include<iostream>
#include<eigen3/Eigen/Dense>
Eigen::Matrix4f conmutador(Eigen::Matrix4f X,Eigen::Matrix4f Y);
int main()
{
  Eigen::Matrix4f Jx,Jy,Jz,Kx,Ky,Kz;//Generadores
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

  
  std::cout <<"conmutador [Jx,Jy] \n"<< conmutador(Jx,Jy) <<std::endl;
  std::cout <<"conmutador [Jx,Jz] \n"<< conmutador(Jx,Jz) <<std::endl;
  std::cout <<"conmutador [Jx,Kx] \n"<< conmutador(Jx,Kx) <<std::endl;
  std::cout <<"conmutador [Jx,Ky] \n"<< conmutador(Jx,Ky) <<std::endl;
  std::cout <<"conmutador [Jx,Kz] \n"<< conmutador(Jx,Kz) <<std::endl;

  std::cout <<"conmutador [Jy,Jx] \n"<< conmutador(Jy,Jx) <<std::endl;
  std::cout <<"conmutador [Jy,Jz] \n"<< conmutador(Jy,Jz) <<std::endl;
  std::cout <<"conmutador [Jy,Kx] \n"<< conmutador(Jy,Kx) <<std::endl;
  std::cout <<"conmutador [Jy,Ky] \n"<< conmutador(Jy,Ky) <<std::endl;
  std::cout <<"conmutador [Jy,Kz] \n"<< conmutador(Jy,Kz) <<std::endl;

  std::cout <<"conmutador [Jz,Jx] \n"<< conmutador(Jz,Jx) <<std::endl;
  std::cout <<"conmutador [Jz,Jy] \n"<< conmutador(Jz,Jy) <<std::endl;
  std::cout <<"conmutador [Jz,Kx] \n"<< conmutador(Jz,Kx) <<std::endl;
  std::cout <<"conmutador [Jz,Ky] \n"<< conmutador(Jz,Ky) <<std::endl;
  std::cout <<"conmutador [Jz,Kz] \n"<< conmutador(Jz,Kz) <<std::endl;
  
  std::cout <<"conmutador [Kx,Jx] \n"<< conmutador(Kx,Jx) <<std::endl;
  std::cout <<"conmutador [Kx,Jy] \n"<< conmutador(Kx,Jy) <<std::endl;
  std::cout <<"conmutador [Kx,Jz] \n"<< conmutador(Kx,Jz) <<std::endl;
  std::cout <<"conmutador [Kx,Ky] \n"<< conmutador(Kx,Ky) <<std::endl;
  std::cout <<"conmutador [Kx,Kz] \n"<< conmutador(Kx,Kz) <<std::endl;
  
  std::cout <<"conmutador [Ky,Jx] \n"<< conmutador(Ky,Jx) <<std::endl;
  std::cout <<"conmutador [Ky,Jy] \n"<< conmutador(Ky,Jy) <<std::endl;
  std::cout <<"conmutador [Ky,Jz] \n"<< conmutador(Ky,Jz) <<std::endl;
  std::cout <<"conmutador [Ky,Kx] \n"<< conmutador(Ky,Kx) <<std::endl;
  std::cout <<"conmutador [Ky,Kz] \n"<< conmutador(Ky,Kz) <<std::endl;
  
  std::cout <<"conmutador [Kz,Jx] \n"<< conmutador(Kz,Jx) <<std::endl;
  std::cout <<"conmutador [Kz,Jy] \n"<< conmutador(Kz,Jy) <<std::endl;
  std::cout <<"conmutador [Kz,Jz] \n"<< conmutador(Kz,Jz) <<std::endl;
  std::cout <<"conmutador [Kz,Kx] \n"<< conmutador(Kz,Kx) <<std::endl;
  std::cout <<"conmutador [Kz,Ky] \n"<< conmutador(Kz,Ky) <<std::endl;
  
  return 0;
}
Eigen::Matrix4f conmutador(Eigen::Matrix4f X,Eigen::Matrix4f Y)
{
   Eigen::Matrix4f S;
   S=X*Y-Y*X;
   return S;
}
