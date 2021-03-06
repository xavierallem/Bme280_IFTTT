/** @file ifttt.cxx
 *  @brief  description of the file 
 *  
 *  The program sends values to ifttt webhook
 * if the temperature from bme280 is above 30
 * and if the ram usage is above 100MB
 *  
 *  @author Allen Xavier
 *  @bug None yet  
 */

/*
 *#####################################################################
 *  Initialization block
 *  ---------------------
 *  This block contains initialization code for this particular file.
 *  It typically contains Includes, constants or global variables used
 *  throughout the file.
 *#####################################################################
 */

/* --- Standard Includes --- */
#include <stdio.h>


/* --- Project Includes --- */
#include <shunyaInterfaces.h>
#include <Wire.h>
#include "bme280.h"
#include <curl/curl.h>
#include "iftt.h"
#include <sys/resource.h>


/*
 *#####################################################################
 *  Process block
 *  -------------
 *  Solve all your problems here 
 *#####################################################################
 */
using namespace rapidjson;



/**
 *  @brief Description on main
 *
 *  Connects and gets temperature , creates json doc
 * and publishes data to ifttt
 *
 *  @return 
 */

int main(){
        /* initializing usage struct */
	struct rusage r_usage;
	/* getting perforamcne parameters */
	getrusage(RUSAGE_SELF,&r_usage);
	/* Variable to store auth key*/
	char auth[50];
	/* Variable to store event name*/
	char event[50];
	printf("Enter TheIFTTT Auth key \n");
	/* Take input of auth key */
	scanf("%[^\n]%*c", auth);
	printf("Enter TheIFTTT event \n");
	/* Take input of even */
	scanf("%[^\n]%*c", event);
        /* Get termperature */
        float temperature = getTemperature(); 
        /* Check condition 1 */
	if(temperature>30)
	{
		/*Json file to be parsed*/
		const char* json;
		sprtinf(json."{\"Temperature\":30,\"Humidity\":%f}",temperature);
		/*Initializing document variable*/
		Document d;
		/*Parsing the json */
		d.Parse(json);
		/*Initializing buffer*/
		StringBuffer buffer;
		/*Wrtier stream-*/
		Writer<StringBuffer> writer(buffer);
		/* Write the JSON document `d` into the buffer`*/
		d.Accept(writer);
		/* Publish the json values and auth */
		POST_IFTTT(buffer.GetString(),auth,event);
	}
	/* Check conditon 2 */
	if(r_usage.ru_idrss>1,000,000){
		
		const char* json1;
		sprtinf(json1."{\"Ram Usage is \":%ld}",r_usage.ru_idrss);
		/*Initializing document variable*/
		Document d1;
		/*Parsing the json */
		d1.Parse(json1);
		/*Initializing buffer*/
		StringBuffer buffer1;
		/*Wrtier stream-*/
		Writer<StringBuffer> writer(buffer1);
		/* Write the JSON document `d1` into the buffer`*/
		d1.Accept(writer);
		/* Publish the json values and auth */
		POST_IFTTT(buffer1.GetString(),auth,event);


	}
	return 0;
}


