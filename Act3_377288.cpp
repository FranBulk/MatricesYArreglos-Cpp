#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdio.h>
#include<fstream>
using namespace std;
int Contrasenia();
char Menu();
void Validacion1(int vector[100], int n);
int Validacion2(int vector2[30], int n, int num);
float PromedioM(float matriz1[10][10], int a, int b);
void MostrarL(long int matriz2[10][10], int a, int b);
void NMCFila(long int matriz2[10][10], int a, int b);
void Creves(string reves, int t);
int Cuenta(char vector3[30], char l, int n);
struct Producto
{
    int clave;
    string descripcion;
    int cantidad;
    float costo;
};
void MostrarE(struct Producto p);
void MostrarPE(struct Producto *p);
void MostrarV(struct Producto p[100], int n);
void Operaciones(float *p2,int n);
void AniosDe(string *numempl, string *nom, long int *anio);
void EscribirC(float cal[50], int n);
void EvaluacionC();
int main()
{
    if (Contrasenia()==1)
    {
        char m;
        while((m!='N')&&(m!='n'))
        {
            system("cls");
            m=Menu();
            switch (m)
            {
            case 'A': case 'a':
            {
                int vector[100], n=0, i;
                cout<<"VALIDADORA DE NUMEROS POSITIVOS, NEGATIVOS Y CERO"<<endl;
                do
                {
                    cout<<"CUANTOS NUMEROS"<<endl;
                    cin>>n;
                    if((n<=0)||(n>100))
                    {
                        cout<<"NUMEROS ENTRE EL 1 AL 100"<<endl;
                    }
                }while((n<=0)||(n>100));
                cout<<"ALMACENAR LOS DATOS"<<endl;
                for(i=0;i<n;i++)
                {
                    cout<<"DAME EL NUMERO"<<endl;
                    cin>>vector[i];
                }
                Validacion1(vector,n);
                break;
            }
            case 'B': case 'b':
            {
                int vector2[30], i, n=0, num=0, c=0;
                cout<<"BUSCADORA DE NUMEROS"<<endl;
                do
                {
                    cout<<"DAME LA CANTIDAD DE NUMEROS"<<endl;
                    cin>>n;
                    if ((n<=0)||(n>30))
                    {
                        cout<<"SOLO NUMEROS ENTRE EL 1 Y EL 30"<<endl;
                    }
                    
                } while ((n<=0)||(n>30));
                cout<<"ALMACENAR LOS DATOS"<<endl;
                for (i=0;i<n;i++)
                {
                    cout<<"DAME EL NUMERO"<<endl;
                    cin>>vector2[i];
                }
                cout<<"CUAL ES EL NUMERO QUE DESEA BUSCAR"<<endl;
                cin>>num;
                c=Validacion2(vector2, n, num);
                if (c!=0)
                {
                    cout<<"EL NUMERO ["<<num<<"] FUE ENCONTRADO ["<<c<<"] VECES"<<endl;
                }
                else
                {
                    cout<<"EL NUMERO ["<<num<<"] NO FUE ENCONTRADO EN EL ARREGLO"<<endl;
                }
                break;
            }
            case 'C': case 'c':
            {
                int i, j;
                float matriz1[10][10], a=0, b=0, r=0; //a= filas, b= columnas
                cout<<"MATRIZ DE PROMEDIO DE ALUMNOS"<<endl;
                do
                {
                    cout<<"DAME EL NUMERO DE FILAS"<<endl;
                    cin>>a;
                    cout<<"DAME EL NUMERO DE COLUMNAS"<<endl;
                    cin>>b;
                    if ((a>10)||(a<=0)||(b<=0)||(b>10))
                    {
                        cout<<"SOLO NUMEROS DEL 1 AL 10"<<endl;
                    }
                } while ((a>10)||(a<=0)||(b<=0)||(b>10));
                for (i=0;i<a;i++) //Filas
                {
                    for (j=0;j<b;j++) //Columnas
                    {
                        do
                        {
                            cout<<"DAME EL VALOR ["<<i<<","<<j<<"]"<<endl;
                            cin>>matriz1[i][j];
                            if ((matriz1[i][j]>10)||(matriz1[i][j]<=0))
                            {
                                cout<<"SOLO NUMEROS DEL 0 AL 10"<<endl;
                            }
                        } while ((matriz1[i][j]>10)||(matriz1[i][j]<0));
                    }
                }
                r=PromedioM(matriz1, a, b);
                cout<<"EL PROMEDIO DE LA MATRIZ ES: "<<r<<endl;
                break;
            }
            case 'D': case 'd':
            {
                long int matriz2[10][10];
                int a=0, b=0, i, j;
                cout<<"MATRIZ DE MULTIPLOS DE 5"<<endl;
                do
                {
                    cout<<"DAME EL NUMERO DE FILAS"<<endl;
                    cin>>a;
                    cout<<"DAME EL NUMERO DE COLUMNAS"<<endl;
                    cin>>b;
                    if ((a>10)||(a<=0)||(b<=0)||(b>10))
                    {
                        cout<<"SOLO NUMEROS DEL 1 AL 10"<<endl;
                    }
                } while ((a>10)||(a<=0)||(b<=0)||(b>10));
                for (i=0;i<a;i++)
                {
                    for (j=0;j<b;j++)
                    {
                        cout<<"DAME EL VALOR ["<<i<<","<<j<<"]"<<endl;
                        cin>>matriz2[i][j];
                    }
                }
                MostrarL(matriz2,a,b);
                NMCFila(matriz2,a,b);
                break;
            }
            case 'E': case 'e':
            {
                string reves;
                cout<<"VOLTEADORA DE ORACIONES"<<endl;
                do
                {
                    cout<<"DAME EL TEXTO QUE DESEAS VOLTEAR"<<endl;
                    fflush(stdin);
                    getline(cin,reves);
                    if (reves.size()>100)
                    {
                        cout<<"EL TEXTO NO DEBE EXCEDER LOS 100 CARACTERES"<<endl;
                    }
                } while (reves.size()>100);
                Creves(reves,reves.size());
                break;
            }
            case 'F': case 'f':
            {
                int n, i;
                char vector3[30], l=0;
                cout<<"IMPRESORA DE CARACTERES Y CONTADORA DE LETRAS"<<endl;
                do
                {
                    cout<<"DAME EL NUMERO DE CARACTERES A IMPLEMENTAR"<<endl;
                    cin>>n;
                    if ((n<=0)||(n>30))
                    {
                        cout<<"SOLO NUMEROS DE ENTRE EL 1 Y EL 30"<<endl;
                    }
                } while ((n<=0)||(n>30));
                for (i=0;i<n;i++)
                {
                    cout<<"DAME EL VALOR NUMERO ["<<i+1<<"]"<<endl;
                    cin>>vector3[i];
                }
                cout<<"CUAL CARACTER DESEA SABER CUANTO SE REPITE?"<<endl;
                cin>>l;
                cout<<"TU CADENA ES: ";
                for (i=0;i<n;i++)
                {
                    cout<<vector3[i];
                }
                cout<<endl;
                cout<<"["<<Cuenta(vector3,l,n)<<"] ES EL NUMERO DE VECES QUE SE REPITE EL CARACTER: "<<l<<endl;
                break;
            }
            case 'G': case 'g':
            {
                struct Producto p;
                cout<<"CAPTURADORA DE ESTRUCTURA DE UN PRODUCTO"<<endl;
                cout<<"DIGITE LA CLAVE DEL PRODUCTO"<<endl;
                cin>>p.clave;
                cout<<"DE UNA DESCRIPCION DEL PRODUCTO"<<endl;
                fflush(stdin);
                getline(cin, p.descripcion);
                cout<<"DIGITE LA CANTIDAD DEL PRODUCTO EXISTENTE"<<endl;
                cin>>p.cantidad;
                cout<<"DIGITE EL COSTO"<<endl;
                cin>>p.costo;
                MostrarE(p);
                break;
            }
            case 'H': case 'h':
            {
                struct Producto *p=new(Producto);
                if(p==NULL)
                {
                    cout<<"PROBLEMA AL RESERVAR MEMORIA INTENTE OTRA VEZ :D"<<endl;
                }
                else
                {
                    cout<<"CAPTURADORA DE ESTRUCTURA DE UN PRODUCTO CON PUNTEROS"<<endl;
                    cout<<"DIGITE LA CLAVE DEL PRODUCTO"<<endl;
                    cin>>p->clave;
                    cout<<"DE UNA DESCRIPCION DEL PRODUCTO"<<endl;
                    fflush(stdin);
                    getline(cin,p->descripcion);
                    cout<<"DIGITE LA CANTIDAD DEL PRODUCTO EXISTENTE"<<endl;
                    cin>>p->cantidad;
                    cout<<"DIGITE EL COSTO"<<endl;
                    cin>>p->costo;
                    MostrarPE(p);
                    free(p);
                }
                break;
            }
            case 'I': case 'i':
            {
                int n, i;
                struct Producto p[100];
                cout<<"CAPTURADORA DE ESTRUCTURA DE VARIOS PRODUCTOS"<<endl;
                do
                {
                    cout<<"DAME EL NUMERO DE PRODUCTOS"<<endl;
                    cin>>n;
                    if ((n<=0)||(n>100))
                    {
                        cout<<"SOLO NUMEROS ENTRE EL 1 Y EL 100"<<endl;
                    }
                } while ((n<=0)||(n>100));
                for (i=0;i<n;i++)
                {
                    cout<<"DIGITE LA CLAVE DEL PRODUCTO ["<<i+1<<"]"<<endl;
                    cin>>p[i].clave;
                    cout<<"DE UNA DESCRIPCION DEL PRODUCTO ["<<i+1<<"]"<<endl;
                    fflush(stdin);
                    getline(cin,p[i].descripcion);
                    cout<<"DIGITE LA CANTIDAD DEL PRDUCTO ["<<i+1<<"]"<<endl;
                    cin>>p[i].cantidad;
                    cout<<"DIGITE EL COSTO DEL PRODUCTO ["<<i+1<<"]"<<endl;
                    cin>>p[i].costo;
                }
                MostrarV(p,n);
                break;
            }
            case 'J': case 'j':
            {
                int x=100;
                int *p1=NULL;
                p1=&x;
                cout<<"DIRECCION DE MEMORIA DEL PUNTERO: "<<p1<<endl;
                cout<<"DIRECCION DE MEMORIA DE X: "<<&x<<endl;
                *p1=(*p1)*1.25;
                cout<<"VALOR DEL PUNTERO: "<<*p1<<endl;
                cout<<"VALOR DE X: "<<x<<endl;
                break;
            }
            case 'K': case 'k':
            {
                float num[50], n, *p2=NULL;
                int i;
                cout<<"CALCULADORA VARIADA DE NUMEROS"<<endl;
                do
                {
                    cout<<"DIGITE CUANTOS NUMEROS DESEA COLOCAR"<<endl;
                    cin>>n;
                    if ((n<=0)||(n>50))
                    {
                        cout<<"SOLO NUMEROS ENTRE EL 1 Y EL 50"<<endl;
                    }
                } while ((n<=0)||(n>50));
                for (i=0;i<n;i++)
                {
                    do
                    {
                        cout<<"DAME LA CANTIDAD ["<<i+1<<"]"<<endl;
                        cin>>num[i];
                        if (num[0]==0)
                        {
                            cout<<"PARA SEGUIR, EL PRIMER NUMERO NO DEBE SER 0"<<endl;
                        }
                    } while (num[0]==0);
                }
                p2=&num[0];
                Operaciones(p2,n);
                break;
            }
            case 'L': case 'l':
            {
                cout<<"CALCULADORA DE ANIOS DE ANTIGUEDAD"<<endl;
                string *numempl=new(string), *nom=new(string);
                long int *anio=new(long int);
                cout<<"DAME EL NUMERO DEL EMPLEADO"<<endl;
                fflush(stdin);
                getline(cin,*numempl);
                cout<<"DAME EL NOMBRE DEL EMPLEADO"<<endl;
                fflush(stdin);
                getline(cin,*nom);
                do
                {
                    cout<<"DAME EL ANIO DE INGRESO"<<endl;
                    cin>>*anio;
                    if((*anio<1900)||(*anio>2023))
                    {
                        cout<<"SOLO AÑOS VALIDOS"<<endl;
                    }
                } while ((*anio<1900)||(*anio>2023));
                AniosDe(numempl,nom,anio);
                break;
            }
            case 'M': case 'm':
            {
                int n, i;
                cout<<"CALIFICACIONES DE UN GRUPO"<<endl;
                do
                {
                    cout<<"DAME EL NUMERO DE CALIFICACIONES"<<endl;
                    cin>>n;
                    if ((n<=0)||(n>50))
                    {
                        cout<<"SOLO NUMEROS ENTRE EL 1 Y EL 50"<<endl;
                    }
                } while ((n<=0)||(n>50));
                ofstream archsal("Califs.txt");
                if (!archsal.is_open())
                {
                    cout<<"ERROR EN ABRIR EL TEXTO :C"<<endl;
                    return 0;
                }
                for (i=0;i<n; i++)
                {
                    float calif=0;
                    cout<<"INGRESE LA CALIFICACION: ["<<i+1<<"]"<<endl;
                    cin>>calif;
                    archsal<<calif<<endl;
                }
                archsal.close();
                ifstream archent("Califs.txt");
                if (!archent.is_open())
                {
                    cout<<"ERROR EN ABRIR EL TEXTO :C"<<endl;
                }
                float califis;
                int a=0,r=0;
                while (archent>>califis)
                {
                    if (califis>7.0)
                    {
                        a++;
                    }
                    else
                    {
                        r++;
                    }
                }
                cout<<"CANTIDAD DE ALUMNOS APROBADOS: ["<<a<<"]"<<endl;
                cout<<"CANTIDAD DE ALUMNOS REPROBADOS: ["<<r<<"]"<<endl;
                break;
            }
            case 'N': case 'n':
            {
                cout<<"VUELVA PRONTO"<<endl;
                break;
            }
            default:
            {
                cout<<"SOLO LETRAS VALIDAS"<<endl;
                break;
            }
            }
            system("pause");
        }
    }
    else
    {
        cout<<"ACCESO DENEGADO"<<endl;
    }
    return 0;
}
int Contrasenia()
{
    int i=3, c=0;
    string contra, contrac="Franco";
    while((contra!=contrac)&&(i!=0))
    {
        cout<<"DAME LA CONTRASENIA"<<endl;
        fflush(stdin);
        getline(cin,contra);
        if (contra!=contrac)
        {
            cout<<"CONTRASENIA INCORRECTA"<<endl;
            cout<<"LE QUEDAN ["<<i-1<<"] INTENTOS"<<endl;
        }
        i--;
    }
    if (contra==contrac)
    {
        c=1;
    }
    else
    {
        c=0;
    }
    return c;
}
char Menu()
{
    char m;
    cout<<"==================MENU======================"<<endl;
    cout<<"A. VECTOR POSITIVOS, NEGATIVOS Y CEROS"<<endl;
    cout<<"B. BUSQUEDA DE UN VECTOR"<<endl;
    cout<<"C. MATRIZ PROMEDIO DE ESTUDIANTES"<<endl;
    cout<<"D. MATRIZ NUMEROS MULTIPLOS DE 5"<<endl;
    cout<<"E. CADENA AL REVES"<<endl;
    cout<<"F. CADENA CUENTA LETRAS"<<endl;
    cout<<"G. REGISTROS"<<endl;
    cout<<"H. PUNTEROS A REGISTROS"<<endl;
    cout<<"I. REGISTROS ARREGLOS"<<endl;
    cout<<"J. PUNTEROS"<<endl;
    cout<<"K. ARREGLOS Y PUNTEROS"<<endl;
    cout<<"L. PUNTEROS ANTIGUEDAD"<<endl;
    cout<<"M. ARCHIVOS"<<endl;
    cout<<"N. SALIR"<<endl;
    cout<<"============================================"<<endl;
    cout<<"QUE DESEA HACER?"<<endl;
    cin>>m;
    return m;
}
void Validacion1(int vector[100], int n)
{
    int i, cp=0, cn=0, cc=0;
    for(i=0;i<n;i++)
    {
        if (vector[i]<0)
        {
            cn++;
        }
        else if (vector[i]>0)
        {
            cp++;
        }
        else
        {
            cc++;
        }
    }
    cout<<"NUMERO DE POSITIVOS ["<<cp<<"]"<<endl;
    cout<<"NUMERO DE NEGATIVOS ["<<cn<<"]"<<endl;
    cout<<"NUMERO DE CEROS     ["<<cc<<"]"<<endl;
}
int Validacion2(int vector2[30], int n, int num)
{
    int i, c=0;
    for (i=0;i<n;i++)
    {
        if (vector2[i]==num)
        {
            c++;
        }
    }
    return c;
    
}
float PromedioM(float matriz1[10][10], int a, int b)
{
    int i, j;
    float s=0, t=0, r=0;
    for (i=0;i<a;i++)
    {
        for (j=0;j<b;j++)
        {
            s=s+matriz1[i][j];
            t++;
        }
    }
    r=s/t;
    return r;
}
void MostrarL(long int matriz2[10][10], int a, int b)
{
    int i, j;
    cout<<"LA MATRIZ ES: "<<endl;
    for (i=0;i<a;i++)
    {
        for (j=0;j<b;j++)
        {
            cout<<"["<<matriz2[i][j]<<"]";
        }
        cout<<endl;
    }
}
void NMCFila(long int matriz2[10][10], int a, int b)
{
    int i, j, cc=0;
    cout<<"==========================================="<<endl;
    for (i=0;i<a;i++)
    {
        for (j=0;j<b;j++)
        {
            cout<<"["<<matriz2[i][j]<<"]";
            if ((matriz2[i][j]%5==0)&&(matriz2[i][j]!=0))
            {
                cc++;
            }
        }
        cout<<" => ["<<cc<<"] MULTIPLOS DE 5"<<endl;
        cc=0;
    }
}
void Creves(string reves, int t)
{
    int i;
    for (i=0;i<=t;i++)
    {
        cout<<reves[t-i];
    }
    cout<<endl;
    cout<<"LA LONGITUD DE LA CADENA ES: ["<<t<<"]"<<endl;
}
int Cuenta(char vector3[30], char l, int n)
{
    int i, cc=0;
    for (i=0;i<n;i++)
    {
        if (vector3[i]==l)
        {
            cc++;
        }
    }
    return cc;
}
void MostrarE(struct Producto p)
{
    cout<<"======================================"<<endl;
    cout<<"CLAVE: "<<p.clave<<endl;
    cout<<"DESCRIPCION: "<<p.descripcion<<endl;
    cout<<"CANTIDA EN EXISTENCIA: "<<p.cantidad<<endl;
    cout<<"PRECIO NORMAL EN UNIDAD: "<<p.costo<<" $"<<endl;
    cout<<"PRECIO CON IVA EN UNIDAD: "<<(p.costo*1.16)<<" $"<<endl;
    cout<<"PRECIO TOTAL S/IVA: "<<(p.cantidad*p.costo)<<" $"<<endl;
    cout<<"PRECIO TOTAL C/IVA: "<<(p.cantidad*p.costo*1.16)<<" $"<<endl;
}
void MostrarPE(struct Producto *p)
{
    cout<<"======================================"<<endl;
    cout<<"CLAVE: "<<p->clave<<endl;
    cout<<"DESCRIPCION: "<<p->descripcion<<endl;
    cout<<"CANTIDAD EN EXISTENCIA: "<<p->cantidad<<endl;
    cout<<"PRECIO NORMAL EN UNIDAD: "<<p->costo<<" $"<<endl;
    cout<<"PRECIO CON IVA EN UNIDAD: "<<(p->costo*1.16)<<" $"<<endl;
    cout<<"PRECIO TOTAL S/IVA: "<<(p->cantidad*p->costo)<<" $"<<endl;
    cout<<"PRECIO TOTAL C/IVA: "<<(p->cantidad*p->costo*1.16)<<" $"<<endl;
}
void MostrarV(struct Producto p[100], int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        if (p[i].costo>20)
        {
             cout<<"================================================================================================="<<endl;
            cout<<"CLAVE DEL PRODUCTO ["<<i+1<<"]: "<<p[i].clave<<endl;
            cout<<"DESCRIPCION DEL PRODUCTO ["<<i+1<<"]: "<<p[i].descripcion<<endl;
            cout<<"CANTIDAD EN EXISTENCIA DEL PRODUCTO ["<<i+1<<"]: "<<p[i].cantidad<<endl;
            cout<<"PRECIO NORMAL EN UNIDAD DEL PRDUCTO ["<<i+1<<"]: "<<p[i].costo<<" $"<<endl;
            cout<<"PRECIO CON IVA EN UNIDAD DEL PRODUCTO ["<<i+1<<"]: "<<p[i].costo*1.16<<" $"<<endl;
            cout<<"PRECIO NORMAL TOTAL DEL PRODUCTO ["<<i+1<<"]: "<<p[i].cantidad*p[i].costo<<" $"<<endl;
            cout<<"PRECIO CON IVA TOTAL DEL PRODUCTO ["<<i+1<<"]: "<<p[i].cantidad*p[i].costo*1.16<<" $"<<endl;
            cout<<"================================================================================================="<<endl;
        }
    }
}
void Operaciones(float *p2,int n)
{
    int i;
    float s=0,r=0,m=1,d=1;
    for (i=0;i<n;i++)
    {
        s=s+*p2;
        r=r-*p2;
        m=m*(*p2);
        d=d/(*p2);
        p2++;
    }
    cout<<"LA SUMA DE LOS NUMEROS ES: "<<s<<endl;
    cout<<"LA RESTA DE LOS NUMEROS ES: "<<r<<endl;
    cout<<"LA MULTIPLICACION DE LOS NUMEROS ES: "<<m<<endl;
    cout<<"LA DIVISION DE TODOS LOS NUMEROS ES: "<<d<<endl;
}
void AniosDe(string *numempl, string *nom, long int *anio)
{
    cout<<"EL NUMERO DEL EMPLEADO: "<<*numempl<<endl;
    cout<<"EL NOMBRE DEL EMPLEADO: "<<*nom<<endl;
    cout<<"ANIO DE ENTRADA: "<<*anio<<endl;
    cout<<"ANIOS DE ANTIGUEDAD: "<<2023-*anio<<endl;
}