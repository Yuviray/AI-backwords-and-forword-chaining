/*Enclosed a program, which comprises the inference engine based on Forward chaining.  You need it for your
project #1.  The program contains some errors and it is not designed to be efficient.
Modify the program to make it better and efficient.  Explain in your report how you have modified the
program to make it better.
*/
/*** FORWARD CHAINING ***/
/************************/
/* Install your IF clauses in squence in the middle of
the program within the first case statement.
EXAMPLE: IF ((A1==2) && (A2==6) || (A3 == 'YES')) S-1;
IF (J=='NO') S-1;
The THEN part of the above construction always contains
S-1. Install your THEN clauses in sequence in the middle
of the program within the second case statement. */

#include <iostream>
#include <cstring>

int flag;
char cndvar[40][5];
char varlt[45][17], /* variable list*/ clvarlt[1445][17]; /* clause var list */
char c[3], vp[3], /* condition variable */  v[3]; /*variable */
char OIL_PUMP[4],OIL_FILTER[4],OIL[4],OIL_DRAIN_PLUG[4],ENGINE_GASKET[4],RADIATOR[4],RADIATOR_HOSE[4],
        TRANSMISION_DRAING_PLUG[4],BATTERY[4],IGNITION_SWITCH[4],STARTER_MOTOR[4],BATTERY_TERMINALS[4],FUEL_LEVEL[4],
        FUEL_CONDITION[4],FUEL_SYSTEM[4],VACUUM_HOSE[4],SPARK_PLUGS[4],FUEL_INJECTORS[4],IGNITION_WIRES[4],ENGINE_COMPONENTS[4]
,ALTERNATOR[4],ALTERNATOR_BELT[4],BATTERY_WIRES[4],ELECTRICAL_SYSTEM[4],COOLANT[4],DRIVE_BELT[4],RADIATOR_FAN[4],
        WATER_PUMP[4],TIRE_PRESSURE[4],AIR_FILTER[4],FUEL_TANK[4],FUEL_MANAGEMENT_SYSTEM[4],BRAKE_PARTS[4],BRAKE_LINES[4],
        REPLACE[4],RECONNECT[4];
char po[10],qu[10];
int instlt[17];         /* instantiated list*/
int f, i, j, k, s, fp   /* front pointer */;
int  bp  /* back pointer */,  gr /* grade */,  sn; /* statement number */
int cn;  /* clause number */

void search();
void check_instantiation();
void instantiate();
void b496();

int main() {
    /******** INITIALIZATION SECTION ***********/
    fp = 1;
    bp = 1;

    for (i = 1; i < 1676; i++)
        strcpy(clvarlt[i], "");
    for (i = 1; i < 40; i++)
        strcpy(cndvar[i], "");
    for (i = 1; i < 11; i++) {
        instlt[i] = 0;
    }

    for (i = 1; i < 45; i++)
        strcpy(varlt[i], "");
    for (i = 1; i < 17; i++) {
        strcpy(cndvar[i], "");
        strcpy(varlt[i], "");
        instlt[i] = 0;
    }

    /* enter variables which are in the IF part, 1 at a time in
    the exact order that they occur. Up to 3 variables per
    IF statement. Do not duplicate any variable names. Any
    name is used only once. If no more variables left, just
    hit return key */
    /****** comment 367 *************/
    strcpy(varlt[1], "OIL_PUMP");
    strcpy(varlt[2], "OIL_FILTER");
    strcpy(varlt[3], "OIL");
    strcpy(varlt[4], "OIL_DRAIN_PLUG");
    strcpy(varlt[5], "ENGINE_GASKET");
    strcpy(varlt[6], "RADIATOR");
    strcpy(varlt[7], "RADIATOR_HOSE");
    strcpy(varlt[8], "TRANSMISSION_DRAIN_PLUG");
    strcpy(varlt[9], "BATTERY");
    strcpy(varlt[10], "IGNITION_SWITCH");
    strcpy(varlt[11], "STARTER_MOTOR");
    strcpy(varlt[12], "BATTERY_TERMINALS");
    strcpy(varlt[13], "FUEL_LEVEL");
    strcpy(varlt[14], "FUEL_CONDITION");
    strcpy(varlt[15], "FUEL_SYSTEM");
    strcpy(varlt[16], "VACUUM_HOSE");
    strcpy(varlt[17], "SPARK_PLUGS");
    strcpy(varlt[18], "FUEL_INJECTORS");
    strcpy(varlt[19], "IGNITION_WIRES");
    strcpy(varlt[20], "ENGINE_COMPONENTS");
    strcpy(varlt[21], "ALTERNATOR");
    strcpy(varlt[22], "ALTERNATOR_BELT");
    strcpy(varlt[23], "BATTERY_WIRES");
    strcpy(varlt[24], "ELECTRICAL_SYSTEM");
    strcpy(varlt[25], "COOLANT");
    strcpy(varlt[26], "DRIVE_BELT");
    strcpy(varlt[27], "RADIATOR_FAN");
    strcpy(varlt[28], "WATER_PUMP");
    strcpy(varlt[29], "TIRE_PRESSURE");
    strcpy(varlt[30], "AIR_FILTER");
    strcpy(varlt[31], "FUEL_TANK");
    strcpy(varlt[32], "FUEL_MANAGEMENT_SYSTEM");
    strcpy(varlt[33], "BRAKE_PARTS");
    strcpy(varlt[34], "BRAKE_LINES");
    strcpy(varlt[35], "REPLACE");
    strcpy(varlt[36], "RECONNECT");

    printf("*** VARIABLE LIST ***\n");
    for (i = 1; i < 37; i++)
        printf("ENTER VARIABLE   %d   %s\n", i, varlt[i]);
    printf("HIT RETURN TO CONTINUE");
    getchar();

    /* enter variables as they appear in the IF clauses, Up to 3
    variables per IF statement. If no more variables left, just
    hit return key */
    /****** comment 407, 408 *************/
    printf("*** CLAUSE-VARIABLE LIST ***\n");
    strcpy(clvarlt[1], "OIL_PUMP");
    strcpy(clvarlt[39], "OIL_FILTER");
    strcpy(clvarlt[77], "OIL");
    strcpy(clvarlt[115], "OIL_DRAIN_PlUG");
    strcpy(clvarlt[153], "ENGINE_GASKET");
    strcpy(clvarlt[191], "RADIATOR");
    strcpy(clvarlt[229], "RADIATOR_HOSE");
    strcpy(clvarlt[267], "TRANSMISSION_DRAIN_PLUG");
    strcpy(clvarlt[305], "BATTERY");
    strcpy(clvarlt[343], "IGNITION_SWITCH");
    strcpy(clvarlt[381], "STARTER_MOTOR");
    strcpy(clvarlt[419], "BATTERY_TERMINALS");
    strcpy(clvarlt[457], "FUEL_LEVEL");
    strcpy(clvarlt[495], "FUEL_CONDITION");
    strcpy(clvarlt[533], "FUEL_SYSTEM");
    strcpy(clvarlt[571], "VACUUM_HOSE");
    strcpy(clvarlt[609], "SPARK_PLUGS");
    strcpy(clvarlt[647], "FUEL_INJECTORS");
    strcpy(clvarlt[685], "IGNITION_WIRES");
    strcpy(clvarlt[723], "ENGINE_COMPONENTS");
    strcpy(clvarlt[761], "BATTERY");
    strcpy(clvarlt[799], "ALTERNATOR");
    strcpy(clvarlt[837], "ALTERNATOR_BELT");
    strcpy(clvarlt[875], "BATTERY_WIRES");
    strcpy(clvarlt[913], "ELECTRICAL_SYSTEM");
    strcpy(clvarlt[951], "COOLANT");
    strcpy(clvarlt[989], "DRIVE_BELT");
    strcpy(clvarlt[1027], "RADIATOR");
    strcpy(clvarlt[1065], "RADIATOR_FAN");
    strcpy(clvarlt[1103], "WATER_PUMP");
    strcpy(clvarlt[1141], "TIRE_PRESSURE");
    strcpy(clvarlt[1179], "AIR_FILTER");
    strcpy(clvarlt[1217], "FUEL_TANK");
    strcpy(clvarlt[1255], "FUEL_MANAGEMENT_SYSTEM");
    strcpy(clvarlt[1293], "BRAKE_PARTS");
    strcpy(clvarlt[1331], "BRAKE_PARTS");
    strcpy(clvarlt[1369], "BRAKE_LINES");
    strcpy(clvarlt[1407], "BRAKE_PARTS");

    for (i = 1; i < 38; i++) {
        printf("** CLAUSE %d\n", i);
        for (j = 1; j < 38; j++) {
            k = 38 * (i - 1) + j;
            printf("VARIABLE %d  %s\n", j, clvarlt[k]);
        }

        if (i == 4) {
            printf("HIT RETURN TO CONTINUE");
            getchar();
        }
    }

    /****** INFERENCE SECTION *****************/
    printf("ENTER CONDITION VARIABLE? ");
    std::cin >> c;
    /* place condition variable c on condition var queue cndvar */
    strcpy(cndvar[bp], c);
    /* move backpointer (bp) to back */
    bp = bp + 1;
    /* set the condition variable pointer consisting of the
    statement number (sn) and the clause number (cn) */
    sn = 1;
    cn = 1;
    /* find the next statement number containing the condition variable
    which is in front of the queue (cndvar), this statement number
    is located in the clause variable list (clvarlt) */
    /* start at the beginning */
    f = 1;
    b496();
}
void b496(){
    bool exit = false;
    while(! false) {
        search();
        /* point to first clause in statement */
        cn = 1;
        if (sn != 0)
            /* more statements */
        {
            /* locate the clause */
            i = 4 * (sn - 1) + cn;
            /* clause variable */
            strcpy(v, clvarlt[i]);
            /* are there any more clauses for this statement */
            while (strcmp(v, "") != 0)
                /* more clauses */
            {
                /* check instantiation of this clause */
                check_instantiation();
                cn = cn + 1;
                /* check next clause */
                i = 4 * (sn - 1) + cn;
                strcpy(v, clvarlt[i]);
            }

            /* no more clauses - check IF part of statement */
            s = 0;
            /* sample IF-THEN statements from the position knowledge base */
            switch (sn) {
                /* statement 1 */
                /***** comment 1500 *****/
                case 1:
                    if (strcmp(OIL_PUMP, "BAD") == 0) s = 1;
                    break;
                    /* statement 2 */
                    /***** comment 1510 *****/
                case 2:
                    if (strcmp(OIL_FILTER, "BAD") == 0) s = 1;
                    break;
                    /* statement 3 */
                    /***** comment 1540 *****/
                case 3:
                    if (strcmp(OIL, "BAD") == 0) s = 1;

                    break;
                    /* statement 4 */
                    /***** comment 1550 *****/
                case 4:
                    if (strcmp(OIL_DRAIN_PLUG, "BAD") == 0) s = 1;

                    break;
                    /* statement 5 */
                case 5:
                    if (strcmp(ENGINE_GASKET, "BAD") == 0)s = 1;
                    break;
                    /* statement 6 */
                case 6:
                    if (strcmp(RADIATOR, "BAD") == 0) s = 1;

                    break;
                case 7:
                    if (strcmp(RADIATOR_HOSE, "BAD") == 0) s = 1;

                    break;
                case 8:
                    if (strcmp(TRANSMISION_DRAING_PLUG, "BAD") == 0) s = 1;

                    break;
                case 9:
                    if (strcmp(BATTERY, "BAD") == 0) s = 1;

                    break;
                case 10:
                    if (strcmp(IGNITION_SWITCH, "BAD") == 0) s = 1;

                    break;
                case 11:
                    if (strcmp(STARTER_MOTOR, "BAD") == 0) s = 1;

                    break;
                case 12:
                    if (strcmp(BATTERY_TERMINALS, "BAD") == 0) s = 1;

                    break;
                case 13:
                    if (strcmp(FUEL_LEVEL, "BAD") == 0) s = 1;

                    break;
                case 14:
                    if (strcmp(FUEL_CONDITION, "BAD") == 0) s = 1;

                    break;
                case 15:
                    if (strcmp(FUEL_SYSTEM, "BAD") == 0) s = 1;

                    break;
                case 16:
                    if (strcmp(VACUUM_HOSE, "BAD") == 0) s = 1;

                    break;
                case 17:
                    if (strcmp(SPARK_PLUGS, "BAD") == 0) s = 1;

                    break;
                case 18:
                    if (strcmp(FUEL_INJECTORS, "BAD") == 0) s = 1;

                    break;
                case 19:
                    if (strcmp(IGNITION_WIRES, "BAD") == 0) s = 1;

                    break;
                case 20:
                    if (strcmp(ENGINE_COMPONENTS, "BAD") == 0) s = 1;

                    break;
                case 21:
                    if (strcmp(BATTERY, "BAD") == 0) s = 1;

                    break;
                case 22:
                    if (strcmp(ALTERNATOR, "BAD") == 0) s = 1;

                    break;
                case 23:
                    if (strcmp(ALTERNATOR_BELT, "BAD") == 0) s = 1;

                    break;
                case 24:
                    if (strcmp(BATTERY_WIRES, "BAD") == 0) s = 1;

                    break;
                case 25:
                    if (strcmp(ELECTRICAL_SYSTEM, "BAD") == 0) s = 1;

                    break;
                case 26:
                    if (strcmp(COOLANT, "BAD") == 0) s = 1;

                    break;
                case 27:
                    if (strcmp(DRIVE_BELT, "BAD") == 0) s = 1;

                    break;
                case 28:
                    if (strcmp(RADIATOR_FAN, "BAD") == 0) s = 1;

                    break;
                case 29:
                    if (strcmp(WATER_PUMP, "BAD") == 0) s = 1;

                    break;
                case 30:
                    if (strcmp(TIRE_PRESSURE, "BAD") == 0) s = 1;

                    break;
                case 31:
                    if (strcmp(AIR_FILTER, "BAD") == 0) s = 1;

                    break;
                case 32:
                    if (strcmp(FUEL_TANK, "BAD") == 0) s = 1;

                    break;
                case 33:
                    if (strcmp(FUEL_MANAGEMENT_SYSTEM, "BAD") == 0) s = 1;

                    break;
                case 34:
                    if (strcmp(BRAKE_PARTS, "BAD") == 0) s = 1;

                    break;
                case 35:
                    if (strcmp(BRAKE_LINES, "BAD") == 0) s = 1;

                    break;
                    /***** comment 1610 *****/
            }

            /* see if the THEN part should be inovked, i.e., s=1 */
            if (s != 1) {
                f = sn + 1;
                //b496();
                continue;
            }
            /* invoke THEN part */
            switch (sn) {
                /*********** comment 1500 ***********/
                /* put variable on the conclusion variable queue */
                case 1:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    instantiate();
                    break;
                    /*********** comment 1510 ***********/
                    /* put variable on the conclusion variable queue */
                case 2:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    instantiate();
                    break;
                    /*********** comment 1540 ***********/
                    /* put variable on the conclusion variable queue */
                case 3:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    instantiate();
                    break;
                    /*********** comment 1550 ***********/
                    /* put variable on the conclusion variable queue */
                case 4:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    instantiate();
                    break;
                    /* put variable on the conclusion variable queue */
                case 5:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    instantiate();
                    break;
                case 6:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    instantiate();
                    break;
                    /*********** comment 1610 ***********/
                case 7:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    instantiate();
                    break;
                    /*********** comment 1510 ***********/
                    /* put variable on the conclusion variable queue */
                case 8:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    instantiate();
                    break;
                    /*********** comment 1540 ***********/
                    /* put variable on the conclusion variable queue */
                case 9:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    instantiate();
                    break;
                    /*********** comment 1550 ***********/
                    /* put variable on the conclusion variable queue */
                case 10:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    instantiate();
                    break;
                    /* put variable on the conclusion variable queue */
                case 11:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    instantiate();
                    break;
                case 12:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    instantiate();
                    break;
                case 13:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    instantiate();
                    break;
                    /*********** comment 1510 ***********/
                    /* put variable on the conclusion variable queue */
                case 14:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    instantiate();
                    break;
                    /*********** comment 1540 ***********/
                    /* put variable on the conclusion variable queue */
                case 15:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    instantiate();
                    break;
                    /*********** comment 1550 ***********/
                    /* put variable on the conclusion variable queue */
                case 16:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    instantiate();
                    break;
                    /* put variable on the conclusion variable queue */
                case 17:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    instantiate();
                    break;
                case 18:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    instantiate();
                    break;
                case 19:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    instantiate();
                    break;
                    /*********** comment 1510 ***********/
                    /* put variable on the conclusion variable queue */
                case 20:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    instantiate();
                    break;
                    /*********** comment 1540 ***********/
                    /* put variable on the conclusion variable queue */
                case 21:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    instantiate();
                    break;
                    /*********** comment 1550 ***********/
                    /* put variable on the conclusion variable queue */
                case 22:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    instantiate();
                    break;
                    /* put variable on the conclusion variable queue */
                case 23:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    instantiate();
                    break;
                case 24:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    instantiate();
                    break;
                case 25:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    instantiate();
                    break;
                    /*********** comment 1510 ***********/
                    /* put variable on the conclusion variable queue */
                case 26:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    instantiate();
                    break;
                    /*********** comment 1540 ***********/
                    /* put variable on the conclusion variable queue */
                case 27:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    instantiate();
                    break;
                    /*********** comment 1550 ***********/
                    /* put variable on the conclusion variable queue */
                case 28:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    instantiate();
                    break;
                    /* put variable on the conclusion variable queue */
                case 29:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    instantiate();
                    break;
                case 30:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    instantiate();
                    break;
                case 31:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    instantiate();
                    break;
                    /*********** comment 1510 ***********/
                    /* put variable on the conclusion variable queue */
                case 32:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    instantiate();
                    break;
                    /*********** comment 1540 ***********/
                    /* put variable on the conclusion variable queue */
                case 33:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    instantiate();
                    break;
                    /*********** comment 1550 ***********/
                    /* put variable on the conclusion variable queue */
                case 34:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    instantiate();
                    break;
                    /* put variable on the conclusion variable queue */
                case 35:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    instantiate();
                    break;
                case 36:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    instantiate();
                    break;
                case 37:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    instantiate();
                    break;
                    /*********** comment 1510 ***********/
                    /* put variable on the conclusion variable queue */
                case 38:
                    strcpy(REPLACE, "YES");
                    printf("Replace = YES\n");
                    strcpy(v, "Replace");
                    instantiate();
                    break;
                    /*********** comment 1540 ***********/
                    /* put variable on the conclusion variable queue */

            }
            f = sn + 1;
            //b496();
            continue;
        }
        fp = fp + 1;
        if (fp < bp) {
            /* check out the condition variable */
            f = 1;
            //b496();
            continue;
        }
        return;
    }
}
/* no more conclusion variables on queue */

//==========================================================================
/* Routine to instantiate a variable (v) if it isn't already.
The instantiate indication (instlt) is a 0 if not, a 1 if it is.
The vriable list (varlt) contains the variable (v) */

void check_instantiation()
{
    i=1;

    /* find variable in the variable list */
    while ((strcmp(v, varlt[i]) != 0) && (i <= 38)) i = i+1;

    /* check if already instantiated */
    if (instlt[i] != 1)
    {
        /* mark instantiated */
        instlt[i] = 1;
        /* the designer of this knowledge base places the input
        statements to instantiate the variables in this case
        statement */

        switch (i)
        {
            /* input statements for sample position knowledge base */
            case 1:
                printf("Is the Oil pump GOOD OR BAD?");
                std::cin >>OIL_PUMP;
                break;
            case 2:
                printf("Is the Oil filter GOOD OR BAD?");
                std::cin >>OIL_FILTER;
                break;
            case 3:
                printf("Is the Oil GOOD OR BAD?");
                std::cin >>OIL;
                break;
            case 4:
                printf("Is the Oil drain plug GOOD OR BAD?");
                std::cin >>OIL_DRAIN_PLUG;
                break;
            case 5:
                printf("Is the engine gasket GOOD OR BAD?");
                std::cin >>ENGINE_GASKET;
                break;
            case 6:
                printf("Is the radiator GOOD OR BAD?");
                std::cin >>RADIATOR;
                break;
            case 7:
                printf("Is the radiator hose GOOD OR BAD?");
                std::cin >>RADIATOR_HOSE;
                break;
            case 8:
                printf("Is the transmission drain plug GOOD OR BAD?");
                std::cin >>TRANSMISION_DRAING_PLUG;
                break;
            case 9:
                printf("Is the battery GOOD OR BAD?");
                std::cin >>BATTERY;
                break;
            case 10:
                printf("Is the ignition switch GOOD OR BAD?");
                std::cin >>IGNITION_SWITCH;
                break;
            case 11:
                printf("Is the starter motor GOOD OR BAD?");
                std::cin >>STARTER_MOTOR;
                break;
            case 12:
                printf("Is the battery terminals GOOD OR BAD?");
                std::cin >>BATTERY_TERMINALS;
                break;
            case 13:
                printf("Is the fuel level GOOD OR BAD?");
                std::cin >>FUEL_LEVEL;
                break;
            case 14:
                printf("Is the fuel condition GOOD OR BAD?");
                std::cin >>FUEL_CONDITION;
                break;
            case 15:
                printf("Is the fuel system GOOD OR BAD?");
                std::cin >>FUEL_SYSTEM;
                break;
            case 16:
                printf("Is the vacuum hose GOOD OR BAD?");
                std::cin >>VACUUM_HOSE;
                break;
            case 17:
                printf("Is the spark plugs GOOD OR BAD?");
                std::cin >>SPARK_PLUGS;
                break;
            case 18:
                printf("Is the fuel injectors GOOD OR BAD?");
                std::cin >>FUEL_INJECTORS;
                break;
            case 19:
                printf("Is the ignition wires GOOD OR BAD?");
                std::cin >>IGNITION_WIRES;
                break;
            case 20:
                printf("Is the engine components GOOD OR BAD?");
                std::cin >>ENGINE_COMPONENTS;
                break;
            case 21:
                printf("Is the battery GOOD OR BAD?");
                std::cin >>BATTERY;
                break;
            case 22:
                printf("Is the alternator GOOD OR BAD?");
                std::cin >>ALTERNATOR;
                break;
            case 23:
                printf("Is the alternator belt GOOD OR BAD?");
                std::cin >>ALTERNATOR_BELT;
                break;
            case 24:
                printf("Is the battery wires GOOD OR BAD?");
                std::cin >>BATTERY_WIRES;
                break;
            case 25:
                printf("Is the electrical system GOOD OR BAD?");
                std::cin >>ELECTRICAL_SYSTEM;
                break;
            case 26:
                printf("Is the coolant GOOD OR BAD?");
                std::cin >>COOLANT;
                break;
            case 27:
                printf("Is the drive belt GOOD OR BAD?");
                std::cin >>DRIVE_BELT;
                break;
            case 28:
                printf("Is the radiator GOOD OR BAD?");
                std::cin >>RADIATOR;
                break;
            case 29:
                printf("Is the radiator fan GOOD OR BAD?");
                std::cin >>RADIATOR_FAN;
                break;
            case 30:
                printf("Is the water pump GOOD OR BAD?");
                std::cin >>WATER_PUMP;
                break;
            case 31:
                printf("Is the tire pressure GOOD OR BAD?");
                std::cin >>TIRE_PRESSURE;
                break;
            case 32:
                printf("Is the air filter GOOD OR BAD?");
                std::cin >>AIR_FILTER;
                break;
            case 33:
                printf("Is the fuel tank GOOD OR BAD?");
                std::cin >>FUEL_TANK;
                break;
            case 34:
                printf("Is the fuel management system GOOD OR BAD?");
                std::cin >>FUEL_MANAGEMENT_SYSTEM;
                break;
            case 35:
                printf("Is the brake parts GOOD OR BAD?");
                std::cin >>BRAKE_PARTS;
                break;
            case 36:
                printf("Is the brake parts GOOD OR BAD?");
                std::cin >>BRAKE_PARTS;
                break;
            case 37:
                printf("Is the brake lines GOOD OR BAD?");
                std::cin >>BRAKE_LINES;
                break;
            case 38:
                printf("Is the brake parts GOOD OR BAD?");
                std::cin >>BRAKE_PARTS;
                break;

        }
    }
    /* end of input statements for the position knowledge base */
}

//==========================================================================
/* Search clause variable list for a varialbe (clvarlt) equal to the
one in front of the conclusion queue (cndvar). Return the statement
number (sn). If there is no match, i.e., sn=0, the first statement
for the space is f. */
void search()
{
    flag = 0;
    sn = f;

    while ((flag == 0) && (sn <= 10))
    {
        cn=1;
        k = (sn-1)*4+cn;
        while ((strcmp(clvarlt[k], cndvar[fp]) != 0) && (cn < 4))
        {
            cn = cn+1;
            k = (sn-1)*4+cn;
        }

        if (strcmp(clvarlt[k], cndvar[fp]) == 0) flag = 1;
        if (flag == 0) sn = sn+1;
    }
    if (flag == 0) sn=0;
}

//==========================================================================
/* Routine to instantiate a varialbe (v) and then place it on the
back of the queu (cndvar[bp]), if it is not already there. */
void instantiate()
{
    i=1;
    /* find varialbe in the varialbe list (varlt) */
    while ((strcmp(v, varlt[i]) != 0) && (i <= 38)) i=i+1;

    /* instantiate it */
    instlt[i] = 1;
    i = 1;

    /* determine if (v) is or already has been on the queue (cndvar) */
    while (((strcmp(v, cndvar[i]) != 0)) && (i <= 38)) i=i+1;

    /* variable has not been on the queue. Store it in the back of the queue */
    if (strcmp(v, cndvar[i]) != 0)
    {
        strcpy(cndvar[bp], v);
        bp=bp+1;
    }
}
