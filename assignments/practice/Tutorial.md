# Tutorial For iftttdemo

## Inroduction 

In this tutorial we will connect `ifttt web-hook` and send values from our temperature sensor `bme280` to `ifttt` platform.

## Pre-requisites

For this tutorial, you need prior knowledge to: -
-  C/C++  coding language
- Ifttt platform for IoT. 
- Must know how web-hook works

To get familiar with ifttt and web-hooks [*click here*](https://medium.com/measuring-the-great-indoors/linking-ifttt-processing-with-webhooks-6b20c6ed722d)

## Steps

- **Step1**: - *Set-up webhook*
    - Create iftt Account
    
    ![lol](https://cdn.shopify.com/s/files/1/0176/3274/files/IFTTT-homepage.PNG?v=1541705179)
    - Create a webhook Applet
    
    ![lol](https://cdn.shopify.com/s/files/1/0176/3274/files/IFTTT-webhooks-filter.PNG?v=1541705925)
    - Get the Auth Key
    
    ![lol](https://cdn.shopify.com/s/files/1/0176/3274/files/IFTTT-webhooks-key-screen.PNG?v=1541706180)
    
- **Step2**: - Download the recquired files from [Here](https://gitlab.iotiot.in/IOTFCA04/module5/tree/master/assignments/practice/problem1) and make sure to put all those files in the same folder.
Make sure you have installed these libraries:-
    - shunyaInterfaces.h
    - Wire.h
    - curl/curl.h
    - sys/resource.h

- **Step3**: Write the Code as follows:-
```c++
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
	chat auth[50];
	printf("Enter TheIFTTT Auth key \n");
	/* Take input of auth key */
	scanf("%[^\n]%*c", auth);
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
		POST_IFTTT(buffer.GetString(),auth);
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
		POST_IFTTT(buffer1.GetString(),auth);


	}
	return 0;
}

```

**_Note_**: - Make sure you have installed the recquired `libraries` before executing the main work file
