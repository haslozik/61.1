#include  <iostream>
#include  <fstream>
#include  <vector>

using namespace std;

struct  liczby {
	int liczba;
};

struct  liczby2 {	
	int roznica;
};

class ciagi {
	
	int stara_roznica;
	int dlugosc;
	int liczba;
	int liczba_pop_c = 0;
	
	vector <struct liczby> t;
	vector <struct liczby2> t2;
	
	public:
		
		void licz();
		void znajdz_max();
};

void  ciagi::licz() {
	ifstream plik;
	ofstream plik2;
	
	plik.open("ciagi.txt");
	plik2.open("wynik.txt");
	
		while (plik.good()) {
 			plik >> dlugosc;
 			for (int i = 0 ; i <dlugosc; i ++) {
   				plik >> liczba;
    			t.push_back (liczba);
    					
    			if (i == 1) stara_roznica = t [1] -t [0];
    			if(i> 1) {
       				int roznica = t [i] - t [i-1];
      				if (roznica! = stara_roznica) {
          				cout<<"zly ciag "<<endl;
      				} else {
      					liczba_pop_c++;
      					t2.push_back(roznica);
					}
   				}
 			}
}
	plik2 <<"Liczba ciagow arytm: "<<liczba_pop_c<<endl;
	plik.close();
	plik2.close();
}

void  ciagi::znajdz_max() {
	ofstream plik2;
	plik2.open("wynik.txt");
	max = t2[0];
	
	for( int i=1; i<200; i++)
		if (max <t2[i])
			max = t2[i];
		plik2<<"Najwieksza r�znica: "<<max;
		plik2.close();
}


int main(int argc, char ** argv) {
	
	ciagi c;
	do.licz ();
	do.znajdz_max ();
	
	
	return 0;
}
