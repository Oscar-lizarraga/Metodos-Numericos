#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;
double *puntos_x,*puntos_y,**efes;

int main(){
  
    int i,j,nom_puntos;
    cout<<" Diferencias Divididas de Newton"<<endl;
    cout <<" Calcula el polinomio interpolador de una funcion" << endl;
    
    for(int i=0;i<87;i++)cout<<".";
    cout << "\nIngrese el numero de puntos: ";
    cin >> nom_puntos;
  
    //Creamos memoria dinamica
    efes=new double *[nom_puntos];
    for(i=0;i<nom_puntos;i++)efes[i]= new double[nom_puntos-(i)];
    puntos_x = new double [nom_puntos];
    puntos_y = new double [nom_puntos];
  
    //Ingresamos las cordenadas de los puntos
    for(i=0; i<nom_puntos;i++){
        cout<<"Ingrese x("<<i<<")=";
        cin>>puntos_x[i];
    }
    cout<<"\nf(Xi)"<<endl;
    for(i=0; i<nom_puntos;i++){
        cout<<"Ingrese f("<<i<<")=";
        cin>>puntos_y[i];
    }

    //Tabla 1
    cout<<"\nXi\t";
    cout<<fixed<<setprecision(3);
    for(i=0;i<nom_puntos;i++)cout<<puntos_x[i]<<"\t";
    cout<<"\nf(Xi)\t";
    for(i=0;i<nom_puntos;i++)cout<<puntos_y[i]<<"\t";

    //Tabla 2
    cout<<endl;
    cout<<"\ni\t\t\t\t";
    for(i=1;i<nom_puntos;i++)cout<<i<<"\t\t";
    cout<<"\nj\tXi\tf(Xi)\t\t";
    for(i=1;i<nom_puntos;i++)cout<<i<<".\t\t";
    cout<<endl;

    //Operaciones
    //Igualamos las cordenas en y de los puntos y se lo igualamos a nuestra matriz
    for(j=0;j<nom_puntos;j++)efes[0][j]=puntos_y[j];
    for(i=1; i<nom_puntos; i++){
        for(j=0; j<nom_puntos-i; j++){
            efes[i][j]=(efes[i-1][j+1]-efes[i-1][j])/(puntos_x[i+j]-puntos_x[j]);
        }
    }
    
    //Imprimir
    for(i=0; i<nom_puntos;i++){
        cout<<i<<"\tX"<<i<<"="<<setprecision(1)<<puntos_x[i]<<"\t"<<setprecision(3);
        for(j=0;j<nom_puntos-i;j++){
            cout<<"F"<<i<<j<<"="<<efes[j][i]<<"\t";
        }
        cout<<endl;
    }

    //Creamos polinomio
    cout<<"\nEl polinomio interpolar es igual a: ";
    for(i=0;i<nom_puntos;i++){
        if(efes[i][0]>0 || efes[i][0]<0){
            if(i<nom_puntos && i>0)cout<<" + ";
            cout<<setprecision(2)<<efes[i][0];
            for(j=0;j<i;j++){
                cout<<"(x-"<<puntos_x[j]<<")";
            }

        }
    }

    //Evaluar puntos
    int n_puntos,k;
    double x,r,total;
    cout<<"\n\nCuantos puntos deseas evaluar?: ";
    cin>>n_puntos;
    for(k=0; k<n_puntos;k++){
        cout<<"\nIngresa punto x"<<char(97+k)<<"= ";
        cin>>x;
        for(i=0;i<nom_puntos;i++){
            if(i==0)total=efes[0][0];
            else{
                for(j=0;j<i;j++){
                    if(j==0)r=efes[i][0];
                    r*=(x-puntos_x[j]);//Es igual a: r=r*(x-puntos_x[j]);
                }
                total+=r;//Es igual a total= total+r;
            }
        }
        cout<<"x"<<char(97+k)<<"="<<total<<endl;
    }
    cout<<"\n\n\n";
    system("pause");
}
