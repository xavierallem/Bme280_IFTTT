/** @file iftt.cxx
*  @brief  
*  
* Provides functions to interface curl with ifttt
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
#include <curl/curl.h>
#include "iftt.h"

/*
*#####################################################################
*  Process block
*  -------------
*  Solve all your problems here 
*#####################################################################
*/

/** 
*  @brief Description on POST_IFTTT
*  
*  This function sends the data to IFTTT through cURL
*
*  @return void
*/

void POST_IFTTT (const char *ptr,const char *ptr1)
{
	
	/*Create Curl instance*/
	CURL *curl;
	CURLcode res;

	/* In windows, this will init the winsock stuff */ 
	curl_global_init(CURL_GLOBAL_ALL);

	/* get a curl handle */ 
	curl = curl_easy_init();
	if(curl) {
		/* First set the URL that is about to receive our POST. This URL can
	just as well be a https:// URL if that is what should receive the
	data. */ 
		char str[50];
		sprintf(str,"https://maker.ifttt.com/trigger/{event}/with/key/%s",ptr1);
		curl_easy_setopt(curl, CURLOPT_URL, str);
		/* Now specify the POST data */ 
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, ptr);

		/* Perform the request, res will get the return code */ 
		res = curl_easy_perform(curl);
		/* Check for errors */ 
		if(res != CURLE_OK)
		fprintf(stderr, "curl_easy_perform() failed: %s\n",
		curl_easy_strerror(res));

		/* always cleanup */ 
		curl_easy_cleanup(curl);
	}
	/* global cleanup */
	curl_global_cleanup();
	
	
}
