//Copyright 2021
#ifndef NEWCXXTEST_H
#define NEWCXXTEST_H

#include "Bank_Simulator.h"
#include "Customer.h"
#include <cxxtest/TestSuite.h>
#include "Teller.h"
#include "Random.h"

class newCxxTest : public CxxTest::TestSuite {
public:

	void test1_arrivalTime() {
		
		Customer::set_max_service_time(5);
		Customer* cust1 = new Customer(30);
		cust1->start_service(1);
		int a = cust1->get_arrival_time();
		TS_ASSERT_EQUALS(a, 30);
	}
	void test2_delayTime() {
		
		Customer::set_max_service_time(5);
		Customer* cust1 = new Customer(30);
		cust1->start_service(60);
		int a = cust1->get_delay_time();
		TS_ASSERT_EQUALS(a, 30);
	}
	void test3_serviceTime() {
		
		Customer::set_max_service_time(5);
		Customer* cust1 = new Customer(30);
		cust1->start_service(60);
		int a = cust1->get_service_time();
		TS_ASSERT_EQUALS(a, 2);
	}
	void test4_totalCustomersServed() {
		Simulator sim;
		sim.setTellers(3);
		Customer::set_max_service_time(5);
		sim.run_simulation(200, .5);
		int a = Customer::get_total_customers_served();
		sim.output_statistics();
		TS_ASSERT_EQUALS(a, 101);
	}
	void test5_averageWait() {
		Simulator sim;
		sim.setTellers(3);
		Customer::set_max_service_time(5);
		sim.run_simulation(200, .5);
		double a = Customer::get_total_delay_time() / Customer::get_total_customers_served();
		TS_ASSERT_EQUALS(a, 0);
	}
	void test6_teller1NumCustServed() {
		Simulator sim;
		sim.setTellers(3);
		Customer::set_max_service_time(5);
		sim.run_simulation(200, .5);
		std::vector<Teller> tell = sim.getTellers();
		int a = tell[0].get_num_customers_served();
		TS_ASSERT_EQUALS(a, 58);
	}
	void test7_teller2NumCustServed() {
		Simulator sim;
		sim.setTellers(3);
		Customer::set_max_service_time(5);
		sim.run_simulation(200, .5);
		std::vector<Teller> tell = sim.getTellers();
		int a = tell[1].get_num_customers_served();
		TS_ASSERT_EQUALS(a, 37);
	}
	void test8_teller3NumCustServed() {
		Simulator sim;
		sim.setTellers(3);
		Customer::set_max_service_time(5);
		sim.run_simulation(200, .5);
		std::vector<Teller> tell = sim.getTellers();
		int a = tell[2].get_num_customers_served();
		TS_ASSERT_EQUALS(a, 6);
	}
	void test9_teller1TotalServiceTime() {
		Simulator sim;
		sim.setTellers(3);
		Customer::set_max_service_time(5);
		sim.run_simulation(200, .5);
		std::vector<Teller> tell = sim.getTellers();
		int a = tell[0].get_total_service_time();
		TS_ASSERT_EQUALS(a, 139);
	}
	void test10_teller2TotalServiceTime() {
		Simulator sim;
		sim.setTellers(3);
		Customer::set_max_service_time(5);
		sim.run_simulation(200, .5);
		std::vector<Teller> tell = sim.getTellers();
		int a = tell[1].get_total_service_time();
		TS_ASSERT_EQUALS(a, 67);
	}
	void test11_teller3TotalServiceTime() {
		Simulator sim;
		sim.setTellers(3);
		Customer::set_max_service_time(5);
		sim.run_simulation(200, .5);
		std::vector<Teller> tell = sim.getTellers();
		int a = tell[2].get_total_service_time();
		TS_ASSERT_EQUALS(a, 10);
	}
	void test12_teller1TotalIdleTime() {
		Simulator sim;
		sim.setTellers(3);
		Customer::set_max_service_time(5);
		sim.run_simulation(200, .5);
		std::vector<Teller> tell = sim.getTellers();
		int a = tell[0].get_total_idle_time();
		TS_ASSERT_EQUALS(a, 60);
	}
	void test13_teller2TotalIdleTime() {
		Simulator sim;
		sim.setTellers(3);
		Customer::set_max_service_time(5);
		sim.run_simulation(200, .5);
		std::vector<Teller> tell = sim.getTellers();
		int a = tell[1].get_total_idle_time();
		TS_ASSERT_EQUALS(a, 129);
	}
	void test14_teller3TotalIdleTime() {
		Simulator sim;
		sim.setTellers(3);
		Customer::set_max_service_time(5);
		sim.run_simulation(200, .5);
		std::vector<Teller> tell = sim.getTellers();
		int a = tell[2].get_total_idle_time();
		TS_ASSERT_EQUALS(a, 190);
	}
	void test15_teller1AvglIdleTime() {
		Simulator sim;
		sim.setTellers(3);
		Customer::set_max_service_time(5);
		sim.run_simulation(200, .5);
		std::vector<Teller> tell = sim.getTellers();
		double a = tell[0].get_total_idle_time()/ tell[0].get_num_customers_served();
		TS_ASSERT_EQUALS(a, 1);
	}
	void test16_teller2AvglIdleTime() {
		Simulator sim;
		sim.setTellers(3);
		Customer::set_max_service_time(5);
		sim.run_simulation(200, .5);
		std::vector<Teller> tell = sim.getTellers();
		double a = tell[1].get_total_idle_time() / tell[1].get_num_customers_served();
		TS_ASSERT_EQUALS(a, 5);
	}
	void test17_teller3AvglIdleTime() {
		Simulator sim;
		sim.setTellers(3);
		Customer::set_max_service_time(5);
		sim.run_simulation(200, .5);
		std::vector<Teller> tell = sim.getTellers();
		double a = tell[2].get_total_idle_time() / tell[2].get_num_customers_served();
		TS_ASSERT_EQUALS(a, 19);
	}
	void test18_size() {
		Simulator sim;
		sim.setTellers(3);
		Customer::set_max_service_time(5);
		sim.run_simulation(200, .5);
		std::vector<Teller> tell = sim.getTellers();
		int a = tell.size();
		TS_ASSERT_EQUALS(a, 3);
	}
	void test19_teller1AvglIdleTime() {
		Simulator sim;
		sim.setTellers(3);
		Customer::set_max_service_time(5);
		sim.run_simulation(200, .5);
		std::vector<Teller> tell = sim.getTellers();
		double a = tell[0].get_total_idle_time() / tell[0].get_num_customers_served();
		TS_ASSERT_EQUALS(a, 0);
	}
	void test20_teller1AvglIdleTime() {
		Simulator sim;
		sim.setTellers(3);
		Customer::set_max_service_time(5);
		sim.run_simulation(200, .5);
		std::vector<Teller> tell = sim.getTellers();
		double a = tell[0].get_total_idle_time() / tell[0].get_num_customers_served();
		TS_ASSERT_EQUALS(a, 1);
		Random newrandom;
	}
};
#endif /*NEWCXXTEST_H*/
