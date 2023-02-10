//Copyright 2021
#include "Bank_Simulator.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
Random myrandom(10);


void Simulator::setTellers(int num) {
	tellers.resize(num);
}

std::vector<Teller> Simulator::getTellers() const {
	return tellers;
}

void Simulator::run_simulation(int max_time, double arrival_rate) {
	for (int time = 0; time < max_time; time++) {
		if (myrandom.next_double() < arrival_rate) {
			Customer *newCustomer = new Customer(time);
			the_customers.push(newCustomer);
		}
		for (int i = 0; i < tellers.size(); i++) {
			if (tellers[i].is_free() == false && tellers[i].get_time_next_free() <= time) {
				tellers[i].end_service(time);
			}
			if (tellers[i].is_free() == true && the_customers.empty() == false) {
				tellers[i].start_service(time, the_customers.front());
				the_customers.front()->start_service(time);
				the_customers.pop();
			}
		}
	}
}

void Simulator::output_statistics() {
	cout << "Total Customers Served: " << Customer::get_total_customers_served() << endl;
	double average_wait =
		double(Customer::get_total_delay_time()) / Customer::get_total_customers_served();
	cout << "Average Wait: " << average_wait << endl;
	cout << "Teller Total     Total    Total Average\n"
		<< "       Customers Service  Idle  Idle\n"
		<< "       Served    Time     Time  Time\n";
	for (size_t i = 0; i < tellers.size(); i++) {
		cout << setw(5) << i;
		cout << setw(9) << tellers[i].get_num_customers_served();
		cout << setw(7) << tellers[i].get_total_service_time();
		cout << setw(9) << tellers[i].get_total_idle_time();
		cout << setw(9) << std::setprecision(3)
			<< double(tellers[i].get_total_idle_time()) /
			tellers[i].get_num_customers_served();
		cout << endl;
	}
}
