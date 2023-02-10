//Copyright 2021

#pragma once
/*
 * File:   Bank_Simulator.h
 * Author: hloi
 *
 * Created on November 25, 2014, 1:14 PM
 */

#ifndef BANK_SIMULATOR_H
#define	BANK_SIMULATOR_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include "Customer.h"
#include "Teller.h"
#include "Random.h"



class Simulator
{
public:

    void run_simulation(int, double);  // start the simulation
    void output_statistics();  // print out the statistics
    void setTellers(int);  // create number of teller
    std::vector<Teller> getTellers() const;  // return tellers vector


private:

    std::vector<Teller> tellers;
    std::queue<Customer*> the_customers;

};

#endif	/* BANK_SIMULATOR_H */
