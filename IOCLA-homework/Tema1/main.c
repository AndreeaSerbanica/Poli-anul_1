#include <stdio.h>
#include "structs.h"
#include <stdlib.h>
#include <string.h>


void (**operations_array)(void*);
void get_operations(void** operations_array);


int main(int argc, char const *argv[]) {


	FILE *fin;

	if (argc < 2) {
		return 1;
	}

	fin = fopen(argv[1], "rb");

	if (fin == NULL) {
		fputs("ERROR! NO FILE!!\n", stderr);
		exit(0);
	}

	int number_sensors, counter = 0;
	fread(&number_sensors, sizeof(int), 1, fin);
	sensor *prioritized_sensors = malloc(number_sensors * sizeof(sensor));
	sensor *sensor = malloc(number_sensors * sizeof(*sensor));
	for (int i = 0; i < number_sensors; i++) {
		fread(&sensor[i].sensor_type, sizeof(sensor[i].sensor_type), 1, fin);
		if(sensor[i].sensor_type == TIRE) {
			sensor[i].sensor_data = malloc(sizeof(tire_sensor));
			fread(sensor[i].sensor_data, sizeof(tire_sensor), 1, fin);
			fread(&sensor[i].nr_operations, sizeof(sensor[i].nr_operations), 1, fin);
			sensor[i].operations_idxs = malloc(sensor[i].nr_operations * sizeof(*sensor[i].operations_idxs));
			fread(sensor[i].operations_idxs, sizeof(*sensor[i].operations_idxs),sensor[i].nr_operations, fin);
		} else if (sensor[i].sensor_type == PMU) {
			sensor[i].sensor_data = malloc(sizeof(power_management_unit));
			fread(sensor[i].sensor_data, sizeof(power_management_unit), 1, fin);
			fread(&sensor[i].nr_operations, sizeof(sensor[i].nr_operations), 1, fin);
			sensor[i].operations_idxs = malloc(sensor[i].nr_operations * sizeof(*sensor[i].operations_idxs));
			fread(sensor[i].operations_idxs, sizeof(*sensor[i].operations_idxs),sensor[i].nr_operations, fin);
			// add PMU sensors in prioritized_sensor array
			prioritized_sensors[counter].sensor_type = PMU;
			prioritized_sensors[counter].sensor_data = malloc(sizeof(power_management_unit));
			power_management_unit *aux = (power_management_unit*)prioritized_sensors[counter].sensor_data; //pointer auxiliar
			power_management_unit *aux1 = (power_management_unit*)sensor[i].sensor_data; //pointer auxiliar
			aux->voltage = aux1->voltage;
			aux->current = aux1->current;
			aux->power_consumption = aux1->power_consumption;
			aux->energy_regen = aux1->energy_regen;
			aux->energy_storage = aux1->energy_storage;
			prioritized_sensors[counter].nr_operations = sensor[i].nr_operations;
			prioritized_sensors[counter].operations_idxs = malloc(sizeof(int) * sensor[i].nr_operations);
			for ( int j = 0; j < sensor[i].nr_operations; j++) {
				prioritized_sensors[counter].operations_idxs[j] = sensor[i].operations_idxs[j];
			}
			counter++;
		}
	}

	// add TIRE sensors in prioritized_sensor array
	for ( int i = 0; i < number_sensors; i++) {
		if (sensor[i].sensor_type == TIRE) {
			prioritized_sensors[counter].sensor_type = TIRE;
			prioritized_sensors[counter].sensor_data = malloc(sizeof(tire_sensor));
			tire_sensor *aux = (tire_sensor*)prioritized_sensors[counter].sensor_data; //pointer auxiliar
			tire_sensor *aux1 = (tire_sensor*)sensor[i].sensor_data; //poiner auxiliar
			aux->pressure = aux1->pressure;
			aux->temperature = aux1->temperature;
			aux->wear_level = aux1->wear_level;
			aux->performace_score = aux1->performace_score;
			prioritized_sensors[counter].nr_operations = sensor[i].nr_operations;
			prioritized_sensors[counter].operations_idxs = malloc(sizeof(int) * sensor[i].nr_operations);
			for ( int j = 0; j < sensor[i].nr_operations; j++) {
				prioritized_sensors[counter].operations_idxs[j] = sensor[i].operations_idxs[j];
			}
			counter++;
		}
	}

	for (int i = 0; i < number_sensors; i++){
		free(sensor[i].operations_idxs);
		free(sensor[i].sensor_data);
	}
	free(sensor);


	// we add the operations to the array
	operations_array = malloc(sizeof(void*) * 8);
	get_operations((void**)operations_array);

	// we read from terminal
	char command[50];
	int index;
	scanf("%s", command);
	while (strcmp(command, "exit") != 0) {
		if (strcmp(command, "print") == 0) {
			scanf("%d", &index);
			if ( index > number_sensors) {
				printf("Index not in range!\n");
				scanf("%s", command);
				continue;
			}else if (index < 0) {
				printf("Index not in range!\n");
				scanf("%s", command);
				continue;
			} else {
				int i = index;
				if (prioritized_sensors[i].sensor_type == TIRE) {
					printf("Tire Sensor\n");
					tire_sensor *ptr_tire_sensor = (tire_sensor*)prioritized_sensors[i].sensor_data;
					printf("Pressure: %.2f\n", ptr_tire_sensor->pressure);
					printf("Temperature: %.2f\n", ptr_tire_sensor->temperature);
					printf("Wear Level: %d%%\n", ptr_tire_sensor->wear_level);
					if (ptr_tire_sensor->performace_score >= 1 && ptr_tire_sensor->performace_score <= 10) {
						printf("Performance Score: %d\n", ptr_tire_sensor->performace_score);
					} else {
						printf("Performance Score: Not Calculated\n");
					}
				} else if (prioritized_sensors[i].sensor_type == PMU) {
					printf("Power Management Unit\n");
					power_management_unit *ptr_pmu_sensor = (power_management_unit*)prioritized_sensors[i].sensor_data;
					printf("Voltage: %.2f\n", ptr_pmu_sensor->voltage);
					printf("Current: %.2f\n", ptr_pmu_sensor->current);
					printf("Power Consumption: %.2f\n", ptr_pmu_sensor->power_consumption);
					printf("Energy Regen: %d%%\n", ptr_pmu_sensor->energy_regen);
					printf("Energy Storage: %d%%\n", ptr_pmu_sensor->energy_storage);
				}
			}
		} else if (strcmp(command, "analyze") == 0) {
			scanf("%d", &index);
			if ( index > number_sensors) {
				printf("Index not in range!\n");
				scanf("%s", command);
				continue;
			} else if (index < 0) {
				printf("Index not in range!\n");
				scanf("%s", command);
				continue;
			} else {
				int index_operations;
				void *ptr_sensor_data = prioritized_sensors[index].sensor_data;
				for (int j = 0 ; j < prioritized_sensors[index].nr_operations; j++) {
					index_operations = prioritized_sensors[index].operations_idxs[j];
					operations_array[index_operations](ptr_sensor_data);
				}
			}
		} else if (strcmp(command, "clear") == 0) {
			for (int i = 0; i < number_sensors; i++) {
				if (prioritized_sensors[i].sensor_type == TIRE) {
					tire_sensor *t = (tire_sensor*)prioritized_sensors[i].sensor_data;
					if ((t->pressure < 19 || t->pressure > 28) || (t->temperature < 0 || t->temperature > 120) || (t->wear_level < 0 || t->wear_level > 100)) {
						free(prioritized_sensors[i].operations_idxs);
						free(prioritized_sensors[i].sensor_data);
						for (int j = i + 1; j < number_sensors; j++) {
							prioritized_sensors[j - 1] = prioritized_sensors[j];
						}
						number_sensors--;
						i--;
					}
				} else if (prioritized_sensors[i].sensor_type == PMU) {
					power_management_unit *p = (power_management_unit*)prioritized_sensors[i].sensor_data;
					if ((p->voltage < 10 || p->voltage > 20) 
						|| (p->current < -100 || p->current > 100) 
						|| (p->power_consumption < 0 || p->power_consumption > 1000) 
						|| (p->energy_regen < 0 || p->energy_regen > 100) 
						|| (p->energy_storage < 0 || p->energy_storage > 100)) {
						free(prioritized_sensors[i].operations_idxs);
						free(prioritized_sensors[i].sensor_data);
						for (int  j = i + 1; j < number_sensors; j++) {
							prioritized_sensors[j - 1] = prioritized_sensors[j];
						}
						number_sensors--;
						i--;
					}
				}
			}

		}
		scanf("%s", command);
	}

	for (int i = 0; i < number_sensors; i++){
		free(prioritized_sensors[i].operations_idxs);
		free(prioritized_sensors[i].sensor_data);
	}
	free(prioritized_sensors);
	free(operations_array);
	fclose(fin);
	return 0;
}
