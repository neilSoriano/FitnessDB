//
//  24HourDBFinal.cpp
//  
//
//  Created by Nathan Huizar and Neil Soriano on 12/4/18.
//

#include <iostream>
#include <stdio.h>
#include <sqlite3.h>
#include <string>

using namespace std;

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;
    for(i = 0; i<argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}


static int TrainerInformation();
static int OwnerInformation();
static int displaySportAmenities();
static int displayComfortAmenities();
static int displayWorkoutPlans();
static int displayEquipment();
static int displayFacilityTypes();
static int displayFacilityCost();
static int displayFacilityLocations();
static int displayOwners();
static int ownerMenu();
static int displayTraineeCosts();
static int displayTraineeMonthly();
static int displayMembershipTypes();
static int displayTrainerInfo();

int menu();




int main() {
    
    menu();
    
}


static int displayTrainerInfo(){
    
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;
    const char* data = "Callback function called";
    char answer;
    
    
    /* Open database */
    rc = sqlite3_open("24hr.db", &db);
    
    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }
    
    /* Create SQL statement */
    sql = "Select tnr_trainerid, tnr_traineeid, tnr_facilityid From Trainer order by tnr_trainerid; ";
    
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
    
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Operation done successfully\n");
    }
    
    sqlite3_close(db);
    
    cout << "Would you like to return to the menu? Y/N ";
    cin >> answer;
    
    if(answer == 'Y'){
        menu();
    }
    
    else
    
    return 0;
    
}

static int displayMembershipTypes(){
    
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;
    const char* data = "Callback function called";
    char answer;
    
    
    /* Open database */
    rc = sqlite3_open("24hr.db", &db);
    
    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }
    
    /* Create SQL statement */
    sql = "Select Distinct(tee_memshiptype) From Trainee";
    
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
    
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Operation done successfully\n");
    }
    
    sqlite3_close(db);
    
    cout << "Would you like to return to the menu? Y/N ";
    cin >> answer;
    
    if(answer == 'Y'){
        menu();
    }
    
    else
    
    return 0;
    
}

static int displayTraineeMonthly(){
    
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;
    const char* data = "Callback function called";
    char answer;
    
    
    /* Open database */
    rc = sqlite3_open("24hr.db", &db);
    
    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }
    
    /* Create SQL statement */
    sql = "Select AVG(tee_monthlyfee), tee_memshiptype From Trainee group by tee_memshiptype";
    
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
    
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Operation done successfully\n");
    }
    
    sqlite3_close(db);
    
    cout << "Would you like to return to the menu? Y/N ";
    cin >> answer;
    
    if(answer == 'Y'){
        menu();
    }
    
    else
    
    return 0;
    
}

static int displayTraineeCosts(){
    
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;
    const char* data = "Callback function called";
    char answer;
    
    
    /* Open database */
    rc = sqlite3_open("24hr.db", &db);
    
    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }
    
    /* Create SQL statement */
    sql = "Select tee_memshipid, tee_monthlyfee, tee_memshiptype From Trainee Order by tee_memshipid";
    
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
    
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Operation done successfully\n");
    }
    
    sqlite3_close(db);
    
    cout << "Would you like to return to the menu? Y/N ";
    cin >> answer;
    
    if(answer == 'Y'){
        menu();
    }
    
    else
    
    return 0;
    
}

static int ownerMenu(){
    
    string arr[21];
    arr[0]="#21RR"; arr[1]="#20MH"; arr[2]="#19JJ"; arr[3]="#18CB"; arr[4]="#17TG";
    arr[5]="#16AB"; arr[6]="#15JH"; arr[7]="#14FOB"; arr[8]="#13JT"; arr[9]="#12MB";
    arr[10]="#11NL"; arr[11]="#10TN"; arr[12]="#09JP"; arr[13]="#08JG"; arr[14]="#07JC";
    arr[15]="#06PW"; arr[16]="#05RJ"; arr[17]="#04DW"; arr[18]="#03SA"; arr[19]="#02AG";
    arr[20]="#01LZ";
    
    string id;
    
    cout << "Enter your owner id" << endl;
    cin >> id;
    
    for(int i = 0; i<id.length(); i++){
        
        if(arr[i] == id){
            
            char answer;
            
            cout << "What would you like to know? " << endl;
            cout << "1. Facility Costs"<< endl;
            cout << "2. Trainee monthly costs" << endl;
            
            cin >> answer;
            
            if (answer == '1'){
                
                displayFacilityCost();
                
            }
            
            if (answer == '2'){
                
                displayTraineeCosts();
                
            }
            
        }
        
        
    }
    
    
}

static int displayOwners(){
    
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;
    const char* data = "Callback function called";
    char answer;
    
    
    /* Open database */
    rc = sqlite3_open("24hr.db", &db);
    
    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }
    
    /* Create SQL statement */
    sql = "Select o_facilityid, o_name From Owner";
    
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
    
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Operation done successfully\n");
    }
    
    sqlite3_close(db);
    
    cout << "Would you like to return to the menu? Y/N ";
    cin >> answer;
    
    if(answer == 'Y'){
        menu();
    }
    
    else
    
    return 0;
    
}

static int displayFacilityLocations(){
    
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;
    const char* data = "Callback function called";
    char answer;
    
    
    /* Open database */
    rc = sqlite3_open("24hr.db", &db);
    
    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }
    
    /* Create SQL statement */
    sql = "Select f_facilityid, f_city From Facility";
    
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
    
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Operation done successfully\n");
    }
    
    sqlite3_close(db);
    
    cout << "Would you like to return to the menu? Y/N ";
    cin >> answer;
    
    if(answer == 'Y'){
        menu();
    }
    
    else
    
    return 0;
    
}

static int displayFacilityCost(){
    
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;
    const char* data = "Callback function called";
    char answer;
    
    
    /* Open database */
    rc = sqlite3_open("24hr.db", &db);
    
    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }
    
    /* Create SQL statement */
    sql = "Select f_facilitycost, f_facilityid From Facility Order by f_facilityid";
    
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
    
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Operation done successfully\n");
    }
    
    sqlite3_close(db);
    
    cout << "Would you like to return to the menu? Y/N ";
    cin >> answer;
    
    if(answer == 'Y'){
        menu();
    }
    
    else
    
    return 0;
    
}

static int displayFacilityTypes(){
    
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;
    const char* data = "Callback function called";
    char answer;
    
    
    /* Open database */
    rc = sqlite3_open("24hr.db", &db);
    
    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }
    
    /* Create SQL statement */
    sql = "Select f_facilityid, f_memshiptype From Facility";
    
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
    
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Operation done successfully\n");
    }
    
    sqlite3_close(db);
    
    cout << "Would you like to return to the menu? Y/N ";
    cin >> answer;
    
    if(answer == 'Y'){
        menu();
    }
    
    else
    
    return 0;
    
}

static int displayEquipment(){
    
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;
    const char* data = "Callback function called";
    char answer;
    
    
    /* Open database */
    rc = sqlite3_open("24hr.db", &db);
    
    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }
    
    /* Create SQL statement */
    sql = "Select e_equipname, e_facilityid From Equipment order by e_facilityid asc";
    
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
    
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Operation done successfully\n");
    }
    
    sqlite3_close(db);
    
    cout << "Would you like to return to the menu? Y/N ";
    cin >> answer;
    
    if(answer == 'Y'){
        menu();
    }
    
    else
    
    return 0;
    
}

static int displayWorkoutPlans(){
    
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;
    const char* data = "Callback function called";
    char answer;
    
    
    /* Open database */
    rc = sqlite3_open("24hr.db", &db);
    
    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }
    
    /* Create SQL statement */
    sql = "Select Distinct(wp_facilityid), wp_memshiptype, wp_fitnessclass From WorkoutPlan order by wp_facilityid;";
    
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
    
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Operation done successfully\n");
    }
    
    sqlite3_close(db);
    
    cout << "Would you like to return to the menu? Y/N ";
    cin >> answer;
    
    if(answer == 'Y'){
        menu();
    }
    
    else
    
    return 0;
    
}

static int displaySportAmenities(){
    
    
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;
    const char* data = "Callback function called";
    char answer;

    
    /* Open database */
    rc = sqlite3_open("24hr.db", &db);
    
    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }
    
    /* Create SQL statement */
    sql = "Select a_facilityid, a_sport From Ameneties";
    
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
    
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Operation done successfully\n");
    }
    
    sqlite3_close(db);
    
    cout << "Would you like to return to the menu? Y/N ";
    cin >> answer;
    
    if(answer == 'Y'){
        menu();
    }
    
    else
    
    return 0;
    
    
}

static int displayComfortAmenities(){
    
    
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;
    const char* data = "Callback function called";
    char answer;

    
    /* Open database */
    rc = sqlite3_open("24hr.db", &db);
    
    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }
    
    /* Create SQL statement */
    sql = "Select Distinct(a_comfort),a_facilityid From Ameneties";
    
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
    
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Operation done successfully\n");
    }
    sqlite3_close(db);
    
    cout << "Would you like to return to the menu? Y/N ";
    cin >> answer;
    
    if(answer == 'Y'){
        menu();
    }
    
    else
    
    return 0;
    
}

static int displayPersonalAmenities(){
    
    
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;
    const char* data = "Callback function called";
    char answer;
    
    /* Open database */
    rc = sqlite3_open("24hr.db", &db);
    
    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }
    
    /* Create SQL statement */
    sql = "Select Distinct(a_personal),a_facilityid From Ameneties";
    
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
    
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Operation done successfully\n");
    }
    sqlite3_close(db);
    
    cout << "Would you like to return to the menu? Y/N ";
    cin >> answer;
    
    if(answer == 'Y'){
        menu();
    }
    
    else
    
    return 0;
    
}

int menu(){
    
    char answer;
    
    cout << "Welcome to 24 hour DB" << endl;
    cout << "What would you like more information about" << endl;
    cout << "1. Trainers" << endl;
    cout << "2. Trainees" << endl;
    cout << "3. Owners" << endl;
    cout << "4. Facilities" << endl;
    cout << "5. Equipment" << endl;
    cout << "6. Workout Plans" << endl;
    cout << "7. Ameneties" << endl;
    cout << "0. To exit" << endl;
    
    
    cin >> answer;
    
    if (answer == '1') {
        
        char answer;
        
        cout << "What would you like to know? " << endl;
        cout << "1. Trainer locations and availability "<< endl;
        
        cin >> answer;
        
        if(answer=='1'){
            
            displayTrainerInfo();
            
        }
        
    }
    
    if (answer == '2') {
        
        char answer;
        
        cout << "What would you like to know? " << endl;
        cout << "1. Monthly fees "<< endl;
        cout << "2. Membership types "<< endl;
        
        
        cin >> answer;
        
        if(answer == '1'){
            
            displayTraineeMonthly();
            
        }
        
        if (answer == '2'){
            
            displayMembershipTypes();
            
        }
        
        else return 0;
    }
    
    if (answer == '3') {
        
        char answer;
        
        cout << "Are you an owner? Y/N  " << endl;
        
        cin >> answer;
        
        if(answer == 'Y'){
            ownerMenu();
        }
        
        if(answer == 'N') {
            
            char answer;
            
            cout << "What would you like to know? " << endl;
            cout << "1. Owners " << endl;

            
            cin >> answer;
            
            if(answer == '1'){
                
                displayOwners();
                
            }
            
        }
       
    }
    
    if (answer == '4') {
        
        char answer;
        
        cout << "What would you like to know? " << endl;
        cout << "1. Facility types"<< endl;
        cout << "2. Facility locations"<< endl;
        
        cin >> answer;
        
        if (answer == '1'){
            
            displayFacilityTypes();
            
        }
        
        if (answer == '2'){
            
            displayFacilityLocations();
            
        }
        
        
    }
    
    if (answer == '5') {
        
        char answer;

        
        cout << "What would you like to know? " << endl;
        cout << "1. Equipment types "<< endl;
        
        cin >> answer;
        
        if(answer == '1'){
            
            displayEquipment();

        }
    }
    
    if (answer == '6') {
        
        char answer;
        
        //query that shows the fitness classes at each facility
        cout << "What would you like to know? " << endl;
        cout << "1. Fitness classes " << endl;
        
        cin>> answer;
        
        if(answer == '1'){
            
            displayWorkoutPlans();
            
        }
        
    }
    
    if (answer == '7') {
        
        char answer;
        
        //query to show the amenities at the different facilities
        cout << "What would you like to know? " << endl;
        cout << "1. Sport Amenities "<< endl;
        cout << "2. Personal Amenities "<< endl;
        cout << "3. Comfort Amenities "<< endl;
        
        cin >> answer;
        
        if(answer == '1'){
            
            displaySportAmenities();
        }
        
        if(answer == '2'){
            
            displayPersonalAmenities();
            
        }
        
        if(answer == '3'){
            
            displayComfortAmenities();
            
        }
        
        
    }
    
    
    else return 0;
}
