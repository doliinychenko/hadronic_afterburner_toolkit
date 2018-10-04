// Copyright 2018 @ Chun Shen

#ifndef BALANCEFUNCTION_H_
#define BALANCEFUNCTION_H_

#include <string>
#include <vector>
#include <array>

#include "ParameterReader.h"
#include "particleSamples.h"

class BalanceFunction {
 private:
    const ParameterReader *paraRdr;
    const std::string path;
    particleSamples *particle_list;

    int particle_monval_a;
    int particle_monval_b;
    bool same_species;

    long int N_b, N_bbar;

    int Bnpts;
    int Bnphi; 
    double dphi;
    double Brap_min;
    double Brap_max;
    double drap;
    double BpT_min, BpT_max;
    std::vector<std::vector<double>> C_ab;
    std::vector<std::vector<double>> C_abarbbar;
    std::vector<std::vector<double>> C_abbar;
    std::vector<std::vector<double>> C_abarb;

 public:
    BalanceFunction(const ParameterReader *paraRdr_in,
                    const std::string path_in,
                    particleSamples *particle_list_in);
    ~BalanceFunction() {};

    void calculate_balance_function();
    void combine_and_bin_particle_pairs(
                std::vector<std::vector<double>> &hist,
                const std::vector< std::vector<particle_info>* >* plist_a,
                const std::vector< std::vector<particle_info>* >* plist_b);
    int get_number_of_particles(
                const std::vector< std::vector<particle_info>* >* plist_b);
    void output_balance_function();
};

#endif  // BALANCEFUNCTION_H_