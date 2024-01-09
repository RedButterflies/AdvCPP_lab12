#include <iostream>
#include <vector>
#include <algorithm>
#include "Car.h"
#include <tuple>

using namespace std;

tuple<int,float,string> funkcja(vector<string>w)
{
    sort(w.begin(),w.end(),[](const string& napis1, const string& napis2){return napis1.size()<napis2.size();});
    int dl_najk_napisu = int(w.at(0).size());
    float srednia_dl_napisu = 0;
    auto liczba_napisow = float(w.size());
    for_each(w.begin(),w.end(),[&srednia_dl_napisu, &liczba_napisow](const string& napis){srednia_dl_napisu+=float(napis.size())/liczba_napisow;});
    string najdluzszyNapis = w.at(int(w.size()-1));
    auto zwrot = make_tuple(dl_najk_napisu,srednia_dl_napisu,najdluzszyNapis);
    return zwrot;
}

int main() {
    vector<int>num = {-1,-2,-3,-4,1,2,3,4,5,6,7,8,9};
    for_each(num.begin(), num.end(),[](int el){cout<<el<<"|";});

    float mean = 0;
    int num_of_elements = int(num.size());
    for_each(num.begin(),num.end(),[&mean,&num_of_elements](int elem){mean+=float(elem)/float(num_of_elements);});
    cout<<"\nSrednia arytmetyczna elementow wektora: "<<mean<<endl;
    int num_of_even = 0;
    for_each(num.begin(),num.end(),[&num_of_even](int elem){if(elem%2==0) num_of_even+=1;});
    cout<<"\nLiczba elementow parzystych w wektorze: "<<num_of_even<<endl;
    num.erase(remove_if(num.begin(),num.end(),[](int el){return el<0;}),num.end());
    cout<<"\nWektor po usunieciu elementow ujemnych"<<endl;
    for_each(num.begin(), num.end(),[](int el){cout<<el<<"|";});
    sort(num.begin(),num.end(),[](int x, int y){if(y%2==0) return x<y ;});
    cout<<"\nWektor po posorotwaniu tak, aby elementy parzyste znajdowaly sie na poczatku a nieparzyste na koncu"<<endl;
    for_each(num.begin(), num.end(),[](int el){cout<<el<<"|";});
    transform(num.begin(),num.end(),num.begin(),[](int el){return -el;});
    cout<<"\nWektor po nadpisaniu elementow liczbami przeciwnymi"<<endl;
    for_each(num.begin(), num.end(),[](int el){cout<<el<<"|";});
    int arg = -5;
    int ile_mniejszych = 0;
    for_each(num.begin(),num.end(),[&arg,&ile_mniejszych](int el){if(el<arg)ile_mniejszych++;});
    cout<<"\nLiczba elementow wektora mniejszych niz -5: "<<ile_mniejszych<<endl;

    cout<<"\nSamochody przed posortowaniem: "<<endl;
    vector<Car>samochody{Car("Seat Leaon",2002,45.5),Car("Fiat ",1965,15.6),Car("Ford Sedan",2021,85.6)};
    for_each(samochody.begin(), samochody.end(), [](Car s){cout<<"\n"<<endl;s.info();});
    int count = 0;
    cout<<"\nSamochody posortowane rosnaco wg roku produkcji"<<endl;
    sort(samochody.begin(), samochody.end(),[](const Car& s1, const Car& s2){return s1.getRokProdukcji()<s2.getRokProdukcji();});
    for_each(samochody.begin(), samochody.end(), [&count](Car s){count++;cout<<"\n"<<count<<".: "<<endl;s.info();});
    cout<<"\nSamochody posortowane rosnaco wg roku produkcji"<<endl;
    count = 0;
    for_each(samochody.begin(), samochody.end(), [&count](Car s){count++;cout<<"\n"<<count<<".: "<<endl;s.info();});
    cout<<"Samochody posortowane malejaco wg pojemnosci silnika: "<<endl;
    sort(samochody.begin(), samochody.end(),[](Car s1, Car s2){return s1.getPojemnoscSilnika()>s2.getPojemnoscSilnika();});
    count = 0;
    for_each(samochody.begin(), samochody.end(), [&count](Car s){count++;cout<<"\n"<<count<<".: "<<endl;s.info();});

    vector<string>words = {"Tomasz","pralka","hulajnoga","Ala","zmywarka"};
    auto wynik = funkcja(words);
    cout<<"\n\n\nWynik funkcji: \n"<<"Dlugosc najkrotszego slowa: "<<get<0>(wynik)<<endl;
    cout<<"Srednia dlugosc napisu: "<<get<1>(wynik)<<endl;
    cout<<"Najdluzszy napis: "<<get<2>(wynik)<<endl;


    return 0;
}
