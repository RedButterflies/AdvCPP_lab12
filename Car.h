//
// Created by szyns on 09.01.2024.
//

#ifndef KROTKILAMBDY_CAR_H
#define KROTKILAMBDY_CAR_H

#include <iostream>
using namespace std;

class Car {
private:
    string model;
    int rok_produkcji;
    float pojemnosc_silnika;
public:
    Car(const string &model, int rokProdukcji, float pojemnoscSilnika);

    const string &getModel() const;

    void setModel(const string &model);

    int getRokProdukcji() const;

    void setRokProdukcji(int rokProdukcji);

    float getPojemnoscSilnika() const;

    void setPojemnoscSilnika(float pojemnoscSilnika);

    void info();
};


#endif //KROTKILAMBDY_CAR_H
