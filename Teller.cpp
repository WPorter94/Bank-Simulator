//Copyright 2021 
#include "Teller.h"

Teller::Teller() {
	this->free = true;
	this->time_next_free = 0;
	this->num_customers_served = 0;
	this->time_service_started = 0;
	this->time_service_ended = 0;
	this->total_service_time = 0;
	this->total_idle_time = 0;
	this->currentCustomer = NULL;
}
bool Teller::is_free() const {
	return this->free;
}
int Teller::get_time_next_free() const {
	return this->time_next_free;
}
int Teller::get_total_service_time() const {
	return this->total_service_time;
}
int Teller::get_total_idle_time() const {
	return this->total_idle_time;
}
int Teller::get_num_customers_served() const {
	return this->num_customers_served;
}
void Teller::start_service(int time, Customer* currentCustomer) {
	
	this->currentCustomer = currentCustomer;
	this->free = false;
	this->time_service_started = time;
	this->total_idle_time += time - this->time_next_free;
	this->time_next_free = time + currentCustomer->get_service_time();
	this->num_customers_served++;

}
void Teller::end_service(int time) {
	this->time_service_ended = time;
	this->total_service_time += this->time_service_ended - this->time_service_started;
	this->free = true;
}
