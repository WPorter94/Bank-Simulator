//Copyright 2021
#include "Customer.h"
#include "Random.h"
extern Random myrandom;


Customer::Customer(int the_arrival_time) {
	this->arrival_time = the_arrival_time;
	this->delay_time = 0;
	this->service_time = myrandom.next_int(max_service_time);
	if (this->service_time == 0) {
		this->service_time += 1;
	}
}
int Customer::start_service(int time) {
	this->delay_time = time - this->arrival_time;
	this->total_delay_time += this->delay_time;
	this->total_customers_served++;
	return this->service_time + time;

}
int Customer::get_delay_time() const {
	return this->delay_time;
}
int Customer::get_arrival_time() const {
	return this->arrival_time;
}
int Customer::get_service_time() const {
	return this->service_time;
}
void Customer::set_max_service_time(int the_max_service_time) {
	max_service_time = the_max_service_time;
}
int Customer::get_total_delay_time() {
	return total_delay_time;
}
int Customer::get_total_customers_served() {
	return total_customers_served;
}
int Customer::total_delay_time = 0;
int Customer::max_service_time = 0;
int Customer::total_customers_served = 0;
