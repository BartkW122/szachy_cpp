#include <iostream>
#include <string>
#include <map>
using namespace std;
class ruch;
class plansza;
class szachy;

class gra{
    public:
    map <string, string> info = { {"Czarne", "c"}, {"Biale", "b"}, {"Pionek", ":"}, {"Wieza", "|"}, {"Skoczek", "*:"}, {"Goniec", "*."},{"Krolowa", "-*"},{"Krol", "*_"} };
    int pozycja_x,pozycja_y;
    string pole_do_gry[8][8];
    
    friend class plansza;
    friend class ruch;
    friend class szachy;
    
    friend void wyswietl_informacje(gra &);
    friend void wyswietl_plansze(gra &);
    friend void zrob_ruch(gra &,plansza &,ruch &);
    
    friend void Szachy_gra(gra &,plansza &,ruch &);
    
};

class plansza{
    public:
    void wyswietl_informacje(gra GRA){
        for (auto informacja : GRA.info) {
            cout << informacja.first << " : " << informacja.second << "\n";
        }    
    }
    
    void wyswietl_plansze(gra GRA,int x,int y,string z){
        cout<<endl;
        //przypisawnie pionkow do miejsc na planszy
        for(int i = 0;i<8;i++){
            for(int j = 0;j<8;j++){
                GRA.pole_do_gry[i][j]="|__|";
                if(x==i && y==j){
                    GRA.pole_do_gry[i][j]=z;
                }
                //GRA.pole_do_gry[x][y]=z;
                
                GRA.pole_do_gry[1][j]="|b:|";
                GRA.pole_do_gry[0][0]="|b||";
                GRA.pole_do_gry[0][7]="|b||";
                GRA.pole_do_gry[0][1]="|b*:|";
				GRA.pole_do_gry[0][6]="|b*:|";
				GRA.pole_do_gry[0][2]="|b*.|";
				GRA.pole_do_gry[0][5]="|b*.|";
                GRA.pole_do_gry[0][3]="|b-*|";
				GRA.pole_do_gry[0][4]="|b*_|";
                
                GRA.pole_do_gry[6][j]="|c:|";
                GRA.pole_do_gry[7][0]="|c||";
                GRA.pole_do_gry[7][7]="|c||";
                GRA.pole_do_gry[7][1]="|c*:|";
				GRA.pole_do_gry[7][6]="|c*:|";
				GRA.pole_do_gry[7][2]="|c*.|";
				GRA.pole_do_gry[7][5]="|c*.|";
                GRA.pole_do_gry[7][4]="|c-*|";
				GRA.pole_do_gry[7][3]="|c*_|";
               
            }
        }
        
         for(int i = 0;i<8;i++){
            cout<<i;
            for(int j = 0;j<8;j++){
                cout<<GRA.pole_do_gry[i][j];
            }
            cout<<endl;
        }
        for(int i = 0;i<8;i++){
            cout<<"   "<<i;
        }
    }
};
class ruch {
public:
    string znak;
    void zrob_ruch(gra &GRA, plansza &PLANSZA, ruch &RUCH) {
        cout << endl;
        cout << "podaj pozycje x :"; cin >> GRA.pozycja_x;
        cout << "podaj pozycje y :"; cin >> GRA.pozycja_y;
        cout << "podaj znak :"; cin >> RUCH.znak;

       
        if(GRA.pozycja_x >= 0 && GRA.pozycja_x < 8 && GRA.pozycja_y >= 0 && GRA.pozycja_y < 8) {
            RUCH.znak="|_"+RUCH.znak+"_|";
        } else {
            cout << "Nie można wstwaić znaku!" << endl;
        }

        PLANSZA.wyswietl_plansze(GRA,GRA.pozycja_x,GRA.pozycja_y,znak);
    }
};

class szachy{
    public:
    void Szachy_gra(gra GRA,plansza PLANSZA,ruch RUCH){
        char z;
        do{
            PLANSZA.wyswietl_informacje(GRA);
            PLANSZA.wyswietl_plansze(GRA,GRA.pozycja_x,GRA.pozycja_y,RUCH.znak);
            RUCH.zrob_ruch(GRA,PLANSZA,RUCH);
            cout<<"\nx:"<<GRA.pozycja_x;
            cout<<"\ny:"<<GRA.pozycja_y;
            cout<<"\nczy chcesz kontynuowac :";cin>>z;
        }while(z=='y');
    }
};
int main()
{
    szachy SZACHY;
    gra GRA;
    plansza PLANSZA;
    ruch RUCH;
    
    /*PLANSZA.wyswietl_informacje(GRA);
    
    PLANSZA.wyswietl_plansze(GRA);
    
    RUCH.zrob_ruch(GRA,PLANSZA,RUCH);*/
    
    SZACHY.Szachy_gra(GRA,PLANSZA,RUCH);

    return 0;
}