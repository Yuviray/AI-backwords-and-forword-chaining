//
// Created by maldo on 9/11/2022.
//
#include <string>

class fc{
private :
    int flag;
    char cndvar[40][5];
    char varlt[45][17], /* variable list*/ clvarlt[1445][17]; /* clause var list */
    char c[3], vp[3], /* condition variable */  v[3]; /*variable */
    char OIL_PUMP[4],OIL_FILTER[4],OIL[4],OIL_DRAIN_PLUG[4],ENGINE_GASKET[4],RADIATOR[4],RADIATOR_HOSE[4],
            TRANSMISSION_DRAIN_PLUG[4],BATTERY[4],IGNITION_SWITCH[4],STARTER_MOTOR[4],BATTERY_TERMINALS[4],FUEL_LEVEL[4],
            FUEL_CONDITION[4],FUEL_SYSTEM[4],VACUUM_HOSE[4],SPARK_PLUGS[4],FUEL_INJECTORS[4],IGNITION_WIRES[4],ENGINE_COMPONENTS[4]
    ,ALTERNATOR[4],ALTERNATOR_BELT[4],BATTERY_WIRES[4],ELECTRICAL_SYSTEM[4],COOLANT[4],DRIVE_BELT[4],RADIATOR_FAN[4],
            WATER_PUMP[4],TIRE_PRESSURE[4],AIR_FILTER[4],FUEL_TANK[4],FUEL_MANAGEMENT_SYSTEM[4],BRAKE_PARTS[4],BRAKE_LINES[4],
            REPLACE[4],RECONNECT[4];
    char po[10],qu[10];
    int instlt[17];         /* instantiated list*/
    int f, i, j, k, s, fp   /* front pointer */;
    int  bp  /* back pointer */,  gr /* grade */,  sn; /* statement number */
    int cn;  /* clause number */
    char end[4]{};

    void search();
    void check_instantiation();
    void instantiate();
    void b496();

public:
    fc(bool b);
    char * start();
};