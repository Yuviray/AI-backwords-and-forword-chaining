//
// Created by maldo on 9/11/2022.
//
#include <string>

class bc{
private :
    /*****backward chaining *******/
/* Install your IF clauses in sequence in the first case
   statement of the main program
   example: if((a1==2) && (a2==6)) s=1;
                      if(strcmp(j, NO") != 0) s=1; 
   the then part of the above construction always
   contains s=1;
   install your the clauses in sequence in the second
   case statement of the main program
   example strcpy(po,"YES"); */
/*  conclusion list */
    char conclt[40][5]{};
/*  variable list */
    char varlt[45][17]{};
/*  clause variable list */
    char clvarlt[1676][17]{};
    char varble[45]{};
//char /* qualify */ qu[4], /* degree*/ de[4];
    char PART[4]{},PROBLEM[4]{},OIL_PRESSURE[4]{},OIL_FILTER[4]{},OIL_GRADE[4]{},LEAK[4]{},OIL_LEAK[4]{},COOLANT_LEAK[4]{},
            TRANS_LEAK[4]{},OIL_DRAIN_PLUG[4]{},ENGINE_LEAK[4]{},RADIATOR_LEAK[4]{},RADIATOR_HOSE[4]{},TRANS_DRAIN_PLUG[4]{},
            ENGINE_ROTATES[4]{},BATT_TERMINALS[4]{},FUEL[4]{},START_MOTOR[4]{},ROUGH[4]{},VACUUM_HOSE[4]{},SPARK_PLUGS[4]{},
            BAD_FUEL[4]{},FUEL_INJECTORS[4]{},IGNITION_WIRES[4]{},KNOCKING[4]{},BATT_CHARGE[4]{},BATT_TEST[4]{},ALTERNATOR[4]{},
            ALT_DRIVE_BELT[4]{},BATT_WIRES[4]{},OVERHEAT[4]{},COOLANT[4]{},DRIVE_BELT[4]{},RADIATOR[4]{},RADIATOR_FAN[4]{},FUEL_USE[4]{},
            TIRE_PRESSURE[4]{},AIR_FILTER[4]{},FUEL_SMELL[4]{},CHECK_BRAKE[4]{},WOBBLE[4]{},CHEMICAL_SMELL[4]{},SPONGEY[4]{},
            SQUEAK[4]{}, end[4]{};
    char buff[128]{};
/* instantiated list */
    int instlt[45]{};
/* statement stack */
    int statsk[45]{};
    int /* clause stack */ clausk[45]{}, sn{}, f{}, i{}, j{}, s{}, k{}, /*stack pointer */ sp{};
    float BATT_VOLTAGE{};
    void determine_member_concl_list(void);
    void push_on_stack(void);
    void instantiate(void);
    void b545(void);
    void b520(void);
    void popStack();
    char yourproblem();

public :
    char * start();
    bc(bool b);
};