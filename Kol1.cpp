#include "Wybor.h"
#
using namespace std;

/*
* Uwaga: Zadania kod rozwiazania zaania umieszczać pomiędzy #ifdef a #endif. 
*/

#ifdef Kol_1


enum class StanDopuszczenia { dopuszczony, niedopuszczony };

class Wlasciciel {
public:

};
class Samochod
{
private:
        char numerRejestracyjny_n[15]; 
           int stanLicznika_n; 
           StanDopuszczenia stanDopuszczenia_n; 
           const Wlasciciel& wlasciciel_n; 
           static Samochod* wzorcowy_n; 
           static double WAR_POCZ;
    public: Samochod(const char* numerRejestracyjny, int stanLicznika, 
        StanDopuszczenia stanDopuszczenia, const Wlasciciel& wlasciciel) 
        : wlasciciel_n(wlasciciel),stanLicznika_n(stanLicznika),stanDopuszczenia_n(stanDopuszczenia)
    { 
        setNumerRejestracyjny(numerRejestracyjny); 
         }

          Samochod() : wlasciciel_n(wzorcowy_n->wlasciciel_n) {
              if (wzorcowy_n==NULL) {
                  throw invalid_argument("BRAK USTAWIENIA WZORCOWEGO AUUTA");
              }
              *this->wzorcowy_n == *wzorcowy_n;
          }
const Wlasciciel& getWlasciciel() const { return wlasciciel_n; }
          int getStanLicznika() const { return stanLicznika_n; }
          static void setWzorcowy(Samochod* wzorcowy) {
              wzorcowy_n = wzorcowy;
          }

      
          const char* getNumerRejestracyjny() const { return numerRejestracyjny_n; }
          StanDopuszczenia getStanDopuszczenia() const { return stanDopuszczenia_n; }
          void setNumerRejestracyjny(const char* numerRejestracyjny) {
              strncpy_s(numerRejestracyjny_n, numerRejestracyjny, 14);
              numerRejestracyjny_n[14] = '\0';
          }

          void setStanLicznika(int stanLicznika) {
              if (stanLicznika < 0) {
                  throw invalid_argument("Stan licznika nie może być ujemny.");
              }
              stanLicznika_n = stanLicznika;
          }

          
          void setStanDopuszczenia(StanDopuszczenia stanDopuszczenia) {
              stanDopuszczenia_n = stanDopuszczenia;
          }

          double obliczWartosc(double WSP_SPARW) const {
              double wartosc = (WAR_POCZ - 0.2 * stanLicznika_n) * (stanDopuszczenia_n == StanDopuszczenia::dopuszczony ? WSP_SPARW : 0.2);
              if (wartosc < 400)
              {
                  throw invalid_argument("samochod musi byc warty wiecej niz 400zl");
              }
              return wartosc;
          }

  
          virtual double obliczZasieg() const {
              if (stanDopuszczenia_n == StanDopuszczenia::niedopuszczony) {
                  throw invalid_argument("NIEDOPUSZCZONY SAMOCHOD!");
              }
              return 800;
          }

          bool operator==(const Samochod& inny) const {
              return (stanLicznika_n - inny.stanLicznika_n) <= 20 &&(stanLicznika_n - inny.stanLicznika_n)>=-20&& stanDopuszczenia_n == inny.stanDopuszczenia_n;
          }

        

         
    };

    Samochod* Samochod::wzorcowy_n = nullptr;

    class SamochodElektryczny : public Samochod {
    private: 
        int stanBaterii_n;

    public: SamochodElektryczny(const char* numerRejestracyjny, int stanLicznika, 
        StanDopuszczenia stanDopuszczenia, const Wlasciciel& wlasciciel, int stanBaterii)
        : Samochod(numerRejestracyjny, stanLicznika, stanDopuszczenia, wlasciciel), stanBaterii_n(stanBaterii) 
    { if (stanBaterii < 0 || stanBaterii > 100)
    { throw invalid_argument("Procenty bateri sa w przedziale 0-100");
    } 
    }

          double obliczZasieg() const {
              if (getStanDopuszczenia() == StanDopuszczenia::niedopuszczony) {
                  throw invalid_argument("Samochod jest niedopuszczony do jazdy.");
              }
              return 2.5 * stanBaterii_n;
          }

          double obliczWartosc(double WSP_SPARW) const {
              double wartosc = Samochod::obliczWartosc(WSP_SPARW) * 0.7;
              if (wartosc < 400)
              {
                  throw invalid_argument("samochod musi byc warty wiecej niz 400zl");
              }
              return wartosc;
          }

    };

    int main() {

        Wlasciciel wlasciciel1;
        

        Samochod samochod("SKL-098PL", 1000, StanDopuszczenia::dopuszczony, wlasciciel1);

    }


#endif 
