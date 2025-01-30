#include <iostream>
#include <string>
using namespace std;
class szachy {
public:
	int info() {
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
		cout<<"*|-kon";
		cout<<endl;
		cout<<endl;
		cout<<"-*-krolowa";
		cout<<endl;
		cout<<"*_-krol";
		cout<<endl;
		return 0;
	};
	int plansza(int x1,int y1,int x2,int y2,string pio) {
		x1--;
		y1--;
		x2--;
		y2--;
		cout<<endl;
		int w=8,k=8;
		string **tab=new string*[w];
		for(int i = 0; i<w; i++) {
			tab[i]=new string[k];
		}

		for(int i = 0; i<w; i++) {
			for(int j = 0; j<k; j++) {
				tab[i][j]="|_|";
				tab[1][j]="|b:|";
 
				tab[0][0]="|b||";
				tab[0][7]="|b||";
                tab[0][1]="|b*||";
				tab[0][6]="|b*||";
				tab[0][2]="|b*.|";
				tab[0][5]="|b*.|";
                tab[0][3]="|b-*|";
				tab[0][4]="|b*_|";
 
				tab[6][j]="|c:|";
				tab[i][j]="|_|";
 
				tab[7][0]="|c||";
				tab[7][7]="|c||";
                tab[7][1]="|c*||";
				tab[7][6]="|c*||";
				tab[7][2]="|c*.|";
				tab[7][5]="|c*.|";
                tab[7][4]="|c-*|";
				tab[7][3]="|c*_|";
			}
		}
		for(int i = 0; i<w; i++) {
			cout<<i+1;
			for(int j = 0; j<k; j++) {
			    if(tab[x1][y1]==pio){
			        cout<<"indeks i: "<<i;
			        tab[x1][y1]=tab[x2][y2];
			    }
				//tab[x2][y2]="|r|";
				cout<<tab[i][j]<<" ";
			}
			cout<<"\n";
		}
 
		return 0;
	}
	int gra() {
	    info();
		int x1,y1,x2,y2;
		string pio;
		cout<<"podaj pionek (pionek zapisz w ||):";
		cin>>pio;
		cout<<"podaj wspolzedne pionka (x) numer od 1 do 8 :";
		cin>>x1;
		cout<<"podaj wspolzedne pionka (y) numer od 1 do 8 :";
		cin>>y1;
		cout<<"podaj numer od 1 do 8 (x):";
		cin>>x2;
		cout<<"podaj numer od 1 do 8 (y):";
		cin>>y2;
		plansza(x1,y1,x2,y2,pio);
		return 0;
	};
};
int main()
{
	szachy szachy;
	szachy.gra();
	return 0;
}