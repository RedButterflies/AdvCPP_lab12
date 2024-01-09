//
// Created by szyns on 09.01.2024.
//

#include "Car.h"

Car::Car(const string &model, int rokProdukcji, float pojemnoscSilnika) : model(model), rok_produkcji(rokProdukcji),
                                                                          pojemnosc_silnika(pojemnoscSilnika) {}

const string &Car::getModel() const {
    return model;
}

void Car::setModel(const string &model) {
    Car::model = model;
}

int Car::getRokProdukcji() const {
    return rok_produkcji;
}

void Car::setRokProdukcji(int rokProdukcji) {
    rok_produkcji = rokProdukcji;
}

float Car::getPojemnoscSilnika() const {
    return pojemnosc_silnika;
}

void Car::setPojemnoscSilnika(float pojemnoscSilnika) {
    pojemnosc_silnika = pojemnoscSilnika;
}

void Car::info() {
    cout<<"Model: "<<model<<endl;
    cout<<"Rok produkcji: "<<rok_produkcji<<endl;
    cout<<"Pojemnosc silnika: "<<pojemnosc_silnika<<endl;

}


