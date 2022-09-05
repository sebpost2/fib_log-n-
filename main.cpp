#include <iostream>

#define forn(i,n) for(int i=0; i<n;i++)

struct fibarray {
    int** ini;

    fibarray(){
        ini=new int*[2];
        forn(i,2){
            ini[i]=new int[2];
        }
        ini[0][0]=0;
        ini[0][1]=1;
        ini[1][0]=1;
        ini[1][1]=1;

    }

    //multiplicacion de matrices
    int** mlt(int** a, int** b, int arows, int brows, int bcols){
        int **res;
        res=new int*[bcols];
        forn(i, bcols){
            res[i]=new int[arows];
        }
        forn(i,arows){
            forn(j,bcols){
                forn(k, brows){
                    res[i][j]+=a[i][k]*b[k][j];
                }
            }
        }
        return res;
    }

    //potenciacion binaria
    void pot(int** &a, int x){
        int** imparint;
        bool impar =0;
        if (x%2!=0){
            imparint=a;
            impar=1;
        }
        if (x>1){
            pot(a,x/2);
        }
        if(x==1){
            return;
        }
        a=mlt(a,a,2,2,2);
        if(impar)
            a=mlt(a,imparint,2,2,2);
    }

    void printini(){
        forn(i,2){
            forn(j,2){
                std::cout<<ini[i][j]<<" | ";
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
    }

    void printini2(){
        forn(i,2){
            forn(j,1){
                std::cout<<ini[i][j]<<" | ";
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
    }

    ~fibarray(){
        forn(i,2){
            delete[] ini[i];
        }
        delete[] ini;
    }
};

int main() {
    int fib;
    std::cin>>fib;
    std::cout<<std::endl;

    fibarray A;
    A.pot(A.ini,fib);
    A.printini();
    A.printini2();
    if (fib==0){
        std::cout<<"\n El resultado es: "<<0<<std::endl;
    }
    std::cout<<"\n El resultado es: "<<A.ini[01][0]<<std::endl;
}
