#include<string>
#include<cstdio>
#include<cstring>
#include<iostream>

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
char conclt[40][5];
/*  variable list */
char varlt[45][17];
/*  clause variable list */
char clvarlt[1676][17];
char varble[3];
char /* qualify */ qu[4], /* degree*/ de[4];
char /* discovery */ di[4], /* position */ po[4],PART[4],PROBLEM[4],OIL_PRESSURE[4],OIL_FILTER[4],OIL_GRADE[4]
    ,LEAK[4],OIL_LEAK[4],COOLANT_LEAK[4],TRANS_LEAK[4],OIL_DRAIN_PLUG[4],ENGINE_LEAK[4],RADIATOR_LEAK[4],RADIATOR_HOSE[4],
    TRANS_DRAIN_PLUG[4],ENGINE_ROTATES[4],BATT_TERMINALS[4],FUEL[4],START_MOTOR[4],ROUGH[4],VACUUM_HOSE[4],
    SPARK_PLUGS[4],BAD_FUEL[4],FUEL_INJECTORS[4],IGNITION_WIRES[4],KNOCKING[4],BATT_CHARGE[4],BATT_TEST[4],ALTERNATOR[4],
    ALT_DRIVE_BELT[4],BATT_WIRES[4],OVERHEAT[4],COOLANT[4],DRIVE_BELT[4],RADIATOR[4],RADIATOR_FAN[4],FUEL_USE[4],TIRE_PRESSURE[4],
    AIR_FILTER[4],FUEL_SMELL[4],CHECK_BRAKE[4],WOBBLE[4],CHEMICAL_SMELL[4],SPONGEY[4],SQUEAK[4];
char buff[128];
/* instantiated list */
int instlt[45];
/* statement stack */
int statsk[45];
int /* clause stack */ clausk[45], sn, f, i, j, s, k, /*stack pointer */ sp;
float /* grade */ gr, /*experience */ ex,BATT_VOLTAGE;
void determine_member_concl_list(void);
void push_on_stack(void);
void instantiate(void);
void b545(void);
void b520(void);
void popStack();
int main() {
    /***** initialization section ******/
    /* stack space is 10 we initially place stack space at 10+1 */
    sp = 45;
    for (i = 1; i < 45; i++) {
        strcpy(conclt[i], "");
        strcpy(varlt[i], "");
        instlt[i] = 0;
        statsk[i] = 0;
        clausk[i] = 0;
    }
    for (i = 1; i < 1677; i++) strcpy(clvarlt[i], "");
    /* enter conclusions which are the variables in the then part,
1 at
    a time.  enter the conclusions in exact order starting at the 1st
    if-then.  after last conclusion hit return key for rest of
    conclusions */
    /*** comment 305 *****/
    strcpy(conclt[1], "Part");
    strcpy(conclt[2], "Part");
    strcpy(conclt[3], "Part");
    strcpy(conclt[4], "Part");
    strcpy(conclt[5], "Part");
    strcpy(conclt[6], "Part");
    strcpy(conclt[7], "Part");
    strcpy(conclt[8], "Part");
    strcpy(conclt[9], "Part");
    strcpy(conclt[10], "Part");
    strcpy(conclt[11], "Part");
    strcpy(conclt[12], "Part");
    strcpy(conclt[13], "Part");
    strcpy(conclt[14], "Part");
    strcpy(conclt[15], "Part");
    strcpy(conclt[16], "Part");
    strcpy(conclt[17], "Part");
    strcpy(conclt[18], "Part");
    strcpy(conclt[19], "Part");
    strcpy(conclt[20], "Part");
    strcpy(conclt[21], "Part");
    strcpy(conclt[22], "Part");
    strcpy(conclt[23], "Part");
    strcpy(conclt[24], "Part");
    strcpy(conclt[25], "Part");
    strcpy(conclt[26], "Part");
    strcpy(conclt[27], "Part");
    strcpy(conclt[28], "Part");
    strcpy(conclt[29], "Part");
    strcpy(conclt[30], "Part");
    strcpy(conclt[31], "Part");
    strcpy(conclt[32], "Part");
    strcpy(conclt[33], "Part");
    strcpy(conclt[34], "Part");
    strcpy(conclt[35], "Part");
    strcpy(conclt[36], "Part");
    strcpy(conclt[37], "Part");
    strcpy(conclt[38], "Part");
    strcpy(conclt[39], "Part");




    printf("*** CONCLUSION LIST ***\n");
    for (i = 1; i < 40; i++) printf("CONCLUSION %d %s\n", i, conclt[i]);
    printf("HIT RETURN TO CONTINUE");
    gets(buff);
    /* enter variables which are in the if part, 1 at a time in the
exact
    order that they occur, up to 3 variables per if statement.  do not
    duplicate any variable names.  any name is used only once.  if no
    more variables left just hit return key. */
    printf("*** VARIABLE LIST *\n");
    /**** comment 367 *****/
    strcpy(varlt[1], "PROBLEM");
    strcpy(varlt[2], "OIL_PRESSURE");
    strcpy(varlt[3], "OIL_FILTER");
    strcpy(varlt[4], "OIL_GRADE");
    strcpy(varlt[5], "LEAK");
    strcpy(varlt[6], "OIL_LEAK");
    strcpy(varlt[7], "COOLANT_LEAK");
    strcpy(varlt[8], "TRANS_LEAK");
    strcpy(varlt[9], "OIL_DRAIN_PLUG");
    strcpy(varlt[10], "ENGINE_LEAK");
    strcpy(varlt[11], "RADIATOR_LEAK");
    strcpy(varlt[12], "RADIATOR_HOSE");
    strcpy(varlt[13], "TRANS_DRAIN_PLUG");
    strcpy(varlt[14], "ENGINE_ROTATES");
    strcpy(varlt[15], "BATT_TERMINALS");
    strcpy(varlt[16], "FUEL");
    strcpy(varlt[17], "BATT_VOLTAGE");
    strcpy(varlt[18], "START_MOTOR");
    strcpy(varlt[19], "ROUGH");
    strcpy(varlt[20], "VACUUM_HOSE");
    strcpy(varlt[21], "SPARK_PLUGS");
    strcpy(varlt[22], "BAD_FUEL");
    strcpy(varlt[23], "FUEL_INJECTORS");
    strcpy(varlt[24], "IGNITION_SWITCH");
    strcpy(varlt[25], "KNOCKING");
    strcpy(varlt[26], "BATT_CHARGE");
    strcpy(varlt[27], "BATT_TEST");
    strcpy(varlt[28], "ALTERNATOR");
    strcpy(varlt[29], "ALT_DRIVE_BELT");
    strcpy(varlt[30], "BATT_WIRES");
    strcpy(varlt[31], "OVERHEAT");
    strcpy(varlt[32], "COOLANT");
    strcpy(varlt[33], "DRIVE_BELT");
    strcpy(varlt[34], "RADIATOR");
    strcpy(varlt[35], "RADIATOR_FAN");
    strcpy(varlt[36], "FUEL_USE");
    strcpy(varlt[37], "TIRE_PRESSURE");
    strcpy(varlt[38], "AIR_FILTER");
    strcpy(varlt[39], "FUEL_SMELL");
    strcpy(varlt[40], "CHECK_BRAKE");
    strcpy(varlt[41], "WOBBLE");
    strcpy(varlt[42], "CHEMICAL_SMELL");
    strcpy(varlt[43], "SPONGEY");
    strcpy(varlt[44], "SQUEAK");

    for (i = 1; i < 45; i++) printf("VARIABLE %d %s\n", i, varlt[i]);
    printf("HIT RETURN KEY TO CONTINUE");
    gets(buff);
    /* enter variables as they appear in the if clauses.  a maximum
of 3
    variables per if statement.  if no more variables hit return
key. */
    printf("*** CLAUSE VARIABLE LIST ***\n");
    /***** comment 407 through 409 ***/
    strcpy(clvarlt[1], "PROBLEM");
    strcpy(clvarlt[45], "PROBLEM");
    strcpy(clvarlt[46], "OIL_PRESSURE");
    strcpy(clvarlt[47], "OIL_GRADE");
    strcpy(clvarlt[48], "OIL_FILTER");
    strcpy(clvarlt[89], "PROBLEM");
    strcpy(clvarlt[90], "OIL_PRESSURE");
    strcpy(clvarlt[91], "OIL_GRADE");
    strcpy(clvarlt[92], "OIL_FILTER");
    strcpy(clvarlt[133], "PROBLEM");
    strcpy(clvarlt[134], "OIL_PRESSURE");
    strcpy(clvarlt[135], "OIL_GRADE");
    strcpy(clvarlt[177], "PROBLEM");
    strcpy(clvarlt[178], "LEAK");
    strcpy(clvarlt[179], "OIL_LEAK");
    strcpy(clvarlt[180], "OIL_DRAIN_PLUG");
    strcpy(clvarlt[221], "PROBLEM");
    strcpy(clvarlt[222], "LEAK");
    strcpy(clvarlt[223], "OIL_LEAK");
    strcpy(clvarlt[224], "ENGINE_LEAK");
    strcpy(clvarlt[265], "PROBLEM");
    strcpy(clvarlt[266], "LEAK");
    strcpy(clvarlt[267], "COOLANT_LEAK");
    strcpy(clvarlt[268], "RADIATOR_LEAK");
    strcpy(clvarlt[309], "PROBLEM");
    strcpy(clvarlt[310], "LEAK");
    strcpy(clvarlt[311], "COOLANT_LEAK");
    strcpy(clvarlt[312], "RADIATOR_HOSE");
    strcpy(clvarlt[353], "PROBLEM");
    strcpy(clvarlt[354], "LEAK");
    strcpy(clvarlt[355], "TRANS_LEAK");
    strcpy(clvarlt[356], "TRANS_DRAIN_PLUG");
    strcpy(clvarlt[397], "PROBLEM");
    strcpy(clvarlt[398], "ENGINE_ROTATES");
    strcpy(clvarlt[399], "BATT_TERMINALS");
    strcpy(clvarlt[400], "BATT_VOLTAGE");
    strcpy(clvarlt[441], "PROBLEM");
    strcpy(clvarlt[442], "ENGINE_ROTATES");
    strcpy(clvarlt[443], "BATT_TERMINALS");
    strcpy(clvarlt[444], "BATT_VOLTAGE");
    strcpy(clvarlt[445], "START_MOTOR");
    strcpy(clvarlt[485], "PROBLEM");
    strcpy(clvarlt[486], "ENGINE_ROTATES");
    strcpy(clvarlt[487], "BATT_TERMINALS");
    strcpy(clvarlt[488], "BATT_VOLTAGE");
    strcpy(clvarlt[489], "START_MOTOR");
    strcpy(clvarlt[529], "PROBLEM");
    strcpy(clvarlt[530], "ENGINE_ROTATES");
    strcpy(clvarlt[531], "BATT_TERMINALS");
    strcpy(clvarlt[573], "PROBLEM");
    strcpy(clvarlt[574], "ENGINE_ROTATES");
    strcpy(clvarlt[575], "FUEL");
    strcpy(clvarlt[617], "PROBLEM");
    strcpy(clvarlt[618], "ENGINE_ROTATES");
    strcpy(clvarlt[619], "FUEL");
    strcpy(clvarlt[661], "PROBLEM");
    strcpy(clvarlt[662], "ROUGH");
    strcpy(clvarlt[663], "VACUUM_HOSE");
    strcpy(clvarlt[705], "PROBLEM");
    strcpy(clvarlt[706], "ROUGH");
    strcpy(clvarlt[707], "SPARK_PLUGS");
    strcpy(clvarlt[749], "PROBLEM");
    strcpy(clvarlt[750], "ROUGH");
    strcpy(clvarlt[751], "BAD_FUEL");
    strcpy(clvarlt[793], "PROBLEM");
    strcpy(clvarlt[794], "ROUGH");
    strcpy(clvarlt[795], "FUEL_INJECTORS");
    strcpy(clvarlt[837], "PROBLEM");
    strcpy(clvarlt[838], "ROUGH");
    strcpy(clvarlt[839], "IGNITION_WIRES");
    strcpy(clvarlt[881], "PROBLEM");
    strcpy(clvarlt[882], "ROUGH");
    strcpy(clvarlt[883], "KNOCKING");
    strcpy(clvarlt[925], "PROBLEM");
    strcpy(clvarlt[926], "BATT_CHARGE");
    strcpy(clvarlt[927], "BATT_TEST");
    strcpy(clvarlt[969], "PROBLEM");
    strcpy(clvarlt[970], "BATT_CHARGE");
    strcpy(clvarlt[971], "BATT_TEST");
    strcpy(clvarlt[972], "ALTERNATOR");
    strcpy(clvarlt[1013], "PROBLEM");
    strcpy(clvarlt[1014], "BATT_CHARGE");
    strcpy(clvarlt[1015], "BATT_TEST");
    strcpy(clvarlt[1016], "ALTERNATOR");
    strcpy(clvarlt[1017], "ALT_DRIVE_BELT");
    strcpy(clvarlt[1057], "PROBLEM");
    strcpy(clvarlt[1058], "BATT_CHARGE");
    strcpy(clvarlt[1059], "BATT_TEST");
    strcpy(clvarlt[1060], "ALTERNATOR");
    strcpy(clvarlt[1061], "ALT_DRIVE_BELT");
    strcpy(clvarlt[1062], "BATT_WIRES");
    strcpy(clvarlt[1101], "PROBLEM");
    strcpy(clvarlt[1102], "BATT_CHARGE");
    strcpy(clvarlt[1103], "BATT_TEST");
    strcpy(clvarlt[1104], "ALTERNATOR");
    strcpy(clvarlt[1105], "ALT_DRIVE_BELT");
    strcpy(clvarlt[1106], "BATT_WIRES");
    strcpy(clvarlt[1145], "PROBLEM");
    strcpy(clvarlt[1146], "OVERHEAT");
    strcpy(clvarlt[1147], "COOLANT");
    strcpy(clvarlt[1189], "PROBLEM");
    strcpy(clvarlt[1190], "OVERHEAT");
    strcpy(clvarlt[1191], "COOLANT");
    strcpy(clvarlt[1192], "DRIVE_BELT");
    strcpy(clvarlt[1233], "PROBLEM");
    strcpy(clvarlt[1234], "OVERHEAT");
    strcpy(clvarlt[1235], "COOLANT");
    strcpy(clvarlt[1236], "DRIVE_BELT");
    strcpy(clvarlt[1237], "RADIATOR");
    strcpy(clvarlt[1277], "PROBLEM");
    strcpy(clvarlt[1278], "OVERHEAT");
    strcpy(clvarlt[1279], "COOLANT");
    strcpy(clvarlt[1280], "DRIVE_BELT");
    strcpy(clvarlt[1281], "RADIATOR");
    strcpy(clvarlt[1282], "RADIATOR_FAN");
    strcpy(clvarlt[1321], "PROBLEM");
    strcpy(clvarlt[1322], "OVERHEAT");
    strcpy(clvarlt[1323], "COOLANT");
    strcpy(clvarlt[1324], "DRIVE_BELT");
    strcpy(clvarlt[1325], "RADIATOR");
    strcpy(clvarlt[1326], "RADIATOR_FAN");
    strcpy(clvarlt[1365], "PROBLEM");
    strcpy(clvarlt[1366], "FUEL_USE");
    strcpy(clvarlt[1364], "TIRE_PRESSURE");
    strcpy(clvarlt[1409], "PROBLEM");
    strcpy(clvarlt[1410], "FUEL_USE");
    strcpy(clvarlt[1411], "TIRE_PRESSURE");
    strcpy(clvarlt[1412], "AIR_FILTER");
    strcpy(clvarlt[1453], "PROBLEM");
    strcpy(clvarlt[1454], "FUEL_USE");
    strcpy(clvarlt[1455], "TIRE_PRESSURE");
    strcpy(clvarlt[1456], "AIR_FILTER");
    strcpy(clvarlt[1457], "FUEL_SMELL");
    strcpy(clvarlt[1497], "PROBLEM");
    strcpy(clvarlt[1498], "FUEL_USE");
    strcpy(clvarlt[1499], "TIRE_PRESSURE");
    strcpy(clvarlt[1500], "AIR_FILTER");
    strcpy(clvarlt[1501], "FUEL_SMELL");
    strcpy(clvarlt[1541], "PROBLEM");
    strcpy(clvarlt[1542], "CHECK_BRAKE");
    strcpy(clvarlt[1543], "WOBBLE");
    strcpy(clvarlt[1585], "PROBLEM");
    strcpy(clvarlt[1586], "CHECK_BRAKE");
    strcpy(clvarlt[1587], "CHEMICAL_SMELL");
    strcpy(clvarlt[1629], "PROBLEM");
    strcpy(clvarlt[1630], "CHECK_BRAKE");
    strcpy(clvarlt[1631], "SPONGEY");
    strcpy(clvarlt[1673], "PROBLEM");
    strcpy(clvarlt[1674], "CHECK_BRAKE");
    strcpy(clvarlt[1675], "SQUEAK");


    for (i = 1; i < 40; i++) {
        printf("** CLAUSE %d\n", i);
        for (j = 1; j < 45; j++) {
            k = 44 * (i - 1) + j;
            printf("VARIABLE %d  %s\n", j, clvarlt[k]);
        }
        /*if (i == 4) {
            printf("HIT RETURN KEY TO CONTINUE");
            gets(buff);
        }*/
    }
    /****** inference section *****/
    printf("** ENTER CONCLUSION ? ");
    gets(varble);
    /* get conclusion statement number (sn) from the conclusion list
       (conclt) */
    /* first statement starts search */
    b520();
}

void determine_member_concl_list() {
/* routine to determine if a variable (varble) is a member of the
   conclusion list (conclt).  if yes return sn != 0.
   if not a member sn=0;
*/
    /* initially set to not a member */
    sn = 0;
    /* member of conclusion list to be searched is f */
    i = f;
    while((strcmp(varble, conclt[i]) != 0) && (i<40))
        /* test for membership */
        {
            i=i+1;

        }
    printf("\ni is %d\n", i);
    if (strcmp(varble, conclt[i]) == 0) sn = i;  /* a member */
}
void push_on_stack()
/* routine to push statement number (sn) and a clause number of 1 onto the
conclusion stack which consists of the statement stack (statsk) and the
clause stack (clausk)..to push decrement stack pointer (sp) */
{
    sp=sp-1;
    statsk[sp] = sn;
    clausk[sp] = 1;
}
void instantiate()
/* routine to instantiate a variable (varble) if it isn't already.  the
instantiate indication (instlt) is a 0 if not, a 1 if it is.  the
variable list (varlt) contains the variable (varble). */
{
    i=1;
    /* find variable in the list */
    while((strcmp(varble, varlt[i]) != 0) && (i<45)) i=i+1;
    if((strcmp(varble, varlt[i]) == 0) && (instlt[i] != 1))
        /*found variable and not already instantiated */
    {
        instlt[i]=1; /*mark instantiated */
        /* the designer of the
       knowledge base places the input statements to
       instantiate the variables below in the case statement */
        switch (i)
        {
            /***** input statement *****/
            /* input statements for sample position knowledge
               base */
            /***** comment 1700 ******/
            case 1: printf("Is there a problem with the car? INPUT YES OR NO");
                gets(PROBLEM);
                break;
            case 2: printf("Is the oil pressure low? INPUT YES OR NO");
                gets(OIL_PRESSURE);
                break;
            case 3: printf("Is the oil filter new? INPUT YES OR NO");
                gets(OIL_FILTER);
                break;
            case 4: printf("Is the oil grade correct? INPUT YES OR NO");
                gets(OIL_GRADE);
                break;
            case 5: printf("Do you see a leak? INPUT YES OR NO");
                gets(LEAK);
                break;
            case 6: printf("Is it an oil leak? INPUT YES OR NO");
                gets(OIL_LEAK);
                break;
            case 7: printf("Is it a coolant leak? INPUT YES OR NO");
                gets(COOLANT_LEAK);
                break;
            case 8: printf("Is it a transmission fluid leak? INPUT YES OR NO");
                gets(TRANS_LEAK);
                break;
            case 9: printf("Is the leak coming from the oil drain plug? INPUT YES OR NO");
                gets(OIL_DRAIN_PLUG);
                break;
            case 10: printf("Is the leak coming from a seam in the engine? INPUT YES OR NO");
                gets(ENGINE_LEAK);
                break;
            case 11: printf("Is the leak coming from the radiator? INPUT YES OR NO");
                gets(RADIATOR_LEAK);
                break;
            case 12: printf("Is the leak coming from a radiator hose? INPUT YES OR NO");
                gets(RADIATOR_HOSE);
                break;
            case 13: printf("Is the leak coming from the transmission drain plug? INPUT YES OR NO");
                gets(TRANS_DRAIN_PLUG);
                break;
            case 14: printf("Does the engine rotate when starting? INPUT YES OR NO");
                gets(ENGINE_ROTATES);
                break;
            case 15: printf("Are the battery terminals connected? INPUT YES OR NO");
                gets(BATT_TERMINALS);
                break;
            case 16: printf("Is there fuel in the tank? INPUT YES OR NO");
                gets(FUEL);
                break;
            case 17: printf("What is the battery voltage? INPUT A REAL NUMBER");
                scanf("%f", &BATT_VOLTAGE);
                break;
            case 18: printf("Is the starter motor working? INPUT YES OR NO");
                gets(START_MOTOR);
                break;
            case 19: printf("Is the car running roughly? INPUT YES OR NO");
                gets(ROUGH);
                break;
            case 20: printf("Are the vacuum hoses worn? INPUT YES OR NO");
                gets(VACUUM_HOSE);
                break;
            case 21: printf("Do the spark plugs looked burned or corroded? INPUT YES OR NO");
                gets(SPARK_PLUGS);
                break;
            case 22: printf("Is there water in the fuel? INPUT YES OR NO");
                gets(BAD_FUEL);
                break;
            case 23: printf(" Do the injectors look clogged or corroded? INPUT YES OR NO");
                gets(FUEL_INJECTORS);
                break;
            case 24: printf("Do the ignition wired look worn or cracked? INPUT YES OR NO");
                gets(IGNITION_WIRES);
                break;
            case 25: printf("Is there a knocking noise coming from inside the engine? INPUT YES OR NO");
                gets(KNOCKING);
                break;
            case 26: printf("Does the battery hold a charge? INPUT YES OR NO");
                gets(BATT_CHARGE);
                break;
            case 27: printf("Does the battery test ok? INPUT YES OR NO");
                gets(BATT_TEST);
                break;
            case 28: printf("Does the alternator test ok? INPUT YES OR NO");
                gets(ALTERNATOR);
                break;
            case 29: printf("Does the alternator drive belt look worn? INPUT YES OR NO");
                gets(ALT_DRIVE_BELT);
                break;
            case 30: printf("Are the battery wires worn or cracked? INPUT YES OR NO");
                gets(BATT_WIRES);
                break;
            case 31: printf("Does the car overheat? INPUT YES OR NO");
                gets(OVERHEAT);
                break;
            case 32: printf("Is there coolant? INPUT YES OR NO");
                gets(COOLANT);
                break;
            case 33: printf("Is the drive belt worn or stretched? INPUT YES OR NO");
                gets(DRIVE_BELT);
                break;
            case 34: printf("Does the radiator look dirty or corroded? INPUT YES OR NO");
                gets(RADIATOR);
                break;
            case 35: printf("Does the radiator fan work? INPUT YES OR NO");
                gets(RADIATOR_FAN);
                break;
            case 36: printf("Is there excessive fuel consumption? INPUT YES OR NO");
                gets(FUEL_USE);
                break;
            case 37: printf("Is the tire pressure correct? INPUT YES OR NO");
                gets(TIRE_PRESSURE);
                break;
            case 38: printf("Does the air filter look clean? INPUT YES OR NO");
                gets(AIR_FILTER);
                break;
            case 39: printf("Can you smell fuel under the car?INPUT YES OR NO");
                gets(FUEL_SMELL);
                break;
            case 40: printf("Is the check brake light on? INPUT YES OR NO");
                gets(CHECK_BRAKE);
                break;
            case 41: printf("Is there a wobble or vibration when braking? INPUT YES OR NO");
                gets(WOBBLE);
                break;
            case 42: printf("Is there a chemical burning smell when braking? INPUT YES OR NO");
                gets(CHEMICAL_SMELL);
                break;
            case 43: printf("Is braking spongey or soft? INPUT YES OR NO");
                gets(SPONGEY);
                break;
            case 44: printf("Is there a squeaking noise when braking?INPUT YES OR NO");
                gets(SQUEAK);
                break;




                /***** comment 1715 ****/
        }
        /* end of inputs statements for sample position knowledge
           base */
    }
}
void b520(){
    f=1;
    determine_member_concl_list();

    if (sn != 0){
        /* if sn = 0 then no conclusion of that name */ do
            /* push statement number (sn) and clause number=1 on
goal
               stack which is composed of the statement stack
(statsk)
               and clause stack (clausk) */
        {
            push_on_stack();
            do
            {
                /* calculate clause location in clause-variable
                   list */
                b545();
            } while(strcmp(varble, "") != 0); /*do-while*/
            /*no more clauses check if part of statement */
            sn = statsk[sp];
            s = 0;
            /**** if then statements ****/
            /* sample if parts of if then statements from
               the position knowledge base */
            switch (sn) {
                /* if part of statement 1 */
                /****** comment 1500 ****/
                case 1: if(strcmp(PROBLEM, "NO") == 0) s = 1;
                    break;
                    /* if part of statement 2 */
                    /***** comment 1510 ******/
                case 2: if((strcmp(PROBLEM, "YES") == 0) &&
                           (strcmp(OIL_PRESSURE, "YES") == 0)&&
                           (strcmp(OIL_GRADE, "YES") == 0)&&
                           (strcmp(OIL_FILTER, "YES") == 0)) s = 1;
                    break;
                    /* if part of statement 3 */
                case 3:
                    if ((strcmp(PROBLEM, "YES") == 0) &&
                        (strcmp(OIL_PRESSURE, "YES") == 0) &&
                        (strcmp(OIL_GRADE, "YES") == 0) &&
                        (strcmp(OIL_FILTER, "NO") == 0)) s = 1;
                    break;
                    /* if part of statement 4 */
                    /******** comment 1560 ******/
                case 4: if((strcmp(PROBLEM, "YES") == 0) &&
                           (strcmp(OIL_PRESSURE, "YES") == 0) &&
                           (strcmp(OIL_GRADE, "NO") == 0)) s = 1;
                    break;
                    /******** comment 1570 ********/
                    /* if part of statement 5 */
                case 5: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(LEAK, "YES") == 0) &&
                            (strcmp(OIL_LEAK, "YES") == 0) &&
                            (strcmp(OIL_DRAIN_PLUG, "YES") == 0)) s = 1;
                    break;
                    /* if part of statement 6 */
                case 6: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(LEAK, "YES") == 0) &&
                            (strcmp(OIL_LEAK, "YES") == 0) &&
                            (strcmp(ENGINE_LEAK, "YES") == 0)) s = 1;
                    break;
                case 7: if((strcmp(PROBLEM, "YES") == 0) &&
                               (strcmp(LEAK, "YES") == 0) &&
                               (strcmp(COOLANT_LEAK, "YES") == 0) &&
                               (strcmp(RADIATOR_LEAK, "YES") == 0)) s = 1;
                    break;
                    /* if part of statement 3 */
                case 8:
                    if ((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(LEAK, "YES") == 0) &&
                            (strcmp(COOLANT_LEAK, "YES") == 0) &&
                            (strcmp(RADIATOR_HOSE, "YES") == 0)) s = 1;
                    break;
                    /* if part of statement 4 */
                    /******** comment 1560 ******/
                case 9: if((strcmp(PROBLEM, "YES") == 0) &&
                    (strcmp(LEAK, "YES") == 0) &&
                    (strcmp(TRANS_LEAK, "YES") == 0) &&
                    (strcmp(TRANS_DRAIN_PLUG, "YES") == 0)) s = 1;
                    break;
                    /******** comment 1570 ********/
                    /* if part of statement 5 */
                case 10: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(ENGINE_ROTATES, "NO") == 0) &&
                            (strcmp(BATT_TERMINALS, "YES") == 0) &&
                            (BATT_VOLTAGE<12)) s = 1;
                    break;
                    /* if part of statement 6 */
                case 11: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(ENGINE_ROTATES, "NO") == 0) &&
                            (strcmp(BATT_TERMINALS, "YES") == 0) &&
                            (BATT_VOLTAGE >= 12.0) &&
                            (strcmp(START_MOTOR, "YES") == 0) )s = 1;
                    break;
                case 12: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(ENGINE_ROTATES, "NO") == 0) &&
                            (strcmp(BATT_TERMINALS, "YES") == 0) &&
                            (BATT_VOLTAGE>=12)&&
                            (strcmp(START_MOTOR, "NO") == 0) )s = 1;
                    break;
                    /* if part of statement 3 */
                case 13:
                    if ((strcmp(PROBLEM, "YES") == 0) &&
                        (strcmp(ENGINE_ROTATES, "NO") == 0) &&
                        (strcmp(BATT_TERMINALS, "NO") == 0)) s = 1;
                    break;
                    /* if part of statement 4 */
                    /******** comment 1560 ******/
                case 14: if((strcmp(PROBLEM, "YES") == 0) &&
                           (strcmp(ENGINE_ROTATES, "YES") == 0) &&
                           (strcmp(FUEL, "NO") == 0)) s = 1;
                    break;
                    /******** comment 1570 ********/
                    /* if part of statement 5 */
                case 15: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(ENGINE_ROTATES, "YES") == 0) &&
                            (strcmp(FUEL, "YES") == 0)) s = 1;
                    break;
                    /* if part of statement 6 */
                case 16: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(ROUGH, "YES") == 0) &&
                            (strcmp(VACUUM_HOSE, "YES") == 0)) s = 1;
                    break;
                case 17: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(ROUGH, "YES") == 0) &&
                            (strcmp(SPARK_PLUGS, "YES") == 0)) s = 1;
                    break;
                    /* if part of statement 3 */
                case 18:
                    if((strcmp(PROBLEM, "YES") == 0) &&
                       (strcmp(ROUGH, "YES") == 0) &&
                       (strcmp(BAD_FUEL, "YES") == 0)) s = 1;
                    break;
                    /* if part of statement 4 */
                    /******** comment 1560 ******/
                case 19: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(ROUGH, "YES") == 0) &&
                            (strcmp(FUEL_INJECTORS, "YES") == 0)) s = 1;
                    break;
                    /******** comment 1570 ********/
                    /* if part of statement 5 */
                case 20: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(ROUGH, "YES") == 0) &&
                            (strcmp(IGNITION_WIRES, "YES") == 0)) s = 1;
                    break;
                    /* if part of statement 6 */
                case 21: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(ROUGH, "YES") == 0) &&
                            (strcmp(KNOCKING, "YES") == 0)) s = 1;
                    break;
                case 22: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(BATT_CHARGE, "NO") == 0) &&
                            (strcmp(BATT_TEST, "NO") == 0)) s = 1;
                    break;
                    /* if part of statement 3 */
                case 23:
                    if((strcmp(PROBLEM, "YES") == 0) &&
                       (strcmp(BATT_CHARGE, "NO") == 0) &&
                       (strcmp(BATT_TEST, "YES") == 0) &&
                        (strcmp(ALTERNATOR, "NO") == 0)) s = 1;
                    break;
                    /* if part of statement 4 */
                    /******** comment 1560 ******/
                case 24: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(BATT_CHARGE, "NO") == 0) &&
                            (strcmp(BATT_TEST, "YES") == 0) &&
                            (strcmp(ALTERNATOR, "YES") == 0)&&
                            (strcmp(ALT_DRIVE_BELT, "YES") == 0)) s = 1;
                    break;
                    /******** comment 1570 ********/
                    /* if part of statement 5 */
                case 25: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(BATT_CHARGE, "NO") == 0) &&
                            (strcmp(BATT_TEST, "YES") == 0) &&
                            (strcmp(ALTERNATOR, "YES") == 0)&&
                            (strcmp(ALT_DRIVE_BELT, "YES") == 0)&&
                            (strcmp(BATT_WIRES, "YES") == 0)) s = 1;
                    break;
                    /* if part of statement 6 */
                case 26: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(BATT_CHARGE, "NO") == 0) &&
                            (strcmp(BATT_TEST, "YES") == 0) &&
                            (strcmp(ALTERNATOR, "YES") == 0)&&
                            (strcmp(ALT_DRIVE_BELT, "YES") == 0)&&
                            (strcmp(BATT_WIRES, "NO") == 0)) s = 1;
                    break;
                case 27: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(OVERHEAT, "YES") == 0) &&
                            (strcmp(COOLANT, "NO") == 0)) s = 1;
                    break;
                    /******** comment 1570 ********/
                    /* if part of statement 5 */
                case 28: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(OVERHEAT, "YES") == 0) &&
                            (strcmp(OVERHEAT, "YES") == 0) &&
                            (strcmp(DRIVE_BELT, "YES") == 0)) s = 1;
                    break;
                    /* if part of statement 6 */
                case 29: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(OVERHEAT, "YES") == 0) &&
                            (strcmp(COOLANT, "YES") == 0)&&
                            (strcmp(DRIVE_BELT, "NO") == 0)&&
                            (strcmp(RADIATOR, "YES") == 0)) s = 1;
                    break;
                case 30: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(OVERHEAT, "YES") == 0) &&
                            (strcmp(COOLANT, "YES") == 0)&&
                            (strcmp(DRIVE_BELT, "NO") == 0)&&
                            (strcmp(RADIATOR, "NO") == 0)&&
                            (strcmp(RADIATOR_FAN, "NO") == 0)) s = 1;
                    break;
                    /* if part of statement 3 */
                case 31:
                    if((strcmp(PROBLEM, "YES") == 0) &&
                       (strcmp(OVERHEAT, "YES") == 0) &&
                       (strcmp(COOLANT, "YES") == 0)&&
                       (strcmp(DRIVE_BELT, "NO") == 0)&&
                       (strcmp(RADIATOR, "NO") == 0)&&
                       (strcmp(RADIATOR_FAN, "YES") == 0)) s = 1;
                    break;
                    /* if part of statement 4 */
                    /******** comment 1560 ******/
                case 32: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(FUEL_USE, "YES") == 0) &&
                            (strcmp(TIRE_PRESSURE, "NO") == 0)) s = 1;
                    break;
                    /******** comment 1570 ********/
                    /* if part of statement 5 */
                case 33: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(FUEL_USE, "YES") == 0) &&
                            (strcmp(TIRE_PRESSURE, "YES") == 0) &&
                            (strcmp(AIR_FILTER, "NO") == 0)) s = 1;
                    break;
                    /* if part of statement 6 */
                case 34: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(FUEL_USE, "YES") == 0) &&
                            (strcmp(TIRE_PRESSURE, "YES") == 0) &&
                            (strcmp(AIR_FILTER, "YES") == 0)&&
                            (strcmp(FUEL_SMELL, "YES") == 0)) s = 1;
                    break;
                case 35: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(FUEL_USE, "YES") == 0) &&
                            (strcmp(TIRE_PRESSURE, "YES") == 0) &&
                            (strcmp(AIR_FILTER, "YES") == 0)&&
                            (strcmp(FUEL_SMELL, "NO") == 0)) s = 1;
                    break;
                    /* if part of statement 6 */
                case 36: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(CHECK_BRAKE, "YES") == 0) &&
                            (strcmp(WOBBLE, "YES") == 0)) s = 1;
                    break;
                case 37: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(CHECK_BRAKE, "YES") == 0) &&
                            (strcmp(CHEMICAL_SMELL, "YES") == 0)) s = 1;
                    break;
                    /* if part of statement 6 */
                case 38:if((strcmp(PROBLEM, "YES") == 0) &&
                           (strcmp(CHECK_BRAKE, "YES") == 0) &&
                           (strcmp(SPONGEY, "YES") == 0)) s = 1;
                    break;
                case 39: if((strcmp(PROBLEM, "YES") == 0) &&
                            (strcmp(CHECK_BRAKE, "YES") == 0) &&
                            (strcmp(SQUEAK, "YES") == 0)) s = 1;
                    break;
                    /* if part of statement 6 */

                    /********* comment 1680 ******/
            }
            /* see if the then part should be invoked */
            if( s != 1) {
                /* failed..search rest of statements for
                   same conclusion */
                /* get conclusion */
                i = statsk[sp];
                strcpy(varble, conclt[i]);
                /* search for conclusion starting at the
                   next statement number */
                f = statsk[sp] + 1;
                determine_member_concl_list();
                sp = sp+1;
            }
            /* pop old conclusion and put on new one */
        } while((s != 1) && (sn !=0));  /* outer do-while loop */
        if(sn != 0){
            /* if part true invoke then part */
            /* then part of if-then statements from the
               position knowledge base */
            switch (sn) {
                /* then part of statement 1 */
                /******* comment 1500 *******/
                case 1: strcpy(PROBLEM, "NO");
                    printf("NO ISSUE\n");
                    break;
                    /* then part of statement 2 */
                    /****** comment 1510 ******/
                case 2: strcpy(PART, "YES");
                    printf("PART = OIL PUMP\n");
                    break;
                    /* then part of statement 3 */
                case 3: strcpy(PART, "YES");
                    printf("PART = OIL FILTER\n");
                    break;
                    /* then part of statement 4 */
                    /******** comment 1560 ******/
                case 4: strcpy(PART, "YES");
                    printf("OIL\n");
                    break;
                    /* then part of statement 5 */
                    /****** comment 1570 *****/
                case 5: strcpy(PART, "YES");
                    printf("OIL DRAIN PLUG\n");
                    break;
                    /* then part of statement 6 */
                case 6: strcpy(PART, "YES");
                    printf("ENGINE GASKET\n");
                    break;
                case 7: strcpy(PART, "YES");
                    printf("RADIATOR\n");
                    break;
                    /* then part of statement 3 */
                case 8: strcpy(PART, "YES");
                    printf("RADIATOR HOSE\n");
                    break;
                    /* then part of statement 4 */
                    /******** comment 1560 ******/
                case 9: strcpy(PART, "YES");
                    printf("TRANSMISSION DRAIN PLUG\n");
                    break;
                    /* then part of statement 5 */
                    /****** comment 1570 *****/
                case 10: strcpy(PART, "YES");
                    printf("BATTERY\n");
                    break;
                    /* then part of statement 6 */
                case 11: strcpy(PART, "YES");
                    printf("IGNITION SWITCH\n");
                    break;
                case 12: strcpy(PART, "YES");
                    printf("STARTER MOTOR\n");
                    break;
                    /* then part of statement 3 */
                case 13: strcpy(PART, "YES");
                    printf("BATTERY TERMINALS\n");
                    break;
                    /* then part of statement 4 */
                    /******** comment 1560 ******/
                case 14: strcpy(PART, "YES");
                    printf("FUEL LEVEL\n");
                    break;
                    /* then part of statement 5 */
                    /****** comment 1570 *****/
                case 15: strcpy(PART, "YES");
                    printf("FUEL SYSTEM\n");
                    break;
                    /* then part of statement 6 */
                case 16: strcpy(PART, "YES");
                    printf("VACUUM HOSE\n");
                    break;
                case 17: strcpy(PART, "YES");
                    printf("SPARK PLUGS\n");
                    break;
                    /* then part of statement 3 */
                case 18: strcpy(PART, "YES");
                    printf("FUEL CONDITION\n");
                    break;
                    /* then part of statement 4 */
                    /******** comment 1560 ******/
                case 19: strcpy(PART, "YES");
                    printf("FUEL INJECTORS\n");
                    break;
                    /* then part of statement 5 */
                    /****** comment 1570 *****/
                case 20: strcpy(PART, "YES");
                    printf("INGITION WIRES\n");
                    break;
                    /* then part of statement 6 */
                case 21: strcpy(PART, "YES");
                    printf("ENGINE COMPONENTS\n");
                    break;
                case 22: strcpy(PART, "YES");
                    printf("BATTERY\n");
                    break;
                    /* then part of statement 3 */
                case 23: strcpy(PART, "YES");
                    printf("ALTERNATOR\n");
                    break;
                    /* then part of statement 4 */
                    /******** comment 1560 ******/
                case 24: strcpy(PART, "YES");
                    printf("ALTERNATOR DRIVE BELT\n");
                    break;
                    /* then part of statement 5 */
                    /****** comment 1570 *****/
                case 25: strcpy(PART, "YES");
                    printf("BATTERY WIRES\n");
                    break;
                    /* then part of statement 6 */
                case 26: strcpy(PART, "YES");
                    printf("ELECTRICAL SYSTEM\n");
                    break;
                case 27: strcpy(PART, "YES");
                    printf("COOLANT\n");
                    break;
                    /* then part of statement 3 */
                case 28: strcpy(PART, "YES");
                    printf("DRIVE BELT\n");
                    break;
                    /* then part of statement 4 */
                    /******** comment 1560 ******/
                case 29: strcpy(PART, "YES");
                    printf("RADIATOR\n");
                    break;
                    /* then part of statement 5 */
                    /****** comment 1570 *****/
                case 30: strcpy(PART, "YES");
                    printf("RADIATOR FAN\n");
                    break;
                    /* then part of statement 6 */
                case 31: strcpy(PART, "YES");
                    printf("WATTER PUMP\n");
                    break;
                case 32: strcpy(PART, "YES");
                    printf("TIRE PRESSURE\n");
                    break;
                case 33: strcpy(PART, "YES");
                    printf("AIR FILTER\n");
                    break;
                case 34: strcpy(PART, "YES");
                    printf("FUEL TANK\n");
                    break;
                case 35: strcpy(PART, "YES");
                    printf("FUEL MANAGMENT SYSTEM\n");
                    break;
                case 36: strcpy(PART, "YES");
                    printf("BRAKE PARTS\n");
                    break;
                case 37: strcpy(PART, "YES");
                    printf("BRAKE PARTS\n");
                    break;
                case 38: strcpy(PART, "YES");
                    printf("BRAKE LINES\n");
                    break;
                case 39: strcpy(PART, "YES");
                    printf("BRAKE PARTS\n");
                    break;

                    /****** comment 1680 ********/
            }
            /* pop the stack */
           popStack();
        }
    }
}
void popStack()
{
    sp=sp+1;
    if(sp >= 11)
        /* finished */
        printf("*** SUCCESS\n");
    else {
        /* stack is not empty */
        /* get next clause then continue */
        clausk[sp] = clausk[sp]+1;
        b545();
    }
}
void b545()
{
    i = (statsk[sp] - 1) * 44 + clausk[sp];
    /* clause variable */
    strcpy(varble, clvarlt[i]);
    if (strcmp(varble, "") != 0) {
        /*is this clause variable a conclusion? */
        f = 1;
        determine_member_concl_list();
        if (sn != 0)
            /* it is a conclusion push it */
            b520();
        /* check instantiation of this clause */
        instantiate();
        clausk[sp] = clausk[sp] + 1;
    }
}