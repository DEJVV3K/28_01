#include <iostream>
#include <fstream>

using namespace std;

int roz = 1000;

void zadanie62() {
	ifstream wej;
    wej.open("liczby1.txt");
    ofstream wyj;
    wyj.open("wynik.txt");
    
	int tab[roz];
	int min = 999999;
	int max = 0;
	
	for (int i = 0; i < roz; i++) {
		wej >> tab[i];
	}
	
	for (int i = 0; i < roz; i++) {
    	if (tab[i] < min) min = tab[i];
    	if (tab[i] > max) max = tab[i];
	}
	
	wyj << "---- zadanie 1 ----" << endl;
	wyj << "  Najmniejsza: " << min << endl;
	wyj << "  Najwieksza: " << max << endl << endl;
	wyj << "----- zadanie 2 -----" << endl;
	
	//zadanie 2
	
	int tab2[roz];
	int najPierwsza;
	int licz = 0;
	int maxLicz = 0;
	int pierwszaLiczba = 0;
	
	for (int i = 0; i < 1000; i++) wej >> tab2[i];
	
	for (int i = 1; i < roz; i++) {
    	if (tab2[i] >= tab2[i - 1]) {
    		licz++;
    		if (pierwszaLiczba == 0) {
    			pierwszaLiczba = tab2[i - 1];
        		licz++;
      		}
    	} else {
    		if (licz > maxLicz) {
        		maxLicz = licz;
        		najPierwsza = pierwszaLiczba;
      		}
      	pierwszaLiczba = 0;
      	licz = 0;
    	}
	}
	
	wyj << "Pierwszy element: " << najPierwsza << endl;
	wyj << "Liczba elementow: " << maxLicz << endl;
	
	wej.close();
	wyj.close();
}

int main() {
	
	zadanie62();
	
	return 0;
}
