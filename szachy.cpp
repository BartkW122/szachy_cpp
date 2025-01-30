#include <iostream>
#include <string>
using namespace std;
class szachy{
    public:
    int info(){
        cout<<"b-bialy";
        cout<<endl;
        cout<<"c-czarny";
        cout<<endl;
        cout<<":-pion";
        cout<<endl;
        cout<<"|-wieza";
        cout<<endl;
        cout<<"*.-goniec";
        cout<<endl;
        cout<<"-*-krolowa";
        cout<<endl;
        cout<<"*_-krol";
        return 0;
    };
    int plansza(int x,int y){
        x--;
        y--;
        cout<<endl;
        int w=8,k=8;
        string **tab=new string*[w];
        for(int i = 0;i<w;i++){
            tab[i]=new string[k];
        }
        for(int i = 0;i<w;i++){
            for(int j = 0;j<k;j++){
               tab[i][j]="|_|";
               tab[1][j]="|b:|";
               tab[6][j]="|c:|";
            } 
        }
        for(int i = 0;i<w;i++){
            cout<<i+1;
            for(int j = 0;j<k;j++){
                tab[x][y]="|r|";
                cout<<tab[i][j]<<" ";
            } 
            cout<<"\n";
        }
 
        return 0;
    }
    int gra(){
        int x,y;
        cout<<"podaj numer od 1 do 8 (x):";
        cin>>x;
        cout<<"podaj numer od 1 do 8 (y):";
        cin>>y;
        info();
        plansza(x,y);
        return 0;
    };
};
int main()
{
    szachy szachy;
    szachy.gra();
    return 0;
}